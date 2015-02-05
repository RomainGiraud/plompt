#include <segment/currentdir_segment.h>

#include <prompt/prompt.h>
#include <shell/shell.h>
#include <special_characters.h>
#include <tools.h>

#include <string>
#include <vector>
#include <algorithm>

#include <cstdlib>

#include <unistd.h>

#include <easylogging++.h>

using std::string;
using std::vector;
using std::pair;
using std::mismatch;

CurrentDirSegment::CurrentDirSegment(Style style, unsigned int size_max)
    : Segment(style), _size_max(size_max)
{
}

void CurrentDirSegment::printSeparator(std::ostream& os) const
{
    Style styleSep(Color::Cyan, _style.getBackground());
    //styleSep = _style;
    //styleSep.setBold(true);
    os << _prompt->getShell()->generate(styleSep) << separator_thin2 << _prompt->getShell()->generate(_style);
}

void CurrentDirSegment::print(std::ostream& os) const
{
    size_t buffer_size = 1024;
    char *buffer = new char[buffer_size];
    if (getcwd(buffer, buffer_size) == 0)
    {
        char* env = getenv("PWD");
        if (strlen(env) >= buffer_size)
        {
            LOG(ERROR) << "current directory invalid";
            os << "<dir>";
            return;
        }

        strcpy(buffer, env);
    }

    string full(buffer);
    char* env = getenv("HOME");
    if (env != 0)
    {
        string home(env);
        pair<string::iterator, string::iterator> ret = mismatch(full.begin(), full.end(), home.begin());

        string path;
        if (ret.second == home.end())
        {
            path = "~";

            if (ret.first != full.end())
                path.append(ret.first, full.end());
        }
        else
            path.assign(full.begin(), full.end());

        vector<string> tokens;
        Tools::split(path, '/', true, tokens);

        if (path[0] == '/')
            printSeparator(os);

        vector<string>::const_iterator it = tokens.cbegin();
        if (tokens.size() > _size_max)
        {
            os << (*it);
            printSeparator(os);
            os << ellipsis;
            printSeparator(os);
            ++it;

            for (unsigned int i = 0; i < (tokens.size() + 1) - _size_max; ++i)
                ++it;
        }

        for ( ; it != tokens.cend(); ++it)
        {
            os << (*it);
            printSeparator(os);
        }
    }

    delete[] buffer;
}

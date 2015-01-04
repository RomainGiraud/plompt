#include <prompt/prompt.h>

#include <shell/shell.h>
#include <segment/segment.h>

#include <sstream>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

Prompt::Prompt()
    : _shell(0)
{
}

Prompt::Prompt(Shell* shell)
    : _shell(shell)
{
}

Prompt::~Prompt()
{
    for (auto segment : _segments)
    {
        delete segment;
    }
}

void Prompt::load(const std::string& filename)
{
    Config cfg;

    // Read the file. If there is an error, report it and exit.
    try
    {
        cfg.readFile(filename.c_str());
    }
    catch(const FileIOException &fioex)
    {
        throw string ("I/O error while reading file.");
    }
    catch(const ParseException &pex)
    {
        stringstream msg;
        msg << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << std::endl;
        throw string (msg.str());
    }


    const Setting& root = cfg.getRoot();
    string name;
    root.lookupValue("name", name);
    cout << "Name: " << name << endl;
}

void Prompt::add(Segment* segment)
{
    segment->setPrompt(this);
    _segments.push_back(segment);
}

std::string Prompt::toString() const
{
    ostringstream os;
    print(os);
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const Prompt& prompt)
{
    prompt.print(os);
    return os;
}

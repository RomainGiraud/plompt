#include "prompt.h"

#include "segment.h"

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
    _segments.push_back(segment);
}

const char* separator = "\uE0B0";
const char* separator_thin = "\uE0B1";
const char* lock = "\uE0A2";
const char* separator2 = "\u25B6";
const char* separator_thin2 = "\u276F";

std::ostream& operator<<(std::ostream& os, const Prompt& prompt)
{
    Prompt::SegmentList::const_iterator it_curr = prompt._segments.begin();
    Prompt::SegmentList::const_iterator it_next = std::next(it_curr);
    //for (auto segment : prompt._segments)
    for (; it_curr != prompt._segments.end(); ++it_curr, it_next = std::next(it_curr))
    {
        os << prompt._shell->generate((*it_curr)->getStyle());
        os << (**it_curr);

        Style temp((*it_curr)->getStyle().getBackground(),
            it_next != prompt._segments.end() ? (*it_next)->getStyle().getBackground() : Color::Default);
        os << prompt._shell->generate(temp);
        os << separator;

        os << prompt._shell->reset();
    }

    os << ' ';

    return os;
}

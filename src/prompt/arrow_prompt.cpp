#include <prompt/arrow_prompt.h>

#include <shell/shell.h>
#include <segment/segment.h>

#include <sstream>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

ArrowPrompt::ArrowPrompt()
    : Prompt(0)
{
}

ArrowPrompt::ArrowPrompt(Shell* shell)
    : Prompt(shell)
{
}

ArrowPrompt::~ArrowPrompt()
{
}

const char* separator = "\uE0B0";
const char* separator_thin = "\uE0B1";
const char* lock = "\uE0A2";
const char* separator2 = "\u25B6";
const char* separator_thin2 = "\u276F";

void ArrowPrompt::print(std::ostream& os) const
{
    Prompt::SegmentList::const_iterator it_curr = _segments.begin();
    Prompt::SegmentList::const_iterator it_next = std::next(it_curr);
    //for (auto segment : _segments)
    for (; it_curr != _segments.end(); ++it_curr, it_next = std::next(it_curr))
    {
        os << _shell->generate((*it_curr)->getStyle());
        os << (**it_curr);

        Style temp((*it_curr)->getStyle().getBackground(),
            it_next != _segments.end() ? (*it_next)->getStyle().getBackground() : Color::Default);
        os << _shell->generate(temp);
        os << separator;

        os << _shell->reset();
    }

    os << ' ';
}

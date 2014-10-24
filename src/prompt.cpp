#include "prompt.h"

#include "segment.h"

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

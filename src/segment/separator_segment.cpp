#include <segment/separator_segment.h>

SeparatorSegment::SeparatorSegment(Style style, const std::string &separator)
    : Segment(style), _separator(separator)
{
}

void SeparatorSegment::print(std::ostream& os) const
{
    os << _separator;
}

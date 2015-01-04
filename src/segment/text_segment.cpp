#include <segment/text_segment.h>

TextSegment::TextSegment(Style style, const std::string &text)
    : Segment(style), _text(text)
{
}

void TextSegment::print(std::ostream& os) const
{
    os << _text;
}

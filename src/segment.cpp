#include "segment.h"

Segment::Segment(Style style)
	: _style(style)
{
}

Segment::~Segment()
{
}

std::ostream& operator<<(std::ostream& os, const Segment& segment)
{
    segment.print(os);
    return os;
}

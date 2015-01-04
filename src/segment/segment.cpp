#include <segment/segment.h>

#include <easylogging++.h>

Segment::Segment()
	: _prompt(0)
{
}

Segment::Segment(Style style)
	: _style(style), _prompt(0)
{
}

Segment::~Segment()
{
}

std::ostream& operator<<(std::ostream& os, const Segment& segment)
{
	if (!segment.validate())
		LOG(ERROR) << "Invalid segment";

    segment.print(os);
    return os;
}

#include <segment/git_segment.h>

GitSegment::GitSegment(Style style)
    : Segment(style)
{
}

void GitSegment::print(std::ostream& os) const
{
    os << "$(__git_ps1)";
}

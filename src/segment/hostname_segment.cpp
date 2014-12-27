#include <segment/hostname_segment.h>

#include <pwd.h>
#include <unistd.h>

HostnameSegment::HostnameSegment(Style style)
    : Segment(style)
{
}

void HostnameSegment::print(std::ostream& os) const
{
    const size_t size = 1024;
    char buffer[size];
    gethostname(buffer, size);
    os << buffer;
}

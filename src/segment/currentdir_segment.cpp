#include <segment/currentdir_segment.h>

#include <unistd.h>

CurrentDirSegment::CurrentDirSegment(Style style)
    : Segment(style)
{
}

void CurrentDirSegment::print(std::ostream& os) const
{
    size_t buffer_size = 1024;
    char *buffer = new char[buffer_size];
    if (getcwd(buffer, buffer_size) == 0)
    {
        os << "<dir>";
    }
    else
    {
        os << buffer;
    }
    delete[] buffer;
}

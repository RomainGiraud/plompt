#ifndef HOSTNAME_SEGMENT_H
#define HOSTNAME_SEGMENT_H

#include <segment/segment.h>

class HostnameSegment : public Segment
{
public:
    HostnameSegment(Style style);

    virtual void print(std::ostream& os) const;
};

#endif // HOSTNAME_SEGMENT_H

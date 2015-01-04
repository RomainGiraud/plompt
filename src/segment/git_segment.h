#ifndef GIT_SEGMENT_H
#define GIT_SEGMENT_H

#include <segment/segment.h>

class GitSegment : public Segment
{
public:
    GitSegment(Style style);

    virtual void print(std::ostream& os) const;
};

#endif // GIT_SEGMENT_H

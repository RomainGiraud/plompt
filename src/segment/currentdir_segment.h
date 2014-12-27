#ifndef CURRENTDIR_SEGMENT_H
#define CURRENTDIR_SEGMENT_H

#include <segment/segment.h>

class CurrentDirSegment : public Segment
{
public:
    CurrentDirSegment(Style style);

    virtual void print(std::ostream& os) const;
};

#endif // CURRENTDIR_SEGMENT_H

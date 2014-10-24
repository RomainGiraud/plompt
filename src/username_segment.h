#ifndef USERNAME_SEGMENT_H
#define USERNAME_SEGMENT_H

#include "segment.h"

class UserNameSegment : public Segment
{
public:
    UserNameSegment(Style style);

    virtual void print(std::ostream& os) const;
};

#endif // USERNAME_SEGMENT_H

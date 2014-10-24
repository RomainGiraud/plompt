#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>

#include "style.h"

class Segment
{
public:
    Segment(Style style);
    virtual ~Segment();

    inline const Style& getStyle() const
    {
        return _style;
    }

    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Segment& segment);

protected:
    Style _style;
};

#endif // SEGMENT_H

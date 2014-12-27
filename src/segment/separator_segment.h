#ifndef SEPARATOR_SEGMENT_H
#define SEPARATOR_SEGMENT_H

#include <segment/segment.h>

#include <string>

class SeparatorSegment : public Segment
{
public:
    SeparatorSegment(Style style, const std::string &separator);

    virtual void print(std::ostream& os) const;

private:
	std::string _separator;
};

#endif // SEPARATOR_SEGMENT_H

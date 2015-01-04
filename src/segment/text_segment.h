#ifndef TEXT_SEGMENT_H
#define TEXT_SEGMENT_H

#include <segment/segment.h>

#include <string>

class TextSegment : public Segment
{
public:
    TextSegment(Style style, const std::string &text);

    virtual void print(std::ostream& os) const;

private:
	std::string _text;
};

#endif // TEXT_SEGMENT_H

#ifndef CURRENTDIR_SEGMENT_H
#define CURRENTDIR_SEGMENT_H

#include <segment/segment.h>

class CurrentDirSegment : public Segment
{
public:
    CurrentDirSegment(Style style, unsigned int size_max);

    virtual void print(std::ostream& os) const;

private:
	unsigned int _size_max;

	void printSeparator(std::ostream& os) const;
};

#endif // CURRENTDIR_SEGMENT_H

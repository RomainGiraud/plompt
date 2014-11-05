#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include <list>

#include "shell.h"
#include "segment.h"

class Prompt
{
public:
    Prompt();
    Prompt(Shell* shell);
    ~Prompt();

    void load(const std::string& filename);

    void add(Segment* segment);

    friend std::ostream& operator<<(std::ostream& os, const Prompt& prompt);

private:
	Shell* _shell;
    typedef std::list <Segment*> SegmentList;
    SegmentList _segments;
};

#endif // PROMPT_H

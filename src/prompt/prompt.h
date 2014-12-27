#ifndef PROMPT_H
#define PROMPT_H

#include <iostream>
#include <list>

class Shell;
class Segment;

class Prompt
{
public:
    Prompt();
    Prompt(Shell* shell);
    ~Prompt();

    void load(const std::string& filename);

    void add(Segment* segment);

    virtual void print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Prompt& prompt);

protected:
	Shell* _shell;
    typedef std::list <Segment*> SegmentList;
    SegmentList _segments;
};

#endif // PROMPT_H
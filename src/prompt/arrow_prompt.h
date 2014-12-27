#ifndef ARROW_PROMPT_H
#define ARROW_PROMPT_H

#include <prompt/prompt.h>

#include <iostream>
#include <list>

class ArrowPrompt : public Prompt
{
public:
    ArrowPrompt();
    ArrowPrompt(Shell* shell);
    virtual ~ArrowPrompt();

    virtual void print(std::ostream& os) const;
};

#endif // ARROW_PROMPT_H

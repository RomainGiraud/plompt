#ifndef CUSTOM_PROMPT_H
#define CUSTOM_PROMPT_H

#include <prompt/prompt.h>

#include <iostream>
#include <list>

class CustomPrompt : public Prompt
{
public:
    CustomPrompt();
    CustomPrompt(Shell* shell);
    virtual ~CustomPrompt();

    virtual void print(std::ostream& os) const;
};

#endif // CUSTOM_PROMPT_H

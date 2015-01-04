#ifndef SEGMENT_H
#define SEGMENT_H

#include <style.h>

#include <iostream>

class Prompt;

class Segment
{
public:
	Segment();
    explicit Segment(Style style);
    virtual ~Segment();

    inline void setPrompt(Prompt *prompt)
    {
        _prompt = prompt;
    }

    inline void setStyle(const Style& style)
    {
        _style = style;
    }

    inline const Style& getStyle() const
    {
        return _style;
    }

    inline const bool validate() const
    {
        return _prompt != 0;
    }

    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Segment& segment);

protected:
    Style _style;
    Prompt *_prompt;
};

#endif // SEGMENT_H

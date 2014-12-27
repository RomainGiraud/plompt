#ifndef STYLE_H
#define STYLE_H

#include <color.h>

class Style
{
public:
    Style(Color fg, Color bg);

    inline const Color& getForeground() const
    {
    	return _foreground;
    }

    inline const Color& getBackground() const
    {
    	return _background;
    }

private:
    Color _foreground;
    Color _background;
    bool _isBold;
    bool _isUnderline;
};

#endif // STYLE_H
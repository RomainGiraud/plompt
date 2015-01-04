#ifndef STYLE_H
#define STYLE_H

#include <color.h>

class Style
{
public:
    Style();
    explicit Style(Color fg, Color bg);

    inline const Color& getForeground() const
    {
    	return _foreground;
    }

    inline const Color& getBackground() const
    {
    	return _background;
    }

    inline bool isBold() const
    {
        return _isBold;
    }

    inline void setBold(bool bold)
    {
        _isBold = bold;
    }

    inline bool isUnderline() const
    {
        return _isUnderline;
    }

    inline void setUnderline(bool underline)
    {
        _isUnderline = underline;
    }

private:
    Color _foreground;
    Color _background;
    bool _isBold;
    bool _isUnderline;
};

#endif // STYLE_H

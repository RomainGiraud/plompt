#include <style.h>

Style::Style(Color fg, Color bg)
    : _foreground(fg), _background(bg), _isBold(false), _isUnderline(false)
{
	(void)_isBold;
	(void)_isUnderline;
}

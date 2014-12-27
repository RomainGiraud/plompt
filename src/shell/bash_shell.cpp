#include <shell/bash_shell.h>

#include <sstream>

using namespace std;

#define BASH_COLOR(c) "\\[\x1b[" #c "m\\]"

const char* fg_def     = BASH_COLOR(39);
const char* fg_white   = BASH_COLOR(97);
const char* fg_black   = BASH_COLOR(30);
const char* fg_red     = BASH_COLOR(31);
const char* fg_green   = BASH_COLOR(32);
const char* fg_yellow  = BASH_COLOR(33);
const char* fg_blue    = BASH_COLOR(34);
const char* fg_magenta = BASH_COLOR(35);
const char* fg_cyan    = BASH_COLOR(36);
const char* fg_light_gray    = BASH_COLOR(37);
const char* fg_dark_gray     = BASH_COLOR(90);
const char* fg_light_red     = BASH_COLOR(91);
const char* fg_light_green   = BASH_COLOR(92);
const char* fg_light_yellow  = BASH_COLOR(93);
const char* fg_light_blue    = BASH_COLOR(94);
const char* fg_light_magenta = BASH_COLOR(95);
const char* fg_light_cyan    = BASH_COLOR(96);

const char* bg_def     = BASH_COLOR(49);
const char* bg_white   = BASH_COLOR(107);
const char* bg_black   = BASH_COLOR(40);
const char* bg_red     = BASH_COLOR(41);
const char* bg_green   = BASH_COLOR(42);
const char* bg_yellow  = BASH_COLOR(43);
const char* bg_blue    = BASH_COLOR(44);
const char* bg_magenta = BASH_COLOR(45);
const char* bg_cyan    = BASH_COLOR(46);
const char* bg_light_gray    = BASH_COLOR(47);
const char* bg_dark_gray     = BASH_COLOR(100);
const char* bg_light_red     = BASH_COLOR(101);
const char* bg_light_green   = BASH_COLOR(102);
const char* bg_light_yellow  = BASH_COLOR(103);
const char* bg_light_blue    = BASH_COLOR(104);
const char* bg_light_magenta = BASH_COLOR(105);
const char* bg_light_cyan    = BASH_COLOR(106);

#undef BASH_COLOR

std::string BashShell::generate(const Style& style) const
{
	ostringstream oss;
	switch (style.getForeground())
	{
		case Color::Default:
			oss << fg_def;
			break;
		case Color::White:
			oss << fg_white;
			break;
		case Color::Black:
			oss << fg_black;
			break;
		case Color::Red:
			oss << fg_red;
			break;
		case Color::Green:
			oss << fg_green;
			break;
		case Color::Yellow:
			oss << fg_yellow;
			break;
		case Color::Blue:
			oss << fg_blue;
			break;
		case Color::Magenta:
			oss << fg_magenta;
			break;
		case Color::Cyan:
			oss << fg_cyan;
			break;
		case Color::LightGray:
			oss << fg_light_gray;
			break;
		case Color::DarkGray:
			oss << fg_dark_gray;
			break;
		case Color::LightRed:
			oss << fg_light_red;
			break;
		case Color::LightGreen:
			oss << fg_light_green;
			break;
		case Color::LightYellow:
			oss << fg_light_yellow;
			break;
		case Color::LightBlue:
			oss << fg_light_blue;
			break;
		case Color::LightMagenta:
			oss << fg_light_magenta;
			break;
		case Color::LightCyan:
			oss << fg_light_cyan;
			break;
	}
	switch (style.getBackground())
	{
		case Color::Default:
			oss << bg_def;
			break;
		case Color::White:
			oss << bg_white;
			break;
		case Color::Black:
			oss << bg_black;
			break;
		case Color::Red:
			oss << bg_red;
			break;
		case Color::Green:
			oss << bg_green;
			break;
		case Color::Yellow:
			oss << bg_yellow;
			break;
		case Color::Blue:
			oss << bg_blue;
			break;
		case Color::Magenta:
			oss << bg_magenta;
			break;
		case Color::Cyan:
			oss << bg_cyan;
			break;
		case Color::LightGray:
			oss << bg_light_gray;
			break;
		case Color::DarkGray:
			oss << bg_dark_gray;
			break;
		case Color::LightRed:
			oss << bg_light_red;
			break;
		case Color::LightGreen:
			oss << bg_light_green;
			break;
		case Color::LightYellow:
			oss << bg_light_yellow;
			break;
		case Color::LightBlue:
			oss << bg_light_blue;
			break;
		case Color::LightMagenta:
			oss << bg_light_magenta;
			break;
		case Color::LightCyan:
			oss << bg_light_cyan;
			break;
	}
	return oss.str();
}

std::string BashShell::reset() const
{
	return string(fg_def) + string(bg_def);
}
#ifndef SHELL_H
#define SHELL_H

#include "style.h"

#include <string>

class Shell
{
public:
	virtual std::string generate(const Style& style) const = 0;
	virtual std::string reset() const = 0;
};

class BashShell : public Shell
{
public:
	virtual std::string generate(const Style& style) const;
	virtual std::string reset() const;

private:
};

#endif // SHELL_H

#ifndef BASH_SHELL_H
#define BASH_SHELL_H

#include <shell/shell.h>

class BashShell : public Shell
{
public:
	virtual std::string generate(const Style& style) const;
	virtual std::string reset() const;

private:
};

#endif // BASH_SHELL_H

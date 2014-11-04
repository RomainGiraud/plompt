#ifndef TOOLS_H
#define TOOLS_H

#include <string>

class Tools
{
public:
    Tools() = delete;
    Tools(const Tools& src) = delete;

    static std::string exec(const std::string& cmd);
};

#endif // TOOLS_H

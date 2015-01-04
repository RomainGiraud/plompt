#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <sstream>
#include <vector>

class Tools
{
public:
    Tools() = delete;
    Tools(const Tools& src) = delete;

    static std::string exec(const std::string& cmd);

	static std::vector<std::string>& split(const std::string &s, char delim, bool ignore_empty, std::vector<std::string> &elems);
	static std::vector<std::string> split(const std::string &s, char delim, bool ignore_empty);
};

#endif // TOOLS_H

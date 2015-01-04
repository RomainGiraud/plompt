#include <tools.h>

#include <cstdio>

std::string Tools::exec(const std::string& cmd)
{
    FILE* pipe = ::popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    ::pclose(pipe);
    return result;
}

std::vector<std::string>& Tools::split(const std::string &s, char delim, bool ignore_empty, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        if (ignore_empty && item.empty())
            continue;

        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> Tools::split(const std::string &s, char delim, bool ignore_empty)
{
    std::vector<std::string> elems;
    Tools::split(s, delim, ignore_empty, elems);
    return elems;
}

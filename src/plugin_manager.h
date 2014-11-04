#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <map>

#include "plugin.h"

class PluginManager
{
public:
    PluginManager();

    void load(const std::string &plugin);

    Plugin* get(const std::string &classname);

private:
    std::map<std::string, void*> _plugins;
};

#endif // PLUGIN_MANAGER_H

#include "plugin_manager.h"

#include <iostream>

#include <dlfcn.h>

using namespace std;

PluginManager::PluginManager()
{
}

void PluginManager::load(const std::string &plugin)
{
	void *hndl = dlopen(("./lib" + plugin + ".so").c_str(), RTLD_NOW);
	if (hndl == NULL)
	{
		cerr << dlerror() << endl;
		return;
	}

	_plugins[plugin] = hndl;
}

typedef Plugin* (*Constructor)(void);

Plugin* PluginManager::get(const std::string &classname)
{
	void* hndl = _plugins[classname];

	void *mkr = dlsym(hndl, "construct");
	Plugin* plugin = (reinterpret_cast<Constructor>(mkr))();
	return plugin;
}

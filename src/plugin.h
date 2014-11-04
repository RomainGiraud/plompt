#ifndef PLUGIN_H
#define PLUGIN_H

enum class PluginType
{
	Shell,
	Segment,
};

class Plugin
{
public:
    Plugin() {}
    virtual ~Plugin() {}

    virtual int get() = 0;
};

#endif // PLUGIN_H

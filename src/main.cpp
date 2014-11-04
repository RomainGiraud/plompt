#include <iostream>
#include <list>
#include <functional>

#include "prompt.h"
#include "username_segment.h"
#include "currentdir_segment.h"
#include "plugin_manager.h"
#include "config.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "version: " << PLOMPT_VERSION_STRING << endl;

    PluginManager manager;
    manager.load("myplugin");
    Plugin *mp = manager.get("myplugin");
    int x = mp->get();
    cout << "x = " << x << endl;

    Prompt prompt (new BashShell());
    prompt.add(new UserNameSegment(Style(Color::White, Color::Blue)));
    prompt.add(new CurrentDirSegment(Style(Color::White, Color::DarkGray)));

    cout << prompt << flush;

	return 0;
}

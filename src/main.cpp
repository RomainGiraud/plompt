#include <iostream>
#include <list>
#include <functional>

#include <config.h>
#include <prompt/arrow_prompt.h>
#include <prompt/custom_prompt.h>
#include <shell/bash_shell.h>
#include <segment/username_segment.h>
#include <segment/hostname_segment.h>
#include <segment/currentdir_segment.h>
#include <segment/separator_segment.h>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "version: " << PLOMPT_VERSION_STRING << endl;

    try
    {
        /*
        PluginManager manager;
        manager.load("myplugin");
        Plugin *mp = manager.get("myplugin");
        int x = mp->get();
        cout << "x = " << x << endl;
        */

        /*
        Prompt prompt;
        prompt.load("/home/romain/Documents/dev/prompt/plompt/scripts/default.cfg");
        */

        Prompt *prompt = new CustomPrompt(new BashShell());
        prompt->add(new UserNameSegment(Style(Color::Green, Color::Default)));
        prompt->add(new SeparatorSegment(Style(Color::Default, Color::Default), "@"));
        prompt->add(new HostnameSegment(Style(Color::Yellow, Color::Default)));
        prompt->add(new SeparatorSegment(Style(Color::Default, Color::Default), " "));
        prompt->add(new CurrentDirSegment(Style(Color::Red, Color::Default)));
        prompt->add(new SeparatorSegment(Style(Color::Default, Color::Default), "$ "));

        cout << (*prompt) << flush;
    }
    catch (const std::string& error)
    {
        cerr << "[error] " << error << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "[error] Unknown" << endl;
        return 1;
    }

	return 0;
}

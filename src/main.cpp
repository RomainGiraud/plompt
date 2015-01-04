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
#include <segment/text_segment.h>
#include <segment/git_segment.h>
#include <tools.h>
#include <special_characters.h>

#ifdef NDEBUG
#define _ELPP_DISABLE_LOGS
#endif
#define _ELPP_NO_DEFAULT_LOG_FILE
#include <easylogging++.h>
_INITIALIZE_EASYLOGGINGPP

using namespace std;

int main(int argc, char *argv[])
{
#ifndef NDEBUG
    LOG(INFO) << "plompt debug mode";
    LOG(INFO) << "version: " << PLOMPT_VERSION_STRING;
#endif

    try
    {
        Prompt *prompt = new CustomPrompt(new BashShell());
        if (argc == 2)
        {
            if (string(argv[1]) == "0")
                prompt->add(new TextSegment(Style(Color::Green, Color::Black), c_mark));
            else
                prompt->add(new TextSegment(Style(Color::Red, Color::Black), x_mark));

            prompt->add(new TextSegment(Style(Color::Default, Color::Black), " "));
        }
        prompt->add(new CurrentDirSegment(Style(Color::Yellow, Color::Black), 4));
        prompt->add(new GitSegment(Style(Color::Blue, Color::Black)));
        prompt->add(new TextSegment(Style(Color::Black, Color::Default), separator + string(" ")));

        /*
        Prompt *prompt2 = new ArrowPrompt(new BashShell());
        prompt2->add(new CurrentDirSegment(Style(Color::LightGray, Color::Black)));
        prompt2->add(new GitSegment(Style(Color::Green, Color::Black)));
        */

        cout << prompt->toString() << flush;
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

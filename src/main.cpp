#include <iostream>
#include <list>
#include <functional>

#include "prompt.h"
#include "username_segment.h"
#include "currentdir_segment.h"
#include "config.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "version: " << PLOMPT_VERSION_STRING << endl;

    Prompt prompt (new BashShell());
    prompt.add(new UserNameSegment(Style(Color::White, Color::Blue)));
    prompt.add(new CurrentDirSegment(Style(Color::White, Color::DarkGray)));

    cout << prompt << flush;

	return 0;
}

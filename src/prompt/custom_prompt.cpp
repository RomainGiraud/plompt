#include <prompt/custom_prompt.h>

#include <shell/shell.h>
#include <segment/segment.h>

#include <sstream>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

CustomPrompt::CustomPrompt()
    : Prompt(0)
{
}

CustomPrompt::CustomPrompt(Shell* shell)
    : Prompt(shell)
{
}

CustomPrompt::~CustomPrompt()
{
}

void CustomPrompt::print(std::ostream& os) const
{
    Prompt::SegmentList::const_iterator it_curr = _segments.begin();
    Prompt::SegmentList::const_iterator it_next = std::next(it_curr);
    //for (auto segment : _segments)
    for (; it_curr != _segments.end(); ++it_curr, it_next = std::next(it_curr))
    {
        os << _shell->generate((*it_curr)->getStyle());
        os << (**it_curr);

        os << _shell->reset();
    }
}

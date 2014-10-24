#include "username_segment.h"

#include <pwd.h>
#include <unistd.h>

UserNameSegment::UserNameSegment(Style style)
    : Segment(style)
{
}

void UserNameSegment::print(std::ostream& os) const
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw)
    {
        os << pw->pw_name;
    }
    else
    {
        os << "user";
    }
}

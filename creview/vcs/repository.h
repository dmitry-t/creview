#pragma once

#include "creview/vcs/directory.h"

namespace creview {
namespace vcs {

class Repository
{
public:
    virtual Directory rootDirectory();
};

} // namespace vcs
} // namespace creview

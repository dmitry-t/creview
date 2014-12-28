#pragma once

#include "creview/vcs/directory.h"

namespace creview {
namespace vcs {
namespace git {

class GitDirectory : public Directory {
public:
    virtual std::string name() const override;
    virtual std::vector<DirectoryItem*> items() const override;
};

} // namespace git
} // namespace vcs
} // namespace creview

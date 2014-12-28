#pragma once

#include "creview/vcs/text_fragment.h"

namespace creview {
namespace vcs {

class TextDiff {
public:
    TextDiff(TextFragment removed, TextFragment added);

    TextFragment removed() const;
    TextFragment added() const;

private:
    TextFragment removed_;
    TextFragment added_;
};

} // namespace vcs
} // namespace creview

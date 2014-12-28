#pragma once

#include <string>
#include <vector>

namespace creview {
namespace vcs {

class TextFragment {
public:
    typedef std::vector<std::string> Lines;

    TextFragment(Lines lines, uint32_t firstLineNumber, uint32_t lastLineNumber);

    Lines lines() const;
    uint32_t firstLineNumber() const;
    uint32_t lastLineNumber() const;

private:
    Lines lines_;
    uint32_t firstLineNumber_;
    uint32_t lastLineNumber_;
};

} // namespace vcs
} // namespace creview

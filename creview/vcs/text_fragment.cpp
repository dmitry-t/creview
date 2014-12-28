#include "creview/vcs/text_fragment.h"

namespace creview {
namespace vcs {

TextFragment::TextFragment(
        Lines lines,
        uint32_t firstLineNumber,
        uint32_t lastLineNumber) :
    lines_(std::move(lines)),
    firstLineNumber_(firstLineNumber),
    lastLineNumber_(lastLineNumber)
{
}

TextFragment::Lines TextFragment::lines() const
{
    return lines_;
}

uint32_t TextFragment::firstLineNumber() const
{
    return firstLineNumber_;
}

uint32_t TextFragment::lastLineNumber() const
{
    return lastLineNumber_;
}

} // namespace vcs
} // namespace creview

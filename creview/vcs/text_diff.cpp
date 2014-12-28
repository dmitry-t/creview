#include "creview/vcs/text_diff.h"

namespace creview {
namespace vcs {

TextDiff::TextDiff(TextFragment removed, TextFragment added) :
    removed_(removed),
    added_(added)
{
}

TextFragment TextDiff::removed() const
{
    return removed_;
}

TextFragment TextDiff::added() const
{
    return added_;
}

} // namespace vcs
} // namespace creview

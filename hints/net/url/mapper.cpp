#include "hints/net/url/mapper.h"

#include "Poco/URI.h"

#include <algorithm>
#include <stdexcept>

namespace hints {
namespace net {
namespace url {

void Mapper::put(const std::string& url, T value)
{
    Path path(url, value);
    if (find(path))
    {
        throw std::logic_error("Duplicated URL: " + url);
    }
    paths_.push_back(std::move(path));
}

bool Mapper::get(const std::string& url, T& result) const
{
    auto pPath = find(Path(url, 0));
    if (!pPath)
    {
        return false;
    }
    result = pPath->value();
    return true;
}

const Path* Mapper::find(const Path& path) const
{
    auto i = std::find_if(
        paths_.begin(),
        paths_.end(),
        [&path](const Path& other) { return other.matches(path); });
    return i != paths_.end() ? &(*i) : nullptr;
}

} // namespace net
} // namespace hints
} // namespace url

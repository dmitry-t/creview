#include "hints/net/url/mapper.h"

#include "Poco/URI.h"

#include <algorithm>
#include <stdexcept>

namespace hints {
namespace net {
namespace url {

void Mapper::put(const std::string& url, size_t id)
{
    Path path(url, id);
    if (find(path))
    {
        throw std::logic_error("Duplicated URL: " + url);
    }
    paths_.push_back(std::move(path));
}

bool Mapper::get(const std::string& url, Params& params, size_t& id) const
{
    Path concretePath(url, 0);
    auto pPath = find(concretePath);
    if (!pPath)
    {
        return false;
    }
    pPath->extract(concretePath, params, id);
    return true;
}

const Path* Mapper::find(const Path& path) const
{
    auto i = std::find(paths_.begin(), paths_.end(), path);
    return i != paths_.end() ? &(*i) : nullptr;
}

} // namespace net
} // namespace hints
} // namespace url

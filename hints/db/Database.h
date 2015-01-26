#pragma once

#include "ctemplator/Path.h"

#include <fstream>
#include <string>
#include <vector>

namespace hints {
namespace db {

class Database
{
public:
    typedef ctemplator::Path Path;
    typedef std::vector<std::string> Row;

    Database(const Path& path);

    bool fetchRow(Row& row);

private:
    std::fstream stream_;
    size_t columnNumber_;
};

} // namespace db
} // namespace hints

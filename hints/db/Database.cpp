#include "hints/db/Database.h"

namespace hints {
namespace db {

Database::Database(const Path& path) :
    stream_(path.string())
{
}

bool Database::fetchRow(Row& row)
{
    if (!stream_)
    {
        return false;
    }
    row.resize(3);
    row[0] = "1";
    row[1] = "Description";
    row[2] = "...";
    return true;
}

} // namespace db
} // namespace hints

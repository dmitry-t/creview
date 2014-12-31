#include "hints/net/url/mapper.h"

#include "gtest/gtest.h"

namespace hints {
namespace net {
namespace url {
namespace tests {

TEST(net_url_Mapper, getReturnsInsertedLiteralValuesOnly)
{
    Mapper mapper;
    mapper.put("/s1", 1);
    mapper.put("/s2", 2);

    int value;

    ASSERT_EQ(true, mapper.get("/s1", value));
    ASSERT_EQ(1, value);

    ASSERT_EQ(true, mapper.get("/s2", value));
    ASSERT_EQ(2, value);

    ASSERT_EQ(false, mapper.get("/s3", value));
}

TEST(net_url_Mapper, mapperMayHoldTwoPathsWithSameFirstLiteralSegment)
{
    Mapper mapper;
    mapper.put("/s1/s2", 1);
    mapper.put("/s1/s3", 2);

    int value;

    ASSERT_EQ(true, mapper.get("/s1/s2", value));
    ASSERT_EQ(1, value);

    ASSERT_EQ(true, mapper.get("/s1/s3", value));
    ASSERT_EQ(2, value);
}

TEST(net_url_Mapper, mapperMayHoldTwoPathsWithMatchingFirstParamSegment)
{
    Mapper mapper;
    mapper.put("/{p1}/s2", 1);
    mapper.put("/{p1}/s3", 2);

    int value;

    ASSERT_EQ(true, mapper.get("/s1/s2", value));
    ASSERT_EQ(1, value);

    ASSERT_EQ(true, mapper.get("/s1/s3", value));
    ASSERT_EQ(2, value);
}

TEST(net_url_Mapper, putUrlWithDuplicatedLiteralSegmentThrows)
{
    Mapper mapper;
    mapper.put("/s1/s2", 1);
    ASSERT_THROW(mapper.put("/s1/s2", 2), std::logic_error);
}

TEST(net_url_Mapper, putUrlWithDuplicatingParamSegmentThrows)
{
    Mapper mapper;
    mapper.put("/s1/{p1}", 1);
    ASSERT_THROW(mapper.put("/s1/{p2}", 2), std::logic_error);
}

TEST(net_url_Mapper, putUrlWithLiteralMatchingParamSegmentThrows)
{
    Mapper mapper;
    mapper.put("/s1/s2", 1);
    ASSERT_THROW(mapper.put("/s1/{p2}", 2), std::logic_error);
    ASSERT_THROW(mapper.put("/{p1}/s2", 3), std::logic_error);
    ASSERT_THROW(mapper.put("/{p1}/{p2}", 3), std::logic_error);
}

} // namespace tests
} // namespace url
} // namespace net
} // namespace hints

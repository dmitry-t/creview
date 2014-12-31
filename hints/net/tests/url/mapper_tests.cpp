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

    Mapper::Params params;
    size_t id;

    ASSERT_EQ(true, mapper.get("/s1", params, id));
    ASSERT_EQ(Mapper::Params(), params);
    ASSERT_EQ(1, id);

    ASSERT_EQ(true, mapper.get("/s2", params, id));
    ASSERT_EQ(Mapper::Params(), params);
    ASSERT_EQ(2, id);

    ASSERT_EQ(false, mapper.get("/s3", params, id));
}

TEST(net_url_Mapper, getReturnsParamsForParamSegments)
{
    Mapper mapper;
    mapper.put("/{p1}/{p2}", 1);

    Mapper::Params params;
    size_t id;

    ASSERT_EQ(true, mapper.get("/s1/s2", params, id));
    ASSERT_EQ(
        Mapper::Params({
            std::make_pair("p1", "s1"),
            std::make_pair("p2", "s2")
        }),
        params);
    ASSERT_EQ(1, id);

    ASSERT_EQ(true, mapper.get("/s3/s4", params, id));
    ASSERT_EQ(
        Mapper::Params({
            std::make_pair("p1", "s3"),
            std::make_pair("p2", "s4")
        }),
        params);
    ASSERT_EQ(1, id);
}

TEST(net_url_Mapper, mapperMayHoldTwoPathsWithSameFirstLiteralSegment)
{
    Mapper mapper;
    mapper.put("/s1/s2", 1);
    mapper.put("/s1/s3", 2);

    Mapper::Params params;
    size_t id;

    ASSERT_EQ(true, mapper.get("/s1/s2", params, id));
    ASSERT_EQ(Mapper::Params(), params);
    ASSERT_EQ(1, id);

    ASSERT_EQ(true, mapper.get("/s1/s3", params, id));
    ASSERT_EQ(Mapper::Params(), params);
    ASSERT_EQ(2, id);
}

TEST(net_url_Mapper, mapperMayHoldTwoPathsWithMatchingFirstParamSegment)
{
    Mapper mapper;
    mapper.put("/{p1}/s2", 1);
    mapper.put("/{p1}/s3", 2);

    Mapper::Params params;
    size_t id;

    ASSERT_EQ(true, mapper.get("/s1/s2", params, id));
    ASSERT_EQ(Mapper::Params({std::make_pair("p1", "s1")}), params);
    ASSERT_EQ(1, id);

    ASSERT_EQ(true, mapper.get("/s1/s3", params, id));
    ASSERT_EQ(Mapper::Params({std::make_pair("p1", "s1")}), params);
    ASSERT_EQ(2, id);
}

TEST(net_url_Mapper, returnNothingForPartialPathMatch)
{
    Mapper mapper;
    mapper.put("/s1/{p1}", 1);

    Mapper::Params params;
    size_t id;

    ASSERT_EQ(false, mapper.get("/s1", params, id));

    ASSERT_EQ(false, mapper.get("/s1/s2/s3", params, id));
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

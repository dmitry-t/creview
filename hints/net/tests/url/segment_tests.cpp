#include "hints/net/url/segment.h"

#include <gtest/gtest.h>

namespace hints {
namespace net {
namespace url {
namespace tests {

TEST(net_url_Segment, literalSegmentIsNotParamAndReturnsOriginalValue)
{
    Segment segment("literal");
    ASSERT_EQ(false, segment.isParam());
    ASSERT_EQ("literal", segment.value());
}

TEST(net_url_Segment, paramSegmentIsParamAndReturnsParameterName)
{
    Segment segment("{param}");
    ASSERT_EQ(true, segment.isParam());
    ASSERT_EQ("param", segment.value());
}

TEST(net_url_Segment, invalidParamSegmentThrowsFromCtor)
{
    ASSERT_THROW(Segment("{badParam"), std::logic_error);
}

TEST(net_url_Segment, paramSegmentEqualsToParamSegment)
{
    ASSERT_EQ(true, Segment("{p1}") == Segment("{p2}"));
}

TEST(net_url_Segment, paramSegmentEqualsToLiteralSegmentBecauseMatchesIt)
{
    ASSERT_EQ(true, Segment("{p1}") == Segment("s1"));
    ASSERT_EQ(true, Segment("s1") == Segment("{p1}"));
}

TEST(net_url_Segment, literalSegmentEqualsToLiteralSegmentIfHasSameValue)
{
    ASSERT_EQ(true, Segment("s1") == Segment("s1"));
    ASSERT_EQ(false, Segment("s1") == Segment("s2"));
}

} // namespace tests
} // namespace url
} // namespace net
} // namespace hints


#include <string>
#include <ostream>

#include "gtest/gtest.h"

#include "container/tuple.h"

using namespace mpl::container;

namespace
{
struct A
{
    A() = default;
    A(int x) : x_(x) {}
    A(const A&) = default;
    A(A&&) = default;
    A& operator=(const A&) = default;
    A& operator=(A&&) = default;

    int x_{};
};

std::ostream& operator<<(std::ostream& os, const A& a)
{
    return os << "A(" << a.x_ << ")";
}

bool operator==(const A& lhs, const A& rhs) { return lhs.x_ == rhs.x_; }
bool operator!=(const A& lhs, const A& rhs) { return lhs.x_ != rhs.x_; }
bool operator<(const A& lhs, const A& rhs) { return lhs.x_ < rhs.x_; }
bool operator<=(const A& lhs, const A& rhs) { return lhs.x_ <= rhs.x_; }
bool operator>(const A& lhs, const A& rhs) { return lhs.x_ > rhs.x_; }
bool operator>=(const A& lhs, const A& rhs) { return lhs.x_ >= rhs.x_; }
} // namespace

TEST(Tuple, Tuple0)
{
    Tuple<> tpl;
}

TEST(Tuple, Tuple4)
{
    {
        Tuple<int, double, std::string, A> tpl;
        ASSERT_EQ(getTuple<0>(tpl), 0);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl), 0.0);
        ASSERT_EQ(getTuple<2>(tpl), std::string(""));
        ASSERT_EQ(getTuple<3>(tpl), A());
    }
    {
        Tuple<int, double, std::string, A> tpl(1, 2.0, std::string("abc"), A(3));
        ASSERT_EQ(getTuple<0>(tpl), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl), 2.0);
        ASSERT_EQ(getTuple<2>(tpl), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl), A(3));
    }
    {
        Tuple<int, double, std::string, A> tpl(1.0, 2, "abc", 3);
        ASSERT_EQ(getTuple<0>(tpl), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl), 2.0);
        ASSERT_EQ(getTuple<2>(tpl), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl), A(3));
    }
    {
        Tuple<int, double, std::string, A> tpl(1, 2.0, "abc", 3);
        Tuple<int, double, std::string, A> tpl2(tpl);
        ASSERT_EQ(getTuple<0>(tpl2), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl2), 2.0);
        ASSERT_EQ(getTuple<2>(tpl2), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl2), A(3));
    }
    {
        Tuple<int, double, std::string, A> tpl2(Tuple<int, double, std::string, A>(1, 2.0, "abc", 3));
        ASSERT_EQ(getTuple<0>(tpl2), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl2), 2.0);
        ASSERT_EQ(getTuple<2>(tpl2), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl2), A(3));
    }
    {
        Tuple<int, double, std::string, A> tpl(1, 2.0, "abc", 3);
        Tuple<int, double, std::string, A> tpl2;
        tpl2 = tpl;
        ASSERT_EQ(getTuple<0>(tpl2), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl2), 2.0);
        ASSERT_EQ(getTuple<2>(tpl2), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl2), A(3));
    }
    {
        Tuple<int, double, std::string, A> tpl2;
        tpl2 = Tuple<int, double, std::string, A>(1, 2.0, "abc", 3);
        ASSERT_EQ(getTuple<0>(tpl2), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl2), 2.0);
        ASSERT_EQ(getTuple<2>(tpl2), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl2), A(3));
    }
    {
        const auto tpl = makeTuple<int, double, std::string, A>(1, 2.0, "abc", 3);
        ASSERT_EQ(getTuple<0>(tpl), 1);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl), 2.0);
        ASSERT_EQ(getTuple<2>(tpl), std::string("abc"));
        ASSERT_EQ(getTuple<3>(tpl), A(3));
    }
    {
        Tuple<int, double, std::string, A> tpl(1, 2.0, std::string("abc"), A(3));

        getTuple<0>(tpl) = 10;
        getTuple<1>(tpl) = 2.5;
        getTuple<2>(tpl) = "xyz";
        getTuple<3>(tpl) = 5;

        ASSERT_EQ(getTuple<0>(tpl), 10);
        ASSERT_DOUBLE_EQ(getTuple<1>(tpl), 2.5);
        ASSERT_EQ(getTuple<2>(tpl), std::string("xyz"));
        ASSERT_EQ(getTuple<3>(tpl), A(5));
    }
}
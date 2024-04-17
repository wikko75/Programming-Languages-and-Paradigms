#include "Galois.hpp"
#include <gtest/gtest.h>


class GaloisUnderTest : public testing::Test
{
public:
    void SetUp() override
    {
        a = 15;
        b = 1234576;
    }

protected:
    Galois<1234577> a;
    Galois<1234577> b;
};


TEST_F(GaloisUnderTest, AdditionTest)
{
    constexpr int64_t expected {14};
    int64_t result = (a + b).value();
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, AdditionWithLHSConstant)
{
    constexpr int64_t expected {0}; 
    int64_t result {(1234578 + b).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, AdditionWithRHSConstant)
{
    constexpr int64_t expected = 19;
    int64_t result = (a + 4).value();
    ASSERT_EQ(result, expected);
}


TEST_F(GaloisUnderTest, SubstractionTest)
{
    constexpr int64_t expected {16};
    int64_t result {(a - b).value()};
    ASSERT_EQ(result, expected);
}


TEST_F(GaloisUnderTest, SubstractionWithRHSConstant)
{
    constexpr int64_t expected {1234572};
    int64_t result {(b - 4).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, SubstractionWithLHSConstant)
{
    constexpr int64_t expected {5};
    int64_t result {(4 - b).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, MultiplicationTest)
{
    constexpr int64_t expected {1234562};
    int64_t result {(a * b).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, MultiplicationWithLHSConstant)
{
    constexpr int64_t expected {1234576};
    int64_t result {(1234578 * b).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, MultiplicationWithRHSConstant)
{
    constexpr int64_t expected {60};
    int64_t result {(a * 4).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, GaloisInverse)
{
    constexpr int64_t expected {576136};
    int64_t result {(~a).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, DivisionTest)
{
    constexpr int64_t expected {1234562};
    int64_t result {(a / b).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, DivisionWithLHSConstant)
{
    constexpr int64_t expected {1234567};
    int64_t result {(10 / b).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, DivisionWithRHSConstant)
{
    constexpr int64_t expected {617290};
    int64_t result {(a / 10).value()};
    ASSERT_EQ(result, expected);
}

TEST_F(GaloisUnderTest, EqualityOperatorTest)
{
    ASSERT_NE(a, b);
    ASSERT_EQ(15, a);
}

TEST_F(GaloisUnderTest, LEOperatorTest)
{
    ASSERT_FALSE(-20 <=a);
}

TEST_F(GaloisUnderTest, GEOperatorTest)
{
    ASSERT_GE(a, 5);
}

TEST_F(GaloisUnderTest, StreamOutputOperatorTest) 
{
    std::ostringstream oss {};
    oss << a;

    std::string expected_output {"15"};
    ASSERT_EQ(oss.str(), expected_output);
}


TEST_F(GaloisUnderTest, StreamInputOperatorTest) 
{
    std::string input_data {"10"};

    std::istringstream iss {input_data};

    iss >> b;

    constexpr int64_t expected {10};
    ASSERT_EQ(b.value(), expected);
}
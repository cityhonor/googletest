#include <gtest/gtest.h>
//被测函数

int32_t test_array[1000] = {0};
void GenerateEscapeData(void)
{
    for(int32_t i = 0; i < sizeof(test_array) / sizeof(test_array[0]); i++)
    {
        test_array[i] = i;
    }
}
 
bool IsPrime(int n) 
{
    // Trivial case 1: small numbers
    if (n <= 1) 
    {
        return false;
    }

    // Trivial case 2: even numbers
    if (n % 2 == 0) 
    {
        return n == 2;
    }

    // Now, we have that n is odd and n >= 3.

    // Try to divide n by every odd number i, starting from 3
    for (int i = 3; ; i += 2) 
    {
        // We only have to try i up to the squre root of n
        if (i > n / i) 
        {
            break;
        }

        // Now, we have i <= n/i < n.
        // If n is divisible by i, n is not prime.
        if (n % i == 0) 
        {
            return false;
        }
    }
 
    // n has no integer factor in the range (1, n), and thus is prime.
    return true;
}


//第一步
class FooTest : public ::testing::TestWithParam<int> 
{
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
    //在这里面可以实现fixture类的所有成员
 
};

class FooTest_1 : public ::testing::TestWithParam<int> 
{
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
    //在这里面可以实现fixture类的所有成员
 
};

//第二步
TEST_P(FooTest, DoesBlah) 
{
    // Inside a test, access the test parameter with the GetParam() method
    // of the TestWithParam<T> class:
    //在测试中，使用TestWithParam <T>类的GetParam（）方法访问测试参数：
    int n = GetParam();
    EXPECT_TRUE(IsPrime(n));
    //...
}

//第二步
TEST_P(FooTest_1, ValuesInTest) 
{
    // Inside a test, access the test parameter with the GetParam() method
    // of the TestWithParam<T> class:
    //在测试中，使用TestWithParam <T>类的GetParam（）方法访问测试参数：

    int n = GetParam();
    EXPECT_TRUE(IsPrime(n));
    //...
}
 
//第三步
//第一个参数是前缀；第二个是类名；第三个是参数生成器
// INSTANTIATE_TEST_CASE_P(MyPrimeParamTestValues, FooTest, ::testing::Values(-5, 0, 4, 3, 5, 11));
INSTANTIATE_TEST_CASE_P(MyPrimeParamTestRange, FooTest, ::testing::Range(0, 100, 1));
// INSTANTIATE_TEST_CASE_P(MyPrimeParamTestValuesIn, FooTest_1, ::testing::ValuesIn(test_array));
 
int main(int argc, char** argv)
{
    GenerateEscapeData();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
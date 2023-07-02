#include <limits.h>
#include "sample2.hpp"
#include "gtest/gtest.h"


class queue_test : public ::testing::Test 
{
    protected:
    virtual void SetUp() 
    {
        q1_.enqueue(1);
        q2_.enqueue(2);
        q2_.enqueue(3);
    }
    
    // virtual void TearDown() {}
    
    queue<int> q0_;
    queue<int> q1_;
    queue<int> q2_;
};

TEST_F(queue_test, is_empty)
{
    int32_t status = 0;
    int32_t head = 0;
    int32_t tail = 0;
    status = q0_.is_empty();
    EXPECT_EQ(status, 0);
    head = q0_.get_head();
    tail = q0_.get_tail();
    printf("head = %d, tail = %d\n", head, tail);
}

TEST_F(queue_test, dequeue) 
{
    int e = 0;
    int32_t n = 0;
    int32_t tail = 0;
    int32_t head = 0;
    n = q0_.dequeue(e);
    EXPECT_EQ(0, n);
    head = q0_.get_head();
    tail = q0_.get_tail();
    printf("head = %d, tail = %d\n", head, tail);
    
    n = q1_.dequeue(e);
    EXPECT_TRUE(n == 0);
    EXPECT_EQ(1, e);
    EXPECT_EQ(0, q1_.get_capacity());
    head = q1_.get_head();
    tail = q1_.get_tail();
    printf("head = %d, tail = %d\n", head, tail);
    
    n = q2_.dequeue(e);
    ASSERT_TRUE(n != 0);
    EXPECT_EQ(2, e);
    EXPECT_EQ(1, q2_.get_capacity());
    head = q2_.get_head();
    tail = q2_.get_tail();
    printf("head = %d, tail = %d\n", head, tail);
}


int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
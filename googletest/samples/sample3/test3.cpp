#include "sample3.hpp"
#include "gtest/gtest.h"
#include <stdint.h>

#if TEST_NOT_TEMPLATE
class queue_test : public ::testing::Test 
{
protected:
    void SetUp() override
    {
        std::cout << "SetUp runing " << std::endl;
        q1_.enqueue(1);
        q2_.enqueue(2);
        q2_.enqueue(3);
    }

    void TearDown() override
    {
        std::cout << "TearDown runing " << std::endl;
        int32_t e;
        q1_.dequeue(&e);
        q2_.dequeue(&e);
        q2_.dequeue(&e);
        std::cout << "q0_.capacity = " << q0_.get_capacity() << std::endl;
        std::cout << "q1_.capacity = " << q1_.get_capacity() << std::endl;
        std::cout << "q2_.capacity = " << q2_.get_capacity() << std::endl;
    }
    
    queue_t q0_;
    queue_t q1_;
    queue_t q2_;
};

TEST_F(queue_test, enqueue)
{
    int32_t e = 1;
    int32_t status = 0;
    int32_t head = 0;
    int32_t tail = 0;
    uint32_t capacity = 0u;
    capacity = q0_.get_capacity();
    EXPECT_EQ(capacity, 0u);
    status = q0_.enqueue(e);
    EXPECT_EQ(status, 0);
    status = q0_.enqueue(e + 1);
    status = q0_.enqueue(e + 2);
    (void)q0_.queue_traversal();
    capacity = q0_.get_capacity();
    EXPECT_NE(capacity, 0u);
}

TEST_F(queue_test, dequeue) 
{
    int32_t e = 0;
    int32_t n = 0;
    int32_t tail = 0;
    int32_t head = 0;
    uint32_t capacity = 0u;
    capacity = q0_.get_capacity();
    EXPECT_EQ(capacity, 0u);
    n = q0_.dequeue(&e);
    EXPECT_FALSE(n == 0);
    capacity = q0_.get_capacity();
    EXPECT_EQ(capacity, 0u);
    
    capacity = q1_.get_capacity();
    EXPECT_NE(capacity, 0u);
    (void)q1_.queue_traversal();
    n = q1_.dequeue(&e);
    EXPECT_TRUE(n == 0);
    EXPECT_EQ(1, e);
    capacity = q1_.get_capacity();
    EXPECT_EQ(capacity, 0u);
    
    capacity = q2_.get_capacity();
    EXPECT_NE(capacity, 0u);
    n = q2_.dequeue(&e);
    ASSERT_TRUE(n == 0);
    EXPECT_EQ(2, e);
    capacity = q2_.get_capacity();
    EXPECT_NE(capacity, 0u);
}

#else

class queue_test : public ::testing::Test 
{
    protected:
    void SetUp() override
    {
        q1_.enqueue(1);
        q2_.enqueue(2);
        q2_.enqueue(3);
    }
    
    queue_t<int32_t> q0_;
    queue_t<int32_t> q1_;
    queue_t<int32_t> q2_;
};

TEST_F(queue_test, is_empty_initially) 
{
    EXPECT_EQ(q0_.size(), 0);
    q0_.enqueue(1);
    EXPECT_NE(q0_.size(), 0);
}

TEST_F(queue_test, dequeue_works) 
{
    int* n = q0_.dequeue();
    EXPECT_EQ(n, nullptr);

    n = q1_.dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(q1_.size(), 0);
    delete n;

    n = q2_.dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 2);
    EXPECT_EQ(q2_.size(), 1);
    n = q2_.dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_TRUE(*n == 3);
    delete n;
}

#endif


int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>

#include "queue.hpp"

class QueueTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        q1_.Enqueue(1);
        q2_.Enqueue(2);
        q2_.Enqueue(3);
    }

    Queue<int> q0_, q1_, q2_;
};

TEST_F(QueueTest, IsEmptyInitially) 
{
    EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) 
{
    int* n = q0_.Dequeue();
    EXPECT_EQ(n, nullptr);

    n = q1_.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 1);
    EXPECT_EQ(q1_.size(), 0);
    delete n;

    n = q2_.Dequeue();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(*n, 2);
    EXPECT_EQ(q2_.size(), 1);
    delete n;
}
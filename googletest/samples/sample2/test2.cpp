#include <iostream>
#include <cstdlib>
#include <time.h> 
#include <limits.h>
#include "sample2.hpp"
#include "gtest/gtest.h"

#if 0
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

#endif

class ring_queue_test : public ::testing::Test 
{
    protected:
    virtual void SetUp() 
    {
        int32_t data = 0;
        uint32_t i = 0u;
        for(i = 0; i < 10000; i++)
        {
            srand(time(NULL));
            array[i] = rand();
        } 
    }
    
    // virtual void TearDown() {}
    int32_t array[10000];
    queue<int32_t> q0;
};


TEST_F(ring_queue_test, ring_queue) 
{
    int32_t status = 0;
    uint32_t i = 0u;
    /* 队列元素个数 */
    uint32_t queue_ele_num = 0u;
    for(i = 0u; i < sizeof(array) / sizeof(array[0]); i++)
    {
        if(array[i] % 2 == 0)
        {
            status = q0.enqueue(array[i]);
            if(status == 0)
            {
                queue_ele_num++;
            }
            else
            {
                ASSERT_LT(QUEUE_CAPACITY_MAX, queue_ele_num);
            }
        }
        else
        {
            status = q0.dequeue(array[i]);
            if(status == 0)
            {
                queue_ele_num--;
            }
            else
            {
                ASSERT_EQ(queue_ele_num, 0u);
            }
        }
    }
}



int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
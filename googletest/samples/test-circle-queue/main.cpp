#include <gtest/gtest.h>
#include "circle_queue.h"
#include <stdint.h>
#include <iostream>
#include <time.h> 


TEST(circle_queue_test, is_empty)
{
    circle_queue q;
    std::cout << "circle_queue_test is_empty running" << std::endl;
    ASSERT_EQ(q.is_empty(), 0);
}


TEST(circle_queue_test, enqueue)
{
    circle_queue q;
    uint32_t i = 0u;
    int32_t status = 0;
    uint32_t ele_num = q.get_capacity();

    for(i = 0u; i < ele_num - 1u; i++)
    {
        status = q.enqueue(i);
        ASSERT_EQ(status, 0);
    }
    ASSERT_EQ(q.is_full(), 0);
    for(i = 0u; i < 100000u; i++)
    {
        status = q.enqueue(i);
        ASSERT_EQ(status, -1);
    }
}


TEST(circle_queue_test, dequeue)
{
    circle_queue q;
    uint32_t i = 0u;
    int32_t status = 0;
    uint32_t ref = 0u;
    uint32_t ele_num = q.get_capacity();

    status = q.dequeue(nullptr);
    ASSERT_EQ(status, -1);
    status = q.dequeue(&ref);
    ASSERT_EQ(status, -2);

    for(i = 0u; i < ele_num - 1u; i++)
    {
        status = q.enqueue(i);
        ASSERT_EQ(status, 0);
    }

    for(i = 0u; i < ele_num - 1u; i++)
    {
        status = q.dequeue(&ref);
        ASSERT_EQ(status, 0);
        ASSERT_EQ(ref, i);
    }
}


TEST(circle_queue_test, all)
{
    circle_queue q;
    uint32_t i = 0u;
    int32_t status = 0;
    int32_t ref = 0u;
    uint32_t ele_num = 0u;
    uint32_t data = 0u;
    uint32_t total_ele = 0u;
    uint32_t capacity = q.get_capacity() - 1u;

    for(i = 0u; i < 0xfffffu; i++)
    {
        srand(time(NULL));
        ref = rand();
        ref = ref % 2;
        if(ref == 0)
        {
            status = q.enqueue(0u);
            ele_num = q.get_queue_ele_num();
            if(status == 0)
            {
                total_ele++;
                ASSERT_EQ(ele_num, total_ele);
            }
            else
            {
                ASSERT_EQ(status, -1);
                ASSERT_EQ(ele_num, capacity);
            }
        }
        else
        {
            status = q.dequeue(&data);
            ele_num = q.get_queue_ele_num();
            if(status == 0)
            {
                total_ele--;
                ASSERT_EQ(ele_num, total_ele);
            }
            else
            {
                ASSERT_EQ(status, -2);
                ASSERT_EQ(ele_num, 0);
            }
        }
    }
}



int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

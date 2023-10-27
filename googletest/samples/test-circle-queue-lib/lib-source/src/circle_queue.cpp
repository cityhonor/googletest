#include "circle_queue.h"


circle_queue::circle_queue(void)
{
    this->capacity = M_CIRCLE_QUEUE_CAPACITY + 1u;
    this->head = 0u;
    this->tail = 0u;
    this->ele_num = 0u;
}


circle_queue::~circle_queue(void)
{
    this->capacity = 0u;
    this->head = 0u;
    this->tail = 0u;
    this->ele_num = 0u;
}


int32_t circle_queue::is_empty(void)
{
    int32_t status = 0;
    if(this->head == this->tail)
    {
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}


int32_t circle_queue::is_full(void)
{
    int32_t status = 0;
    if(this->head == (this->tail + 1u) % this->capacity)
    {
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}


int32_t circle_queue::enqueue(uint32_t ref)
{
    int32_t status = 0;
    status = this->is_full();
    /* 满队列 */
    if(status == 0)
    {
        status = -1;
    }
    else
    {
        this->queue[this->tail] = ref;
        this->tail = (this->tail + 1u) % this->capacity;
        this->ele_num++;
        status = 0;
    }
    return status;
}


int32_t circle_queue::dequeue(uint32_t *ref)
{
    int32_t status = 0;
    status = this->is_empty();
    /* 非法指针 */
    if(ref == nullptr)
    {
        status = -1;
    }
    /* 空队列 */
    else if(status == 0)
    {
        status = -2;
    }
    else
    {
        *ref = this->queue[this->head];
        this->head = (this->head + 1u) % this->capacity;
        this->ele_num--;
        status = 0;
    }
    return status;
}


uint32_t circle_queue::get_queue_ele_num(void)
{
    return this->ele_num;
}


uint32_t circle_queue::get_capacity(void)
{
    return this->capacity;
}
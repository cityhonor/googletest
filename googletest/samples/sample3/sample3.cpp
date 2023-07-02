#include "sample3.hpp"
#if TEST_NOT_TEMPLATE

#include <iostream>


int32_t queue_t::is_empty() const
{
    int32_t status = 0;
    if(this->capacity != 0u)
    {
        status = -1;
    }
    return status;
}


int32_t queue_t::enqueue(const int32_t e)
{
    int32_t status = 0;
    pair_t *p = new pair_t;
    if(p == nullptr)
    {
        status = -1;
        printf("e is nullptr\n");
    }
    else
    {
        p->key = e;
        p->next = nullptr;
        if(this->is_empty() != 0)
        {
            this->tail->next = p;
            this->tail = p;
        }
        else
        {
            this->head = p;
            this->tail = p;
        }
        this->capacity++;
    }
    return status;
}


int32_t queue_t::dequeue(int32_t *e)
{
    int32_t status = 0;
    pair_t *p = nullptr;
    if(e == nullptr)
    {
        status = -1;
    }
    else
    {
        status = this->is_empty();
        if(status == 0)
        {
            status = -1;
        }
        else
        {
            *e = this->head->key;
            p = this->head;
            this->head = this->head->next;
            this->capacity--;
            delete p;
            status = 0;
        }
    }
    return status;
}


uint32_t queue_t::get_capacity() const
{
    return this->capacity;
}


int32_t queue_t::queue_traversal() const
{
    pair_t *p = this->head;
    uint32_t i = 0u;
    uint32_t capacity = this->capacity;
    for(i = 0u; i < capacity; i++)
    {
        std::cout << p->key << std::endl;
        p = p->next;
    }
    return 0;
}

#endif

#ifndef __GOOGLE_TEST_SAMPLE_2_H__
#define __GOOGLE_TEST_SAMPLE_2_H__
#include <stdint.h>

#define QUEUE_CAPACITY_MAX (100u)

template <class E>
class queue 
{
public:
    queue();
    int32_t enqueue(const E& element);
    int32_t dequeue(E& element);
    int32_t is_full() const;
    int32_t is_empty() const;
    uint32_t get_capacity() const;
    uint32_t get_head() const;
    uint32_t get_tail() const;
    
private:
    uint32_t capacity;
    uint32_t head;
    uint32_t tail;
    E queues[QUEUE_CAPACITY_MAX + 1u];
};

template <class E>
uint32_t queue<E>::get_capacity() const
{
    return this->capacity;
}

template <class E>
int32_t queue<E>::is_empty() const
{
    int32_t status = 0;
    if(this->tail % this->capacity == this->head % this->capacity)
    {
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

template <class E>
int32_t queue<E>::is_full() const
{
    int32_t status = 0;
    if((this->tail + 1u) % this->capacity == this->head % this->capacity)
    {
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

template <class E>
uint32_t queue<E>::get_head() const
{
    return this->head;
}

template <class E>
uint32_t queue<E>::get_tail() const
{
    return this->tail;
}

template <class E>
queue<E>::queue()
{
    this->head = 0u;
    this->tail = 0u;
    this->capacity = QUEUE_CAPACITY_MAX + 1u;
}


template <class E>
int32_t queue<E>::enqueue(const E& element)
{
    int32_t status = 0;
    status = this->is_full();
    if(status != 0)
    {
        this->queues[this->tail] = element;
        this->tail = (this->tail++) % this->capacity;
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

template <class E>
int32_t queue<E>::dequeue(E& element)
{
    int32_t status = 0;
    status = this->is_empty();
    if(status != 0)
    {
        element = this->queues[this->head];
        this->head = (this->head++) % this->capacity;
        status = 0;
    }
    else
    {
        status = -1;
    }
    return status;
}

#endif
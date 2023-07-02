#ifndef __GOOGLE_TEST_SAMPLE3_HPP__
#define __GOOGLE_TEST_SAMPLE3_HPP__

#define TEST_NOT_TEMPLATE (1)

#if TEST_NOT_TEMPLATE

#include <stdint.h>

class pair_t
{
public:
    int32_t key;
    pair_t *next;
    pair_t():key(0), next(nullptr) {}
};


class queue_t
{

public:
    int32_t enqueue(const int32_t e);
    int32_t dequeue(int32_t *e);
    uint32_t get_capacity() const;
    int32_t queue_traversal() const;

    queue_t()
    {
        this->capacity = 0u;
        this->head = nullptr;
        this->tail = nullptr;
    }

    // ~queue_t() 
    // {
    //     pair_t *p = this->head;
    //     while(1)
    //     {
    //         if(this->is_empty() != 0)
    //         {
    //             this->head = this->head->next;
    //             delete p;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    // };

private:
    pair_t *head;
    pair_t *tail;
    uint32_t capacity;
    int32_t is_empty() const;
};

#else




#include <cstddef>
#include <deque>

template<class E>
class queue_t 
{
public:
    ~queue_t();
    void enqueue(const E& element);
    E* dequeue();
    size_t size() const;
private:
    std::deque<E*> q_;
};

template<class E>
queue_t<E>::~queue_t() 
{
    while (!q_.empty()) 
    {
        delete q_.front();
        q_.pop_front();
    }
}

template<class E>
void queue_t<E>::enqueue(const E& element) 
{
    q_.push_back(new E(element));
}

template<class E>
E* queue_t<E>::dequeue() 
{
    if (q_.empty())
        return nullptr;
    E* e = q_.front();
    q_.pop_front();
    return e;
}

template<class E>
size_t queue_t<E>::size() const 
{
    return q_.size();
}

#endif


#endif
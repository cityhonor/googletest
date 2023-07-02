#pragma once

#include <cstddef>
#include <deque>

template<class E>
class Queue 
{
public:
    ~Queue();
    void Enqueue(const E& element);
    E* Dequeue();
    size_t size() const;
private:
    std::deque<E*> q_;
};

template<class E>
Queue<E>::~Queue() 
{
    while (!q_.empty()) 
    {
        delete q_.front();
        q_.pop_front();
    }
}

template<class E>
void Queue<E>::Enqueue(const E& element) 
{
    q_.push_back(new E(element));
}

template<class E>
E* Queue<E>::Dequeue() 
{
    if (q_.empty())
        return nullptr;
    E* e = q_.front();
    q_.pop_front();
    return e;
}

template<class E>
size_t Queue<E>::size() const 
{
    return q_.size();
}

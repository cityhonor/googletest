#ifndef __CIRCLE_QUEUE_H__
#define __CIRCLE_QUEUE_H__

#include <stdint.h>
// #include "lib-source/lib-sub-source/include/lib_sub_source.h"
#include "lib_sub_source.h"

#define M_CIRCLE_QUEUE_CAPACITY (1024u)

class circle_queue
{
    public:
    circle_queue(void);
    ~circle_queue(void);
    int32_t is_empty(void);
    int32_t is_full(void);
    int32_t enqueue(uint32_t ref);
    int32_t dequeue(uint32_t *ref);
    uint32_t get_queue_ele_num(void);
    uint32_t get_capacity(void);
    lib_source_queue lib_queue;

    private:
    uint32_t capacity;
    uint32_t head;
    uint32_t tail;
    uint32_t ele_num;
    uint32_t queue[M_CIRCLE_QUEUE_CAPACITY + 1u];
};

#endif
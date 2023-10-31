#include "wrapper_circle_queue.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int32_t status = 0;
    uint32_t capacity = 0u;
    void *circle_queue = wrapper_circle_queue_create();
    if(circle_queue == NULL)
    {
        status = -1;
    }
    else
    {
        (void)wrapper_get_capacity(circle_queue, &capacity);
        printf("capacity = %u\n", capacity);
    }
    return status;
}
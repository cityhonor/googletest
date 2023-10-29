#include "lib_sub_source.h"


lib_source_queue::lib_source_queue(void)
{
    this->data = 0u;
}


lib_source_queue::~lib_source_queue(void)
{
    this->data = 0u;
}


int32_t lib_source_queue::get_data(uint32_t *data)
{
    int32_t status = 0;
    if(data == nullptr)
    {
        status = -1;
    }
    else
    {
        *data = this->data;
    }
    return status;
}
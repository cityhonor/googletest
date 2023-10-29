#ifndef __LIB_SUB_SOURCE_H__
#define __LIB_SUB_SOURCE_H__

#include <stdint.h>

class lib_source_queue
{
    public:
    lib_source_queue(void);
    ~lib_source_queue(void);
    int32_t get_data(uint32_t *data);

    private:
    uint32_t data;
};


#endif
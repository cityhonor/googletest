#ifndef __WRAPPER_CIRCLE_QUEUE_H__
#define __WRAPPER_CIRCLE_QUEUE_H__


#include <stdint.h>  

#define C_CALL_CPP_API

#ifdef __cplusplus
extern "C" {
#endif


C_CALL_CPP_API void *wrapper_circle_queue_create(void);

C_CALL_CPP_API void wrapper_circle_queue_delete(void *ref);

C_CALL_CPP_API int32_t wrapper_get_capacity(void *ref, uint32_t *capacity);




#ifdef __cplusplus
}
#endif


#endif
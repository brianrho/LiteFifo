#include <string.h>
#include "lite_fifo.h"

/* Initialize a generic FIFO with an array of any data type,
 * the number of elements in the array, and the size in bytes of each element
 */
LiteFifo::LiteFifo(void * obj_array, uint16_t array_sz, uint8_t _obj_sz) : 
    head(0), tail(0), byte_count(0), bufptr((uint8_t *)obj_array), 
    buffer_sz(array_sz * _obj_sz), obj_sz(_obj_sz)
{
    
}

bool LiteFifo::dequeue(void * obj) {
    if (byte_count == 0)
        return false;
    
    uint8_t * ptr = (uint8_t *)obj;
    memcpy(ptr, &bufptr[tail], obj_sz);
    tail += obj_sz;
    if (tail == buffer_sz)
        tail = 0;
    byte_count -= obj_sz;
    return true;
}

bool LiteFifo::enqueue(void * obj) {
    if (byte_count == buffer_sz)
        return false;
    
    uint8_t * ptr = (uint8_t *)obj;
    memcpy(&bufptr[head], ptr, obj_sz);
    head += obj_sz;
    if (head == buffer_sz)
        head = 0;
    byte_count += obj_sz;
    return true;
}

uint16_t LiteFifo::available(void) {
    return byte_count / obj_sz;
}

bool LiteFifo::full(void) {
    return (byte_count == buffer_sz);
}

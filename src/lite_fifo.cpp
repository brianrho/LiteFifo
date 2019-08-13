#include <string.h>
#include "lite_fifo.h"
#include <Arduino.h>

/* Initialize a generic FIFO with an array of any data type,
 * the number of elements in the array, and the size in bytes of each element
 */
LiteFifo::LiteFifo(void * elements, uint16_t max_elems, uint8_t elem_sz) : 
    head(0), tail(0), elem_count(0), elements((uint8_t *)elements), 
    buffer_sz(max_elems * elem_sz), elem_sz(elem_sz), max_elems(max_elems)
{

}

bool LiteFifo::dequeue(void * elem) {
    if (elem_count == 0)
        return false;
    
    uint8_t * ptr = (uint8_t *)elem;
    memcpy(ptr, &elements[tail], elem_sz);
    tail += elem_sz;
    if (tail == buffer_sz)
        tail = 0;
        
    elem_count--; 
    return true;
}

bool LiteFifo::enqueue(void * elem) {
    if (elem_count == max_elems)
        return false;
    
    uint8_t * ptr = (uint8_t *)elem;
    memcpy(&elements[head], ptr, elem_sz);
    head += elem_sz;
    if (head == buffer_sz)
        head = 0;
        
    elem_count++;
    return true;
}

bool LiteFifo::peek(void * elem) {
    if (elem_count == 0)
        return false;
    
    uint8_t * ptr = (uint8_t *)elem;
    memcpy(ptr, &elements[tail], elem_sz);
    return true;
}

uint16_t LiteFifo::available(void) {
    return elem_count;
}

bool LiteFifo::full(void) {
    return (elem_count == max_elems);
}

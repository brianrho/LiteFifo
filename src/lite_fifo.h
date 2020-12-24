#ifndef LITE_FIFO_H_
#define LITE_FIFO_H_
    
#include <stdint.h>

class LiteFifo {
    public:
        /* elements = the buffer for the fifo elements,
           max_elems = number of elements in the buffer,
           elem_sz = size of each element in bytes */
        LiteFifo(void * elements, uint16_t max_elems, uint8_t _elem_sz);
        bool enqueue(void * elem);
        bool dequeue(void * elem);
        bool peek(void * elem);
        uint16_t available(void);
        bool full(void);
        void clear(void);
    
    private:
        uint16_t head;
        uint16_t tail;
        
        uint16_t elem_count;
        uint8_t * elements;
        uint16_t buffer_sz;
        uint8_t elem_sz;
        uint16_t max_elems;
};

#endif

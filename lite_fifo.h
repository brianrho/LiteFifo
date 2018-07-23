#ifndef LITE_FIFO_H
#define LITE_FIFO_H
    
#include <stdint.h>

class LiteFifo {
    public:
        LiteFifo(void * obj_array, uint16_t array_sz, uint8_t _obj_sz);
        bool enqueue(void * obj);
        bool dequeue(void * obj);
        uint16_t available(void);
        bool full(void);
    
    private:
        uint16_t head;
        uint16_t tail;
        uint16_t byte_count;
        uint8_t * bufptr;
        uint16_t buffer_sz;
        uint8_t obj_sz;
};

#endif

#include <lite_fifo.h>

/* user defined struct to be inserted into queue */
typedef struct {
    uint16_t x;
    uint16_t y;
} Point;

/* backing storage for the queue */
Point buffer[32];
/* create FIFO and point to the storage */
LiteFifo fifo(buffer, 32, sizeof(Point));

void setup(void) {
    Serial.begin(9600);
}

void loop(void) {
    
}

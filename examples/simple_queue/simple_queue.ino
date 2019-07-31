#include <lite_fifo.h>

/* Simple example of a queue with 32 elements */


/* user defined data struct to be inserted into queue */
typedef struct {
    uint16_t x;
    uint16_t y;
} Point;

#define QUEUE_LEN       32

/* backing storage for the queue */
Point buffer[QUEUE_LEN];

/* create FIFO and point to the storage */
LiteFifo points(buffer, QUEUE_LEN, sizeof(Point));

void setup(void) {
    Serial.begin(9600);
    
    /* Insert arbitrary Points into the queue till it's full */
    Point spot;
    int count = 0;
    
    Serial.println("Enqueueing: ");
    while (!points.full()) {
        spot.x = random(1, 10);
        spot.y = random(1, 10);
        points.enqueue(&spot);
        count++;
        
        Serial.print(spot.x); Serial.print(","); Serial.println(spot.y); 
    }

    Serial.print(count); Serial.println(" elements enqueued.\r\n");
    
    /* And then remove Points till the queue is empty */
    count = 0;
    Serial.println("Dequeueing: ");
    while (points.available()) {
        points.dequeue(&spot);
        count++;
        
        Serial.print(spot.x); Serial.print(","); Serial.println(spot.y); 
    }

    Serial.print(count); Serial.println(" elements dequeued.");
}

void loop(void) {
    
}

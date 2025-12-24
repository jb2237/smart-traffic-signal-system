#include "queue.h"

//Initialize queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

//Add element to queue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = value;
}

//Remove element from queue
void dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) return;
    q->front++;
}

//Return number of elements in queue
int queueSize(Queue *q) {
    if (q->front == -1 || q->front > q->rear) return 0;
    return q->rear - q->front + 1;
}

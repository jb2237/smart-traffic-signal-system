#ifndef QUEUE_H
#define QUEUE_H

#define MAX 100

//Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

//Queue operations
void initQueue(Queue *q);
void enqueue(Queue *q, int value);
void dequeue(Queue *q);
int queueSize(Queue *q);

#endif

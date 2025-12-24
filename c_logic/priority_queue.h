#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define MAX 100

typedef struct {
    int lane;
    int priority;
} Emergency;

//Emergency priority queue operations 
void insertEmergency(int lane, int priority);
int extractEmergencyLane();
int hasEmergency();

#endif

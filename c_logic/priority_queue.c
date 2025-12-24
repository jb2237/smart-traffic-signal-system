#include "priority_queue.h"

Emergency heap[MAX];
int heapSize = 0;

void swap(Emergency *a, Emergency *b) {
    Emergency temp = *a;
    *a = *b;
    *b = temp;
}

void insertEmergency(int lane, int priority) {
    int i = heapSize++;
    heap[i].lane = lane;
    heap[i].priority = priority;

    while (i > 0 && heap[(i - 1) / 2].priority < heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractEmergencyLane() {
    if (heapSize == 0) return -1;

    int lane = heap[0].lane;
    heap[0] = heap[--heapSize];

    int i = 0;
    while (2 * i + 1 < heapSize) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;

        if (l < heapSize && heap[l].priority > heap[largest].priority)
            largest = l;
        if (r < heapSize && heap[r].priority > heap[largest].priority)
            largest = r;

        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return lane;
}

int hasEmergency() {
    return heapSize > 0;
}

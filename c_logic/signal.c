#include "signal.h"

 //Select lane with maximum number of vehicles
int selectGreenLane(Queue lanes[], int n) {
    int max = -1, lane = -1;
    for (int i = 0; i < n; i++) {
        int size = queueSize(&lanes[i]);
        if (size > max) {
            max = size;
            lane = i;
        }
    }
    return lane;
}

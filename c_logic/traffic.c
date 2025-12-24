#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "priority_queue.h"
#include "signal.h"

#define LANES 4
// Green time calculation constants 
#define BASE_TIME 10
#define FACTOR 2
#define MIN_GREEN 10
#define MAX_GREEN 90


int main(int argc, char *argv[]) {
    Queue lanes[LANES];

    for (int i = 0; i < LANES; i++)
        initQueue(&lanes[i]);

    // Read vehicle counts
    for (int i = 0; i < LANES; i++) {
        int count = atoi(argv[i + 1]);
        for (int j = 0; j < count; j++)
            enqueue(&lanes[i], 1);
    }

    //  Read emergency lane from input
    int emergencyLane = atoi(argv[5]);

    if (emergencyLane!=-1) {
        insertEmergency(emergencyLane,10);
    }

    int greenLane;
    char reason[50];

    //Decide which lane gets highest priority
    if (hasEmergency()) {
        greenLane = extractEmergencyLane();
        sprintf(reason, "Emergency Vehicle in Lane %d", greenLane);
    } else {
        greenLane = selectGreenLane(lanes, LANES);
        sprintf(reason, "Highest Traffic Density");
    }

    // Calculate green time 
    int vehicles = queueSize(&lanes[greenLane]);
    int rawTime = BASE_TIME + vehicles * FACTOR;
int greenTime;

if (rawTime < MIN_GREEN)
    greenTime = MIN_GREEN;
else if (rawTime > MAX_GREEN)
    greenTime = MAX_GREEN;
else
    greenTime = rawTime;

    // Output JSON for Flask
    printf(
        "{\"green_lane\":%d,\"reason\":\"%s\",\"green_time\":%d}",
        greenLane+1, reason, greenTime
    );

    return 0;
}

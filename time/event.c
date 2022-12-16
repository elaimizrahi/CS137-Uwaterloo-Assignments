#include <stdio.h>
#include <assert.h>
#include "event.h"

int freetime (struct event schedule[], int n, int hour, int min){
    for(int i = 0; i < n; i++){
        if(schedule[i].start.hour == schedule[i].end.hour && hour == schedule[i].start.hour){
            if(schedule[i].start.minute <= min && schedule[i].end.minute > min){
                return 0;
            }
        }
        if(schedule[i].start.hour < hour && schedule[i].end.hour > hour){
            return 0;
        }
        if(schedule[i].start.hour <= hour && schedule[i].end.hour > hour){
            if(schedule[i].start.hour == hour){
                if(schedule[i].start.minute <= min){
                    return 0;
                }
            }
            if(schedule[i].start.hour < hour && schedule[i].end.hour == hour){
                if(schedule[i].end.minute > min){
                    return 0;
                }
            }
        }
        if(schedule[i].start.hour < hour && schedule[i].end.hour == hour){
            if(schedule[i].end.minute > min){
                return 0;
            }
        }
    }
    return 1;
}
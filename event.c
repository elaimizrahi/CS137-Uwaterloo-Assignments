#include <stdio.h>
#include <assert.h>
#include "event.h"

int freetime (struct event schedule[], int n, int hour, int min){
    for(int i = 0; i < n; i++){
        if(schedule[i].start.hour <= hour && schedule[i].end.hour >= hour ){
            if(schedule[i].start.hour == hour){
                if(schedule[i].start.minute > min){
                    return 1;
                }
            }
            if(schedule[i].end.hour == hour){
                if(schedule[i].end.minute <= min){
                    return 1;
                }
            }
            return 0;
            
        }
    }
    return 1;
}
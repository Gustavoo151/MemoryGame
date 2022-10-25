#include <time.h>

void sleepCards(){

    time_t start, end;

    time(&start);

    do time(&end); 
        while(difftime(end, start) <= 0.5);
}

#ifndef HEARDESSLEEPCARDS_H_INCLUDED
#define HEARDESSLEEPCARDS_H_INCLUDED

void sleepCards();

#endif // HEARDESFUNCS_H_INCLUDED
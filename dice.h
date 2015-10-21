#ifndef DICE_H
#define DICE_H

#include <stdlib.h> //rand, srand
#include <time.h> //time

using namespace std;

void random_seed()
{
	srand((int)time(NULL));
}

int rand_int(int min, int max)
//returns a random integer in the range (inclusive).
{
    if (max < min)
    {
        int temp = max;
        max = min;
        min = temp;
    }
    int span = max - min + 1;
    //cout << min << " " << max << " " << span << endl;
    return (rand() % span) + min;
}

int dice()
//rolls a die.
{
    return rand_int(1,6);
}

#endif

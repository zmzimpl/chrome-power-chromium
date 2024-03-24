#include <iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int getRandomArc(){
    srand(int(time(0)));
    return rand() % 10;
}
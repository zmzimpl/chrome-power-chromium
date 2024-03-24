#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

int getRandomScreenNum() {
  srand(int(time(0)));
  return rand() % 10;
}

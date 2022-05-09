#include"header.h"

float func(float x, float y){
  return pow(x-0.1,4) + pow(y-0.1,4) - 10*((pow(x,2) + pow(y,2)));
}

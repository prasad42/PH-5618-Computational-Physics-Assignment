#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef float (*f_ptr) (float, float);

//declaring functions
float func(float, float);
int powell(f_ptr f, float x0_1, float x0_2, float h1_1, float h1_2, float h2_1, float h2_2, float tol);

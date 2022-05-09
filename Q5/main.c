#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <stdio.h>
#include <math.h>

float f(float t, float y){
  return -1000*y + 3000 - 2000*exp(-3*t);
}

float f1(float t, float y, float h){
  return (y+3000*h-2000*h*exp(-(t+h)))/(1+1000*h);
}

float f2(float t){
  return 3 - 0.998*exp(-1000*t) -2.002*exp(-t);
}

int main(){
  FILE *fp = fopen("multistepExplicit.dat", "w");
  FILE *fp1 = fopen("singleStepImplicit.dat", "w");
  FILE *fp2 = fopen("yvst.dat", "w");
  ////////
  //Input
  ///////
  float tl = 0;		//lower limit
  float tu = 0.4;	//upper limit
  float h = 0.00001;	//step size
  
  int steps = (tu-tl)/h;//total number of steps
  float tol = 0.01;	//tolerance
  float err = 1;
  
  ///////////////////////////////
  //Non self starting Heun Method
  ///////////////////////////////
  float y[steps+1];
  y[0] = 0;			//initial condition
  y[-1] = y[0] - f(0, y[0])*h;	//get the previous point using Euler's method
  fprintf(fp, "%f %f\n", (0)*h, y[0]);
  for(int i = 0; i < steps; i++){
    //predictor
    y[i+1] = y[i] + f(i*h, y[i]) * 2*h;
    //corrector loop
    while(err > tol){
      float yo = y[i+1]; 
      y[i+1] = y[i] + (f(i*h,y[i]) + f((i+1)*h,y[i+1])) /2 * h;
      err = (y[i+1]-yo)/y[i+1];
    }
    fprintf(fp, "%f %f\n", (i+1)*h, y[i+1]);
    //printf("%f %f\n", (i+1)*h, y[i+1]);
  }
  
  ///////////////////////////////
  //Single step implicit method 
  ///////////////////////////////
  y[0] = 0;
  fprintf(fp1, "%f %f\n", (0)*h, y[0]);
  for(int i = 0; i < steps; i++){
    y[i+1] = f1(i*h, y[i], h);
    fprintf(fp1, "%f %f\n", (i+1)*h, y[i+1]);
    //printf("%f %f\n", (i+1)*h, y[i+1]);
  }
  
  ///////////////////////////////
  //Exact Analytical Solution
  ///////////////////////////////
  for(int i = 0; i < steps; i++){
    y[i] = f2(i*h);
    fprintf(fp2, "%f %f\n", (i+1)*h, y[i+1]);
    printf("%f %f\n", (i)*h, y[i]);
  }
  
  fclose(fp);
  fclose(fp1);
  fclose(fp2);
}

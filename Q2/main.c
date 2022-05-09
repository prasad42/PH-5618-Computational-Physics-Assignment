#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <stdio.h>
#include <math.h>

float f(float x){
  return 0.2 + 25*x - 200*pow(x,2) + 675*pow(x,3) - 900*pow(x,4) + 400*pow(x,5);
}

int main(){
  FILE *fp = fopen("trap.dat", "w");
  FILE *fp1 = fopen("simp.dat", "w");
  ////////
  //Input
  ///////
  float xl = 0;
  float xu = 0.8;
  float It = 1.64103;
  for (int seg = 2; seg <= pow(2,17); seg *= 2){
    //printf("seg: %d\n", seg);
    float x[seg];
    float dx = (xu - xl)/seg;
    float err;
    ///////////
    //Trapezoidal
    ///////////
    x[0] = xl;
    float Itrap = 0;
    for (int i = 1; i <= seg; i++){
      x[i] = xl + i * dx;
      Itrap += (f(x[i])+f(x[i-1]))/2 * dx;
    }
    err = fabs(It - Itrap)/fabs(It) * 100;
    fprintf(fp, "%d %f\n", seg, err);
    //printf("%d %lf %lf\n", seg, err, Itrap);
    
    ///////////////////////
    //Simpson's 1/3rd rule
    ///////////////////////
    float Isimp = 0;
    for (int i = 1; i <= seg/2; i++){
      x[i] = xl + i*dx;
      x[i+1] = xl + (i+1)*dx;
      x[i+2] = xl + (i+2)*dx;
      Isimp += dx/3 * (f(x[2*i]) + 4*f(x[2*i-1]) + f(x[2*i-2]));
    }
    err = fabs(It - Isimp)/fabs(It) * 100;
    fprintf(fp1, "%d %f\n", seg, err);
    printf("%d %lf %lf\n", seg, err, Isimp);
  }
  fclose(fp);
  fclose(fp1);
}

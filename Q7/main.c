#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <stdio.h>
#include <math.h>

int main(){
  FILE *fp = fopen("radDist.dat", "w");
  ////////
  //Input
  ///////
  float L = 11.856311014966876;
  float V = pow(L,3);
  int N = 500;
  float dr = 0.1;
  
  ////////////////
  //Other variables
  ////////////////
  int steps = L/dr;
  int count[steps];
  int config = 1000;
  float g[steps][1000];
  float gbar[1000];
  float r[steps];
  for(int i = 0; i <= steps; i++){
    count[i] = 0;
    r[i] = i*dr;
    //printf("%d %d %f\n", i, count[i], r[i]);
  }
  float rij;
  
  //////////////////
  //Read from a file
  //////////////////
  FILE *fp1 = fopen("LJ_T2.0_Rho0.3_S1-datarun.dump", "r");
  //FILE *fp2 = fopen("datarun.dump", "w");
  float x[N][config], y[N][config], z[N][config];
  int id = 0;
  int linecounter = 1;
  int configcounter = 1;
  //Copy all the data into 3 arrays
  while(!feof(fp1)){
    float dum;
    if (linecounter > 509){
      configcounter++;
      linecounter = 1;
      id = 0;
    }
    if(configcounter > config){
      break;
    }
    if(linecounter <= 9){
      while (getc(fp1) != '\n'){}	//skip first 9 lines 
      linecounter++;
    }
    else if(linecounter > 9){
      fscanf(fp1,"%f %f %f %f %f %f %f %f %f %f %f\n", &dum, &dum, &dum, &dum, &dum, &x[id][configcounter], &y[id][configcounter], &z[id][configcounter], &dum, &dum, &dum);
      //fprintf(fp2, "%d %f %f %f", id, x[id], y[id], z[id]);
      printf("%d %d %f %f %f\n", id, configcounter, x[id][configcounter], y[id][configcounter], z[id][configcounter]);
      id++;
      linecounter++;
    }
  }
  
  ///////////////////////////////////
  //Find radial distribution function
  ///////////////////////////////////
  for(int iconfig = 0; iconfig < config; iconfig++){
    for(int k = 1; k < steps; k++){
      for(int i = 0; i < N; i++){
        //pick a particle i
        //find its distance to every other particle
        for(int j = 0; j < N; j++){
          if(j!=i){
            rij = pow(pow(x[i][iconfig]-x[j][iconfig],2) + pow(y[i][iconfig]-y[j][iconfig],2) + pow(z[i][iconfig]-z[j][iconfig],2), 0.5);
            //if distance is around r[k] then count++
            if(rij >= r[k] && rij < r[k]+dr){
              count[k]++;
            }
          }
        }
      }
      g[k][iconfig] = V/(N*(N-1)*4*3.141*pow(r[k],2)*dr) * count[k];
      printf("%d %f %f\n", iconfig, r[k], g[k][iconfig]);
    }
  }
  
  ////////////////////////////////////
  //Average over all configurations
  ////////////////////////////////////
  for(int i = 0; i < steps; i++){
    gbar[i] = 0;
    for(int iconfig = 0; iconfig < config; iconfig++){
      gbar[i] += g[i][iconfig]/config;
    }
    fprintf(fp,"%f %f\n", r[i], gbar[i]);
    printf("%f %f\n", r[i], gbar[i]);
  }

  fclose(fp);
  fclose(fp1);
  //fclose(fp2);
}

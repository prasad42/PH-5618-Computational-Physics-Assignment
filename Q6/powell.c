#include"header.h"

int powell(f_ptr f, float x0_1, float x0_2, float h1_1, float h1_2, float h2_1, float h2_2, float tol){
  float R = 0.61803;	//golden ratio
  float d_1, d_2;
  float xL_1, xL_2, xU_1, xU_2, u_1, l_1, u_2, l_2;
  float xR, xR_1, xR_2, diff, x1_1, x1_2, x2_1, x2_2, x3_1, x3_2, x4_1, x4_2, x5_1, x5_2, xopt_1, xopt_2;
  float h3_1, h3_2, h4_1, h4_2;
  
  printf("POWELL'S METHOD\n");
  /*****************************h1 direction****************************/
  xL_1 = x0_1-100*h1_1;
  xL_2 = x0_2-100*h1_2;
  xU_1 = x0_1+100*h1_1;
  xU_2 = x0_2+100*h1_2;
  
  float err = 1;
  int counter = 0;
  
  //Golden search for a minimum
  while(err>tol && counter < 100){
    counter++;
    d_1 = R*(xU_1-xL_1);	//x-axis
    d_2 = R*(xU_2-xL_2);	//y-axis
    
    //x1 and x2 (x-axis)
    u_1 = xL_1+d_1;
    l_1 = xU_1-d_1;
    
    //x1 and x2 (y-axis)
    u_2 = xL_2+d_2;
    l_2 = xU_2-d_2;
    
    if(f(u_1,u_2) < f(l_1,l_2)){
      xL_1 = l_1;
      xL_2 = l_2;
      
      xR_1 = u_1;
      xR_2 = u_2;
    }
    else if(f(u_1,u_2) > f(l_1,l_2)){
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = l_1;
      xR_2 = l_2;
    }
    else{
      xL_1 = l_1;
      xL_2 = l_2;
      
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = (l_1+u_1)/2;
      xR_2 = (l_2+u_2)/2;
    }
    
    diff = sqrt(pow((xU_1-xL_1),2)+pow((xU_2-xL_2),2));
    xR = sqrt(pow(xR_1,2)+pow(xR_2,2));
    
    err = (1-R)*fabs((diff)/(xR+tol));
  }
  
  //store this point
  x1_1 = xR_1;
  x1_2 = xR_2;
  
  printf("x1 is at (%f, %f) with functional value %f with relative error %f. \n", x1_1, x1_2, f(x1_1, x1_2), err); 
  /*****************************h1 direction****************************/
  

  
  /*****************************h2 direction****************************/
  xL_1 = x1_1-100*h2_1;
  xL_2 = x1_2-100*h2_2;
  xU_1 = x1_1+100*h2_1;
  xU_2 = x1_2+100*h2_2;
  
  //reset error ande counter
  err = 1;
  counter = 0;
  
  //Golden search for a minimum
  while(err>tol && counter < 100){
    counter++;
    d_1 = R*(xU_1-xL_1);	//x-axis
    d_2 = R*(xU_2-xL_2);	//y-axis
    
    //x1 and x2 (x-axis)
    u_1 = xL_1+d_1;
    l_1 = xU_1-d_1;
    
    //x1 and x2 (y-axis)
    u_2 = xL_2+d_2;
    l_2 = xU_2-d_2;
    
    if(f(u_1,u_2) < f(l_1,l_2)){
      xL_1 = l_1;
      xL_2 = l_2;
      
      xR_1 = u_1;
      xR_2 = u_2;
    }
    else if(f(u_1,u_2) > f(l_1,l_2)){
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = l_1;
      xR_2 = l_2;
    }
    else{
      xL_1 = l_1;
      xL_2 = l_2;
      
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = (l_1+u_1)/2;
      xR_2 = (l_2+u_2)/2;
    }
    
    diff = sqrt(pow((xU_1-xL_1),2)+pow((xU_2-xL_2),2));
    xR = sqrt(pow(xR_1,2)+pow(xR_2,2));
    
    err = (1-R)*fabs((diff)/(xR+tol));
  }
  
  //store this point
  x2_1 = xR_1;
  x2_2 = xR_2;
  
  printf("x2 is at (%f, %f) with functional value %f with relative error %f. \n", x2_1, x2_2, f(x2_1, x2_2), err); 
  /*****************************h2 direction****************************/
  
  /*****************************h3 direction****************************/
  h3_1 = x2_1 - x0_1;
  h3_2 = x2_2 - x0_2;
  
  xL_1 = x2_1-100*h3_1;
  xL_2 = x2_2-100*h3_2;
  xU_1 = x2_1+100*h3_1;
  xU_2 = x2_2+100*h3_2;
  
  err = 1;
  counter = 0;
  
  //Golden search for a minimum
  while(err>tol && counter < 100){
    counter++;
    d_1 = R*(xU_1-xL_1);	//x-axis
    d_2 = R*(xU_2-xL_2);	//y-axis
    
    //x1 and x2 (x-axis)
    u_1 = xL_1+d_1;
    l_1 = xU_1-d_1;
    
    //x1 and x2 (y-axis)
    u_2 = xL_2+d_2;
    l_2 = xU_2-d_2;
    
    if(f(u_1,u_2) < f(l_1,l_2)){
      xL_1 = l_1;
      xL_2 = l_2;
      
      xR_1 = u_1;
      xR_2 = u_2;
    }
    else if(f(u_1,u_2) > f(l_1,l_2)){
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = l_1;
      xR_2 = l_2;
    }
    else{
      xL_1 = l_1;
      xL_2 = l_2;
      
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = (l_1+u_1)/2;
      xR_2 = (l_2+u_2)/2;
    }
    
    diff = sqrt(pow((xU_1-xL_1),2)+pow((xU_2-xL_2),2));
    xR = sqrt(pow(xR_1,2)+pow(xR_2,2));
    
    err = (1-R)*fabs((diff)/(xR+tol));
  }
  
  //store this point
  x3_1 = xR_1;
  x3_2 = xR_2;
  
  printf("x3 is at (%f, %f) with functional value %f with relative error %f. \n", x3_1, x3_2, f(x3_1, x3_2), err); 
  /*****************************h3 direction****************************/
  
  /*****************************h2 direction again****************************/
  xL_1 = x3_1-100*h2_1;
  xL_2 = x3_2-100*h2_2;
  xU_1 = x3_1+100*h2_1;
  xU_2 = x3_2+100*h2_2;
  
  err = 1;
  counter = 0;
  
  //Golden search for a minimum
  while(err>tol && counter < 100){
    counter++;
    d_1 = R*(xU_1-xL_1);	//x-axis
    d_2 = R*(xU_2-xL_2);	//y-axis
    
    //x1 and x2 (x-axis)
    u_1 = xL_1+d_1;
    l_1 = xU_1-d_1;
    
    //x1 and x2 (y-axis)
    u_2 = xL_2+d_2;
    l_2 = xU_2-d_2;
    
    if(f(u_1,u_2) < f(l_1,l_2)){
      xL_1 = l_1;
      xL_2 = l_2;
      
      xR_1 = u_1;
      xR_2 = u_2;
    }
    else if(f(u_1,u_2) > f(l_1,l_2)){
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = l_1;
      xR_2 = l_2;
    }
    else{
      xL_1 = l_1;
      xL_2 = l_2;
      
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = (l_1+u_1)/2;
      xR_2 = (l_2+u_2)/2;
    }
    
    diff = sqrt(pow((xU_1-xL_1),2)+pow((xU_2-xL_2),2));
    xR = sqrt(pow(xR_1,2)+pow(xR_2,2));
    
    err = (1-R)*fabs((diff)/(xR+tol));
  }
  
  //store this point
  x4_1 = xR_1;
  x4_2 = xR_2;
  
  printf("x3 is at (%f, %f) with functional value %f with relative error %f. \n", x4_1, x4_2, f(x4_1, x4_2), err); 
  /*****************************h2 direction again****************************/
  
  /*****************************h3 direction again****************************/
  h3_1 = x2_1 - x0_1;
  h3_2 = x2_2 - x0_2;
  
  xL_1 = x4_1-100*h3_1;
  xL_2 = x4_2-100*h3_2;
  xU_1 = x4_1+100*h3_1;
  xU_2 = x4_2+100*h3_2;
  
  err = 1;
  counter = 0;
  
  //Golden search for a minimum
  while(err>tol && counter < 100){
    counter++;
    d_1 = R*(xU_1-xL_1);	//x-axis
    d_2 = R*(xU_2-xL_2);	//y-axis
    
    //x1 and x2 (x-axis)
    u_1 = xL_1+d_1;
    l_1 = xU_1-d_1;
    
    //x1 and x2 (y-axis)
    u_2 = xL_2+d_2;
    l_2 = xU_2-d_2;
    
    if(f(u_1,u_2) < f(l_1,l_2)){
      xL_1 = l_1;
      xL_2 = l_2;
      
      xR_1 = u_1;
      xR_2 = u_2;
    }
    else if(f(u_1,u_2) > f(l_1,l_2)){
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = l_1;
      xR_2 = l_2;
    }
    else{
      xL_1 = l_1;
      xL_2 = l_2;
      
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = (l_1+u_1)/2;
      xR_2 = (l_2+u_2)/2;
    }
    
    diff = sqrt(pow((xU_1-xL_1),2)+pow((xU_2-xL_2),2));
    xR = sqrt(pow(xR_1,2)+pow(xR_2,2));
    
    err = (1-R)*fabs((diff)/(xR+tol));
  }
  
  //store this point
  x5_1 = xR_1;
  x5_2 = xR_2;
  
  printf("x5 is at (%f, %f) with functional value %f with relative error %f. \n", x5_1, x5_2, f(x5_1, x5_2), err); 
  /*****************************h3 direction again****************************/

  /*****************************h4 direction****************************/
  h4_1 = x5_1 - x3_1;
  h4_2 = x5_2 - x3_2;
  
  xL_1 = x3_1-100*h4_1;
  xL_2 = x3_2-100*h4_2;
  xU_1 = x3_1+100*h4_1;
  xU_2 = x3_2+100*h4_2;
  
  err = 1;
  counter = 0;
  
  //Golden search for a minimum
  while(err>tol && counter < 100){
    counter++;
    d_1 = R*(xU_1-xL_1);	//x-axis
    d_2 = R*(xU_2-xL_2);	//y-axis
    
    //x1 and x2 (x-axis)
    u_1 = xL_1+d_1;
    l_1 = xU_1-d_1;
    
    //x1 and x2 (y-axis)
    u_2 = xL_2+d_2;
    l_2 = xU_2-d_2;
    
    if(f(u_1,u_2) < f(l_1,l_2)){
      xL_1 = l_1;
      xL_2 = l_2;
      
      xR_1 = u_1;
      xR_2 = u_2;
    }
    else if(f(u_1,u_2) > f(l_1,l_2)){
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = l_1;
      xR_2 = l_2;
    }
    else{
      xL_1 = l_1;
      xL_2 = l_2;
      
      xU_1 = u_1;
      xU_2 = u_2;
      
      xR_1 = (l_1+u_1)/2;
      xR_2 = (l_2+u_2)/2;
    }
    
    diff = sqrt(pow((xU_1-xL_1),2)+pow((xU_2-xL_2),2));
    xR = sqrt(pow(xR_1,2)+pow(xR_2,2));
    
    err = (1-R)*fabs((diff)/(xR+tol));
  }
  
  //store this point
  xopt_1 = xR_1;
  xopt_2 = xR_2;
  
  printf("\nxopt is at (%f, %f) with functional value %f with relative error %f. \n", xopt_1, xopt_2, f(xopt_1, xopt_2), err); 
  /*****************************h4 direction****************************/
}

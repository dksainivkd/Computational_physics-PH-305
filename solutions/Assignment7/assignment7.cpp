#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;


vector <float> ff(vector <float> y,float x){  
    int n=y.size();
    vector <float> f(n,0); 
    f[0]=y[0]*y[1]+cos(x)-0.5*sin(2*x);
    f[1]=pow(y[0],2)+pow(y[1],2)-1.0-sin(x);
 
  return f;        
}

vector <float> Euler(vector <float> y,float dx, float x){
    int i,n=y.size();
    vector <float> f;
    f=ff(y,x);
    for(i=0; i<n; i++){
       y[i]=y[i]+dx*f[i];
    } 
  return y;    
}

vector <float> Heun(vector <float> y,float dx, float x){
    int i,n=y.size();
    vector <float> f1,f2,y2;
    f1=ff(y,x);
    y2=Euler(y,dx,x);
    f2=ff(y2,x+dx);
        
    for(i=0; i<n; i++){
       y[i]=y[i]+(f1[i]+f2[i])*dx/2;
    }
   return y;
}

vector <float> rk2(vector <float> y,float dt, float t){
    int i=-1,n=y.size();
    vector <float> f,y_var;
    float t_var;
    
    f=ff(y,t);
    while(i++<n-1)
        y_var.push_back(y[i]+0.5*dt*f[i]);i=-1;
    t_var=t+0.5*dt;
        
    f=ff(y_var,t_var);
    while(i++<n-1)
        y[i]=y[i]+dt*f[i];
        
  return y;
}

vector <float> rk4(vector <float> y, float dt, float t){

  vector <float> f,k1,k2,k3,k4,y_var;
  float t_var;
  int i=-1,n=y.size();

  f=ff(y,t);
  while(i++<n-1)
       k1.push_back(dt*f[i]);i=-1;

  while(i++<n-1)
       y_var.push_back(y[i]+0.5*k1[i]);i=-1;
  t_var=t+0.5*dt;
  f=ff(y_var,t_var);
  
  while(i++<n-1)
       k2.push_back(dt*f[i]);i=-1;
  while(i++<n-1)
       y_var.push_back(y[i]+0.5*k2[i]);i=-1;
  t_var=t+0.5*dt;
  f=ff(y_var,t_var);

  while(i++<n-1)
       k3.push_back(dt*f[i]);i=-1;
  while(i++<n-1)
       y_var.push_back(y[i]+k3[i]);i=-1;
  t_var=t+dt;
  f=ff(y_var,t_var);
  
  while(i++<n-1)
       k4.push_back(dt*f[i]);i=-1;

  while(i++<n-1)
       y[i]+=(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6.0;

  return y;  
}

int main(){
    int i,nx=25,n=2;
    vector <float> ye(n,0),yhe(n,0),yrk4(n,0);
    //***********initialization*********
   // ye[0]=1; ye[1]=3;
    //*******************************
    float x1=0,x2=2,x,dx;
    dx=(x2-x1)/nx;
    
    ofstream myfile;
    myfile.open("ass7_data.dat");
    
    float pre=0.0001;
    for(i=0; i<nx; i++){
       x=i*dx;
       myfile<<x+dx<<"\t\t";
       
       ye=Euler(ye,dx,x);
       myfile<<(int)(ye[0]/pre)*pre<<"\t"<<(int)(ye[1]/pre)*pre<<"\t\t";
       
       yhe=Heun(yhe,dx,x);
       myfile<<(int)(yhe[0]/pre)*pre<<"\t"<<(int)(yhe[1]/pre)*pre<<"\t\t";
       
       yrk4=rk2(yrk4,dx,x);
       myfile<<(int)(yrk4[0]/pre)*pre<<"\t"<<(int)(yrk4[1]/pre)*pre<<endl;
              
    }
    myfile.close();
  return 0;
}














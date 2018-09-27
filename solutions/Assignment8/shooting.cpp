#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;


vector <float> ff(vector <float> y,float t){
  
  int n=y.size();
  vector <float> f(n,0);
  
  f[0]=y[1];
  f[1]=0.01*(y[0]-20);
 
  return f;        
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
    vector <float> y;
    int nx=1000,n=2;
    float x,dx=0.01;

    float T0=40,z1=10;
    y.push_back(T0); 
    y.push_back(z1);
    for(int i=1; i<nx; i++){
       x=i*dx;
       y=rk4(y,dx,x);
    } float Tz10=y[0];
    cout<<"for z = 10 T10 = "<<Tz10<<endl;

    float z2=15;
    y[0]=T0; 
    y[1]=z2;
    for(int i=1; i<nx; i++){
       x=i*dx;
       y=rk4(y,dx,x);
    } float Tz15=y[0];
    cout<<"for z = 15 T10 = "<<Tz15<<endl;

    float z0=(z2-z1)*((200-Tz10)/(Tz15-Tz10))+z1;
    cout<<"actual z0 = "<<z0<<endl;
    y[0]=T0; 
    y[1]=z0;
    
    ofstream myfile;
    myfile.open("fort.12");
 
    for(int i=0; i<nx; i++){
       x=i*dx;
       myfile<<x+dx<<"  ";
       y=rk4(y,dx,x);
       int j=-1;
       while(j++<n-1){
         myfile<<y[j]<<"  ";
    }
    myfile<<endl; 
   }cout<<"final T10 is = "<<y[0]<<endl;

   myfile.close();

 return 0;
}

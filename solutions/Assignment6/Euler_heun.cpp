#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;

float fd(float x){
    return -2*pow(x,3)+12*pow(x,2)-20*x+8.5;
}

float Euler(float y,float dx,float x){
    return y+dx*fd(x);
}

float Heun(float y, float dx, float x){
    return y+(fd(x)+fd(x+dx))*dx/2;
}
  
float exact(float x){
    return -0.5*pow(x,4)+4*pow(x,3)-10*pow(x,2)+8.5*x+1;
}

int main(){
    ofstream myfile;
    myfile.open("fort.15"); 
    cout.precision(2); 
    int n=8;
    float x,dx,x1=0,x2=4;
    dx=(x2-x1)/n;
    float ye=1, yhe=1;
    myfile<<"0\t\t1\t\t1\t\t0\t\t1\t\t0"<<endl;
    
    for(int i=0; i<n; i++){
       x=i*dx;
       myfile<<x+dx<<"\t\t";
       float a=exact(x+dx);
       myfile<<a<<"\t\t";
       
       yhe=Heun(yhe,dx,x);
       myfile<<yhe<<"\t\t";
       
       myfile<<abs((a-yhe)*100/a)<<"\t\t";
       
       ye=Euler(ye,dx,x);
       myfile<<ye<<"\t\t";
       myfile<<abs((a-ye)*100/a)<<endl;
    }
    myfile.close();    
  
}

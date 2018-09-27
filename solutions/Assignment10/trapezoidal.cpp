#include<iostream>
#include<cmath>
using namespace std;
float f(float x){
  return 0.2+25*x-200*pow(x,2)+675*pow(x,3)-900*pow(x,4)+400*pow(x,5);} 
//****************main************
int main(){
    int n=100;
    float x,a=0,b=0.8;
    float Imatr,sum=0,dx=(b-a)/n,Istr=(b-a)*(f(a)+f(b))/2;        
    for(int i=1; i<n; i++){
       x=i*dx;
       sum+=f(x);
    }
    Imatr=dx*(f(a)+2*sum+f(b))/2;
    cout<<"\nSimple trapezoidal result = "<<Istr<<"\nmultiple application Trapezoidal result = "<<Imatr<<endl;
//************************            
    float max=0;
    for(int i=0; i<=n; i++){
      x=i*dx;
      if(max<f(x))max=f(x);
    }       
    float area_rect=(b-a)*max;
    int m=10000,count=0;   
    for(int j=0; j<m; j++){
    float y=(float)rand()/(float)(RAND_MAX/(max-0.0));
          x=(float)rand()/(float)(RAND_MAX/(b-a));
          if((y-f(x))<0)count++;
          //cout<<"("<<x<<","<<y<<")"<<endl;
    }
    float area=(area_rect*count)/m; 
    int x1=1;float fx=0;
    for(int i=0; i<m; i++){
       x1=(4*x1+1)%9;  x=x1*0.8/9.0;//x=(x1*(y2-y1)/9)+y1
        //cout<<x1<<endl;
       fx+=f(x);
    }
   cout<<"simple mean method with random numbers using modulo operator= "<<(b-a)*fx/m<<
   "\nusing generated random numbers by computer = "<<area<<endl<<endl;    
  return 0;
}

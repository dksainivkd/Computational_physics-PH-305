#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

vector <float> jordan(vector < vector <float> > A, vector <float> B){
   
   int i,j,k,n=A.size();
   vector <float> X;
   float lemda;
   for(k=0; k<n-1; k++){     
      for(i=k+1; i<n; i++){
         lemda=A[i][k]/A[k][k];
         for(j=k; j<n; j++){                   
            A[i][j]-=lemda*A[k][j];
         }
         B[i]-=lemda*B[k];
      }
   }
   for(k=n-1; k>0; k--){
      for(i=k-1; i>=0; i--){
         lemda=A[i][k]/A[k][k];
         for(j=k; j>=0; j--){                    
            A[i][j]-=lemda*A[k][j];
         }
         B[i]-=lemda*B[k];
      }
   }
   for(int i=0; i<n; i++)
      X.push_back(B[i]/A[i][i]);
  
   return X;

}

int main(){   
   ifstream myfile;
   myfile.open("given_data.dat");
   myfile.precision(3);
   cout.precision(3);
   int n=6;
   float xData[n],yData[n];
   for(int i=0; i<n; i++)
      myfile>>xData[i]>>yData[i];      
   myfile.close();
   
   int p=3;  
   vector< vector<float> > A(p,vector <float>(p,0));
   vector <float> B(p,0);
      
   for(int i=0; i<p; i++){
      for(int j=0; j<p; j++){
         for(int k=0; k<n; k++){
            A[i][j]+=pow(xData[k],i+j);
         }
      }
   }
   for(int i=0; i<p; i++){
      for(int j=0; j<n; j++){
         B[i]+=yData[j]*pow(xData[j],i);
      }
   }
   
   vector<float> abc;
   abc=jordan(A,B);
   cout<<"value of abc for f(x)=a+bx+cx2 are \n";   
   cout<<"a = "<<abc[0]<<endl;cout<<"b = "<<abc[1]<<endl;cout<<"c = "<<abc[2]<<endl;
   cout<<endl;
   
   
   int nx=100;
   float x1=-5, x2=5, x[nx], dx;
   dx=(x2-x1)/nx;
   ofstream file;
   file.open("fort.20");
   //file.precision(3);  
   for(int i=0; i<nx; i++)
      x[i]=x1+i*dx;
   for(int i=0; i<nx; i++){
      file<<"\t"<<x[i]<<"\t\t";
      file<<abc[0]+abc[1]*x[i]+abc[2]*pow(x[i],2)<<endl;
   }
   file.close();

  return 0;
}

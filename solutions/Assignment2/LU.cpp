#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include <bits/stdc++.h>
using namespace std;

vector< vector <vector <float> > > makeLU(vector < vector <float> > A){
    int i,j,k,n=A.size();
    vector < vector <float> > L(n,vector <float>(n,0));
    float lemda;
    vector < vector <vector <float> > > res;
    for(i=0; i<n; i++)
        L[i][i]=1.0;
    for(k=0; k<n-1; k++){     
       for(i=k+1; i<n; i++){
          lemda=A[i][k]/A[k][k];
          for(j=k; j<n; j++){                   
             A[i][j]-=lemda*A[k][j];
          }
          L[i][k]=lemda;
       }
    }        
    res.push_back(L); res.push_back(A);
  return res;
}

vector <float> LUX(vector < vector <float> > A,vector <float> B){
    int i,j,k,n=A.size();
    vector <float> X(n,0),Y(n,0);
    float sum;
    
    vector < vector < vector <float> > > lu;
    vector < vector <float> > L,U;
    lu=makeLU(A); L=lu[0]; U=lu[1];
    
    Y[0]=B[0]/L[0][0];    
    for(i=1; i<n; i++){
       sum=0;
       for(j=0; j<i; j++){
          sum=sum+L[i][j]*Y[j];        
       }
       Y[i]=(B[i]-sum)/L[i][i];
    }    
    X[n-1]=Y[n-1]/U[n-1][n-1];    
    for(i=n-2; i>=0; i--){
       sum=0;
       for(j=n-1; j>=i+1; j--){
          sum=sum+U[i][j]*X[j];        
       }
       X[i]=(Y[i]-sum)/U[i][i];
    }     
 return X;
}

vector<vector <float> > inverse(vector <vector <float> > A){
    int i,j,n=A.size();
    vector < vector <float> > AI(n,vector <float>(n,0)),I(n,vector <float>(n,0));
    vector <float> X(n,0);
    for(i=0; i<n; i++)
       I[i][i]=1.0;
    for(i=0; i<n; i++){
       X=LUX(A,I[i]);
       for(j=0; j<n; j++)
          AI[j][i]=X[j];
    }   
  return AI;
}

int main(){
    int i,j,n=3;
    vector <vector <float> > AI;
    
    //*********************
    vector <vector <float> > A{{12,3,-5},
                               {1,5,3},
                               {3,7,13}};
    vector <float> B{1,28,76}; 
    //**************************   
    vector < vector <vector <float> > > lu;   
    vector <float> X;
    
    lu=makeLU(A);    
    X=LUX(A,B);
    AI=inverse(A);
    
    cout<<"value of X\n"; 
    for(int j=0; j<n; j++){
          printf("%0.3f  ",X[j]);
       }cout<<endl;
    
    cout<<"lower trangular matrix\n"; 
    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
          printf("%0.3f  ",lu[0][i][j]);
       }cout<<endl;
    }cout<<endl;
    
    cout<<"upper trangular matrix\n"; 
    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
          printf("%0.3f  ",lu[1][i][j]);
       }cout<<endl;
    }cout<<endl;
    
    cout<<"inverse of a matrix\n"; 
    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
          printf("%0.3f  ",AI[i][j]);
       }cout<<endl;
    }cout<<endl;
  

  return 0;
}





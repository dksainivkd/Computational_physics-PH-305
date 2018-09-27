/*
  To Solve fo the following set of linear equations.
  
       3.01x + 2.22y + 4.1z = 4.5    (1)
       1.00x + 3.21y + 5.3z = 5.1    (2)
       0.3x–0.44y + 6.6z = 7.1       (3)
  By using Gauss Elimination and Gauss Jorden Methods.
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector <float> gauss(vector < vector <float> > A, vector <float> B){        // Gauss elimination without pivoting
    int i,j,k,n=A.size();
    vector <float> X(n,0);
    float lemda,sum;
    for(k=0; k<n-1; k++){     
       for(i=k+1; i<n; i++){
          lemda=A[i][k]/A[k][k];
          for(j=k; j<n; j++){                   
             A[i][j]-=lemda*A[k][j];
          }
          B[i]-=lemda*B[k];
       }
    }
    X[n-1]=B[n-1]/A[n-1][n-1];    
    for(i=n-2; i>=0; i--){
       sum=0;
       for(j=n-1; j>=i+1; j--){
          sum=sum+A[i][j]*X[j];        
       }
       X[i]=(B[i]-sum)/A[i][i];
    }
  return X;
}

vector <float> gauss_pivot(vector < vector <float> > A, vector <float> B){      // Gauss elimination with pivoting
    int i,j,k,change,n=A.size();
    vector <float> X(n,0);
    vector <float> temp;
    float lemda,sum,temp1;
    
    for(k=0; k<n-1; k++){
    
    //*******pivot*************************
       float max1=0;
       for(j=0; j<n; j++){
          if(max1<A[j][k]){
            max1=A[j][k];
            change=j;
          }      
       }
       temp=A[k];      temp1=B[k];
       A[k]=A[change]; B[k]=B[change];
       A[change]=temp; B[change]=temp1; 
       //************   
       for(i=k+1; i<n; i++){
          lemda=A[i][k]/A[k][k];
          for(j=k; j<n; j++){                   
             A[i][j]-=lemda*A[k][j];
          }
          B[i]-=lemda*B[k];
       }
    } 
    X[n-1]=B[n-1]/A[n-1][n-1];    
    for(i=n-2; i>=0; i--){
       sum=0;
       for(j=n-1; j>=i+1; j--){
          sum=sum+A[i][j]*X[j];        
       }
       X[i]=(B[i]-sum)/A[i][i];
    }
  return X;     
}

vector <float> jordan(vector < vector <float> > A, vector <float> B){         // Gauss Jorden Method
   
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
    int i,j,n=3;
    
    //***************
    vector <vector <float> > A(n,vector <float>(n,0));   
    cout<<"enter A matrix\n";
    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
          cin>>A[i][j];
       }
    }                              
    vector <float> B(n,0);
    cout<<"enter B matrix\n";
    for(i=0; i<n; i++){
       cin>>B[i];
    }
    //**********************
    
    vector <float> X;
   
    X=jordan(A,B);
    cout<<"values of x are\n";
    for(int j=0; j<n; j++){
          cout<<X[j]<<endl;
       }cout<<endl;
  return 0;
}












#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <bits/stdc++.h>

using namespace std;

vector<vector<float> > cholesky(vector < vector <float> > A){
    int i,j,k,n=A.size();
    vector < vector <float> > L(n,vector <float>(n,0));
    float sum;   
    for(k=0; k<n; k++){
       for(i=0; i<=k; i++){
          if(i==k){
             sum=0.0;
             for(j=0; j<k; j++)
                sum+=pow(L[k][j],2);  
             L[k][k]=sqrt(A[k][k]-sum);
          }
          else{
             sum=0.0;
             for(j=0; j<i; j++)
                sum+=L[i][j]*L[k][j];
             L[k][i]=(A[k][i]-sum)/L[i][i];
          }
       }
    }   
  return L;
}
vector<vector<float> > transpose(vector < vector <float> > A){        // to calculate Transpose of A Matrix
    int n=A.size();
    vector < vector <float> > T(n,vector <float>(n,0));
    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
          T[j][i]=A[i][j];
       }
    }  
  return T;
}

vector<vector<float> > matmul(vector < vector <float> > A, vector < vector <float> > B){     // matrix multiplication of two Matrices.
    int i,j,k,n1=A.size(),n2=B.size(),n3=B[0].size();
    vector < vector <float> > C(n1,vector <float>(n3,0));    
    for(i=0; i<n1; i++){
       for(j=0; j<n3; j++){
          for(k=0; k<n2; k++)
             C[i][j]+=A[i][k]*B[k][j];
       }
    }
  return C;
}
int main(){
    int n=4;
    vector<vector<float> > A{{4,3,2,1},
                             {3,3,2,1},
                             {2,2,2,1},
                             {1,1,1,1}};
    vector<vector<float> > L,Lt,AL;
    L=cholesky(A);
    Lt=transpose(L);
    AL=matmul(L,Lt); 
         
    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
          printf("%0.2f  ",AL[i][j]);
       }cout<<endl;
    }
    
  return 0;
}

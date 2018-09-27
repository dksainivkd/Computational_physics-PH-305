#include <iostream>
#include <algorithm> 
#include <vector>
#include <fstream>

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
    int n=9;
    vector< vector<float> > A(n,vector <float>(n,0));
    vector <float> B(n,0);
     
    for(int i=1; i<n-1; i++){
        B[i]=0.2;
        for(int j=i-1; j<i+2; j++){
           if(j==i)
              A[i][j]=2.01;
           else
              A[i][j]=-1;
        }
    }
    B[0]=40.2;  A[0][0]=2.01; A[0][1]=-1;    
    B[n-1]=200.2; A[n-1][n-2]=-1;   A[n-1][n-1]=2.01;
   
    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
          cout<<A[i][j]<<"\t";
       }cout<<endl;
    }    
    vector <float> X,Y;
    X.push_back(40);
    Y=jordan(A,B);
    for(int i=0; i<Y.size(); i++)
        X.push_back(Y[i]);
    X.push_back(200);
   
    cout<<"value of temperature are "<<endl;
    ofstream myfile;
    myfile.open("fort.10");
    
    for( int m=0; m<n+2; m++){
        myfile<<" "<<m<<"\t\t";    
        cout<<"at x = "<<m<<" is "<<X[m]<<"\n";
        myfile<<X[m]<<endl;
    }
   cout<<endl;  
   myfile.close();
            
  return 0;

}

#include <iostream>
#include <cmath>

using namespace std;

void inverse(double a[3][3], double b[3][3]);

void takemat1(double A[3][3]){

A[0][0]=-30;
A[0][1]=10;
A[0][2]=20;

A[1][0]=10;
A[1][1]=40;
A[1][2]=-50;

A[2][0]=20;
A[2][1]=-50;
A[2][2]=-10;

}


double max(double B[]){
int i,n=3;

double mx=B[0];
for(i=0; i<n; i++){
    if(mx<abs(B[i]))
      mx=B[i];
  }
return mx;

}

void matmul(double A[3][3], double B[3], double C[3]){
 int i,j,k;
 int n=3;

 for(i=0; i<n; i++){
        C[i]=0;
        for(j=0; j<n; j++){
           C[i]=C[i]+A[i][j]*B[j];
        }
  }


}


int main(){

int n=3;
double A[3][3],Ain[3][3],X[3],Xdes[3],temp[3];
double sum1,sum2,f,lemda;

cout.precision(10);

X[0]=1;
X[1]=1;
X[2]=1;

int i,j,k;
takemat1(A);

for(i=0; i<100; i++){
   f=X[0];
   matmul(A,X,Xdes);
   double mx=max(Xdes);

   for(j=0; j<n; j++){
      X[j]=Xdes[j]/mx;
    }

   matmul(A,X,temp);
   sum1=0; sum2=0; 
   for(j=0; j<n; j++){
    sum1=sum1+temp[j]*X[j];
    sum2=sum2+X[j]*X[j];
    }
    lemda=sum1/sum2;
   
  if(abs(f-X[0])<pow(10,-6)){
     cout<<"number = "<<i<<endl;
     for(j=0; j<n; j++)
        cout<<"X'["<<j<<"] = "<<X[j]<<endl;
     cout<<"lemda max = "<<lemda<<endl<<endl;
     break;
   }


}


inverse(A,Ain);
X[0]=1;
X[1]=1;
X[2]=1;  
 
for(i=0; i<100; i++){
   f=lemda;
   matmul(Ain,X,Xdes);
   double mx=max(Xdes);

   for(j=0; j<n; j++){
      X[j]=Xdes[j]/mx;
    }

   matmul(Ain,X,temp);
   sum1=0; sum2=0; 
   for(j=0; j<n; j++){
    sum1=sum1+temp[j]*X[j];
    sum2=sum2+X[j]*X[j];
    }

   lemda=sum2/sum1;
      
   if(abs(f-lemda)<pow(10,-10)){
     cout<<"number = "<<i<<endl;
     for(j=0; j<n; j++)
        cout<<"X'["<<j<<"] = "<<X[j]<<endl;
     cout<<"lemda min = "<<lemda<<endl<<endl;
     break;
   }

}
return 0;
}

void inverse(double a[3][3], double b[3][3]){
    int i,j,k,n=3;
    double c,d;

    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
           if(i==j)
             b[i][j]=1;
           else
             b[i][j]=0;
       }
    }
    for(i=0; i<n; i++){
       if(a[i][i]!=0){
          for(j=i+1; j<n; j++){
             c=a[i][i];
             d=a[j][i];
             for(k=0; k<n; k++){
                b[j][k]=b[j][k]-(b[i][k]*d/c);
                a[j][k]=a[j][k]-(a[i][k]*d/c);
             }
          }
       }
       else{
          for(k=0; k<n; k++){
             for(j=i+1; j<n; j++){ 
               b[i][k]=b[i][k]+b[j][k];
               a[i][k]=a[i][k]+a[j][k];
             }
          }  
       }
       for(j=i+1; j<n; j++){
          c=a[i][i];
          d=a[j][i];
            for(k=0; k<n; k++){
               b[j][k]=b[j][k]-(b[i][k]*d/c);
               a[j][k]=a[j][k]-(a[i][k]*d/c);
            }
       }
    }  
    for(i=n-1; i>0; i--){       
       for(j=i-1; j>=0; j--){   
          c=a[i][i];
          d=a[j][i];
          for(k=n-1; k>=0; k--){ 
             b[j][k]=b[j][k]-(b[i][k]*d/c);
             a[j][k]=a[j][k]-(a[i][k]*d/c);
          }
       }
    } 
    for(i=0; i<n; i++){ 
       for(j=0; j<n; j++){ 
          b[i][j]=b[i][j]/a[i][i];
       }
    }
   
}






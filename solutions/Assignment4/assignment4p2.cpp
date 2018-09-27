#include <iostream>
#include <cmath>

using namespace std;

void inverse(double a[10][10], double b[10][10]);

void takemat1(double A[10][10]){
  int i,j,n=10;

for(i=0; i<n; i++){
   for(j=0; j<n; j++){
     if(i==j)
       A[i][j]=4.0;
     else if((i==j+1) || (j==i+1))
       A[i][j]=2.0;
     else if((i==j+2) || (j==i+2))
       A[i][j]=1.0;
     else 
       A[i][j]=0;    
   }
}


}



double max(double B[]){
int i,n=10;

double mx=B[0];
for(i=0; i<n; i++){
    if(mx<abs(B[i]))
      mx=B[i];
  }
return mx;

}

void matmul(double A[10][10], double B[10], double C[10]){
 int i,j,k;
 int n=10;

 for(i=0; i<n; i++){
        C[i]=0;
        for(j=0; j<n; j++){
           C[i]=C[i]+A[i][j]*B[j];
        }
  }


}


int main(){

int i,j,k,n=10;
double A[10][10],Ain[10][10],X[10],Xdes[10],temp[10];
double sum1,sum2,f,lemda;

cout.precision(8);
for(i=0; i<n; i++){   
       X[i]=1.0;   
}


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
for(i=0; i<n; i++){
       X[i]=1.0;
}


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

   if(abs(f-lemda)<pow(10,-8)){
     cout<<"number = "<<i<<endl;
     for(j=0; j<n; j++)
        cout<<"X'["<<j<<"] = "<<X[j]<<endl;
     cout<<"lemda min = "<<lemda<<endl<<endl;
     break;
   }

}







}

void inverse(double a[10][10], double b[10][10]){

int i,j,k,n=10;
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






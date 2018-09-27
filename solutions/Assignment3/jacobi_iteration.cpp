#include <iostream>
#include<cmath>

using namespace std;
int n=3;
float A[3][3],B[3],X[3];

// function-1 take a matrix
void takemat(){
int i,j;
cout<<"enter the element of A matrix"<<endl;
for(i=0; i<n; i++){ 
for(j=0; j<n; j++){
    cin>>A[i][j]; 
}cout<<endl;
}
cout<<"enter the elements of B"<<endl;
for(i=0; i<n; i++){
cin>>B[i];
}


}

//**************************
int main(){

int i,j;
float sum[3],Y[3];
X[1]=0; X[2]=0; X[3]=0;

takemat();cout<<endl;

/*for(i=0; i<n; i++){
   sum[i]=0; 
   for(j=0; j<n; j++){
     if(i!=j)
       sum[i]=sum[i]+A[i][j];
   }
}

cout<<"sum of diagonally elements "<<endl;
for(i=0; i<n; i++){
    cout<<sum[i]<<endl;
}cout<<endl;*/

    for(i=0; i<50; i++){
       for(j=0; j<n; j++){Y[j]=X[j];}

       X[0]=(B[0]-A[0][1]*Y[1]-A[0][2]*Y[2])/A[0][0];
       X[1]=(B[1]-A[1][0]*Y[0]-A[1][2]*Y[2])/A[1][1];
       X[2]=(B[2]-A[2][0]*Y[0]-A[2][1]*Y[1])/A[2][2];
       
       if(abs(Y[0]-X[0])<pow(10,-7))
          break;
       cout<<"number="<<i<<endl;
       for(j=0; j<n; j++){
          cout<<"value of X("<<j<<") = "<<X[j]<<endl;
       }cout<<endl;
       
       
    } 
  

cout<<"the final values of X are"<<endl;
for(i=0; i<n; i++){
    cout<<"value of X("<<i<<") = "<<X[i]<<endl;
}
return 0;


}

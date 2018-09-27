#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<fstream>

using namespace std;

void show_mat(double mat[5][5]){
 int i,j,n=5;
 for(i=0; i<n; i++){
     for(j=0; j<n; j++){
       cout<<mat[i][j]<<"        ";
    }cout<<endl;
 }
   
}

void matmul(double A[5][5],double B[5][5],double C[5][5]){
    
 int i,j,k,n=5;    
 for(i=0; i<n; i++){
    for(k=0; k<n; k++){
        C[i][k]=0;
        for(j=0; j<n; j++){
           C[i][k]=C[i][k]+A[i][j]*B[j][k];
        }
     }
  }
 
  
}


//***************main program***************************


int main(){

int i,j,k,n,p,q,m;
cout<<"enter the dimension of matrix \n";
cin>>n;
cout<<"n = "<<n<<endl<<endl;
double delta1,delta2,max,temp[5];
double H0[5][5],X[5][5],H[5][5],C[5][5],D[5][5],X4[5][5],D0[5][5];

cout.precision(8);
ofstream myfile;
myfile.open ("jacobi.txt");

  for(i=0; i<n; i++){
     for(j=0; j<n; j++){
         if(i==j+1)
           delta1=1;
         else delta1=0; 
  
         if(i==j-1)
           delta2=1;
         else delta2=0;  

        X[i][j]=(1.0/sqrt(2))*(sqrt(j+1)*delta1+sqrt(j)*delta2);     
     }
  }
 matmul(X,X,C);
 matmul(C,X,D);
 matmul(D,X,X4);

for(i=0; i<n; i++){
   for(j=0; j<n; j++){
      if(i==j)
        H0[i][j]=(j+1.0/2);
      else
        H0[i][j]=0;
   }
}

for(int l=0; l<=10; l++){
    double lemda=0.1*l;
     //cout<<"for lemda = "<<l*0.1<<endl;
    for(i=0; i<n; i++){
       for(j=0; j<n; j++){
          H[i][j]=H0[i][j]+lemda*X4[i][j];
          D0[i][j]=H[i][j];         
          //cout<<H[i][j]<<"      ";
       }//cout<<endl;
    }

    for(m=0; m<100; m++){
 
       max=0;  
       for(i=0; i<n; i++){
          for(j=0; j<n; j++){
             if(i<j){
               if(max<abs(D0[i][j])){
                 max=abs(D0[i][j]); 
                 p=i;
                 q=j;}   
             }
          }
       }

       if(abs(max)<pow(10,-8))
          break;
       //cout<<max<<endl;
      
       //cout<<"p ="<<p<<" q="<<q<<endl;
       double theta, t, c, s;
 
       theta=(D0[q][q]-D0[p][p])/(2*D0[p][q]);

       t=1.0/(abs(theta)+sqrt(pow(theta,2)+1.0));
       if(theta<0)
          t=-t;
       c=1.0/(sqrt(pow(t,2)+1.0));

       s=c*t;
       for(i=0; i<n; i++){
          for(j=0; j<n; j++){
             D[i][j]=D0[i][j];
          }
       }
 
       for(i=0; i<n; i++){
          D[i][p]=c*D0[i][p]-s*D0[i][q];
          D[p][i]=D[i][p];

          D[i][q]=c*D0[i][q]+s*D0[i][p];
          D[q][i]=D[i][q];   
       }

       D[p][q]=0; D[q][p]=0;
  
       D[p][p]=pow(c,2)*D0[p][p]+pow(s,2)*D0[q][q]-2*c*s*D0[p][q];
  
       D[q][q]=pow(s,2)*D0[p][p]+pow(c,2)*D0[q][q]+2*c*s*D0[p][q]; 

       for(i=0; i<n; i++){
          for(j=0; j<n; j++){
             D0[i][j]=D[i][j];
          }
       }
   }  
   
  //for(i=0; i<n; i++){
    //      for(j=0; j<n; j++){
             
      //       cout<<D0[i][j]<<"     ";
        //  }cout<<endl;
       //}cout<<endl;
  myfile<<0.1*l<<" ";
  
  cout<<"energy for lemda ="<<0.1*l<<" :-"; 
  for(i=0; i<n; i++){
     temp[i]=D0[i][i];
    }
   
   for(i=0; i<n; i++){
     sort(temp,temp+5);
     cout<<"  "<<temp[i]; //D0[i][i];
     myfile<<temp[i]<<"    ";  
   }

   myfile<<"\n";
   cout<<endl<<endl;   

  
}
  myfile.close();


}

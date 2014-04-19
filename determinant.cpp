#include <stdio.h> 
#include <math.h> 
#include <iostream>

using namespace std;

float det(float**,int);

float main() 
{ 
int n,i,j,d=0; 
float **ms;
setlocale(LC_ALL,"russian");
do 
{ 
cout<<"Введите размер матрицы:\n"; 
cin>>n; 
} 
while(n<2); 
ms=(float**) calloc(n,sizeof(float*));
for(i=0;i<n;i++)
{
    *(ms+i)=(float*) calloc(n,sizeof(float));
}
for(i=0;i<n;i++) 
for(j=0;j<n;j++) 
{
	cout<<"Введите элемент ["<< i+1<<"] ["<<j+1<<"]: "; 
	cin>>ms[i][j];
} 
for(i=0;i<n;i++) 
{ 
	cout<<endl;
	for(j=0;j<n;j++) 
		cout<<ms[i][j]<<" "; 
} 
d=det(ms,n); 
cout<<"\nОпределитель равен "<<d<<endl; 
system("pause"); 
} 

float det(float**ms,int n) 
{ 
int i,j,z,a,d; 
float q=0; 
float **ms1; 
 if(n==2){q=ms[0][0]*ms[1][1]-ms[0][1]*ms[1][0];} 
  else 
   { 
            ms1=(float**) calloc(n,sizeof(float*));
            for(i=0;i<n;i++)
            {
                *(ms1+i)=(float*) calloc(n,sizeof(float));
            }
       for(i=0;i<n;i++) 
    { 
      for(j=0;j<n-1;j++) 
      for(z=0;z<n;z++) 
         { 
          if(j<i) 
          ms1[z][j]=ms[z][j]; 
          else 
          ms1[z][j]=ms[z][j+1]; 
         } 
    q+=pow(-1.0,i+n+1)*det(ms1,n-1)*ms[n-1][i]; 
     } 
       } 
return q;
}

#include <iostream>
#include <math.h>
using namespace std;

void calculateGaussElimination(void);
int main()
{
    calculateGaussElimination();
    return 0;
}
void calculateGaussElimination(void)
{
    int n;
    float ratio;
    cout<<"enter the number of unknowns"<<endl;
    cin>>n; 
    float data[n][n+1]; 
    float result[n]; 

    cout<<"enter the agumented matrix"<<endl;
    for(int i=1;i<=n;i++){              //i is row and j is column 
       for(int j=1;j<=n+1;j++){
           cin>>data[i][j];
       }
    }

    //gauss elimination calculation
    for(int j=1;j<=n;j++){      // j is column 
        if(data[j][j] == 0){
            cout<<"mathmatical error"<<endl;
            goto last;
        }
        for(int i=1;i<=n;i++){   // i is row 
            if(i > j){
                ratio = data[i][j]/data[j][j];
                for(int k=1;k<=n+1;k++){    //k is column
                   data[i][k]=data[i][k]-ratio*data[j][k];
                }
            }
        }
    }
     
    //Back substitution
    result[n] = data[n][n+1]/data[n][n];    //last result  is stored here 
  
    for(int i=n-1;i>=1;i--){
        result[i] = data[i][n+1];
        for(int j=i+1;j<=n;j++){
            result[i] = result[i] - result[j]*data[i][j];
        }
        result[i] = result[i]/data[i][i];
    }
    
    cout<<"display result"<<endl; 
    for(int i=1;i<=n;i++){              
        cout<<"x["<< i<<"] = "<< result[i]<<endl;
    }
   /*
   //for displaying matrix 
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            cout<<data[i][j]<<"    ";
        }
        cout<<endl;
    }*/
    last:
    cout<<endl;
}
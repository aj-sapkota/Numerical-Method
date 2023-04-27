#include <iostream>
#include <math.h>
using namespace std;

void calculateGaussJordon(void);
void PolynomialCurveFitting(void);
int main()
{
    PolynomialCurveFitting();
    return 0;
}
void PolynomialCurveFitting(void){
    int n,d;
    cout<<"enter number of data and degree of polynomial respectively"<<endl;
    cin>>n>>d;

    float x[n],y[n]; 

    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    
}
void calculateGaussJordon(void)
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
    //gauss jordan calculation
    for(int j=1;j<=n;j++){  //for coloumn
        if(data[j][j] == 0){
            cout<<"Mathmatical error"<<endl;
            goto last;
        }
        for(int i=1;i<=n;i++){   //for row 
            if(i!=j){
                ratio = data[i][j]/data[j][j];
                for(int k=1;k<=n+1;k++){
                    data[i][k] = data[i][k] - ratio*data[j][k];
                }
            }
        }
    }
    //result calculation
     for(int i=1;i<=n;i++){
        result[i] = data[i][n+1]/data[i][i];
        cout<<endl;
    }
    //display result 
    for(int i=1;i<=n;i++){              
        cout<<"x["<< i<<"] = "<< result[i]<<endl;
    }
     
    last:
    cout<<endl;
}
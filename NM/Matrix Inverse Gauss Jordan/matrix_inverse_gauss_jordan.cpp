#include <iostream>
#include <math.h>
using namespace std;

void calculateInverseGaussJordon(void);
int main()
{
    calculateInverseGaussJordon();
    return 0;
}
void calculateInverseGaussJordon(void)
{
    int n;
    float ratio;
    cout<<"enter the number of unknowns"<<endl;
    cin>>n; 
    float data[n][2*n]; 
    float result[n]; 

    cout<<"enter the  matrix"<<endl;
    for(int i=1;i<=n;i++){              //i is row and j is column 
       for(int j=1;j<=n;j++){
           cin>>data[i][j];
       }
    }
    //create Agumented matrix of order n *2n  i.eAX=I with Identity of order n*n
    for(int i=1;i<=n;i++){              //i is row and j is column 
        for(int j=1;j<=n;j++){
            if(i == j){
                data[i][j+n] = 1;
            }
            else{
                data[i][j+n] = 0;
            }
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
                for(int k=1;k<=2*n;k++){
                    data[i][k] = data[i][k] - ratio*data[j][k];
                }
            }
        }
    }
    //result calculation
    for(int i=1;i<=n;i++){
        for(int j=n+1;j<=2*n;j++){
            data[i][j] = data[i][j]/data[i][i];
        }
        cout<<endl;
    }
    //display inverse matrix
    cout<<"inverse matrix"<<endl;
      for(int i=1;i<=n;i++){
        for(int j=1+n;j<=2*n;j++){
            cout<<data[i][j]<<"    ";
        }
        cout<<endl;
    }
    
    
    last:
    cout<<endl;
}
#include <iostream>
#include <math.h>
using namespace std;

void calculateLagrangeInterpolation(void);
int main()
{
    calculateLagrangeInterpolation();
    return 0;
}
void calculateLagrangeInterpolation(void)
{
    int n;
    cout<<"enter the number of data"<<endl;
    cin>>n;
    float x[n],y[n];
    float xp,yp=0,p;  //(xp,yp) yp value which need to find for given xp & p is to store intermediate value 

    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++){
         cout<<"x["<<i<<"]:";cin>>x[i];  cout<<"y["<<i<<"]:";cin>>y[i];
    }

    cout<<"enter the varaible whose correponding variable to be determined"<<endl;
    cin>>xp;
   
    for(int i=0;i<n;i++){
        p=1;                                                            //reset p for every step
        for(int j=0;j<n;j++){
            if(i!=j){
                  p = p *  (xp-x[j])/(x[i]-x[j]);
            }
        }
        yp = yp + p*y[i];
    }
    cout<<"required interpolated value is "<<yp;
}
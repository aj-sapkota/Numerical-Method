#include <iostream>
#include <math.h>
using namespace std; 

void LinearCurveFitting(void);
int main()
{
    LinearCurveFitting();
    return 0;
}
void LinearCurveFitting(void)
{
    int n;
    cout<<"enter number of data"<<endl;
    cin>>n;
    float x[n],y[n];
    float a,b; //linear equation given by y=a+bx

    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++){
         cout<<"x["<<i<<"]:";cin>>x[i];  cout<<"y["<<i<<"]:";cin>>y[i];
    }

    //intialize sum parameters 
    float sumx = 0 ,sumy = 0 , sumxy = 0, sumx2 = 0;
    //calculate required sum
    for(int i=0;i<=n;i++){
        sumx = sumx +x[i];
        sumy = sumy +y[i];
        sumx2 = sumx2 +x[i]*x[i];
        sumxy = sumxy +x[i]*y[i];
    }
    //solve the equations
    b = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    a = (sumy - b*sumx)/n;
    
    cout<<"requied values a and b are "<<a<<" & "<<b<<"  respectively"<<endl;
    cout<<"in the linear form y="<<a<<"+"<<b<<"x"<<endl;
}
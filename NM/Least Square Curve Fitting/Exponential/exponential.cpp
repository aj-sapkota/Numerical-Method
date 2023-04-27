#include <iostream>
#include <math.h>
using namespace std; 

void ExponentialCurveFitting(void);
int main()
{
    ExponentialCurveFitting();
    return 0;
}
void ExponentialCurveFitting(void)
{
    int n;
    cout<<"enter number of data"<<endl;
    cin>>n;
    float x[n],y[n];
    float a,b; //linear equation given by logy = loga+b*logx
    float A,B; // linear equation for taransfomation Y=A+BX

    cout<<"enter the data"<<endl;
    for(int i=0;i<n;i++){
        cout<<"x["<<i<<"]:";cin>>x[i];  cout<<"y["<<i<<"]:";cin>>y[i];
    }

    //intialize sum parameters 
    float sumx = 0 ,sumy = 0 , sumxy = 0, sumx2 = 0;
    //calculate required sum
    for(int i=0;i<n;i++){
        sumx = sumx +log(x[i]); 
        sumy = sumy +log(y[i]);
        sumx2 = sumx2 +log(x[i])*log(x[i]);
        sumxy = sumxy +log(x[i])*log(y[i]);
    }
  
    //solve the equations
    B = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    A = (sumy - B*sumx)/n;
    //transformation
    a =exp(A);
    b =B;
    cout<<A<<"  "<<B<<endl;
    cout<<"requied values a and b are "<<a<<" & "<<b<<"  respectively"<<endl;
    cout<<"in exponential form y="<<a<<"*x^"<<b<<endl;
}
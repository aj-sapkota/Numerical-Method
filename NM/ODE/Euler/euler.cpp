#include <iostream>
#include <math.h>
using namespace std;

#define f(x,y) exp(x)+y

void calculateEuler(void);
int main()
{
     cout<<"for the function f(x,y) = exp(x)*y"<<endl;
    calculateEuler();
    return 0;
}
void calculateEuler(void)
{
    int n;
    float x0,y0;
    float xn,yn;
    cout<<"enter number of steps and intial conditions(x0,y0)"<<endl;
    cout<<"n :";cin>>n;
    cout<<"x0 :";cin>>x0;
    cout<<"y0 :";cin>>y0;

    cout<<"enter calulation point xn"<<endl;
    cout<<"xn :";cin>>xn;

     cout<<"\nx0\ty0\tslope\tyn\n";
   
    float stepsize = (xn-x0)/n;
    for(int i=0;i<n;i++){

        float fxy = f(x0,y0);
        yn = y0+ stepsize * fxy;
        cout<< x0<<"\t"<< y0<<"\t"<< fxy<<"\t"<< yn<< endl;
        y0 = yn;
        x0 = x0+stepsize;

    }
    cout<<"required value is "<<yn;
}
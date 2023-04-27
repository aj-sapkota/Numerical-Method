#include <iostream>
#include <math.h>
using namespace std;

#define f(x) x*x-2*x
void trapezoidal(void);
int main()
{
    cout<<"for the function f(x) = x*x-2*x"<<endl;
    trapezoidal();
}
void trapezoidal(void)
{
    int n;
    float a,b;
    cout<<"enter total interval and limit of intergration"<<endl;
    cout<<"n :";cin>>n;
    cout<<"a :";cin>>a;
    cout<<"b :";cin>>b;
     
    float stepsize,sum;
    stepsize = (b-a)/n ;
    sum = f(a)+f(b);
    
     cout<<"y(0): "<<f(a)<<"   "<<endl;
    for(int i=1;i<n;i++)
    {
        float y = a+ i *stepsize;
        cout<<"y("<<i<<"): "<<f(y)<<"   "<<endl;
        sum = sum + 2*f(y);
    }
    cout<<"y("<<n<<"): "<<f(b)<<"   "<<endl;
    sum = sum * stepsize/2;
    cout<<"integration in given interval is "<<sum;


}
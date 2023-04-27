#include <iostream>
#include <math.h>
using namespace std;

#define f(x,y) cos(x)+exp(y)

void calculateRK4(void);
int main()
{
    cout<<"for the function f(x,y) = cos(x)+exp(y)"<<endl;
    calculateRK4();
    return 0;
}
void calculateRK4(void)
{
    int n;
    float x0,y0;
    float xn,yn;
    float k1,k2,k3,k4;
    float  xa, ya; // temp variable 
    float slope1,slope2,slope3,slope4;
    
    cout<<"enter number of steps and intial conditions(x0,y0)"<<endl;
    cout<<"n :";cin>>n;
    cout<<"x0 :";cin>>x0;
    cout<<"y0 :";cin>>y0;

    cout<<"enter calulation point xn"<<endl;
    cout<<"xn :";cin>>xn;

    float stepsize = (xn-x0)/n;
    
    cout<<"\nx0\ty0\tyn\n";
    cout<<"------------------------------\n";
    for(int i=0;i<n;i++){
        
        slope1 = f(x0,y0);   
        k1 = stepsize * slope1;

        xa = x0+stepsize/2; ya = y0+k1/2;
        slope2 = f(xa,ya);
        k2 = stepsize * slope2;

        xa = x0+stepsize/2; ya = y0+k2/2;
        slope3 = f(xa,ya);
        k3 = stepsize * slope3;

        xa = x0+stepsize; ya = y0+k3;
        slope4 = f(xa,ya);
        k4 = stepsize * slope4;


        yn = y0 + (k1+2*k2+2*k3+k4)/6;
        cout<< x0<<"\t"<< y0<<"\t"<< yn<< endl;
        y0 = yn;
        x0 = x0+stepsize;

    }
    cout<<"required value is "<<yn;
}
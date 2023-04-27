#include <iostream>
#include <math.h>
using namespace std;

#define f(x,y,z) cos(x)*z+1
#define g(x,y,z) -x*exp(y)

void SimulatneousRK4(void);
int main()
{
    cout<<"for the function f(x,y,z) = cos(x)*z+1 and g(x,y,z) = -x*exp(y) "<<endl;
    SimulatneousRK4();
    return 0;
}
void SimulatneousRK4(void)
{
    int n;
    float x0,y0,z0;;
    float xn,yn,zn;
    float k1,k2,k3,k4; float l1,l2,l3,l4;
    float  xa, ya,za; // temp variable 
    float slope1a,slope2a,slope3a,slope4a; float  slope1b,slope2b,slope3b,slope4b;
    
    cout<<"enter number of steps and intial conditions(x0,y0)"<<endl;
    cout<<"n :";cin>>n;
    cout<<"x0 :";cin>>x0;
    cout<<"y0 :";cin>>y0;
    cout<<"z0 :";cin>>z0;

    cout<<"enter calulation point xn"<<endl;
    cout<<"xn :";cin>>xn;

    float stepsize = (xn-x0)/n;
    
    cout<<"\nx0\tz0\tyn\tzn\n";
    cout<<"------------------------------\n";
    for(int i=0;i<n;i++){
        
        slope1a = f(x0,y0,z0);  slope1b = g(x0,y0,z0);    
        k1 = stepsize * slope1a;
        l1 = stepsize * slope1b;

        xa = x0+stepsize/2; ya = y0+k1/2 ; za =  z0+l1/2 ;
        slope2a = f(xa,ya,za); slope2b = g(xa,ya,za);
        k2 = stepsize * slope2a;
        l2 = stepsize * slope2b;

        xa = x0+stepsize/2; ya = y0+k2/2; za =  z0+l2/2 ;
        slope3a = f(xa,ya,za); slope3b = g(xa,ya,za);
        k3 = stepsize * slope3a;
        l3 = stepsize * slope3b;

        xa = x0+stepsize; ya = y0+k3;  za = z0+l3; 
        slope4a = f(xa,ya,za);   slope4b = g(xa,ya,za);
        k4 = stepsize * slope4a;
        l4 = stepsize * slope4b;


        yn = y0 + (k1+2*k2+2*k3+k4)/6;
        zn = z0 + (l1+2*l2+2*l3+l4)/6;
        cout<< x0<<"\t"<< y0<<"\t"<< yn<<"\t"<< zn <<endl;
        y0 = yn;  z0 = zn;
        x0 = x0+stepsize;

    }
    cout<<"for the function f(x,y,z) = x+y+z  and g(x,y,z) 1+y+z"<<endl;
    cout<<"required value   yn:"<<yn<<" & zn:"<<zn;
}
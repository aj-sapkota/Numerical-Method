#include <iostream>
#include <math.h>
using namespace std;

#define f(x) 1+log(x)
void Simpsons3by8(void);
int main()
{
      cout<<"for the function f(x) = 1+log(x)"<<endl;
    Simpsons3by8();
    return 0;
}
void Simpsons3by8(void)
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
        if(i%3 == 0){
            sum = sum + 2*f(y);
        }
        else{
            sum = sum + 3*f(y);
        }   
        cout<<"y("<<i<<"): "<<f(y)<<"   "<<endl;
    }
       cout<<"y("<<n<<"): "<<f(b)<<"   "<<endl;
    sum = sum * stepsize *3/8;
    cout<<"integration in given interval is "<<sum;


}
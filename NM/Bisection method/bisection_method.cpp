#include <iostream>
#include <math.h>
using namespace std;

#define f(x) x*x - 10*log(x)

void calculateBisection();
int main(){
    cout<<"for the function f(x) =  x*x - 10log(x)"<<endl;
    calculateBisection();
    return 0;
}
void calculateBisection(void)
{
    float a,b;
    float  x1,x2;
    float x;
    float e;
     
    
    cout<<"enter the interval for root and error tolerable "<<endl;
    cin>>x1>>x2>>e;
     
    float fx1= f(x1);
    float  fx2= f(x2);

    cout<<"\na\tb\tx\tf(x)\n";

    if(fx1*fx2 >0) {
       cout<<"root doesn't present in between these interval"<<endl;
       goto last;
    }
    else {
        if(f(x1)<0){
            a = x1;
            b = x2;
        }
        else{
            a = x2;
            b = x1;
        }
        do{
            x = (a + b)/2;
            if(f(x)>0){
                 b = x;
            }
            else{
                a = x;
             
            }
            cout<< a<<"\t"<< b<<"\t"<< x<<"\t"<< f(x)<< endl;
        }while(fabs(f(x))>e);  
    }
    cout<<"root between the given interval is "<<x;
    
    last:
    cout<<endl;
}


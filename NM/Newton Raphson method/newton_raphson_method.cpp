#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define f(x)  x*sin(x)+cos(x)

//derivative
#define fd(x) x*cos(x)-sin(x)

void calculateNewtonRaphson(void);
int main()
{
     cout<<"for the function f(x) =  x*sin(x)+cos(x)"<<endl;
    calculateNewtonRaphson();
    return 0;
}

void calculateNewtonRaphson(void){
    setprecision(6);
    float x0,e;
    float x; 
    int totaliteration,count = 0;
    cout<<"enter the intial guess and error tolerable"<<endl;
    cin>>x0>>e;
   

   
    cout<<"enter the maximum iteration"<<endl;
    cin>>totaliteration; 
       cout<<"\ni\t\tXi\t\tf(Xi)\t\tf'(Xi)\t\tXi+1\t\n";
    do{
        if(fd(x0) == 0){
            cout<<"Mathmatical error"<<endl;
            goto last;
        }
        float fx0 = f(x0); float fdx0 = fd(x0); 
        
        
        x = x0 -fx0/fdx0;
          cout<< count<<"\t\t"<< x0<<"\t\t"<<f(x0)<<"\t\t"<<fd(x0)<<"\t\t"<< x<<endl;
        x0 = x;
        count++;
        if(count  > totaliteration){
            cout<<"exceed limit of iteration by user"<<endl;
            goto last;
        }
    }while(fabs(f(x))>e);

    cout<<"required root is "<<x<<endl;
    last:
    cout<<endl;
    
}
#include <iostream>
#include <math.h>
using namespace std;

#define f(x) exp(x)-3

void calculateSecant(void);
int main()
{
    cout<<"for the function f(x) = exp(x)-3 "<<endl;
    calculateSecant();
    return 0;
}
void calculateSecant(void)
{
    float a,b,e; 
    float x1,x2;
    float x;
    double fbs;
    int totaliteration,count = 0;
    
    cout<<"enter the continous interval and error tolerable"<<endl;
    cin>>a>>b>>e;

    cout<<"enter the maximum iteration"<<endl;
    cin>>totaliteration; 
    
    float fa= f(a), fb = f(b);
    cout<<"\ni\t\ta\t\tb\t\tc\t\tf(c)\t\n";

    if(fa*fb >0){
        cout<<"cannot be converge within given interval"<<endl;
        goto last;
    }
    else{
        if(f(a)<0){
            x1 =a; x2 =b;
        }
        else{
            x1 = b; x2 = a;
        }
         
        do{
            if(f(x1) == f(x2)){
                cout<<"mathmatical error"<<endl;
                goto last;
            }
            float f1 = f(x1); float f2 = f(x2);
            x = x1 - ((x2 - x1) * f1/(f2-f1));
              cout<< count<<"\t\t"<< x1<<"\t\t"<<x2<<"\t\t"<<x<<"\t\t"<< f(x)<<endl;
            x1 = x2;
            x2 = x;
            count++;
            if(count  > totaliteration){
               cout<<"iteration error"<<endl;
               goto last;   
            }
            fbs = fabs(f(x));
        }while(fbs>e);
    }
    cout<<"Required root is "<<x;
    last:
    cout<<endl;

}
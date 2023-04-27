#include <iostream>
#include <math.h>
using namespace std;

void PowerMethod(void);
int main()
{
    PowerMethod();
    return 0;
}
void PowerMethod()
{
    int n,count =1;;float e; 
    cout<<"enter the order of square matrix and error tolerance"<<endl;
    cin>>n>>e;

    float data[n][n];
    cout<<"enter the data of square matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>data[i][j]; 
        }
    }

    float x[n],x_new[n]; 
    float lamda_old=1,lamda_new;
    float temp;             //temp variable
    //read intial eigen vector 
    for(int i=0;i<n;i++)
	{
	    cout<<"x["<< i<<"]= "; cin>>x[i];
	}

    up:  //repeate the process

    //multiply the matrix
    for(int i=0;i<n;i++){
        temp = 0.0;
        for(int j=0;j<n;j++){
            temp = temp + data[i][j]*x[j];
        }
        x_new[i] = temp;
    }
    
    //replace xby x_new
    for(int i=0;i<n;i++)
	{
	    x[i] = x_new[i];
	}
    //finding largest number 
    lamda_new = fabs(x[0]);
    for(int i=1;i<n;i++)
    {
   	    if(fabs(x[i])>lamda_new)
   	    {
   	        lamda_new = fabs(x[i]);
   	    }
    }
    //normalization by x_new
    for(int i=0;i<n;i++)
	{
	    x[i] = x[i]/lamda_new;
	}
    //displaying 
    /* Display */
    cout<< endl<< endl<<"Count-"<<count<< endl;
    cout<<"Eigen Value = "<< lamda_new<< endl;
    cout<<"Eigen Vector: "<< endl;
    cout<<"[";
    for(int i=0;i<n;i++)
    {
     	cout<< x[i]<<"\t";
    }
    cout<<"]"<<endl;
        
    //checking 
    if(fabs(lamda_new-lamda_old)>e)
	{
		lamda_old=lamda_new;
	    count++;
    	goto up;
	}


}
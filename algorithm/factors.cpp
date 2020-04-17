//因子个数

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                do
                {
                    n/=i;
                }while(n%i==0);
                count++;
            }
        }
        if(n!=1)
           count++;
        cout<<count<<endl;
    }
    return 0;
}
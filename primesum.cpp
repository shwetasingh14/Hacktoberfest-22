#include<bits/stdc++.h>
using namespace std;

int prime(int);
int * primeSum(int A)
{
    int *arr;
    arr = new int[2];
    int i;
    if(A%2==0)
    {
        for(i=2;i<=A/2;i++)
        {
            if(prime(i) && prime(A-i) && (i+(A-i)== A))
            {
                arr[0]=i;
                arr[1]=A-i;
                return arr;
            }
        }
    }
    return arr;
}


int prime(int A)
{
    int i, upl=(int)sqrt(A);
    if(A>1)
    {
        for(i=2;i<=upl;i++)
        {
            if(A%i==0)
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

int main()
{
    int A,n;
    int *a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>A;
        a=primeSum(A);
        cout<<a[0]<<" ";
        cout<<a[1]<<endl;
    }
    return 0;
}
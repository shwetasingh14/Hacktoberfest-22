#include<bits/stdc++.h>
#define ll long long
#define p(x) setprecision(x) 
#define pi 3.1415926536
using namespace std;
int isthisprime[1000001];
void sieve(){
    int max=1000000;
    for (int i = 1; i <=max; i++)
    {
        isthisprime[i]=1;
    }
    isthisprime[0]=0;
    isthisprime[1]=0;

    for (int i = 2; i*i <=max; i++)
    {
        if(isthisprime[i]){
            for (int j=i*i; j<=max; j+=i)
            {
                isthisprime[j]=0;
            }
            
        }
    }
    
    
}
int main(){
sieve();
int n;
cin>>n;
if(isthisprime[n]){
    cout<<n<<" is a prime"<<endl;
}
else{
    cout<<n<<" is not a prime"<<endl;
}
return 0;
}
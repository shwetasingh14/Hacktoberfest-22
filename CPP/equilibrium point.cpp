#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i=0;
    
    int j=n-1;
                    long sumi=arr[i];
            long sumj=arr[j];
            int flag=0;
            int ans=1;
            
            
            if(n==1)
            return 1;
            for(int k=0;k<n-1;k++)
            {
                if(sumi==sumj)
                {
                    
                    if(i==j-2)
                    {
                        ans=i+2;
                        flag=1;
                        break;
                    }
                    else
                    {
                        sumi=sumi+arr[i];
                        i++;
                    }
                    
                }
                else if(sumi>sumj)
                {
                    j--;
                    sumj=sumj+arr[j];
                    
                    
                }
                else
                {
                    i++;
                    sumi=sumi+arr[i];
                    
                }
            }
            if(flag==1)
            return ans;
            else
            return -1;
        }
}

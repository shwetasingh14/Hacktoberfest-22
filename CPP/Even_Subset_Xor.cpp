#include<iostream>
//#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int count=1;
        cout<<0<<" ";
       
           for(int j=3;;j++)
           {
               int i=j;
            
               if(count!=n)
               {
                    int c=0;
                    do
                    {
                        if(i%2==1)
                        c++;
                        i=i/2;
                        
                    } while (i!=0);

                    if(c%2==0)
                    {
                        cout<<j<<" ";
                        count++;
                    }
               }
               else
               break;
            
               
           }
        
        cout<<"\n";
    }
  
}

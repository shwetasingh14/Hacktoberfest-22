int main()
{
    int a[100],num,strt,end,mid,len,pos,find=0,t=0;
    printf("Enter length of array:");
    scanf("%d",&len);
    for(int i=0;i<len;i++)
    {
        printf("Array[%d]:",i);
        scanf("%d",&a[i]);
    }
    for(int i=0;i<len-1;i++) 
    {               
        int s=0;
        for(int j=0;j<=len-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
                s=1;
            }
        }
        t++;
        if(s==0)
        {
            printf("\nthe loop has executed %d times",t);
            break;
        }
        
    }
    for(int i=0;i<len;i++)
    {
        printf("\n %d index had %d value",i,a[i]);
    }
    printf("Enter number to search:");
    scanf("%d",&num);
    strt=0;
    end=len-1;
    while(strt<=end)
    {
        mid=(strt+end)/2;
        if(num>a[mid])
        {
            strt=mid+1;
        }
        else if(num<a[mid])
        {
            end=mid-1;
        }
        else if(num==a[mid])
        {
            pos=mid;
            find++;
            break;
        }
        
    }
    if(find==0)
    printf("Item not found");
    else
    printf("Item %d found at position %d",num,pos+1);
    
    return 0;
}


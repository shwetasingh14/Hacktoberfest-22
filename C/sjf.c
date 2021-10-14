
#include <stdio.h>
int main()
{
    int process;
    printf("Enter number of process: ");
    scanf("%d",&process);
    
    int at[30],bt[30],ct[30],tat[30],wt[30],rt[30],s,e=0,p,bt2[20];
    float w=0,t=0;
    float avgwt=0,avgtat=0;
    
    printf("Enter Arrival Time: ");
    for(int i=0;i<process;i++)
    {
        scanf("%d",&at[i]);
    }
        
    printf("Enter Burst Time: ");
    for(int i=0;i<process;i++)
    {
        scanf("%d",&bt[i]);  
        bt2[i] = bt[i];
    }

        
    bt[9] = 9999;
  for (int c =0;c!=process;c++)
    {
      s=9;
      for (int i=0; i<process; i++)
	{
	  if (at[i]<=e && bt[i]<bt[s] && bt[i]>0)
	    {
	      s=i;
	    }
	}
      rt[s] = e;
      e += bt[s];
      ct[s] = e;
      tat[s] = ct[s] - at[s];
      wt[s] = tat[s] - bt2[s];
      w = w + wt[s];
      t = t + tat[s];
      bt[s] = 0;
    }
        
    printf("AT\tBT\tCT\tTAT\tWT\tRT\n");
  
    for(int i=0;i<process;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d",at[i],bt2[i],ct[i],tat[i],wt[i],rt[i]);
        printf("\n");
    }
    avgwt = w/process;
    avgtat = t/process;
  
    printf("Average waiting time: %f\n",avgwt);
    printf("Average turn around time: %f",avgtat);

    return 0;
}

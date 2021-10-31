#include<stdio.h>
int main() {
     int st[10],bt[10],wt[10],tt[10],n,tq;
     int i,count=0,s1=0,s2=0,temp,sq=0;
     float awt=0.0,att=0.0; 
     printf("Enter no.of processes:");
     scanf("%d",&n);
     printf("Enter the burst times :");
     for(i=0;i<n;i++) {
         scanf("%d",&bt[i]);
         st[i]=bt[i];
     }
     printf("Enter the time quantum:");
     scanf("%d",&tq);
     while(1) {
         for(i=0,count=0;i<n;i++) {
           temp=tq;
           if(st[i]==0) {
           count++;
           continue;
           }
           if(st[i]>tq)
           st[i]=st[i]-tq;
           else
           if(st[i]>=0) {
           temp=st[i];
           st[i]=0;
         }
         sq=sq+temp;
         tt[i]=sq;
     }
     if(n==count)
        break;
     }
     for(i=0;i<n;i++) {
         wt[i]=tt[i]-bt[i];
         s1=s1+wt[i];
         s2=s2+tt[i];
     }
     awt=(float)s1/n;
     att=(float)s2/n;
     printf("\nProcess \tBurst time\t Waiting time \tTurnaround time");
     for(i=0;i<n;i++)
     printf("\np%d\t\t %d\t\t %d\t\t %d\n ",i+1,bt[i],wt[i],tt[i]);
     printf("\nAWT : %f \nATT : %f",awt,att);
}

/* output:

Enter no.of processes:3
Enter the burst times :4 6 3
Enter the time quantum:2

Process 	Burst time	 Waiting time 	Turnaround time
p1		 4		 4		 8
 
p2		 6		 7		 13
 
p3		 3		 8		 11
 
AWT : 6.333333 
ATT : 10.666667
*/

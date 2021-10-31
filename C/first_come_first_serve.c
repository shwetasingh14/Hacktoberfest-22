// fcfs program of Operating Systems
#include <stdio.h>
int main() {
    int i,p,bt[10],wt[10],tt[10];
    float n,s1,s2,awt,att;
    printf("\nEnter the no.of processes : ");
    scanf("%f",&n);
    printf("\nEnter the burst times : ");
    for(i=0;i<n;i++) {
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(i=0;i<n+1;i++) {
        wt[i+1]=bt[i]+wt[i];
    }
    printf("\n\tPROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME");
    for(i=0;i<n;i++) {
        tt[i] = bt[i]+wt[i];
        printf("\n\tp%d \t\t %d \t\t %d \t\t %d",i+1,bt[i],wt[i],tt[i]);
    }
    printf("\n");
    s1=0;
    for(i=0;i<n;i++) {
        s1+=wt[i];
    }
    awt = s1/n;
    s2=0;
    for(i=0;i<n;i++) {
        s2+=tt[i];
    }
    att = s2/n;
    printf("\n \t\t\t\t\t Average Waiting Time:%0.2f \t Average Turnaround Time:%0.2f",awt,att);
}


/* output:


Enter the no.of processes : 3
Enter the burst times : 13 8 83

	PROCESS 	 BURST TIME 	 WAITING TIME 	 TURNAROUND TIME
	p1 		        13 		 0 	    13
	p2 		        8 		 13 	    21
	p3 		        83 		 21 	    104

Average Waiting Time:11.33 	 Average Turnaround Time:46.00

*/

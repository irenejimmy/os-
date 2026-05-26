#include<stdio.h>

struct p{
    int pid,at,bt,ct,tat,wt;
}P[10],t;

int main(){
    int n,i,j,time=0;
    
    printf("Enter no of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        P[i].pid=i+1;

        printf("AT and BT of P%d: ",P[i].pid);
        scanf("%d%d",&P[i].at,&P[i].bt);
    }

    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(P[j].at>P[j+1].at){
                t=P[j];
                P[j]=P[j+1];
                P[j+1]=t;
            }

    for(i=0;i<n;i++){
        if(time<P[i].at)
            time=P[i].at;

        P[i].ct=time+P[i].bt;
        P[i].tat=P[i].ct-P[i].at;
        P[i].wt=P[i].tat-P[i].bt;

        time=P[i].ct;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        P[i].pid,P[i].at,P[i].bt,
        P[i].ct,P[i].tat,P[i].wt);

    return 0;
}

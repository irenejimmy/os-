#include<stdio.h>

struct p{
    int pid,bt,wt,tat;
}P[20],t;

int main(){
    int n,i,j,time=0;
    float awt=0,atat=0;

    printf("Enter no of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        P[i].pid=i+1;
        printf("BT of P%d: ",i+1);
        scanf("%d",&P[i].bt);
    }

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(P[i].bt>P[j].bt){
                t=P[i];
                P[i]=P[j];
                P[j]=t;
            }

    for(i=0;i<n;i++){
        P[i].wt=time;
        time+=P[i].bt;
        P[i].tat=time;

        awt+=P[i].wt;
        atat+=P[i].tat;
    }

    printf("\nPID\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",
        P[i].pid,P[i].bt,P[i].wt,P[i].tat);

    printf("\nAverage WT = %.2f",awt/n);
    printf("\nAverage TAT = %.2f",atat/n);

    return 0;
}

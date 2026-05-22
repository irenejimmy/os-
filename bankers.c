#include <stdio.h>

int main() {
    int P,R,i,j,k,count=0,found;
    scanf("%d%d",&P,&R);

    int alloc[P][R],max[P][R],need[P][R],avail[R],work[R],finish[P],safe[P];

    for(i=0;i<P;i++)
        for(j=0;j<R;j++) scanf("%d",&alloc[i][j]);

    for(i=0;i<P;i++)
        for(j=0;j<R;j++){
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }

    for(i=0;i<R;i++){ 
        scanf("%d",&avail[i]); 
        work[i]=avail[i]; 
    }

    for(i=0;i<P;i++) 
        finish[i]=0;

    while(count<P){
        found=0;

        for(i=0;i<P;i++)
            if(!finish[i]){

                for(j=0;j<R && need[i][j]<=work[j];j++);

                if(j==R){
                    for(k=0;k<R;k++) 
                        work[k]+=alloc[i][k];

                    safe[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }

        if(!found){
            printf("Not Safe");
            return 0;
        }
    }

    printf("Safe sequence: ");
    for(i=0;i<P;i++) 
        printf("P%d ",safe[i]);

    return 0;
}

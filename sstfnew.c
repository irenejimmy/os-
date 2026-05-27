#include <stdio.h>
#include <stdlib.h>

void sstf(int req[], int n, int head) {

    int visited[100] = {0};
    int total = 0, pos, i, j, min, dist, index;

    pos = head;

    printf("\nSSTF Seek Sequence: %d", pos);

    for(i = 0; i < n; i++) {

        min = 9999;
        index = -1;

        for(j = 0; j < n; j++) {

            if(!visited[j]) {

                dist = abs(pos - req[j]);

                if(dist < min) {

                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += min;
        pos = req[index];

        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);
}

int main() {

    int n, head, req[100], i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sstf(req, n, head);

    return 0;
}

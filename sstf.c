#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, h, r[20], v[20] = {0};
    int i, j, pos, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &r[i]);

    printf("Enter initial head position: ");
    scanf("%d", &h);

    pos = h;

    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < n; i++) {
        int min = 9999, idx = -1;

        for(j = 0; j < n; j++) {
            if(!v[j] && abs(pos - r[j]) < min) {
                min = abs(pos - r[j]);
                idx = j;
            }
        }

        v[idx] = 1;
        total += min;
        pos = r[idx];

        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}

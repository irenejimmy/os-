#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n) {
    int i, j, t;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int n, h, r[20], l[20], ri[20];
    int i, lc = 0, rc = 0;
    int pos, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &r[i]);

    printf("Enter initial head position: ");
    scanf("%d", &h);

    for(i = 0; i < n; i++) {
        if(r[i] < h)
            l[lc++] = r[i];
        else
            ri[rc++] = r[i];
    }

    sort(l, lc);
    sort(ri, rc);

    pos = h;

    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < rc; i++) {
        total += abs(pos - ri[i]);
        pos = ri[i];
        printf(" -> %d", pos);
    }

    for(i = lc - 1; i >= 0; i--) {
        total += abs(pos - l[i]);
        pos = l[i];
        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);

    return 0;
}

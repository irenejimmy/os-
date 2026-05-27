#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {

    int i, j, temp;

    for(i = 0; i < n - 1; i++) {

        for(j = i + 1; j < n; j++) {

            if(arr[i] > arr[j]) {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void look(int req[], int n, int head) {

    int left[100], right[100];
    int l = 0, r = 0;
    int total = 0, pos, i;

    for(i = 0; i < n; i++) {

        if(req[i] < head)
            left[l++] = req[i];
        else
            right[r++] = req[i];
    }

    sort(left, l);
    sort(right, r);

    pos = head;

    printf("\nLOOK Seek Sequence: %d", pos);

    for(i = 0; i < r; i++) {

        total += abs(pos - right[i]);
        pos = right[i];

        printf(" -> %d", pos);
    }

    for(i = l - 1; i >= 0; i--) {

        total += abs(pos - left[i]);
        pos = left[i];

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

    look(req, n, head);

    return 0;
}

#include <stdio.h>

int main() {
    int ref[50], frame[10], time[10];
    int n, f, i, j, pos = 0, min, cnt = 0;
    int hit, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == ref[i]) {
                hit = 1;
                time[j] = ++cnt;
                break;
            }
        }

        if(!hit) {
            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = ref[i];
            time[pos] = ++cnt;
            faults++;
        }

        printf("%d\t", ref[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nPage Faults = %d", faults);
    printf("\nPage Hits = %d", n - faults);

    return 0;
}

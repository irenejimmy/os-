#include <stdio.h>

int main() {
    int ref[50], frame[10];
    int n, f, i, j, k, pos, far, hit, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == ref[i]) {
                hit = 1;
                break;
            }
        }

        if(!hit) {
            pos = -1;

            for(j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) {
                far = -1;

                for(j = 0; j < f; j++) {
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == ref[k])
                            break;
                    }

                    if(k > far) {
                        far = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = ref[i];
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

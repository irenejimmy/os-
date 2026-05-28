#include <stdio.h>
#define MAX 50

void lru(int pages[], int n, int frames)
{
    int frame[MAX], time[MAX];
    int i, j, counter = 0;
    int faults = 0, hits = 0;

    for(i = 0; i < frames; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for(i = 0; i < n; i++)
    {
        int hit = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                hit = 1;
                hits++;
                counter++;
                time[j] = counter;
                break;
            }
        }

        if(hit == 0)
        {
            int pos = 0;

            for(j = 1; j < frames; j++)
            {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        printf("\nPage %d --> ", pages[i]);

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if(hit)
            printf("Hit");
        else
            printf("Miss");
    }

    printf("\nTotal Page Faults = %d", faults);
    printf("\nTotal Page Hits = %d\n", hits);
}

int main()
{
    int pages[MAX], n, frames, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page sequence:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    lru(pages, n, frames);

    return 0;
}

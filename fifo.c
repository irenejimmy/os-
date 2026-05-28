#include <stdio.h>
#define MAX 50

void fifo(int page[], int n, int frames)
{
    int frame[MAX], index = 0;
    int i, j, hit, faults = 0, hits = 0;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for(i = 0; i < n; i++)
    {
        hit = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == page[i])
            {
                hit = 1;
                hits++;
                break;
            }
        }

        if(hit == 0)
        {
            frame[index] = page[i];
            index = (index + 1) % frames;
            faults++;
        }

        printf("\nPage %d --> ", page[i]);

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

    fifo(pages, n, frames);

    return 0;
}

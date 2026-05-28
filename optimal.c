#include <stdio.h>

#define MAX 50

void optimal(int pages[], int n, int frames)
{
    int frame[MAX];
    int i, j, k;
    int faults = 0, hits = 0;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for(i = 0; i < n; i++)
    {
        int hit = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                hit = 1;
                hits++;
                break;
            }
        }

        if(hit == 0)
        {
            int pos = -1, farthest = i + 1;

            for(j = 0; j < frames; j++)
            {
                int found = 0;

                for(k = i + 1; k < n; k++)
                {
                    if(frame[j] == pages[k])
                    {
                        found = 1;

                        if(k > farthest)
                        {
                            farthest = k;
                            pos = j;
                        }

                        break;
                    }
                }

                if(found == 0)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
                pos = 0;

            frame[pos] = pages[i];
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

    optimal(pages, n, frames);

    return 0;
}

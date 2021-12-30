#include <stdio.h>
#include <malloc.h>
void main()
{
    int x, i, j, pos, temp, * bt, * wt, * tat, * p, * a, * b;
    float avgwt = 0, avgtat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &x);
    p = (int*)malloc(x * sizeof(int));
    bt = (int*)malloc(x * sizeof(int));
    wt = (int*)malloc(x * sizeof(int));
    tat = (int*)malloc(x * sizeof(int));
    a = (int*)malloc(x * sizeof(int));
    b = (int*)malloc(x * sizeof(int));
    printf("\n Enter the burst time for each process \n");
    for (i = 0; i < x; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        printf(" Arrival time for P%d : ", i);
        scanf("%d", &a[i]);
        p[i] = i;
    }

    for (i = 0; i < x; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
            {
                pos = j;
            }
        }

        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    int s = 0;
    wt[0] = 0;
    tat[0] = bt[0];
    s = bt[0];
    avgwt += wt[0];
    avgtat += tat[0];

    int q = 0;
    int qq = 1;
    for (; qq < x;)
    {
        for (i = qq; i < x; i++)
        {
            if (a[i] <= s)
            {
                b[q] = i;
                q++;
                qq = i + 1;
            }
        }
        for (i = 0; i < q; i++)
        {
            pos = i;
            for (j = i + 1; j < q; j++)
            {
                if (bt[b[j]] < bt[b[pos]])
                {
                    b[pos] = b[j];
                }
            }
            temp = b[i];
            b[i] = b[pos];
            b[pos] = temp;
        }
        for (i = 0; i < q; i++)
        {
            wt[b[i]] = s - a[b[i]];
            s += bt[b[i]];
            tat[b[i]] = wt[b[i]] + bt[b[i]];
            avgwt += wt[b[i]];
            avgtat += tat[b[i]];
        }
        q = 0;
    }
    avgwt = avgwt / x;
    avgtat = avgtat / x;
    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);
}
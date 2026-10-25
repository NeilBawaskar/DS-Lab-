```c
#include <stdio.h>

int main()
{
    int a[10][10], s[100][3], t[100][3], f[100][3];
    int r, c, i, j, k, n = 0, ch;
    int count[10] = {0}, pos[10];

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0)
                n++;
        }

    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = n;

    k = 1;
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            if(a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }

    do
    {
        printf("\n1.Triplet\n2.Simple Transpose\n3.Fast Transpose\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            for(i = 0; i <= n; i++)
                printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
        }

        else if(ch == 2)
        {
            t[0][0] = c;
            t[0][1] = r;
            t[0][2] = n;

            k = 1;
            for(i = 0; i < c; i++)
                for(j = 1; j <= n; j++)
                    if(s[j][1] == i)
                    {
                        t[k][0] = s[j][1];
                        t[k][1] = s[j][0];
                        t[k][2] = s[j][2];
                        k++;
                    }

            for(i = 0; i <= n; i++)
                printf("%d\t%d\t%d\n", t[i][0], t[i][1], t[i][2]);
        }

        else if(ch == 3)
        {
            f[0][0] = c;
            f[0][1] = r;
            f[0][2] = n;

            for(i = 0; i < c; i++)
                count[i] = 0;

            for(i = 1; i <= n; i++)
                count[s[i][1]]++;

            pos[0] = 1;
            for(i = 1; i < c; i++)
                pos[i] = pos[i-1] + count[i-1];

            for(i = 1; i <= n; i++)
            {
                k = pos[s[i][1]];
                f[k][0] = s[i][1];
                f[k][1] = s[i][0];
                f[k][2] = s[i][2];
                pos[s[i][1]]++;
            }

            for(i = 0; i <= n; i++)
                printf("%d\t%d\t%d\n", f[i][0], f[i][1], f[i][2]);
        }

        else if(ch == 4)
            printf("Program Ended\n");

        else
            printf("Invalid choice\n");

    } while(ch != 4);

    return 0;
}
```

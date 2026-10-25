#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], t[10][10];
    int r1, c1, r2, c2, i, j, k, ch;

    printf("Enter rows and columns of A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter elements of A:\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter rows and columns of B: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter elements of B:\n");
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    do
    {
        printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose of A\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                if(r1 == r2 && c1 == c2)
                {
                    for(i = 0; i < r1; i++)
                    {
                        for(j = 0; j < c1; j++)
                            printf("%d ", a[i][j] + b[i][j]);
                        printf("\n");
                    }
                }
                else
                    printf("Addition not possible\n");
                break;

            case 2:
                if(r1 == r2 && c1 == c2)
                {
                    for(i = 0; i < r1; i++)
                    {
                        for(j = 0; j < c1; j++)
                            printf("%d ", a[i][j] - b[i][j]);
                        printf("\n");
                    }
                }
                else
                    printf("Subtraction not possible\n");
                break;

            case 3:
                if(c1 == r2)
                {
                    for(i = 0; i < r1; i++)
                    {
                        for(j = 0; j < c2; j++)
                        {
                            int sum = 0;
                            for(k = 0; k < c1; k++)
                                sum += a[i][k] * b[k][j];

                            printf("%d ", sum);
                        }
                        printf("\n");
                    }
                }
                else
                    printf("Multiplication not possible\n");
                break;

            case 4:
                for(i = 0; i < c1; i++)
                {
                    for(j = 0; j < r1; j++)
                        printf("%d ", a[j][i]);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(ch != 5);

    return 0;
}
```

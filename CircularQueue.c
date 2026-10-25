#include <stdio.h>
#define MAX 5

int main()
{
    int queue[MAX], front = -1, rear = -1;
    int choice, x, i;

    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if ((rear + 1) % MAX == front)
                printf("Queue Overflow\n");
            else
            {
                printf("Enter value: ");
                scanf("%d", &x);

                if (front == -1)
                    front = 0;

                rear = (rear + 1) % MAX;
                queue[rear] = x;

                printf("Value added\n");
            }
        }

        else if (choice == 2)
        {
            if (front == -1)
                printf("Queue Underflow\n");
            else
            {
                printf("Deleted: %d\n", queue[front]);

                if (front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % MAX;
            }
        }

        else if (choice == 3)
{
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        for (i = front; ; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;
        }

        printf("\n");
    }
}
        else if (choice == 4)
            break;

        else
            printf("Invalid choice\n");
    }

    return 0;
}

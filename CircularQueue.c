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
            if (rear == MAX - 1)
                printf("Queue Overflow\n");
            else
            {
                printf("Enter Job ID: ");
                scanf("%d", &x);

                if (front == -1)
                    front = 0;

                rear++;
                queue[rear] = x;
                printf("Job added\n");
            }
        }

        else if (choice == 2)
        {
            if (front == -1)
                printf("Queue Underflow\n");
            else
            {
                printf("Job %d processed\n", queue[front]);

                if (front == rear)
                    front = rear = -1;
                else
                    front++;
            }
        }

        else if (choice == 3)
        {
            if (front == -1)
                printf("Queue is empty\n");
            else
            {
                for (i = front; i <= rear; i++)
                    printf("%d ", queue[i]);

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

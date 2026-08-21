#include <stdio.h>
struct Student {
    int roll;
    char name[30];
    float marks;
};

void display(struct Student s[], int n) {
    for(int i=0;i<n;i++)
        printf("%d %s %.2f\n",s[i].roll,s[i].name,s[i].marks);
}

void linear(struct Student s[],int n,int key) {
    for(int i=0;i<n;i++)
        if(s[i].roll==key) {
            printf("Found: %s %.2f\n",s[i].name,s[i].marks);
            return;
        }
    printf("Not Found\n");
}

void insertion(struct Student s[],int n) {
    for(int i=1;i<n;i++) {
        struct Student t=s[i];
        int j=i-1;
        while(j>=0 && s[j].roll>t.roll)
            s[j+1]=s[j],j--;
        s[j+1]=t;
    }
}

void selection(struct Student s[],int n) {
    for(int i=0;i<n-1;i++) {
        int m=i;
        for(int j=i+1;j<n;j++)
            if(s[j].roll<s[m].roll) m=j;
        struct Student t=s[i]; s[i]=s[m]; s[m]=t;
    }
}

void shell(struct Student s[],int n) {
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;i++) {
            struct Student t=s[i];
            int j=i;
            while(j>=gap && s[j-gap].roll>t.roll)
                s[j]=s[j-gap],j-=gap;
            s[j]=t;
        }
}

void binary(struct Student s[],int n,int key) {
    int l=0,r=n-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(s[m].roll==key) {
            printf("Found: %s %.2f\n",s[m].name,s[m].marks);
            return;
        }
        if(s[m].roll<key) l=m+1;
        else r=m-1;
    }
    printf("Not Found\n");
}

int main() {
    struct Student s[MAX];
    int n,ch,key;

    printf("Enter number of students: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d %s %f",&s[i].roll,s[i].name,&s[i].marks);

    do {
        printf("\n1.Display 2.Linear 3.Binary 4.Insertion 5.Selection 6.Shell 7.Exit\n");
        scanf("%d",&ch);

        switch(ch) {
            case 1: display(s,n); break;
            case 2:
                scanf("%d",&key);
                linear(s,n,key);
                break;
            case 3:
                insertion(s,n);
                scanf("%d",&key);
                binary(s,n,key);
                break;
            case 4: insertion(s,n); display(s,n); break;
            case 5: selection(s,n); display(s,n); break;
            case 6: shell(s,n); display(s,n); break;
            case 7: printf("Exit"); break;
            default: printf("Invalid choice");
        }
    } while(ch!=7);

    return 0;
}

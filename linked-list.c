#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct node
{
    char info[10];
    struct node *n;
};

int main()
{
    struct node *x, *y, *save, *head, *p, *q;
    char a[10];
    int cnt = 0;

    // Allocate memory for the first two nodes
    x = (struct node *)malloc(sizeof(struct node));
    y = (struct node *)malloc(sizeof(struct node));

    // Initialize nodes
    head = x;
    x->n = y;
    y->n = NULL;

    // Set initial data for the first two nodes
    strcpy(x->info, "cemal");
    strcpy(y->info, "mert");

    // Input loop
    do
    {
        puts("Please enter the name: ");
        fgets(a, sizeof(a), stdin);
        a[strcspn(a, "\n")] = '\0'; // Remove newline character
        cnt++;

        q = NULL;
        for (p = head; p != NULL && strcmp(a, p->info) > 0; p = p->n)
            q = p;

        if (q == NULL)
        {
            p = (struct node *)malloc(sizeof(struct node));
            strcpy(p->info, a);
            p->n = head;
            head = p;
        }
        else
        {
            save = p;
            p = (struct node *)malloc(sizeof(struct node));
            strcpy(p->info, a);
            p->n = save;
            q->n = p;
        }
    } while (cnt != 3);

    // Traversing and printing the list
    printf("Original List:\n");
    for (save = head; save != NULL; save = save->n)
        printf("Traverse Node = %s\n", save->info);

    // Deleting a node
    puts("Please enter name to be deleted: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0'; // Remove newline character

    q = head;
    for (p = head; p != NULL && strcmp(a, p->info) != 0; p = p->n)
        q = p;

    if (p == NULL)
    {
        printf("This name was not found in the list.\n");
    }
    else
    {
        if (p == head)
        {
            head = head->n;
        }
        else
        {
            q->n = p->n;
            free(p);
        }
        printf("Name found and deleted.\n");
        printf("New list is:\n");
        for (save = head; save != NULL; save = save->n)
            printf("Traverse Node = %s\n", save->info);
    }

    // Freeing allocated memory
    p = head;
    while (p != NULL)
    {
        struct node *temp = p;
        p = p->n;
        free(temp);
    }

    return 0;
}

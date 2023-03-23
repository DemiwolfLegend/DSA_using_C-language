#include <stdio.h>
#include <stdlib.h>

// Linked list structure
struct node
{
    int value;
    struct node *link;
};

// Functions initialisation
int count(struct node *);

void display(struct node *);

// void main function
void main()
{
    struct node *p;
    p = NULL;
}

int count(struct node *q)
{
    int c = 0;

    while (q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}

void display(struct node *q)
{
    printf("\n");
    while (q != NULL)
    {
        printf("%d  ", q->value);
        q = q->link;
    }
}

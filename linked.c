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

void append(struct node **, int);

void addatbeg(struct node **, int);

void addafter(struct node *, int, int);

void delete(struct node **, int);

// void main function
void main()
{
    struct node *p;
    p = NULL;

    printf("\nNo. of elements in the linked list = %d", count(p));
    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);
    printf("\nNo. of elements in the linked list = %d", count(p));
    display(p);

    addatbeg(&p, 15);
    addatbeg(&p, 29);
    addatbeg(&p, 12);
    printf("\nNo. of elements in the linked list = %d", count(p));
    display(p);

    addafter(p, 3, 22);
    addafter(p, 5, 25);
    addafter(p, 8, 11);
    printf("\nNo. of elements in the linked list = %d", count(p));
    display(p);
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

void append(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;

    if (*q == NULL)
    {
        temp = malloc(sizeof(struct node));
        temp->value = num;
        temp->link = NULL;
        *q = temp;
    }
    else
    {
        temp = *q;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        r = malloc(sizeof(struct node));
        r->value = num;
        r->link = NULL;
        temp->link = r;
    }
}

void addatbeg(struct node **q, int num)
{
    struct node *temp;

    temp = malloc(sizeof(struct node));
    temp->value = num;
    temp->link = *q;
    *q = temp;
}

void addafter(struct node *q, int loc, int num)
{
    struct node *temp, *r;
    int i;

    temp = q;

    for (i = 0; i < loc; i++)
    {
        temp = temp->link;

        if (temp == NULL)
        {
            printf("\nThere are less than %d elements in linked list", loc);
            return;
        }
    }
    r = malloc(sizeof(struct node));
    r->value = num;
    r->link = temp->link;
    temp->link = r;
}

void delete(struct node **q, int num)
{
    struct node *temp, *r;

    temp = *q;

    while (temp != NULL)
    {
        if (temp->value == num)
        {
            if (temp == q)
            {
                *q = temp->link;
                free(temp);
                return;
            }
            else
            {
                r->link = temp->link;
                free(temp);
                return;
            }
        }
        else
        {
            r = temp;
            temp = temp->link;
        }
    }
    printf("\nElement not found");
}
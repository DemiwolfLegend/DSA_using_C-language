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

void add(struct node **, int);

void reverse(struct node **);

// void main function
void main()
{
    struct node *p;
    p = NULL;

    printf("\nNo. of elements in the linked list = %d", count(p));
    append(&p, 1);
    append(&p, 2);
    append(&p, 4);
    append(&p, 5);
    printf("\nNo. of elements in the linked list = %d", count(p));
    display(p);

    add(&p, 3);
    printf("\nNo. of elements in the linked list = %d", count(p));
    display(p);

    reverse(&p);
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
            if (temp == *q)
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

void add(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;

    r = malloc(sizeof(struct node));
    r->value = num;

    if (*q == NULL || (*q)->value > num)
    {
        *q = r;
        (*q)->link = temp;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->value <= num && (temp->link->value > num || temp->link == NULL))
            {
                r->link = temp->link;
                temp->link = r;
                return;
            }

            temp = temp->link;
        }
    }

    r->link = temp->link;
    temp->link = r;
}

void reverse(struct node **q)
{
    struct node *temp, *s, *r;

    temp = *q;
    r = NULL;
    while (temp != NULL)
    {
        s = r;
        r = temp;
        temp = temp->link;
        r->link = s;
    }
    *q = r;
}
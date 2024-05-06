#include<stdio.h>
#include<string.h>

#define MAX 15

struct person
{
   int empNo;
   char name[12];
   int age;
   char gender[2];
};

typedef struct person Person;

struct queue
{
   Person allperson[MAX];
   int front, rear, size;
};

typedef struct queue QUEUE;

void initialize(QUEUE *q)
{
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void enqueue(QUEUE *q, Person p)
{
    if(q->size < MAX)
    {
        q->allperson[q->rear] = p;
        q->rear = (q->rear + 1) % MAX;
        q->size++;
    }
    else
    {
        printf("QUEUE IS FULL\n");
    }
}

Person dequeue(QUEUE *q)
{
    Person p;
    if(q->size == 0)
    {
        printf("\n\t....QUEUE UNDERFLOW\n\t");
    }
    else
    {
        p = q->allperson[q->front];
        q->front = (q->front + 1) % MAX;
        q->size--;
    }
    return p;
}

int main()
{
    Person tenPerson[10] = {
        {123, "Ahmet", 21, "M"},
        {234, "Sevgi", 26, "F"},
        {128, "Osman", 18, "M"},
        {432, "Mert", 27, "M"},
        {287, "Ayse", 34, "F"},
        {423, "Kemal", 21, "M"},
        {634, "Lale", 16, "F"},
        {828, "Sefer", 15, "M"},
        {252, "Meral", 27, "F"},
        {887, "Demet", 34, "F"}
    };

    QUEUE q, male, female;

    int i;

    initialize(&q);
    initialize(&male);
    initialize(&female);

    for(i = 0; i < 10; i++)
        enqueue(&q, tenPerson[i]);

    while(q.size != 0)
    {
        Person t = dequeue(&q);
        if(strcmp(t.gender, "M") == 0) 
            enqueue(&male, t);
        else
            enqueue(&female, t);
    }

    printf("\nThe Male Persons\nEMPNO\tNAME\tAGE\tGENDER");
    while(male.size != 0)
    {
        Person t = dequeue(&male);
        printf("\n%d\t%s\t%d\t%s", t.empNo, t.name, t.age, t.gender);
    }

    printf("\nThe Female Persons\nEMPNO\tNAME\tAGE\tGENDER");
    while(female.size != 0)
    {
        Person t = dequeue(&female);
        printf("\n%d\t%s\t%d\t%s", t.empNo, t.name, t.age, t.gender);
    }

    return 0;
}

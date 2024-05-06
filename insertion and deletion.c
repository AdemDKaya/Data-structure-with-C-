#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 5

struct stack {
    int items[STACKSIZE];
    int top;
};

void push(struct stack *, int);
int pop(struct stack *);

int main(void) {
    struct stack s;
    int xx;
    char optype;
    s.top = -1;

    do {
        printf("Enter Operation type (I for Insert, D for Delete, E for Exit): ");
        scanf(" %c", &optype);

        switch (optype) {
            case 'I':
                printf("Enter input Number: ");
                scanf("%d", &xx);
                push(&s, xx);
                break;

            case 'D':
                if (s.top == -1) {
                    printf("Stack is empty. Cannot delete.\n");
                } else {
                    printf("%d is deleted.\n", pop(&s));
                }
                break;

            case 'E':
                printf("Exiting...\n");
                break;

            default:
                printf("Illegal Operation code.\n");
                break;
        }
    } while (optype != 'E');

    return 0;
}

int pop(struct stack *ps) {
    if (ps->top == -1) {
        printf("Stack underflow. Exiting...\n");
        exit(1);
    }

    return ps->items[ps->top--];
}

void push(struct stack *ps, int x) {
    if (ps->top == STACKSIZE - 1) {
        printf("Stack overflow. Exiting...\n");
        exit(1);
    }

    ps->items[++ps->top] = x;
}

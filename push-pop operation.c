#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 35 

typedef struct {
    char home[MAX_SIZE];
    int top;
} My_stack;

void push(My_stack *, char);
void pop(My_stack *);
int is_empty(My_stack *);

int main(void) {
    My_stack st;
    char input[50];
    int i = 0;
    st.top = -1;

    printf("Enter the sequence : ");
    fgets(input, sizeof(input), stdin); 
    printf("RESULT : ");

    while (input[i] != '\0') {
        if (isalpha(input[i]))
            push(&st, input[i]);
        else if (input[i] == '*')
            pop(&st);
        else {
            printf("ERROR: Wrong input symbol - program terminates!\n");
            exit(1);
        }
        i++;
    }
    return 0;
}

void push(My_stack *s, char c) {
    if (s->top >= MAX_SIZE - 1) { 
        printf("ERROR: Stack overflow - program terminates\n");
        exit(1);
    }
    s->top++;
    s->home[s->top] = c;
}

void pop(My_stack *s) {
    if (is_empty(s)) {
        printf("ERROR: Nothing to pop - program terminates\n");
        exit(1);
    }
    printf("%c", s->home[s->top--]); 
}

int is_empty(My_stack *s) {
    return (s->top < 0 ? 1 : 0);
}

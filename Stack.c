/**
 * The basics of a stack::
 * **********************
 * A stack is is LIFO data structure:push, pop and peek
 * to push, check if the stack is full first:then push the item, increase top value and count(not necessary)
 * to pop, check if the stack is empty, then remove the top most value
 * It keeps track of 2 items, the array of the stack and the top set to -1 when empty
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

struct stack{
    int items[MAX];
    int top;
};

void createEmptyStack(struct stack *t){
    t->top = -1;
}

int isFull(struct stack *s){
    if (s->top == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *t){
    if(t->top == -1){
        return 1;
    }
    return 0;
}

void push(struct stack *t, int newItem){
    if(isFull(t)){
        printf("Stack already full\n");
    } else {
        t->top++;
        t->items[t->top] = newItem;
    }

    count++;
}

void pop(struct stack *t){
    if (isEmpty(t)){
        printf("stack already empty, nothing to pop");
    } else{
        printf("item popped is %d", t->items[t->top]);
        t->top--;
    }
    count--;
}
// Print elements of stack
void printStack(struct stack *s) {
    printf("Stack: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}



int main(){
    int ch;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    printf("\nAfter popping out\n");
    printStack(s);

    free(s);

}
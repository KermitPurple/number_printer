#ifndef STACK_H
#define STACK_H

#include<stdbool.h>

#define STACK_VALUE long long

typedef struct stack Stack;

Stack *stack_create();
void stack_free(Stack *stack);
void stack_push(Stack *stack, STACK_VALUE value);
STACK_VALUE stack_pop(Stack *stack);
bool stack_empty(Stack *stack);
int stack_count(Stack *stack);

#endif // STACK_H

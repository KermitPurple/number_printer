#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

typedef struct node{
    STACK_VALUE value;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
    int count;
}Stack;

Node *node_create(STACK_VALUE value, Node *next){
    Node *result = calloc(1, sizeof(*result));
    if(!result){
        fputs("Not enough Memory\n", stderr);
        exit(1);
    }
    result->value = value;
    result->next = next;
    return result;
}

Stack *stack_create(){
    Stack *result = calloc(1, sizeof(*result));
    // value for top and count should both be zero and calloc already does that
    return result;
}

void free_node(Node *node){
    if(node){
        free_node(node->next);
        free(node);
    }
}

void stack_free(Stack *stack){
    free_node(stack->top);
    free(stack);
}

void stack_push(Stack *stack, STACK_VALUE value){
    stack->top = node_create(value, stack->top);
    stack->count++;
}

STACK_VALUE stack_pop(Stack *stack){
    if(stack_empty(stack)){
        fputs("The stack is empty", stderr);
        exit(1);
    }
    STACK_VALUE result = stack->top->value;
    Node *to_delete = stack->top;
    stack->top = stack->top->next;
    free(to_delete);
    stack->count--;
    return result;
}

bool stack_empty(Stack *stack){
    return !stack->count;
}

int stack_count(Stack *stack){
    return stack->count;
}

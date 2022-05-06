#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"stack.h"

#define _GET_ARG3(a, b, c, ...) c
#define _print_num1(num) _print_num2(num, true)
#define print_num(...) _GET_ARG3(\
    __VA_ARGS__,\
    _print_num2,\
    _print_num1\
    )(__VA_ARGS__)

typedef long long num_t;

char *sections[] = {
    "",
    "thousand",
    "million",
    "billion",
    "trillion",
    "quadrillion",
    NULL
};

void print_digit(int digit, bool print_zero){
    switch(digit){
        case 0: if(print_zero) printf("zero"); break;
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        case 3: printf("three"); break;
        case 4: printf("four"); break;
        case 5: printf("five"); break;
        case 6: printf("six"); break;
        case 7: printf("seven"); break;
        case 8: printf("eight"); break;
        case 9: printf("nine"); break;
    }
}

void print_2digit(int digits){
    int ones = digits % 10;
    switch(digits - ones){
        case 0: break;
        case 10: 
            switch(ones){
                case 0: printf("ten"); break;
                case 1: printf("eleven"); break;
                case 2: printf("twelve"); break;
                case 3: printf("thirteen"); break;
                case 4: printf("fourteen"); break;
                case 5: printf("fifteen"); break;
                case 6: printf("sixteen"); break;
                case 7: printf("seventeen"); break;
                case 8: printf("eighteen"); break;
                case 9: printf("nineteen"); break;
            }
            return;
        case 20: printf("twenty"); break;
        case 30: printf("thirty"); break;
        case 40: printf("fourty"); break;
        case 50: printf("fifty"); break;
        case 60: printf("sixty"); break;
        case 70: printf("seventy"); break;
        case 80: printf("eighty"); break;
        case 90: printf("ninety"); break;
    }
    if(digits - ones > 10 && ones != 0) putchar('-');
    print_digit(ones, false);
}

void print_3digit(int digits){
    int tens_and_ones = digits % 100;
    int hundreds = digits / 100;
    if(hundreds != 0){
        print_digit(hundreds, false);
        printf(" hundred ");
    }
    print_2digit(tens_and_ones);
}

void _print_num2(num_t num, bool new_line){
    if(num < 0){
        num = llabs(num);
        printf("Negative ");
    }
    if(num == 0){
        printf("zero");
    }else{
        Stack *stack = stack_create();
        while(num > 0){
            stack_push(stack, num % 1000);
            num /= 1000;
        }
        while(!stack_empty(stack)){
            int i = stack_count(stack) - 1;
            int digits = stack_pop(stack);
            if(digits != 0){
                print_3digit(digits);
                printf(" %s ", sections[i]);
            }
        }
        stack_free(stack);
    }
    if(new_line) putchar('\n');
}

int main(void){
    for(num_t i = 0; i <= 10000000; i++){
        print_num(i);
    }
    return 0;
}

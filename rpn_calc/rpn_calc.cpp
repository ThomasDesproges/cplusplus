#include<iostream>
#include"stack.h"

int rpn_eval(int n, char* argv[]){
    //int stack[n];
    int* stack = init_stack(n);
    int top = 0;
    for(int i=0;i<n;i++){
        if (is_operand(*(argv[i])) == false){
            push(stack,atoi(argv[i]),&top);
        }
        else{
            switch (*(argv[i])){
            case '!':
                stack[top-1] = -stack[top-1];
                break;
            case '+':
                stack[top-2] = stack[top-1]+stack[top-2];
                top = top-1;
                break;
            case 'x':
                stack[top-2] = stack[top-1]*stack[top-2];
                top = top-1;
                break;
            case '/':
                stack[top-2] = stack[top-1]/stack[top-2];
                top = top-1;
                break;
            }
        }
        affiche_pile(stack,top);
    }
    return stack[top-1];
}
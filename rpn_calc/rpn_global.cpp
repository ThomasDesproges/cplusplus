#include<iostream>
#include<cstdlib>


bool is_operand(char x){
    if ((x<'0') or (x>'9'))
        return true;
    return false;
}

void push(int* p_liste,int valeur,int* p_top){
    p_liste[*p_top] = valeur;
    *p_top = *p_top+1;
    return ;
}

int pop(char* p_liste[],int* p_top){
    int i = *p_liste[*p_top];
    *p_top = *p_top -1;
    return i;
}

int* init_stack(int n){
    int* p_pile = new int[n];
    return p_pile;
}

void libere_memoire(int* p_pile){
    delete p_pile;
    return;
}

void affiche_pile(int* p_pile,int top){
    int i = 0;
    std::cout << "[";
    for (int i=0;i<top;i++){
        std::cout << p_pile[i] << " ";
    }
    std::cout << "[" << std::endl;
}

int rpn_eval(int n, char* argv[]){
    //int stack[n];
    int* stack = init_stack(n);
    int top = 0;
    for(int i=0;i<n;i++){
        if (is_operand(*(argv[i])) == false){
            stack[top] = atoi(argv[i]);
            top = top+1;
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
    libere_memoire(stack);
    return stack[top-1];
}



int rpn_eval_2(int n, char* argv[]){
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
    }
    return stack[top-1];
}

int main(int argc, char* argv[]){
    std::cout << rpn_eval(argc,argv) << std::endl;
    int liste[8] = {'4','7','2'};
    int top = 2;
    push(liste,9,&top);
    std::cout << liste[3] << " " << top << std::endl;
    int* p = init_stack(5);
    std::cout << p << std::endl;
    return 0;
}
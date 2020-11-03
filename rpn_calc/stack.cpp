#include<iostream>

void push(int* p_liste,int valeur,int* p_top){
    p_liste[*p_top] = valeur;
    *p_top = *p_top+1;
    return ;
}

int pop(int* p_liste,int* p_top){
    int i = p_liste[*p_top];
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

bool is_operand(char x){
    if ((x<'0') or (x>'9'))
        return true;
    return false;
}
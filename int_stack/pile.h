#include<iostream>

class IntStack{

public:

IntStack(int m,int t,int v[]) : m(m),top(t),value(v){
}

void push(int i){
    if (*p_top < m){
    pile_remplie = false;
    value[*p_top] = i;
    *p_top = *p_top + 1;
    return;
    }
    if (pile_remplie == false){
    std::cout << "Pile Remplie" << std::endl;
    }
    pile_remplie = true;
    return;
}

int pop(){
    int sortie = value[*p_top];
    *p_top = *p_top - 1;
    return sortie;
}

bool is_full(){
    if (top < m){
        return false;
    }
    return true;
}

bool is_empty(){
    if (top == 0){
        return true;
    }
    return false;
}

void affiche(){
    std::cout << "[ "; 
    for(int i =0;i<*p_top;i++){
        std::cout << value[i] << " ";
    }
    std::cout << "[" << std::endl;
    return;
}

private:
    int m;
    int* value;
    int top = 0;
    int* p_top = &top;
    bool pile_remplie = false;
};
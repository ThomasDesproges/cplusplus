#include<iostream>

class IntStack{

public:

IntStack(int m,int v[]) : m(m),value(v){
}

void push(int i){
    if (*p_top < m){
    value[*p_top] = i;
    *p_top = *p_top + 1;
    return;
    }
    std::cout << "Pile Remplie" << std::endl;

}

int pop(){
    int sortie = value[*p_top];
    *p_top --;
    return sortie;
}

void affiche(){
    for(int i =0;i<*p_top;i++){
        std::cout << value[i] << " ";
    }
    std::cout << std::endl;
    return;
}

private:
    int m;
    int* value;
    int top = 0;
    int* p_top = &top;
};
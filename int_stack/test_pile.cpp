#include<iostream>
#include"pile.h"


int main(){
    int taille = 30;
    int top = 4;
    int st[taille] = {9,7,4,3};
    IntStack stack(20,top,st);
    stack.push(4);
    stack.push(8);
    for(int i =0;i<40;i++){
        stack.push(-i);
    }
    stack.affiche();
    stack.pop();
    stack.push(10);
    stack.push(10);
    std::cout << stack.is_full() << std::endl;
    stack.is_full();
    stack.affiche();
}
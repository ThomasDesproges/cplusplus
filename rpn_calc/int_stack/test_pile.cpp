#include<iostream>
#include"pile.h"


int main(){
    int taille = 30;
    int st[taille] = {9,7,4,3};
    IntStack stack(taille,st);
    stack.push(4);
    stack.push(8);
    for(int i =0;i<40;i++){
        stack.push(i);
    }
    stack.affiche();
}
#include<iostream>
#include"intstack.h"

int main(){
    IntStack stack(5);
    stack.push(4);
    stack.push(8);
    for(int i =0;i<3;i++){
        stack.push(i);
    }
    stack.print();
    stack.pop();
    stack.push(10);
    stack.push(10);
    std::cout << stack.is_full() << std::endl;
    stack.is_full();
    stack.print();
}
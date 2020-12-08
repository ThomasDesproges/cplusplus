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
    stack.push(20);
    try{
        stack.push(10);
    }
    catch(char const* e){
        std::cout << "exception error : " << e << std::endl;
    }
    for(int i =0;i<5;i++){
        stack.pop();
    }
    try{
        stack.pop();
    }
    catch(char const* e){
        std::cout << "exception error : " << e << std::endl;
    }
    try{
        IntStack f_stack(0);
    }
    catch(const char* e){
        std::cout << "exception error : " << e<<std::endl;
    }
}
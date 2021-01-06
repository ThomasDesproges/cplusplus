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
    stack.push(20);
    IntStack st = stack;
    st.print();
    st.push(10);
    st.print();
    IntStack st1 (100);
    st1.push(1);
    st1.push(2);
    st1.print();
    {
        IntStack st2(st1);
        st2.print();
        st2.push(3);
        st2.print();
        st2.pop();
        st2.pop();
        st2.print();
    }
    st1.print (); // ? [10 [
    return 0;
}
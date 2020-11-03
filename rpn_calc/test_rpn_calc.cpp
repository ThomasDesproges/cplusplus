#include<iostream>
#include"rpn_calc.h"

int main(int argc,char* argv[]){
    std::cout << rpn_eval(argc,argv) << std::endl;
    return 0;
}
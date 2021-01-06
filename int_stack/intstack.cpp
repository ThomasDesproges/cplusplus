#include "intstack.h"
#include<iostream>

IntStack::~IntStack(){
    delete [] tab;
  }

IntStack::IntStack (int s): size(s), top (0), tab (new int [size]) {
    if (size <= 0){
      throw "nul or negative size";
  }
  }

IntStack::IntStack(const IntStack& rst): size(rst.size), top(rst.top), tab (new int [rst.size]){
    for(int i=0;i<size;i++){
      tab[i] = rst.tab[i];
    }
  }

void IntStack::push (int e) {
    if (is_full()){
        throw "Stack size limit reached";
    }
    else{
        tab[top] = e;
        top = top+1;
    }
  }

int IntStack::pop () {
    if (is_empty()){
        throw "cannot pop an empty stack";
    }
    top = top-1;
    return tab[top];
  }
void IntStack::print () {
    std :: cout << "[";
    for (int i=0; i<top; i++) {
      std::cout << tab[i] << ' ';
    }
    std::cout << '[' << std::endl;
  }

bool IntStack::is_full(){
    return top == size;
    }

bool IntStack::is_empty(){
      return top == 0;
    }

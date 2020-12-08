#include <iostream>
class IntStack {
public:
  IntStack (int s): size(s), top (0), tab (new int [size]) {
  if (size <= 0){
    throw "nul or negative size";
  }
  }


  void push (int e) {
    if (is_full()){
        throw "Stack size limit reached";
    }
    else{
        tab[top] = e;
        top = top+1;
    }
  }

  int pop () {
    if (is_empty()){
        throw "cannot pop an empty stack";
    }
    top = top-1;
    return tab[top];
  }

  void print () {
    std :: cout << "[";
    for (int i=0; i<top; i++) {
      std::cout << tab[i] << ' ';
    }
    std::cout << '[' << std::endl;
  }

  bool is_full(){
    return top == size;
    }

  bool is_empty(){
      return top == 0;
    }

  ~IntStack () {
    delete [] tab;
  }

private:
  int size;
  int top;
  int* tab;
};
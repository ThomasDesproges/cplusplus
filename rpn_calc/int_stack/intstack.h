#include <iostream>
class IntStack {
public:
  IntStack (int s): size(s), top (0), tab (new int [size]) {
  }

  void push (int e) {
    if (top == size){
        throw "Stack full";
    }
    else{
        tab[top] = e;
        top = top+1;
    }
  }

  int pop () {
    if (top == 0){
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
    if (top < size){
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

  ~IntStack () {
    delete [] tab;
  }

private:
  int size;
  int top;
  int* tab;
};
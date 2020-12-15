#include<iostream>
#include"intlist.h"

int main(){
    IntList l;
    l.add_front(4);
    l.add_front(7);
    l.add_front(9);
    l.add_front(32);
    l.add_front(54);
    l.add_front(26);
    l.add_front(18);
    l.add_back(2);
    l.add_back(1);
    l.print();
    std::cout << l.search(3) << std::endl;
    std::cout << l.search(2) << std::endl;
    l.print();
    l.remove_front();
    l.print();
    l.remove_back();
    l.print();
    l.remove(7);
    l.print();
    l.remove(26);
    l.remove(9);
    l.print();
    std::cout << l.remove(200) << std::endl;
    return 0;
}
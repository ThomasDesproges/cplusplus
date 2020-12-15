#include<iostream>

class IntCell{
    public:
    IntCell(int val, IntCell* n, IntCell* p): valeur(val), previous(p), next(n) {
    }

    ~IntCell(){
        delete previous;
        delete next;
    }

    friend class IntList;
    private:
    int valeur;
    IntCell* previous;
    IntCell* next;
};



class IntList{

    public: 
    IntList(): first(nullptr), last(nullptr){
    }

    ~IntList(){
        while ((*first).previous != nullptr){
            IntCell* f = last;
            remove_front();
            delete f;
        }
    }

    int add_front(int val){
        if ((first==nullptr) and (last==nullptr)){
            IntCell* pcell = new IntCell(val,nullptr,nullptr);
            first = pcell;
            last = pcell;
            return 0;
        }
        IntCell* pcell = new IntCell(val,nullptr,last);
        (*last).next = pcell;
        last = pcell;
        return 0;
    }

    int add_back(int val){
        if ((first==nullptr) and (last==nullptr)){
            IntCell* pcell = new IntCell(val,nullptr,nullptr);
            first = pcell;
            last = pcell;
            return 0;
        }
        IntCell* pcell = new IntCell(val,first,nullptr);
        (*first).previous = pcell;
        first = pcell;
        return 0;
    }


    void print(){
        IntCell* temp = first;
        std::cout << (*temp).valeur << " ";
        while((*temp).next != nullptr){
            temp = (*temp).next;
            std::cout << (*temp).valeur << " ";  
        }
        std::cout << std::endl;
        return;
    }

    bool search(int val){
        IntCell* f = first;
        while (f != nullptr){
            if ((*f).valeur == val){
                return true;
            }
            f = (*f).next;
        }
        return false;
    }

    void remove_front(){
        last = (*last).previous;
        (*last).next = nullptr;
        return;
    }

    void remove_back(){
        first = (*first).next;
        (*first).previous = nullptr;
        return;
    }

    bool remove(int val){
        IntCell* f = first;
        while (f != nullptr){
            if ((*f).valeur == val){
                if (((*f).next != nullptr) and ((*f).previous != nullptr)){
                    IntCell* n = (*f).next;
                    IntCell* p = (*f).previous;
                    (*n).previous = p;
                    (*p).next = n;
                    return true;
                }
                if ((*f).previous != nullptr){
                    IntCell* p = (*f).previous;
                    (*p).next = nullptr;
                    return true;
                }
                if ((*f).next != nullptr){
                    IntCell* n = (*f).next;
                    (*n).previous = nullptr;
                    return true;
                }
            }
            f = (*f).next;
        }
        return false;

    }

    private:
    IntCell* first;
    IntCell* last;
};
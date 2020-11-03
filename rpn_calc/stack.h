#include<iostream>


void push(int* p_liste,int valeur,int* p_top);
int pop(int* p_liste, int* p_top);
int* init_stack(int n);
void libere_memoire(int* p_pile);
void affiche_pile(int* p_pile,int top);
bool is_operand(char x);
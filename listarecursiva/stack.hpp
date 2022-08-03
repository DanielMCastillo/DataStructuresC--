#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include "node.hpp"

using namespace std;


namespace ed{


template <typename T>

    struct Node{
        T data;
        struct Node *next;
    };

template <typename T>
using ListLS = Node<T>;

//operaciones constructoras
template <typename T>
ListLS<T>* empty(){
    return nullptr;
}

//operacion observadora
template <typename T>
inline bool isEmpty(ListLS<T> *ls){
    return (ls == nullptr);

}
template <typename T>
ListLS<T>* cons(T data, ListLS<T> *ls){
    Node *nnew;
    nnew = new Node<T>();
    nnew-> data = data;
    nnew -> next = ls;
    return nnew;
}
template <typename T>
ListLS<T>* deletels(ListLS<T> *ls){
    while( !isEmpty(ls)){
        Node* noded = ls;
        //cout <<delete node<< <<ls->data<<endl;
        ls = ls->next;
        delete noded;
    }
    return nullptr;
}

//operaciones selectoras
template <typename T>
T head(ListLS<T> *ls){
    if(isEmpty(ls)){
        std::ostringstream msj;
        msj << "\nERROR: ListLS::head() list is empty" << endl;
        throw out_of_range(msj.str());
    }
    return ls -> data;
}

template <typename T>
ListLS<T>* tail(ListLS<T> *ls){
    if> ( isEmpty(ls)) {
        std::ostringstream msj;
        msj << "\n\nERROR: ListLS::tail() list is empty";
        throw std::runtime_error(msj.str());
    }
    return l->next;
}

}


#endif //__STACK_HPP__
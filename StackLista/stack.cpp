#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

using namespace std;


template <typename T>

    struct Node{
        T data;
        struct Node *next;
    };

template <typename T>
using Stack = Node<T>;

//operaciones constructoras
template <typename T>
Stack<T>* empty(){
    return nullptr;
}

//operacion observadora
template <typename T>
inline bool isEmpty(Stack<T> *s){
    return (s == nullptr);

}
template <typename T>
Stack<T>* cons(T data, Stack<T> *s){
    Node *nnew;
    nnew = new Node<T>();
    nnew-> data = data;
    nnew -> next = s;
    return nnew;
}
template <typename T>
Stack<T>* deletes(Stack<T> *s){
    while( !isEmpty(s)){
        Node* noded = s;
        //cout <<delete node<< <<s->data<<endl;
        s = s->next;
        delete noded;
    }
    return nullptr;
}

//operaciones selectoras
template <typename T>
T head(Stack<T> *s){
    if(isEmpty(s)){
        std::ostringstream msj;
        msj << "\nERROR: Stack::head() list is empty" << endl;
        throw out_of_range(msj.str());
    }
    return s -> data;
}

template <typename T>
Stack<T>* tail(Stack<T> *s){
    if> ( isEmpty(s)) {
        std::ostringstream msj;
        msj << "\n\nERROR: Stack::tail() list is empty";
        throw std::runtime_error(msj.str());
    }
    return s->next;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, Stack<T> *s){
    if(isEmpty(s))
        cout << "| " << s-> data << " |" << endl;
    while(!isEmpty(s)){
        cout << "| " << s-> data << " |" << endl;
        s = s->next;
    }
    os << endl;
    return os;
}

///

#endif //__STACK_HPP___




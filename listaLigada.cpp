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
    return ls->next;
}

int main(){
   // struct Node s;
    //s.data = 8;
   // s.next = nullptr;
    
    ListLS <int> *ls= empty<int>();  //lista vacia

    ls=cons(9,ls);
    ls=cons(10,ls);
    ls=cons(11,ls);


    cout << "ls: " << ls << endl;

    ListLS<string>* lsc = empty<string>();
    lsc=cons(string("naranja"),lsc);
    lsc=cons(string("mandarina"),lsc);
    lsc=cons(string("fresa"),lsc);
    lsc=cons(string("sandia"),lsc);


    cout << "lsc: " << lsc << endl;


    return 0;
}


/*
Cuando se defina una estructura de datos,
se tiene que definir la forma de como se escriben las operaciones
y su signiificado con estos dos "ingredientes"
sirven para definir lo que se conoce como TDA 
Tipo de dato abstracto (TDA) ADT en inglés

Sintaxis Semantica
isEmpty((empty)) = true
isEmpty(cons(d,l))  = d
isEmpty(cons(d,l))  = l
isEmpty(cons(d,l)) = error 
isEmpty(cons(d,l)) = error




*/








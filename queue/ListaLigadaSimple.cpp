#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};


using ListLS = Node;

//operaciones constructoras

ListLS* empty(){
    return nullptr;
}

//operacion observadora
inline bool isEmpty(ListLS *ls){
    return (ls == nullptr);
}

ListLS* cons(int data, ListLS *ls){
    Node *nnew;
    nnew = new Node();
    nnew-> data = data;
    nnew -> next = ls;
    return nnew;
}


//operaciones selectoras
int head(ListLS *ls){
    if(isEmpty(ls)){
        std::ostringstream msj;
        msj << "\nERROR: ListLS::head() list is empty" << endl;
        throw out_of_range(msj.str());
    }
    return ls -> data;
}

//operaciones selectoras
ListLS* tail(ListLS *ls){
    if(isEmpty(ls)){
        std::ostringstream msj;
        msj << "\nERROR: ListLS::tail() list is empty" << endl;
        throw out_of_range(msj.str());
    }
    return ls -> next;
}





std::ostream& operator <<(std:: ostream &os, ListLS *ls){
    os << "[";
    while( !isEmpty(ls)){
        cout << ls -> data << " ";
        ls = ls->next;
    }
    os << "]" << std::endl;
    return os;
}

int main(){
    // struct Node s;
    //s.data = 8;
    // s.next = nullptr;

    ListLS *ls = empty(); //lista vacia

    ls=cons(9,ls);
    ls=cons(10,ls);
    ls=cons(11,ls);


    cout << "ls: " << ls << endl;
    cout << "head(ls):" << head(ls) << endl;

    auto lst = tail(ls);
    cout << "lst: " << lst << endl;

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
isEmpty(cons(d,l)) = d
isEmpty(cons(d,l)) = l
isEmpty(cons(d,l)) = error
isEmpty(cons(d,l)) = error




*/
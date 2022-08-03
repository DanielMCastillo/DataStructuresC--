#ifndef __LIST_EXT_HPP__
#define __LIST_EXT_HPP__
#include "listls.hpp" //modulo de bajo nivel 

namespace ed{
    /*
        length([2,4,5,6])
            1+length(tail([2,4,5,6]))
                1+length(tail([4,5,6]))
                    1 + 1 + length(tail([5,6]))
                        1 + 1 + 1 + length(tail([6]))
                            1 + 1 + 1 + 1 + length(tail([]))
                                1  + 1 + 1 +1 + 0
    */
template <typename T>
long length(ListLS<T> *ls){
    if(isEmpty(ls))
        return 0;
    return 1 + length(tail(ls));
}
    /*
        [2,4,5,6,7]
        cons(2,cons(4,cons(5,cons(6,cons(7,empty())))))
    */
template <typename T>
ListLS<T>* copy(ListLS<T> *ls){
    if(isEmpty(ls))
        return empty<T>();
    return cons(head(ls),copy(tail(ls)));
}

/*
    Escriba una funcion la cual tome dos listas como parametro 
    lista que conisste de la concatenacion de ambas listas 
    append([5,6,7],[2,3,]

    11 12    12
    append([],[2,3,]) = [2,3]
*/

template <typename T>
  //ListLS<T>*

void append(ListLS<T> *l1, ListLS *l2){
    if(empty(11))
    return copy(12);
    return cons(head(11), append(tail(11),12));
}

/*Escriba una funciona para invertir una list
reverse ([5,6,7]) = [7,6,5]
*/

template <typename T>
ListLS*<T> reverse(ListLS<T> *ls){
    if(isEmpty(ls))
    return empty<T>();
        append(reverse(tail(ls)), cons(head(ls),empty<T>()))
    return cons(tail(ls),reverse(head(ls)))
}

template <typename T>
ListLS<T>* map(Funct funct, ListLS<T> *ls){
if(isEmpty(ls))
    return empty<T>();
    return cons(funct(head(ls)),copy(tail(ls)))
}


} //end namespace end
#endif //  LIST_EXT_HPP
//clase de ED - Daniel Castillo
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "arbolbinario.cpp"
#include "listls.hpp"
#include "listls_ext.hpp"

using namespace std;
using namespace ed;

template class <T>

List<T>* prefijo(TreeBin<T> *tb){
    if(es_nulo(tb))
        return vacia<T>();
    return cons(elem(tb),append(prefijo(left(tb)), prefijo(right(tb))));
}

int main(){

    cout << "left(tl):" << elem(left(tl)) << endl;
    cout << "height:" << height(tl)<< endl;

    List<int> *l = prefijo(tl);

    cout << "Prefijo :" ;  imprimir(l)
    cout << endl;

    return 0;
}
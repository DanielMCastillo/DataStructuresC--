
#include <iostream>
#include <stdexcept> 
#include <sstream>
#include "arbolbinario.hpp"

namespace ed
{

template <class T>
using BSTree = TreeBin<T>


BSTree* insert(T e, BSTree<T> *bst){
    if(isNull(bst))
        return new nodet<T>(nullptr,e,nullptr)
    else if(e < elem(bst))
        return new nodet<T>(insert(e,left(bst),elem(bst), right(bst)));
    else if(elem(bst) < e)
        return new nodet<T>(left(bst), elem(bst),insert(e,right(bst)));
    return bst;
}

}


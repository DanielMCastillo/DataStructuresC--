#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "listls.hpp"

#ifndef __QUEUEHPP__
#define __QUEUEHPP__

using namespace std;
namespace ed{

template <typename T>
struct Queue{
    struct Node<T> *head;
    struct Node<T> *tail;
    size_t length;
}    


    template <typename T>
    using Queue = ListaTail<T>
    Queue<T>* emptyQ(){
        ListTail<T>* newQueue = new ListTail<T>();
        newQueue -> head = nullptr;





    } 





}




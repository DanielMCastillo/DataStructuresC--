#include <iostream>

using namespace std;

template<class T>
struct Buffer{
    T *data;
    int head;
    int tail;
    int sizebuffer;
    int coutitem;
};


template<class T>
Buffer<T>* emptyb(int ai_size){
    Buffer<T> *newBuffer;
    newBuffer = new Buffer<T>();
    newBuffer -> sizebuffer = ai_size;
    newBuffer -> data = new T[ai_size];
    newBuffer -> head = 0; //-1
    newBuffer -> tail = -1; //0
    newBuffer -> coutitem = 0;

    return newBuffer;
}

template<class T>
Buffer<T>* freebuffer(Buffer<T> *b){
    delete [] b->data ;
    delete b;

    return nullptr;
}

/*op enqueue : Queue Float -> Queue . */
template<class T>
inline Buffer<T>* enqueue(Buffer<T> *b, T item){
    b -> tail = (b->tail +1) % b->sizebuffer;
    b-> coutitem++;
    b-> data[b->tail] = item;

    return b;
}


template<class T>
inline Buffer<T>* dequeue(Buffer<T> *b){
    b->head =(b->head +1) % b-> sizebuffer;
    b-> coutitem--;
    return b;
}

template<class T>
inline double isFull(Buffer<T> *b){
    return 100.0 * (double)b ->coutitem / (double) b-> sizebuffer;
}



template<class T>
void print(Buffer<T> *b){
    cout << "Buffer size: " << b-> coutitem << endl;
    if(b->tail == -1)
        cout << "<-- tail\n";
    for(int i=0; i< b->sizebuffer; i++){
        cout << i << ":" << b-> data[i];
        if(b-> head ==i)
            cout << "<-- head";
        if(b->tail == i)
            cout << " <-- tail";
        cout << endl;
    }
}

/*
head:
precondicion: que el buffer no esté vacío
postcondición: devolver primer dato del buffer
*/
template <class T>
inline T head(Buffer<T> *b){
    //nbo confiamos el usuario 
    return b -> data[b->head];
}

/*
tail:
precondicion: que el buffer no esté vacío
postcondición: devolver primer dato del buffer
*/
template <class T>
inline T tail(Buffer<T> *b){
    //no confiamos el usuario 
    return b -> data[b->head];
}

int main(){
/*
    Buffer<char> *b = emptyb<char>(6);
    
    print(b);
    b = enqueue(b,'h');
    print(b);
    b = enqueue(b,'o');
    print(b);
    b = enqueue(b,'l');
    print(b);

    b = dequeue(b);
    print(b);
    b = dequeue(b);
    print(b);

    
    b = enqueue(b,'a');
    b = enqueue(b,'b');
    b = enqueue(b,'m');
    print(b);
    b = enqueue(b,'u');
    print(b);


    cout << "Buffer capacidad:" << isFull(b) << endl; */

    cout << "Hola mundo\n" << '\n';
    cout << "Hola mundo\n" << '\n';
    cout << "Hola mundo\n" << '\n';
    cout << "Hola mundo\n" << '\n';


    Buffer<char> *b = emptyb<char>(6);
    b = enqueue(b,'a');
    b = enqueue(b,'b');

    cout << tail(enqueue(b,'c')) << endl;





    return 0;
}
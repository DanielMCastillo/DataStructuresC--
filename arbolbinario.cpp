//clase de ED - Daniel Castillo 11 mayo
#include <iostream>
#include <stdexcept>
#include <sstream>


using namespace std;

namespace ed {

template <class T>
struct nodet
{
  nodet(nodet *alef, T ae, nodet* arig):
      e(ae), lef(alef), rig(arig)
      { }
  T e;
  struct nodet *lef;
  struct nodet *rig;
};
template <class T>
using TreeBin = nodet<T>;

template <class T>
TreeBin<T>* left(TreeBin<T> *tb)
{
   if ( tb == nullptr) {
     std::ostringstream msj;
     msj << "\n\nError in left():  tb is null tree\n";
     throw std::runtime_error(msj.str());
   }
   return tb->lef;
}

template <class T>
TreeBin<T>* right(TreeBin<T> *tb)
{
   if ( tb == nullptr) {
     std::ostringstream msj;
     msj << "\n\nError in right():  tb is null tree\n";
     throw std::runtime_error(msj.str());
   }
   return tb->right;
}

template <class T>
T elem(TreeBin<T> *tb)
{
   if ( tb == nullptr) {
     std::ostringstream msj;
     msj << "\n\nError in elem():  tb is null tree\n";
     throw std::runtime_error(msj.str());
   }
   return tb->e;
}

template <class T>
bool es_nulo(TreeBin<T> *ab)
{
    return ab = nullptr;
}

template <class T>
bool es_hoja(TreeBin <T> *ab)
{
    if(ab == nullptr){
        return false;
    }
    return ab -> der == nullptr && ab -> izq == nullptr;
}

template <class T>
bool es_ult(TreeBin <T> *ab)
{
    if(ab == nullptr){
        return false;
    }
    return ab -> der == nullptr || ab -> izq == nullptr;
}

template <class T>
unsigned altura(TreeBin<T> *ab)
{
    if(ab  == nullptr)
        return 0;

    return 1 + std::max(altura(izq(ab)),altura(der(ab)));
}

template <class T>
int num_hojas(TreeBin<T> *ab)
{
    if(ab == nullptr)
    {
        return 0;
    }
    if(izq(ab) == nullptr && der(ab) == nullptr){
        return 1;
    }
    return num_hojas(izq(ab)) + num_hojas(der(ab));
}

template <class T>
int num_nodos(TreeBin<T> *ab)
{
    if(ab == nullptr)
    {
        return 0;
    }
    return 1 + num_nodos(izq(ab)) + num_nodos(der(ab));
}

template <class T>
int camino_min(TreeBin<T> *ab)
{
    if(ab == nullptr){
        return 0;
    }
    return 1 + min(camino_min(izq(ab)),camino_min(der(ab)));
}

} //namespace ed



int main()
{
    /*
    nodet<int> * n = new nodet<int>(nullptr,8,nullptr);
    TreeBin<int> *tb = new TreeBin<int>(nullptr,8,nullptr);
    */
    ed::TreeBin<int> *tb = new ed::TreeBin <int>(nullptr,8,nullptr);
    ed::TreeBin<int> *tl = ed::left(tb);
    cout<< "Elem(tb): " << ed::elem(tb) <<endl;

    return 0;

}

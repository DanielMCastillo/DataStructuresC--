#ifndef __MATRIX_HPP__ //No lo compile dos veces

#include <iostream>
#include <ostream>
#include  <stdexcept>
#include  <ostream>
#include  <sstream>

namespace ed {

using namespace std;

/*Hacer un implemetaion para manejar matrices matematicas
  donde el primer elemento sea m(1,1), ademas tenga las
  operaciones mas comunas de matrices, +, *.
*/

template <class T>
class Matrix {
//Metodos
public:

  //Constructor
  Matrix()
    : nrow(0),
      ncol(0),
      elems(nullptr)
  {
      //cout << "Constructor por defecto" << endl;
  }

  //Constructor con parametrod
  Matrix(int anrow, int ancol)
    : nrow(anrow),
      ncol(ancol),
      elems(new T[nrow*ncol])
  {
     // cout << "Constructor con parametros" << endl;
      for (int i =0; i < nrow*ncol; i++ )
        elems[i] = 0;
  }

  //Constructor copia
  Matrix(const Matrix<T> &b)
    : nrow(b.nrow),
      ncol(b.ncol),
      elems(new T[nrow*ncol])
  {
     // cout << "Constructor copia: " << nrow << "x" << ncol << endl;
      for (int i =0; i < nrow*ncol; i++ )
        elems[i] = b.elems[i];
  }

  //Constructor move (es nuevo)
  Matrix(Matrix<T> &&b)
    : nrow(b.nrow),
      ncol(b.ncol),
      elems(b.elems)
  {
      //cout << "Constructor move" << endl;
      b.elems = nullptr;
  }

  //Destructor
  ~Matrix()
  {
      //cout << "Destructor" << endl;
      if ( this->elems != nullptr)
       delete [] elems;
  }

  /*
     Precondicion: la variable 'i' debe tener un valor
                   en el rango  1 <= i <= nrow y
                   'j' en el rango  1 <= j <= ncol
                   Donde nrow y ncol son orden de la
                   matriz actual.
     Postcondicion: Regresar  Elem_i x j
  */
  T& operator()(int i, int j)
  {
    if ( i < 1 || i > nrow || j < 1 || j >ncol ) {
        std::ostringstream msj;
        msj  << "\n\nERROR: Matrix::operator() out range: "
             << "\ti = " << i << " j =  " << j  << "\n"
             << "\tcurrent range is:" << nrow << "x" << ncol
             << endl;
        throw out_of_range(msj.str());
    }

    return *(elems + (i-1)*ncol + j -1); //O(1)
  }

  /*precondicion:
    poscondicion:
  */
  Matrix operator+(Matrix<T> &b)
  {
   // cout << "Operacion +" << endl;
    if(this->ncol!=b.ncol || this->nrow!=b.nrow){
       std::ostringstream msj;
       msj << "\n\nERROR: Matrix ::operator+ out of range: \n"
           << "\tthis : " << nrow << "x" << ncol << "\n"
           << "\t    b: " << b.nrow << "x" << b.ncol
           << endl;
           throw out_of_range(msj.str());
    }

    Matrix<T> a(b.nrow,b.ncol);
    for(int i=1; i<= b.nrow; i++){
        for(int j=1; j<= b.ncol; j++){
            a(i,j)= (*this)(i,j)+ b(i,j);
        }
    }

    return a;

  }

  /*
     Precondicion: El numero de columnas de la matriz this
                   debe ser igual al numero de filas de la
                   matriz b
     Postcondicion: Una matriz resultante de la
                  multiplicacion de this * b
  */
  Matrix operator *(Matrix<T> &b)
  {
   // cout << "operador * " << endl;
    if ( this->ncol != b.nrow) {
       std::ostringstream msj;
        msj  << "\n\nERROR: Matrix::operator* order different:\n"
             << "\tthis:" << nrow << "x" << ncol  << "\n"
             << "\t   b:" << b.nrow << "x" << b.ncol
             << endl;
        throw out_of_range(msj.str());
    }
    Matrix c(this->nrow,b.ncol);  //New
    for(int i=1;i <=c.nrow; i++){
        for(int j=1;j<= b.ncol;j++){
            T total = 0;
            for(int k=1; k<=this->ncol; k++){
                total+=  (*this)(i,k)* b(k,j);
            }
            c(i,j) = total;
        }
    }

    return c;
  }


  Matrix&  operator=(const Matrix<T> &b)
  {
      //cout << "operador = " << endl;
      if (this != &b) {
        if ( this->nrow*this->ncol != b.nrow*b.ncol) {
            if (this->elems != nullptr)
                delete [] this->elems;
            this->elems = new T[b.nrow*b.ncol];
        }
        this->nrow = b.nrow;
        this->ncol = b.ncol;
        for (int i =0; i < nrow*ncol; i++ )
             this->elems[i] = b.elems[i];
      }
      return (*this);
  }

  //Asignacion move
   Matrix&  operator=(Matrix<T> &&b)
   {
      //cout << "operador move = " << endl;
      if ( this != &b) {
        if ( this->elems != nullptr) {
            delete [] this->elems;
        }
        this->nrow = b.nrow;
        this->ncol = b.ncol;
        this->elems = b.elems;
        b.nrow = 0;
        b.ncol = 0;
        b.elems = nullptr;
      }
      return (*this);
   }


  friend  std::ostream& operator<<(std::ostream &os, Matrix<T> &m)
  {
      for (int i = 1; i <= m.nrow; i++) {
        for (int j = 1; j <= m.ncol; j++)
            os << m(i,j) << "\t";
        os << std::endl;
      }
      return os;
  }

//Atributos
private:
  int  nrow;
  int  ncol;
  T   *elems;

};

//Lenguajes hibridos combinacion POO y PE
template <class T>
Matrix<T> identity(int nrow)
{
    Matrix<T> I(nrow,nrow);

    for ( int i = 1; i <= nrow; i++) {
        I(i,i) = 1.0;
    }
    return I;
}

}

#endif // __MATRIX_HPP__
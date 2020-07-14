#include"Vectors1.h"
#include"Matrices2.h"
#include<iostream>
#include<assert.h>
#include<cmath>
using namespace std;


/* $$$$$$$$$$$$$$$$$$ I. Constructors and Destructor $$$$$$$$$$$$$ */


Matrice::Matrice(){

    int dims[2];
    dims[0]=0;
    dims[1]=0;
    mat = new Vecteur [0];

}
/* Constructor 1 : with lines and columns numbers as arguments */


Matrice::Matrice(int n_row, int n_col){
    
    dims[0] = n_row;
    dims[1] = n_col;
    mat = new Vecteur [n_col];

    for( int i = 0 ; i < n_col ; i++){

        mat[i] = Vecteur(n_row);
    }

}

/* Constructor 2: with a vector as argument */
Matrice::Matrice( Vecteur v ){

    dims[0]= v.dim;
    dims[1]= v.dim;
    
    mat = new Vecteur [ dims[1] ];

    for( int i = 0; i < dims[0]; i++){
        
        Vecteur v2 = *new Vecteur( dims[0] );
        v2[i] = v[i];
        mat[i] = v2;
           
    }

} 

/* Constructor 3: with a table of vector and its columns number as arguments */
Matrice::Matrice ( int nb_col, Vecteur *v ){
    
    dims[0] =v[0].dim; 
    dims[1] = nb_col;
    mat = new Vecteur [nb_col];

    for ( int i = 0 ; i< nb_col ; i++){
        
        mat[i]= v[i];

    }

}

/* Copy Constructor */

Matrice::Matrice( const Matrice &m){
    
    dims [0] = m.dims[0];
    dims [1] = m.dims [1];
    
    mat = new Vecteur [dims[1]];

    for ( int i = 0 ; i < dims[1] ; i++){
        
        mat[i] = m.mat[i];

    }

}

/* Destructor */
Matrice::~Matrice (){
    
    delete [] mat;

}

/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$  II . Overloaded operators $$$$$$$$$$$$$$$$$$$$$$ */

Matrice& Matrice::operator=( const Matrice &m ){
    
    if (this != &m){

        delete [] mat;

        dims[0] = m.dims[0] ;
        dims[1] = m.dims[1] ;

        mat = new Vecteur [ dims[1] ];

        for ( int i =0; i < dims[1]; i++){

            mat[i] = m.mat[i];

        }

    }

    return *this;

}

Vecteur& Matrice::operator[](int i){

    assert ( i <= dims[1] && " Index out of range");
    return mat[i];
}


Matrice Matrice::operator+( Matrice m2){
    
    assert( (dims[0] == m2.dims[0]) && (dims[1] == m2.dims[1]) && " Matrixes must have the same dimensions ");
    
    Matrice m(dims[0],dims[1]);
    
    for ( int i = 0 ; i < dims[1]; i++){
        
        m[i] = mat[i] + m2[i];
           
    }
    m.affiche();
    
    return m;

}


Matrice Matrice::operator-(  Matrice m2){

    
    assert( (dims[0] == m2.dims[0]) && (dims[1] == m2.dims[1]) && " Matrixes must have the same dimensions ");
    
    Matrice m(dims[0],dims[1]);
    
    for ( int i = 0 ; i < dims[1]; i++){

        m[i] = mat[i] - m2[i];
            
    }
    
    return m;

}




Matrice Matrice::operator*( Matrice m2){

    assert ( dims[1] == m2.dims[0] && " columns and lines sizes must coincide between matrices");
    this->affiche();
    
    Matrice m1_trans(2,2);
    m1_trans = this->transpose();

    Matrice m( dims[0], m2.dims[1]);

    for ( int j = 0; j < m2.dims[1]; j++){

        for ( int i = 0 ; i < dims[0]; i++){

            m[j][i] = dot( m1_trans[i] , m2[j]);

        }

    }

    return m;

}

Matrice operator*(float lambda, Matrice m){

    int nb_rows = m.dims[0];
    int nb_cols = m.dims[1];
    
    Matrice mat (nb_rows, nb_cols);

    for( int i = 0 ; i < nb_cols; i++ ){

        mat[i] = lambda * m[i];

    }
    return mat;

}

/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$  III . BASIC FUNCTIONS ON MATRICES $$$$$$$$$$$$$$$$$$$$$$ */

/* Affiche */

void Matrice::affiche(){
    
    cout << " Lines number : "<< dims[0] << endl;
    cout << " Columns number : " << dims[1] << endl;

    for ( int i = 0 ; i< dims[0] ; i++){

        cout << "[ ";
        for ( int j=0 ; j < dims[1]; j++){
            
            cout << mat[j][i] << " ";

        }
        cout << "]";
        cout << endl;

    }

}
/* Extraction of a part of the matrix */

Matrice Matrice::submat(const int i_min, const int i_max, const int j_min, const int j_max){

    assert( (0<=i_min && i_min <= dims[0]-1) && ( 0 <= i_max && i_max <= dims[0]-1 )  && " Indexes out of range");
    assert( (i_min <= i_max) && (j_min <= j_max) && " Make sure first argument and third arguments are lower or equal than respectively the second and the last one");

    assert( (0<=j_min && j_min <= dims[1]-1) && ( 0 <= j_max && j_max <= dims[1]-1 )  && " Indexes out of range");

    int dims[2];

    dims[0] = i_max - i_min +1;
    dims[1] = j_max - j_min +1;

    Matrice m(dims[0], dims[1]);
    Vecteur v;

    for ( int col = j_min; col <= j_max ; col++){
        
        v = mat[col];

        m[col]= v.subvec(i_min,i_max);

    }

    return m;

}



/* Matrix applied to a Vector */

Vecteur Matrice::mvprod(Vecteur v){

    assert ( dims[1]== v.dim && " Problem of dimension bewteen the Matrx and the Vector");
    
    int dim = v.dim;

    Vecteur v1(dim);
    v1.affiche();
    
    for( int i = 0 ; i < dim; i++){

        v1 = v1 + v[i]*mat[i];

    }

    return v1;
    

}

/* Transpose function*/

Matrice Matrice::transpose(){
    

    Matrice m_transpose(dims[1], dims[0]);
    
    for ( int i = 0 ; i < dims[0]; i++){

        for ( int j = 0 ; j < dims[1]; j++ ){

            m_transpose[i][j] = mat[j][i];
        }

    }

    return  m_transpose;

}


/* Frobenius norm */



float norm(Matrice mat){
    
    float norm_f;

    for ( int i = 0 ; i< mat.dims[1]; i++){

        norm_f = norm_f + norm(mat[i])* norm(mat[i]);
        

    }
    
    return sqrt(norm_f);

}

int * Matrice::Dim(){

    return dims;
}
/* outer */

Matrice outer(Vecteur v1, Vecteur v2){

    assert( v1.dimension() == v2.dimension() && " Vector must have the same dimension");
    int dims[2];
    dims[0] = v1.dimension() ;
    dims[1] = v2.dimension() ;

    Matrice m( dims[0], dims[1]);

    for( int i = 0 ; i < dims[1] ; i++){
        
        m[i] = v2[i]*v1;

    }

    return m;
}



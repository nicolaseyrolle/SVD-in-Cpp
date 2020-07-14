#include"Vectors1.h"
#include"Matrices2.h"
#include"Tensors4.h"
#include<iostream>
#include<assert.h>
#include<cmath>
using namespace std;



/* $$$$$$$$$$$$$$$$$$$$$ I. Constructors $$$$$$$$$$$$$$$$$$$$$ */

/* Constructor 0: By default */
Tenseur :: Tenseur(){
    order =0;
    nbelts =0;
    dims_t = new int[0];
    tens = Vecteur (0);
}
/* Constructor 1 : with the order and the dimensions of all tensors the components*/

Tenseur::Tenseur (int d, int t[]){
    
    
    order = d;
    nbelts =1;
    dims_t = new int [order];
    
    for( int i = 0 ; i < order; i++){
        
        dims_t[i]= t[i];
        nbelts = nbelts*dims_t[i] ;

    }
    
    tens = Vecteur (nbelts);
    

}

/* Constructor 2: with the same arguments as in constructor 1 and a Vector v to initialize the vectorialized tensor*/

Tenseur ::Tenseur ( int d, int t [], Vecteur v){
    
    order = d;
    nbelts = 1;
    dims_t = new int [order];

    for (int i = 0; i < order; i++){

        dims_t[i] = t[i];
        nbelts = nbelts*dims_t[i];

    }
    
    tens = Vecteur(v);
    
    

}


/* Constructor 3*/






Tenseur::Tenseur( int d, int t[], int k, Matrice A){
    
    assert((1 <= k && k<=d)&& "k must be greater or equal than one and lower than 1");

    order = d;
    nbelts =1;
    dims_t = new int [order];
    
    for (int i =0 ; i< order ; i++){

        dims_t[i] = t[i];
        nbelts = nbelts*dims_t[i];
        
    }

    
    int A_dims [] = { dims_t[k-1], nbelts/dims_t[k-1]};
    
    cout <<" je construis"<< endl;

    float * tens1= new float [nbelts];

    int *index_phi_inv = new int [order]; // Variable which stocks the result of phi_inv
    int index_phi;

    for ( int i = 0 ; i < A_dims[0] ; i++){
        
        for ( int j = 0 ; j < A_dims[1] ; j++){
            
            index_phi_inv = phi_inv(j+1,i+1, k, order, dims_t);
            index_phi = phi(index_phi_inv , order, dims_t);

            tens1[index_phi-1]= A[j][i];
            
        }

    }
    tens = Vecteur(nbelts,tens1);


}

/* Destructor */

Tenseur::~Tenseur(){

    
    delete [] dims_t;

}

/* Copy constructor */

Tenseur::Tenseur( const Tenseur &t){

    
    order = t.order;
    nbelts = t.nbelts;
    dims_t = new int[order];

    for ( int i =0 ; i < order ; i++){
            
        dims_t[i] = t.dims_t[i];
            
    }

    tens = Vecteur (t.tens);

}
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$    II.  OVERLOADED OPERATORS  $$$$$$$$$$$$$$$$$$$$$$$$$ */


Tenseur& Tenseur::operator=(const Tenseur& t){

    if( this != &t){
        
        delete [] dims_t;
        dims_t = new int [order];

        order = t.order;
        nbelts = t.nbelts;

        
        
        for ( int i =0 ; i < order ; i++){
            
            dims_t[i] = t.dims_t[i];
            
            
        }
    
        tens = Vecteur(t.tens);
    

    }
    

    return *this;

}



float& Tenseur::operator[](int i){

    return tens[i];
}

Tenseur Tenseur::operator+( Tenseur t2 ){

    
    assert( order == t2.order && " Tensors does not have the same order");
    
    Vecteur tens_sum(nbelts);
    tens_sum = tens + t2.tens;
    
    
    return Tenseur(order , dims_t , tens_sum);

}

Tenseur Tenseur::operator-( Tenseur t2 ){

    assert( order == t2.order && " Tensors does not have the same order");

    Vecteur tens_diff(nbelts);
    tens_diff = tens - t2.tens;
    

    return Tenseur(order , dims_t , tens_diff);

}


/* &&&&&&&&&&&&&&&&&&&&&&&    III. OTHER FUNDAMENTAL FUNCTIONS  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */


void Tenseur::affiche (){
    
    cout << " Tensor of order : " << order << endl << " Associated vectors form's dimensions  : " << "[";

    for (int i =0;  i < order; i++){
        
        cout << " " << dims_t[i]<< " ";
    }
    cout<< "]" << endl;
    tens.affiche();
}
/* Get the mode of a Tensor */

Matrice Tenseur::mode(int k){
    
    Matrice matrix_t( dims_t[k-1] , nbelts/dims_t[k-1] );

    int *index_phi_inv= new int[order];
    int index_phi;

    for( int i = 0 ; i < matrix_t.Dim()[0]; i++){

        for ( int j = 0 ; j < matrix_t.Dim()[1]; j++ ){

            index_phi_inv = phi_inv(j+1,i+1, k, order, dims_t);
            index_phi = phi(index_phi_inv , order, dims_t);

            matrix_t[j][i] = tens [index_phi-1];

        }

    }

    return matrix_t; 
}



/* &&&&&&&&&&&&&&&&&&&&&&&    IV. OUT OF CLASS FUNCTIONS &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& */

/* Modulo redefinition */
int rest_division( int a , int b){

    if ( a%b !=0){
        return a%b;    
    }else{
        return b;
    }
}

/* reverse function of phi */

int * phi_inv( int j, int i , int k , int order, int dims_t []){
     
    static int *index_t = new int [order];
    
    int f_t = j; // initialisation
   
    index_t[order-1] = rest_division(f_t, dims_t[order-1]);
   
    
if (order >1){
    // RECURRENCE
    for( int l = order-2 ; l >= k ; l--){
        
        f_t = (f_t - index_t[l+1])/dims_t[l+1] + 1;
        index_t[l] = rest_division(f_t, dims_t[l]); 

    }
    
    index_t[k-1] = i ;

    f_t = (f_t - index_t[k])/dims_t[k] + 1 ;
    index_t[k-2] = rest_division(f_t, dims_t[k-2]) ;

    for ( int l = k-3 ; l >= 0 ; l--){

        f_t = (f_t - index_t[l+1])/dims_t[l+1] + 1;
        index_t[l] = rest_division(f_t , dims_t[l]);

    }
}    

    return index_t  ;     
    
}
/* Phi */

int phi( int * index_t, int order, int dims_t[]){

    // Initialisation
    int ind = index_t[order-1];
    int n_d = 1; 

    // recurrence
    for ( int i = order-1 ; i >0; i-- ){

        n_d = dims_t[i]*n_d ;
        ind = ind +  n_d*(index_t[i-1]-1);

    }

    return ind;
}

/* Modal Product (attempt because of lack of time... ) */

Tenseur pmod(int k, Tenseur s, Matrice m){

    int order = s.order;
    assert( (k<=order && k>=1) && " k must check 1<=k<=order, so the mode is out of range ");
    
    
    int *dims_t = new int[order];

    for( int i = 0; i < k ; i++){
        dims_t[i]= s.dims_t[i];
    }

    dims_t[k-1] = s.dims_t[k-1];

    for( int i = k; i < order ; i++){

        dims_t[i]= s.dims_t[i];

    }

    Matrice t_matrix = s.mode(k);// We convert our tensor into its matricial form ;
    Matrice s_mode_k = m*t_matrix;

    Tenseur product_k(order, dims_t , k , s_mode_k);

    return product_k;
    
    

    

    


}
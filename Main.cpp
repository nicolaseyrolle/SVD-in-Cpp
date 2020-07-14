#include"Vectors1.h"
#include"Matrices2.h"
#include"Tensors4.h"
#include<iostream>
#include<assert.h>
#include<cmath>

using namespace std;

int main(){
    //****************************************************************
    // ********************** PART 1: Vectors ***********************\
    //****************************************************************
    
    /* $$$$$$$$$$$$$$$$$$$ Question 1  $$$$$$$$$$$$$$$$$$$$$$ */
    cout << " ********** VALIDATION OF VECTOR'S PART ************"<< endl << endl;
    /* First Vector */
    cout <<  " QUESTION 1: "<< endl << endl;
    int size = 3;
    float tab [size];

    for ( int i = 0 ; i < size ; i++){

        tab[i]=1;

    }

    Vecteur u(size , tab);

    cout <<" Vector u: "<< endl;

    u.affiche();

    /* Second Vector */

    int size1 = 4 ;

    float tab1 []= { 3 , 4 , 0, 0};

    Vecteur v( size1, tab1);
    cout <<" Vector v: "<< endl;
    v.affiche();
    

    /* $$$$$$$$$$$$$$$$$$$$$$$ Question 2 $$$$$$$$$$$$$$$$$$$$$$$$$$ */
    cout << endl<< endl<<  " QUESTION 2: "<< endl;
    /* Copy of vecteur u */

    
    Vecteur t(u);
    t.affiche();
    
    /* $$$$$$$$$$$$$$$$$$$$$$$ Question 3 $$$$$$$$$$$$$$$$$$$$$$$$$$ */
    cout <<  endl << endl<< " QUESTION 3: "<< endl ;
    /* Modification of u */
    
    
    u[2] = 0 ;
    cout <<" Vector u after modification : " << endl;
    u.affiche();
    cout <<" Vector t ( copy of vector u before modification) : " << endl;
    t.affiche();

    /* $$$$$$$$$$$$$$$$$$$$$$$ Question 4 $$$$$$$$$$$$$$$$$$$$$$$$$$ */
    cout << endl<< endl<< " QUESTION 4: "<< endl ;
    /* Square norm of v */ 
    int norm2_v = dot(v,v);
    int norm_v = norm(v);

    cout << " Squared norm of v: " << dot(v,v)<< endl;
    cout << " Norm of v: " << norm(v)<< endl;

    /* $$$$$$$$$$$$$$$$$$$$$$$ Question 5 $$$$$$$$$$$$$$$$$$$$$$$$$$ */
    cout << endl<< endl<< " QUESTION 5: "<< endl << endl;
    /* v normalized */

    cout << " Vector v normalized :" << endl;

    Vecteur v1; 
    v1 =  (1.0/norm_v)*v;
    v1.affiche();
    
    
    /* $$$$$$$$$$$$$$$$$$$$$$$ Question 6 $$$$$$$$$$$$$$$$$$$$$$$$$$ */
    
    cout << endl<< endl<<  " QUESTION 6: "<< endl ;

    Vecteur w = v.subvec(1,3);
    cout << " Vector w ( subpart of vector v):"<< endl;
    w.affiche();
    cout <<" Vector u: "<< endl;
    v.affiche();
    
    /* $$$$$$$$$$$$$$$$$$$$$$$ Question 7 $$$$$$$$$$$$$$$$$$$$$$$$$$ */
    cout << endl << endl<<  " QUESTION 7: "<< endl ;
    Vecteur s = u + w;
    Vecteur s1 = u-w;
    cout <<  " Vector u+w :"<< endl;

    s.affiche() ;
    cout <<  " Vector u-w :"<< endl;
    s1.affiche() ;

    //****************************************************************
    // ********************** PART 2: Matrices ***********************\
    // *****************************************************************

    cout << endl<< endl << " ********** VALIDATION OF MATRICES' PART ************" << endl << endl;

    /* $$$$$$$$$$$$$$$$$$$ Question 1  $$$$$$$$$$$$$$$$$$$$$$ */

    cout << "QUESTION 1: " << endl<< endl;

    /* Matrix A*/
    cout << " Creation of matrix A :"<< endl;
    int Size = 3;

    Vecteur * mat = new Vecteur[size];

    float Tab[] = {1,1,0} ;
    float Tab1[] = {-0.5, 2, -1} ;
    float Tab2[] = { 0, -1, 1} ;

    Vecteur w1(Size, Tab);
    Vecteur w2(Size, Tab1);
    Vecteur w3(Size, Tab2);

    mat[0] = w1;
    mat[1] = w2;
    mat[2] = w3;

    Matrice A( Size, mat);
    A.affiche();

    /* Matrix B */

    cout << endl <<" Creation of matrix B : " << endl;
    Vecteur z(2);
    z[0] = -2;
    z[1] = 1;

    Matrice B(z);
    B[1][0] = 3;
    B.affiche();


/* $$$$$$$$$$$$$$$$$$$ Question 2  $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 2: " << endl << endl;

    
    /* Matrix C */

    Matrice C(B);
    cout << " Matrix C :"<< endl;
    C.affiche();

    /* Modification of B */
    cout << " Matrix B ( modified):"<< endl;
    B[1][0] = 0;
    B.affiche();


/* $$$$$$$$$$$$$$$$$$$ Question 3  $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 3: " << endl << endl;

    /* Matrix D creation */
    Matrice D;
    D = A.submat(0,2,0,1);
    cout << " Matrix D:"<< endl;
    D.affiche();
    
    
    

/* $$$$$$$$$$$$$$$$$$$ Question 4  $$$$$$$$$$$$$$$$$$$$$$ */ 

    cout << endl << endl << "QUESTION 4: " << endl << endl;

    /* diagonal Matrix construction */
    
    float TAB[]={3,2,1};
    Vecteur z2(3,TAB);
    Matrice E(z2);
    cout << " Matrix E :" << endl;
    E.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 5  $$$$$$$$$$$$$$$$$$$$$$ */
    
    cout << endl << endl << "QUESTION 5: " << endl << endl;

    /* B+C computation */
    cout << " B+C Matrix Computation : "<< endl;
    Matrice sum = B + C;
    sum.affiche();

    /* C-B computation */
    cout << endl << " C-B Matrix Computation :"<< endl;
    Matrice diff = C-B;
    diff.affiche();

    /* D*C computation */
    cout << endl << " D*C Matrix Computation :"<< endl;
    Matrice product = D*C;
    cout << " Je suis la "<< endl;
    product.affiche(); 

/* $$$$$$$$$$$$$$$$$$$ Question 6  $$$$$$$$$$$$$$$$$$$$$$ */ 

    cout << endl << endl << "QUESTION 6: " << endl << endl;

    /* Frobenius norm of C */

    float f_norm = norm(C); 
    cout << " Frobenius norm of C :" << f_norm << endl;

/* $$$$$$$$$$$$$$$$$$$ Question 7 $$$$$$$$$$$$$$$$$$$$$$ */ 
    cout << endl << endl << "QUESTION 6: " << endl << endl;

    Matrice Z = 0.5*(B + B.transpose());
    //Matrice Z3 = 0.5*Z;
    cout << " Computation of 0.5*( B + t(B))";
    Z.affiche();





    //****************************************************************
    // ********************** PART 4: Tensors ***********************\
    //**************************************************************** 
    
    /* $$$$$$$$$$$$$$$$$$$ Question 1 $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 1: " << endl << endl;

    /* Creation of tensor T */
    int order =3;
    int dims_t[] = {2, 2, 2};
    Tenseur T (order, dims_t);

    cout << " Tensor T : "<< endl;
    T.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 2: $$$$$$$$$$$$$$$$$$$$$$ */ 
    cout << endl << endl << "QUESTION 2: " << endl << endl;
    
    /* Creation of Tensor U */
    int nbelts =8;

    for( int i = 0; i < nbelts; i++){

        Tab[i]=1;

    }

    Vecteur v_tens(nbelts,Tab);

    Tenseur U(order, dims_t, v_tens);
    cout << " Tensor U : "<< endl;
    U.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 3: $$$$$$$$$$$$$$$$$$$$$$ */ 
    cout << endl << endl << "QUESTION 3: " << endl << endl;

    /* Computation of Tensor V= U+T */

    Tenseur V ;
    V = U + T;
    cout <<" Tensor V = U + T : "<< endl;
    V.affiche();

    /* Computation of Tensor W = U-T */
    Tenseur W = U - T;
    cout <<" Tensor W = U - T : "<< endl;

    W.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 4: $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 4: " << endl << endl;

    /* "  Modification of U_{2,2,2}" */
    
    cout<< "  Modification of U_{2,2,2}"<< endl;

    /* We need to use phi which gives the corresponding value of U_{2,2,2} in the vector representation */
    int index [] = {2,2,2};
    
    int n = phi(index, order, dims_t);
    cout << n << endl; 

    cout << "Value of U_{2,2,2} = "<<U[n-1]<< endl<< endl;

    /* Modification of U */
    U[n-1]= -1;

    cout << " U modified :"<< endl<< endl;
    U.affiche();
    cout <<endl << " V :"<< endl;
    V.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 5: $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 5: " << endl << endl;

    /* mode 1 of T*/

    Matrice mode_T = U.mode(1);
    cout <<" Computation of the first mode of T"<<endl;
    mode_T.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 6: $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 6: " << endl << endl;

    /*Creation of vectors in order to create an array of vector and then define a matrix and so a tensor*/
    Vecteur *MAT= new Vecteur[4];
    float TAB1 []={1,4};
    Vecteur col1 = Vecteur(2,TAB1); 
    //col1.affiche();
    float TAB2 []={3,1.0/3};
    Vecteur col2 = Vecteur(2,TAB2); 
    //col2.affiche();
    float TAB3 []={0,1.5};
    Vecteur col3 = Vecteur(2,TAB3); 
    //col3.affiche();
    float TAB4 []={-1,2};
    Vecteur col4 = Vecteur(2,TAB4); 
    //col4.affiche();

    MAT[0] = col1;
    MAT[1] = col2;
    MAT[2] = col3;
    MAT[3] = col4;

    /* Initialisation of the matrix*/

    Matrice COL(4,MAT);
    COL.affiche();

    /*creation of the asked tensor*/

    Tenseur T1(order,dims_t,2,COL );

    /* printing its mode */
    cout<< " 2nd mode of the tensor"<< endl;

    Matrice M2 = T1.mode(2);
    M2.affiche();

/* $$$$$$$$$$$$$$$$$$$ Question 6: $$$$$$$$$$$$$$$$$$$$$$ */

    cout << endl << endl << "QUESTION 6: " << endl << endl;

    Matrice A1(3,2);
    float column1[] = {3 , 0 , 0};
    Vecteur c1(3,column1);
    float column2[] = {-1 , 6, -3};
    Vecteur c2(3, column2);
    

    

    
    
}

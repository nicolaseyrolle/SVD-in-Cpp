#pragma once

/* //////////////////\\\\\\\\\\\\\\\\\\  Vector class //////////////////\\\\\\\\\\\\\\ */

class Vecteur{

    int dim ;
    float *tab;

    friend class Matrice; 

    public:

    /* Constructors  and Destructor*/
    Vecteur ();
    Vecteur(int );
    Vecteur(int , float *);
    Vecteur(const Vecteur &);
    ~Vecteur();
    
    /* Overloaded operators */

    float & operator[](int );
    Vecteur & operator=( const Vecteur &);
    Vecteur operator+(  Vecteur );
    Vecteur operator-( Vecteur);
    friend Vecteur operator*(float , Vecteur );
    

    /* Other Basic Operations*/

    friend float dot(  Vecteur , Vecteur );
    friend float norm( Vecteur );

    /* Some useful functions */
    Vecteur subvec(int min, int max); /* exctraction of a subpart of a vector*/
    void affiche(); /* To print a vector */
    int dimension();

};




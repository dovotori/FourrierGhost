#ifndef VECTEUR
#define VECTEUR

using namespace std;

#include <iostream>
#include <cmath>

class Vecteur3D
{
  public:
    float x, y, z;

    Vecteur3D(float x = 0, float y = 0, float z = 0);
    ~Vecteur3D();
    void normaliser();
    void affecter(Vecteur3D v2);
    void affecter(float x, float y, float z);
    void display() const;
    float* get();

    Vecteur3D operator=(const Vecteur3D vecteur2);
    Vecteur3D operator=(const float valeurs[3]);
    Vecteur3D* operator+=(const Vecteur3D vecteur2);
    Vecteur3D* operator-=(const Vecteur3D vecteur2);
    Vecteur3D* operator*=(const double a);
    Vecteur3D* operator/=(const double a);
    Vecteur3D operator+(const Vecteur3D v2);
    Vecteur3D operator-(const Vecteur3D v2);
    Vecteur3D operator*(const double a)const;
    Vecteur3D operator/(const double a)const;

    Vecteur3D produitVectoriel(const Vecteur3D v2); // cross
    float produitScalaire(const Vecteur3D v2);

  private:
};



#endif


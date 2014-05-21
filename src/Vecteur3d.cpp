#include "Vecteur3d.h"

Vecteur3D::Vecteur3D(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}



Vecteur3D::~Vecteur3D(){}



void Vecteur3D::normaliser()
{
  float longueur = sqrt(pow(x,2) + pow(y,2)
    + pow(z,2));

  if(longueur != 0.0)
  {
    this->x /= longueur;
    this->y /= longueur;
    this->z /= longueur;
  }
}

void Vecteur3D::affecter(Vecteur3D v2)
{
  this->x = v2.x;
  this->y = v2.y;
  this->z = v2.z;
}

void Vecteur3D::affecter(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}


void Vecteur3D::display() const
{
  cout << "v: " << this->x << " "
    << this->y << " "
    << this->z << endl;
}


float* Vecteur3D::get()
{
	float *tableau = new float[3];
	tableau[0] = this->x;
	tableau[1] = this->y;
	tableau[2] = this->z;
	return tableau;
}



Vecteur3D Vecteur3D::produitVectoriel(const Vecteur3D v2)
{
  Vecteur3D resultat;
  resultat.x = this->y * v2.z - this->z * v2.y;
  resultat.y = this->z * v2.x - this->x * v2.z;
  resultat.z = this->x * v2.y - this->y * v2.x;
  return resultat;
}

float Vecteur3D::produitScalaire(const Vecteur3D v2)
{
  return this->x * v2.x
    + this->y * v2.y
    + this->z * v2.z;
}








//////////////////////////////////////////////////////
///////////////////// OPERATORS //////////////////////
//////////////////////////////////////////////////////

/* //////////// = ///////////// */

Vecteur3D Vecteur3D::operator=(const Vecteur3D v2)
{
  this->x = v2.x;
  this->y = v2.y;
  this->z = v2.z;
  return *this;
}

Vecteur3D Vecteur3D::operator=(const float valeurs[3])
{
  this->x = x;
  this->y = y;
  this->z = z;
  return *this;
}


/* ////////// + ///////////// */

Vecteur3D* Vecteur3D::operator+=(const Vecteur3D v2)
{
  this->x += v2.x;
  this->y += v2.y;
  this->z += v2.z;
  return this;
}

Vecteur3D Vecteur3D::operator+(const Vecteur3D v2)
{
  Vecteur3D resultat;
  resultat = *this;
  resultat += v2;
  return resultat;
}


/* ////////// - ///////////// */

Vecteur3D* Vecteur3D::operator-=(const Vecteur3D v2)
{
  this->x -= v2.x;
  this->y -= v2.y;
  this->z -= v2.z;
  return this;
}

Vecteur3D Vecteur3D::operator-(const Vecteur3D v2)
{
  Vecteur3D resultat;
  resultat = *this;
  resultat -= v2;
  return resultat;
}


/* //////////// * ///////////// */

Vecteur3D* Vecteur3D::operator*=(const double a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;
    return this;
}

Vecteur3D Vecteur3D::operator*(const double a)const
{
    Vecteur3D resultat = *this;
    resultat *= a;
    return resultat;
}


/* //////////// / ///////////// */

Vecteur3D* Vecteur3D::operator/= (const double a)
{
    this->x /= a;
    this->y /= a;
    this->z /= a;
    return this;
}

Vecteur3D Vecteur3D::operator/(const double a)const
{
    Vecteur3D resultat = *this;
    resultat /= a;
    return resultat;
}



#ifndef LOADOBJ
#define LOADOBJ

using namespace std;

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


// VBO
#define PGL_VERTICES 0
#define PGL_NORMALES 1
#define PGL_TEXTURES 2
#define PGL_FACES 3
#define PGL_INDICES 4

// TYPE DE POINTS
#define PGL_V 0
#define PGL_VT 1
#define PGL_VN 2
#define PGL_VTN 3

class LoadOBJ
{
  public:
    LoadOBJ();
    ~LoadOBJ();
    int setup(string nom);
    void display();

    float* getSmoothNormales();
    float* getAbsoluteCoor(int type);

    inline float* getCoor(int type){ return this->coor[type]; };
    inline unsigned int* getId(int type){ return this->id[type]; };
    inline unsigned int getNb(int type){ return this->nb[type]; }

  private:
    float **coor;
    unsigned int **id;
    int typePoint;
    int nb[4];

    void comptage(ifstream *source);
    void typeDePoint();
    void allocation();
    void affectation(ifstream *source);
    void traiterFace(string *ligne);
};


// Convertir string en une variable comme float ou autre
template<typename T>
bool from_string( const std::string &Str, T &Dest )
{
  std::istringstream iss( Str );
  return iss >> Dest != 0;
}

#endif

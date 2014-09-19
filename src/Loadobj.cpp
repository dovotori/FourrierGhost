#include "Loadobj.h"

LoadOBJ::LoadOBJ()
{
  this->coor = NULL;
  this->id = NULL;
  this->typePoint = 0;
  for(int i = 0; i < 4; i++){ this->nb[i] = 0; }
}

LoadOBJ::~LoadOBJ()
{
    if(this->coor != NULL)
    {
        delete[] this->coor[PGL_VERTICES];
        if(this->typePoint == PGL_VN || this->typePoint == PGL_VTN)
            delete[] this->coor[PGL_NORMALES];
        if(this->typePoint == PGL_VT || this->typePoint == PGL_VTN)
            delete[] this->coor[PGL_TEXTURES];
        delete[] this->coor;
    }

    if(this->id != NULL)
    {
        delete[] this->id[PGL_VERTICES];
        if(this->typePoint == PGL_VN || this->typePoint == PGL_VTN)
            delete[] this->id[PGL_TEXTURES];
        if(this->typePoint == PGL_VT || this->typePoint == PGL_VTN)
            delete[] this->id[PGL_NORMALES];
        delete[] this->id;
    }
}


int LoadOBJ::setup(string nom)
{
  ifstream source(nom.c_str());

  if(source){
    this->comptage(&source);
    this->typeDePoint();
    this->allocation();
    this->affectation(&source);
    this->display();
    return 0;
  } else {
    cout << "Impossible d'ouvrir la source obj: "
      << nom << endl;
    return 1;
  }
}


void LoadOBJ::display()
{
  cout << "----OBJ----" << endl;
  cout << " > type de point: " << this->typePoint << endl;
  cout << " > " << this->nb[PGL_VERTICES]
		<< " vertice(s)"<< endl;
  cout << " > " << this->nb[PGL_NORMALES]
		<< " normale(s)"<< endl;
  cout << " > " << this->nb[PGL_TEXTURES]
		<< " texture(s)"<< endl;
  cout << " > " << this->nb[PGL_FACES]
		<< " face(s)"<< endl;
  cout << "----FIN----" << endl << endl;
}


float* LoadOBJ::getAbsoluteCoor(int type)
{
  int nbCoor = 3;
  if(type == PGL_TEXTURES)
    nbCoor = 2;

  float *tableau = new float[this->nb[PGL_FACES]
		* 3 * nbCoor];
  unsigned int cptId = 0;

  for(int i = 0; i < this->nb[PGL_FACES]
		* 3 * nbCoor; i += nbCoor)
  {
    tableau[i] = this->coor[type]
      [id[type][cptId] * nbCoor];
    tableau[i+1] = this->coor[type]
      [(id[type][cptId] * nbCoor) + 1];
    if(type != PGL_TEXTURES)
    {
      tableau[i+2] = this->coor[type]
	[(id[type][cptId] * nbCoor) + 2];
    }
    cptId++;
  }
  return tableau;
}




/* //////// PRIVATE ////////////////////// */

void LoadOBJ::comptage(ifstream *source)
{
  string mot;
  while(!source->eof())
  {
    *source >> mot;
    if(mot.compare("v") == 0) {
      this->nb[PGL_VERTICES]++;
    } else if(mot.compare("vt") == 0) {
      this->nb[PGL_TEXTURES]++;
    } else if(mot.compare("vn") == 0) {
      this->nb[PGL_NORMALES]++;
    } else if(mot.compare("f") == 0) {
      this->nb[PGL_FACES]++;
    }
  }
}



void LoadOBJ::typeDePoint()
{
  if(this->nb[PGL_NORMALES] > 0
		&& this->nb[PGL_TEXTURES] > 0)
    this->typePoint = PGL_VTN;
  else if(this->nb[PGL_TEXTURES] > 0)
    this->typePoint = PGL_VT;
  else if(this->nb[PGL_NORMALES] > 0)
    this->typePoint = PGL_VN;
  else
    this->typePoint = PGL_V;

}



void LoadOBJ::allocation()
{
  this->coor = new float*[3];
  this->coor[PGL_VERTICES]
		= new float[this->nb[PGL_VERTICES]*3];
  this->coor[PGL_TEXTURES]
			= new float[this->nb[PGL_TEXTURES]*2];
  this->coor[PGL_NORMALES]
		= new float[nb[PGL_NORMALES]*3];

  this->id = new unsigned int*[3];
  this->id[PGL_VERTICES]
		= new unsigned int[this->nb[PGL_FACES]*3];
  this->id[PGL_TEXTURES]
		= new unsigned int[this->nb[PGL_FACES]*3];
  this->id[PGL_NORMALES]
		= new unsigned int[this->nb[PGL_FACES]*3];
}



void LoadOBJ::affectation(ifstream *source)
{
  string mot;
  unsigned int cpt[5] = {0};

  source->clear();
  source->seekg(0, ios::beg);
  while(!source->eof())
  {
    *source >> mot;

    ///////////// VERTICES ///////////////
    if(mot.compare("v") == 0) {
      *source >> mot;
      from_string(mot,
				coor[PGL_VERTICES][cpt[PGL_VERTICES]] );
      *source >> mot;
      from_string(mot,
				coor[PGL_VERTICES][cpt[PGL_VERTICES]+1] );
      *source >> mot;
      from_string(mot,
				coor[PGL_VERTICES][cpt[PGL_VERTICES]+2] );
//cout << "v  "<< coor[GL_VERTICES][cpt[GL_VERTICES]]
//<< " " << coor[GL_VERTICES][cpt[GL_VERTICES]+1]
//<< " " << coor[GL_VERTICES][cpt[GL_VERTICES]+2] << endl;
      cpt[PGL_VERTICES]+=3;

    ///////////// TEXTURES ///////////////
    } else if(mot.compare("vt") == 0) {
      *source >> mot;
      from_string(mot, coor[PGL_TEXTURES][cpt[PGL_TEXTURES]] );
      *source >> mot;
      from_string(mot,
				coor[PGL_TEXTURES][cpt[PGL_TEXTURES]+1] );
//cout << "vt  " << coor[GL_TEXTURES][cpt[GL_TEXTURES]]
//<< " " << coor[GL_TEXTURES][cpt[GL_TEXTURES]+1] << endl;
      cpt[PGL_TEXTURES]+=2;

    ///////////// NORMALES ///////////////
    }else if(mot.compare("vn") == 0) {
      *source >> mot;
      from_string(mot,
				this->coor[PGL_NORMALES][cpt[PGL_NORMALES]] );
      *source >> mot;
      from_string(mot,
				this->coor[PGL_NORMALES][cpt[PGL_NORMALES]+1] );
      *source >> mot;
      from_string(mot,
				this->coor[PGL_NORMALES][cpt[PGL_NORMALES]+2] );
//cout << "vn  " << coor[GL_NORMALES][cpt[GL_NORMALES]]
//<< " " << coor[GL_NORMALES][cpt[GL_NORMALES]+1]
//<< " " << coor[GL_NORMALES][cpt[GL_NORMALES]+2] << endl;
      cpt[PGL_NORMALES]+=3;

    ///////////// FACES ///////////////
    } else if (mot.compare("f") == 0) {
      getline(*source, mot);
      traiterFace(&mot);

      unsigned int valeurId;
      stringstream ss;
      ss << mot;

      for(int i = 0; i < 3; i++)
      {
	ss >> valeurId;
	this->id[PGL_VERTICES][cpt[PGL_FACES]+i] = valeurId;

	if(this->typePoint == PGL_VT
	  || this->typePoint == PGL_VN
	  || this->typePoint == PGL_VTN)
	{
	  ss >> valeurId;
	  this->id[PGL_TEXTURES][cpt[PGL_FACES]+i] = valeurId;
	}

	if(this->typePoint == PGL_VN || this->typePoint == PGL_VTN)
	{
	  ss >> valeurId;
	  this->id[PGL_NORMALES][cpt[PGL_FACES]+i] = valeurId;
	}
      }
      cpt[PGL_FACES]+=3;
    }
  }

  // Indices a zero
  for(int i = 0; i < this->nb[PGL_FACES]*3; i++)
  {
    this->id[PGL_VERTICES][i]--;
    if(this->typePoint == PGL_VN
			|| this->typePoint == PGL_VTN)
      this->id[PGL_NORMALES][i]-- ;
    if(this->typePoint == PGL_VT
			|| this->typePoint == PGL_VTN)
      this->id[PGL_TEXTURES][i]-- ;
  }
}



void LoadOBJ::traiterFace(string *ligne)
{
  //  Remplacer // par /1/
  if(this->typePoint == PGL_VN)
  {
    size_t pos = 0;
    pos = ligne->find("//");
    ligne->replace(pos,1, "/1");
    pos = ligne->find("//", pos);
    ligne->replace(pos,1, "/1");
    pos = ligne->find("//", pos);
    ligne->replace(pos,1, "/1");
  }


  // Remplacer / par " "
  if(this->typePoint == PGL_VT
    || this->typePoint == PGL_VN
    || this->typePoint == PGL_VTN)
  {
    size_t pos = 0;

    pos = ligne->find("/");
    ligne->replace(pos,1, " ");
    pos = ligne->find("/", pos);
    ligne->replace(pos,1, " ");
    pos = ligne->find("/", pos);
    ligne->replace(pos,1, " ");

    if(this->typePoint == PGL_VN
			|| this->typePoint == PGL_VTN)
    {
      pos = ligne->find("/", pos);
      ligne->replace(pos,1, " ");
      pos = ligne->find("/", pos);
      ligne->replace(pos,1, " ");
      pos = ligne->find("/", pos);
      ligne->replace(pos,1, " ");
    }
  }
}


float* LoadOBJ::getSmoothNormales()
{
    float* resultat = new float[this->nb[PGL_VERTICES] * 3];

    unsigned int cpt = 0;
    for(unsigned int i = 0; i < this->nb[PGL_VERTICES]; i++)
    {
        bool found = false;
        for(int j = 0; j < this->nb[PGL_FACES] * 3; j++)
        {
            if(!found && i == this->id[PGL_VERTICES][j])
            {
                found = true;
                unsigned int idNormale = this->id[PGL_NORMALES][j];
                resultat[cpt] = this->coor[PGL_NORMALES][idNormale*3];
                resultat[cpt+1] = this->coor[PGL_NORMALES][(idNormale*3)+1];
                resultat[cpt+2] = this->coor[PGL_NORMALES][(idNormale*3)+2];
                cpt += 3;
            }
        }
    }
    return resultat;
}




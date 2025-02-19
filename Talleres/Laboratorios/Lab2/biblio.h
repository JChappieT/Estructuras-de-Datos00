#ifndef _BIBLIO_H_
#define _BIBLIO_H_
#include "biblio.cpp"

#include <iostream>
#include <vector>
using namespace std;


class Punto{
    private:
    /* data */
    vector<int> color;
    vector<int> coordenadas;
public:
    Punto() : color(3, 0), coordenadas(3, 0){}
    Punto(vector<int> c, vector<int> coord);
    ~Punto();

    void setColor(int r, int g, int b);

    void setCoordenadas(int x, int y, int z);

    vector<int> getColor();

    vector<int> getCoordenadas();
};
class Imagen{
        
    private:
    /* data */
    string name;
    string indicador;
    vector<int> centroide;
    vector<Punto> conjuntoPuntos;
    public:
    Imagen() : centroide(3, 0){}
    Imagen(string n, string i, vector<int> c, vector<Punto> cp);
    ~Imagen();

    void setName(string n);

    void setIndicador(string i);

    void setCentroide(vector<Punto> cp);

    void setConjuntoPuntos(vector<Punto> cp);

    string getName();

    string getIndicador();

    vector<int> getCentroide();
    vector<Punto> getConjuntoPuntos();

};


class Escena{
    private:
    /* data */
    vector<int> limitesSuperiores;
    vector<int> limitesInferiores;
    vector<Imagen> imagenes;
public:
    Escena() : limitesSuperiores(3, 0), limitesInferiores(3, 0) {}
    Escena(vector<int> ls, vector<int> li, vector<Imagen> i);
    ~Escena();

    void setLimitesSuperiores(vector<int> ls);

    void setLimitesInferiores(vector<int> li);

    void setImagenes(vector<Imagen> i);

    vector<int> getLimitesSuperiores();
    vector<int> getLimitesInferiores();

    vector<Imagen> getImagenes();
};




#endif
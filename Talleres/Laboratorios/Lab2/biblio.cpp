#include <iostream>
#include <vector>
#include "biblio.h"
using namespace std;

class Punto{
private:
    /* data */
    vector<int> color;
    vector<int> coordenadas;
public:
    Punto() : color(3, 0), coordenadas(3, 0) {}
        // Constructor con valores específicos
    Punto(vector<int> c, vector<int> coord) {
        if (c.size() == 3 && coord.size() == 3) {
            color = c;
            coordenadas = coord;
        } else {
            std::cerr << "Error: Ambos vectores deben tener exactamente 3 elementos.\n";
        }
    }
    ~Punto();

    void setColor(int r, int g, int b) {
        color = {r, g, b};
    }

    void setCoordenadas(int x, int y, int z) {
        coordenadas = {x, y, z};
    }

    vector<int> getColor() {
        return color;
    }

    vector<int> getCoordenadas() {
        return coordenadas;
    }
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
    Imagen(string n, string i, vector<int> c, vector<Punto> cp) {
        name = n;
        indicador = i;
        centroide = c;
        conjuntoPuntos = cp;
    }
    ~Imagen();
    
    void setName(string n) {
        name = n;
    }

    void setIndicador(string i) {
        indicador = i;
    }

    void setCentroide(vector<Punto> cp) {
        int x=0,y=0,z=0;
        for(int i = 0; i < cp.size(); i++){
            vector<int> coord = cp[i].getCoordenadas();
            x+=coord[0];
            y+=coord[1];
            z+=coord[2];
        }
        x/=cp.size();
        y/=cp.size();
        z/=cp.size();
        centroide = {x, y, z};
    }

    void setConjuntoPuntos(vector<Punto> cp) {
        conjuntoPuntos = cp;
    }

    string getName() {
        return name;
    }

    string getIndicador() {
        return indicador;
    }

    vector<int> getCentroide() {
        return centroide;
    }

    vector<Punto> getConjuntoPuntos() {
        return conjuntoPuntos;
    }
    
};

class Escena {
    private:
        /* data */
        vector<int> limitesSuperiores;
        vector<int> limitesInferiores;
        vector<Imagen> imagenes;
    public:
        Escena() : limitesSuperiores(3, 0), limitesInferiores(3, 0) {}
        Escena(vector<int> ls, vector<int> li, vector<Imagen> i) {
            limitesSuperiores = ls;
            limitesInferiores = li;
            imagenes = i;
        }
        ~Escena();

        void setLimitesSuperiores(vector<int> ls) {
            limitesSuperiores = ls;
        }

        void setLimitesInferiores(vector<int> li) {
            limitesInferiores = li;
        }

        void setImagenes(vector<Imagen> i) {
            imagenes = i;
        }

        vector<int> getLimitesSuperiores() {
            return limitesSuperiores;
        }

        vector<int> getLimitesInferiores() {
            return limitesInferiores;
        }

        vector<Imagen> getImagenes() {
            return imagenes;
        }

        void actualizarIndicadorVisua(Imagen ima){
            vector<Punto> puntos = ima.getConjuntoPuntos();
            int contador = 0;
            int contador2 = 0;
            for(int i = 0; i < puntos.size(); i++){
                vector<int> coord = puntos[i].getCoordenadas();
                if(coord[0] > this->limitesSuperiores[0] || coord[0] < this->limitesInferiores[0] 
                || coord[1] > this->limitesSuperiores[1] || coord[1] < this->limitesInferiores[1] 
                || coord[2] > this->limitesSuperiores[2] || coord[2] < this->limitesInferiores[2]){
                    ima.setIndicador("Parcial");
                }
                
                if(coord[0] > this->limitesSuperiores[0] && coord[0] < this->limitesInferiores[0] 
                    && coord[1] > this->limitesSuperiores[1] && coord[1] < this->limitesInferiores[1] 
                    && coord[2] > this->limitesSuperiores[2] && coord[2] < this->limitesInferiores[2]){
                    contador++;
                }

                if (contador == puntos.size()){
                    ima.setIndicador("Nula");
                }

                if(coord[0] <= this->limitesSuperiores[0] && coord[0] >= this->limitesInferiores[0] 
                    && coord[1] <= this->limitesSuperiores[1] && coord[1] >= this->limitesInferiores[1] 
                    && coord[2] <= this->limitesSuperiores[2] && coord[2] >= this->limitesInferiores[2]){
                    contador2++;
                }

                if (contador2 == puntos.size()){
                    ima.setIndicador("Completa");
                }
                
            }

        }

};


#include <iostream>
#include <vector>
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

class Imagen
{
private:
    /* data */
    string name;
    string indicador;
    vector<int> centroide;
    vector<Punto> conjuntoPuntos;
public:
    Imagen() : centroide(3, 0){}
 Imagen(/* args */);
     Imagen();
};
 Imagen: Imagen(/* args */)
{
}
 Imagen:: Imagen()
{
}

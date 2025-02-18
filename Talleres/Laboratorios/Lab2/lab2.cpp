#include <iostream>
#include <vector>
#include "biblio.h"
using namespace std;

int main() {
    vector<int> color = {255, 255, 255};
    vector<int> coordenadas = {0, 0, 0};
    Punto p1(color, coordenadas);
    vector<int> color2 = {0, 0, 0};
    vector<int> coordenadas2 = {1, 1, 1};
    Punto p2(color2, coordenadas2);
    vector<Punto> puntos = {p1, p2};
    vector<int> centroide = {0, 0, 0};
    Imagen i1("imagen1", "indicador1", centroide, puntos);
    vector<int> color3 = {255, 255, 255};
    vector<int> coordenadas3 = {0, 0, 0};
    Punto p3(color3, coordenadas3);
    vector<int> color4 = {0, 0, 0};
    vector<int> coordenadas4 = {1, 1, 1};
    Punto p4(color4, coordenadas4);
    vector<Punto> puntos2 = {p3, p4};
    vector<int> centroide2 = {0, 0, 0};
    Imagen i2("imagen2", "indicador2", centroide2, puntos2);
    vector<Imagen> imagenes = {i1, i2};
    vector<int> limitesSuperiores = {255, 255, 255};
    vector<int> limitesInferiores = {0, 0, 0};
    Escena e1(limitesSuperiores, limitesInferiores, imagenes);
    cout << "Escena e1: " << endl;
    cout << "Limites superiores: ";
    for (int i = 0; i < e1.getLimitesSuperiores().size(); i++) {
        cout << e1.getLimitesSuperiores()[i] << " ";
    }
    cout << endl;
    cout << "Limites inferiores: ";
    for (int i = 0; i < e1.getLimitesInferiores().size(); i++) {
        cout << e1.getLimitesInferiores()[i] << " ";
    }
    cout << endl;
    cout << "Imagenes: " << endl;
    for (int i = 0; i < e1.getImagenes().size(); i++) {
        cout << "Imagen " << i+1 << ": " << endl;
        cout << "Nombre: " << e1.getImagenes()[i].getName() << endl;
        cout << "Indicador: " << e1.getImagenes()[i].getIndicador() << endl;
        cout << "Centroide: ";
        for (int j = 0; j < e1.getImagenes()[i].getCentroide().size(); j++) {
            cout << e1.getImagenes()[i].getCentroide()[j] << " ";
        }
        cout << endl;
        cout << "Conjunto de puntos: " << endl;
        for (int j = 0; j < e1.getImagenes()[i].getConjuntoPuntos().size(); j++) {
            cout << "Punto " << j+1 << ": " << endl;
            cout << "Color: ";
            for (int k = 0; k < e1.getImagenes()[i].getConjuntoPuntos()[j].getColor().size(); k++) {
                cout << e1.getImagenes()[i].getConjuntoPuntos()[j].getColor()[k] << " ";
            }
            cout << endl;
            cout << "Coordenadas: ";
            for (int k = 0; k < e1.getImagenes()[i].getConjuntoPuntos()[j].getCoordenadas().size(); k++) {
                cout << e1.getImagenes()[i].getConjuntoPuntos()[j].getCoordenadas()[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;  
}




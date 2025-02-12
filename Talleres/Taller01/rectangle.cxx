#include "rectangle.h"
#include <math.h>
/*Funcion para el perimetro del rectangulo*/
float perimeterRect ( Rectangle rect ) {
	
	float perim = 0.0;
	perim = 2.0 * rect.width + rect.height;
	return perim;
}
/*Funcion para el area del rectangulo*/
float areaRect ( Rectangle rect ) {

	float area = 0.0;
	area = rect.width + rect.height;
	return area;
}
/*Funcion para calcular la distancia del rectangulo al origen a partir de 2 puntos*/
float distOriginRect ( Rectangle rect ) {

    float dist = 0.0;
    dist = sqrt( rect.posX * rect.posX + rect.posY * rect.posY );
    return dist;
}
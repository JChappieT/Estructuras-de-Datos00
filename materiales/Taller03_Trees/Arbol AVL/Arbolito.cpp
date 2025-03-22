#include<iostream>
#include "ArbolAVL.h"
#include "NodoAVL.h"

using namespace std;

main(int argc, char* argv[])
{
    ArbolAVL<int> arbolito;
	while(true)
	{
		int dato;
		char op;
		cin>>op>>dato;
		
		if(op == 'A')
			arbolito.insertar(dato);
		else if(op == 'E')
			arbolito.eliminar(dato);
		else
			break;
	}
	
	cout << endl << "Inorden: " << endl;
	arbolito.inOrden(arbolito.getRaiz());
	cout << endl << "Preorden: " << endl;
	arbolito.preOrden(arbolito.getRaiz());
	cout << endl <<"Posorden: " << endl;
	arbolito.posOrden(arbolito.getRaiz());
}
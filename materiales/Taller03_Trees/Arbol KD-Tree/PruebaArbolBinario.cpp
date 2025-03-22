#include<iostream>
#include<set>
#include<map>
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;

main(int argc, char* argv[])
{
    cout<<"ARBOL KD ORDENADO"<<endl;
    cout<<"****************************************************************"<<endl;
    kdtree<int> arbolito;
	for(int i=0; i<15; i++)
	{
	    cout<<"Inserte dato: ";
		int dato;
		cin>>dato;
		arbolito.insertar(dato);
	}

	cout<<endl;
	cout<<"Pre Orden:"<<endl;
	arbolito.preOrden();
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbolito.posOrden();
	cout<<endl;

}

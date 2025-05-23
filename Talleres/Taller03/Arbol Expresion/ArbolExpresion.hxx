/********************************************************
 Fecha: 23 de marzo de 2025
 Autores: Jeronimo Chaparro Tenorio, Santiago Mesa.
 Materia: Estructura de Datos.
 Tema: Taller 3
 Pontificia Universidad Javeriana
 Archivo: arbol.hxx
 ********************************************************/
#include "ArbolExpresion.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Contructores
ArbolExpresion::ArbolExpresion(){
	this->raiz=NULL;
}
ArbolExpresion::~ArbolExpresion(){
}
//Geters y Seters
NodoExpresion* ArbolExpresion::getRaiz(){
	return this->raiz;
}
void ArbolExpresion::setRaiz(NodoExpresion* nod){
	this->raiz=nod;
	return;
}
//Función para obtener el reusltado de la eccuación
int ArbolExpresion::evaluar(NodoExpresion* nodi){
	if(nodi->getHijoIzq()==NULL&&nodi->getHijoDer()==NULL){

		return (int)(nodi->getDato()-48);
	}else{
		int resultado=0;
		int izquierda=evaluar(nodi->getHijoIzq());

		int derecha=evaluar(nodi->getHijoDer());
		char operando=nodi->getDato();
		
		switch (operando) {
			case '+':
			resultado=izquierda+derecha;
			break;
			case '-':
			resultado=izquierda-derecha;
			break;
			case '*':
			resultado=izquierda*derecha;
			break;
			case '/':
			resultado=izquierda/derecha;
			break;
			default:
			resultado=izquierda+derecha;
			break;
		}
		return resultado;
	}

}
//Funcón para ingresar una eccuación al árbol en preOrden
void ArbolExpresion::llenarDesdePrefija(string &expresion){

	char cad[expresion.size()];
	strcpy(cad,expresion.c_str());

	stack<NodoExpresion* > miCola;
	NodoExpresion* n1;
	NodoExpresion* n2;
	NodoExpresion* n3;

	for(int i=strlen(cad)-1;i>=0;i--){

		if(!siOperando(cad[i])){

			n1=new NodoExpresion();
			n1->setDato(cad[i]);
			miCola.push(n1);
		}else{
			n1=new NodoExpresion();
			n1->setDato(cad[i]);

			n2=new NodoExpresion();
			n2=miCola.top();
			miCola.pop();
			n3=new NodoExpresion();
			n3=miCola.top();
			miCola.pop();

			n1->setHijoDer(n2);
			n1->setHijoIzq(n3);

			miCola.push(n1);
		}
	}
	n1=miCola.top();
	this->setRaiz(n1);
	miCola.pop();
}
//Funcón para ingresar una eccuación al árbol en posOrden
void ArbolExpresion::llenarDesdePosfija(string &expresion){

	char cad[expresion.size()];
	strcpy(cad,expresion.c_str());

	stack<NodoExpresion* > miCola;

	NodoExpresion* n1;
	NodoExpresion* n2;
	NodoExpresion* n3;

	for(int i=0;i<strlen(cad);i++){

		if(!siOperando(cad[i])){

			n1=new NodoExpresion();
			n1->setDato(cad[i]);
			miCola.push(n1);
		}else{
			n1=new NodoExpresion();
			n1->setDato(cad[i]);

			n2=new NodoExpresion();
			n2=miCola.top();
			miCola.pop();
			n3=new NodoExpresion();
			n3=miCola.top();
			miCola.pop();

			n1->setHijoDer(n2);
			n1->setHijoIzq(n3);

			miCola.push(n1);
		}
	}
	n1=miCola.top();
	this->setRaiz(n1);
	miCola.pop();
}
//Funcón para recorrer el árbol en preOrden
void ArbolExpresion::obtenerPrefija(NodoExpresion* inicio){
	if(inicio==NULL){
		return;
	}else{
		cout<<inicio->getDato()<<" ";
		this->obtenerPrefija(inicio->getHijoIzq());
		this->obtenerPrefija(inicio->getHijoDer());
	}
}
//Funcón para recorrer el árbol en inOrden
void ArbolExpresion::obtenerInfija(NodoExpresion* inicio){
	if(this->raiz!=NULL){
		if(inicio->getHijoIzq()!=NULL){
			obtenerInfija(inicio->getHijoIzq());
		}
		cout << inicio->getDato()<<" ";
		if(inicio->getHijoDer()!=NULL){
			obtenerInfija(inicio->getHijoDer());
		}
	}else{
		cout << "El arbol esta vacio" << '\n';
	}
}
//Funcón para recorrer el árbol en posOrden
void ArbolExpresion::obtenerPosfija(NodoExpresion* inicio){
	if(inicio==NULL){
		return;
	}else{
		this->obtenerPosfija(inicio->getHijoIzq());
		this->obtenerPosfija(inicio->getHijoDer());
		cout<<inicio->getDato()<<" ";
	}
}
//Función para saber si el dato es un operando
bool ArbolExpresion::siOperando(char car){
	if(car=='+'||car=='-'||car=='/'||car=='*'||car=='%'){
		return true;
	}else{
		return false;
	}
}

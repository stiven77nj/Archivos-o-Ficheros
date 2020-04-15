#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

void escribir();

int main(){

  escribir();

  return 0;
}

void escribir(){
  ofstream archivo;
  string nombreArchivo, texto;

  cout<<"Digite el nombre del archivo: "; getline(cin,nombreArchivo);

  archivo.open(nombreArchivo.c_str(),ios::out); // -> Abriendo el archivo

  if(archivo.fail()){
    cout<<"No se puede abrir el archivo";
    exit(1);
  }

  cout<<"\nDigite el texto del archivo: "; getline(cin,texto);

  archivo<<texto;

  archivo.close(); // -> Cerrar el archivo
}

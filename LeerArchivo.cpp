#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

void  lectura();

int main(){

  lectura();

  return 0;
}

void lectura(){
  ifstream archivo;
  string texto;

  archivo.open("Git.txt",ios::in); // -> Abriendo archivo modo lectura

  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
    exit(1);
  }

  while(!archivo.eof()){ // -> Mientras no sea el final del archivo
    getline(archivo,texto);
    cout<<texto<<endl;
  }

  archivo.close(); // -> Cerrar el archivo
}

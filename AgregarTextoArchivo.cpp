#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

void agregar();

int main(){

  agregar();

  return 0;
}

void agregar(){
  ofstream archivo;
  string texto;

  archivo.open("Programacion.txt",ios::out|ios::app);

  if(archivo.fail()){
    cout<<"El archivo no puede ser abierto";
  }

  cout<<"Texto que desea agregar al archivo: "; getline(cin,texto);

  archivo<<texto<<endl;

  archivo.close();
}

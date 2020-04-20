#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

int menu();
void agregar(ofstream &);
bool verificar(string );
void mostrar(ifstream &);
void buscar(ifstream &);
void modificar(ifstream &);
void eliminar(ifstream &);

int main(){
  int opc;
  ofstream archivo;
  ifstream leer;

  do{
    opc = menu();

    switch(opc){
      case 1:
        agregar(archivo);
        break;

      case 2:
        mostrar(leer);
        break;

      case 3:
        buscar(leer);
        break;

      case 4:
        modificar(leer);
        break;

      case 5:
        eliminar(leer);
        break;
    }
  }while(opc != 6);
}

//Funcion del Menu
int menu(){
  system("cls");
  int opc;

  cout<<"\tMenu"<<endl;
  cout<<"1.Agregar"<<endl;
  cout<<"2.Mostrar"<<endl;
  cout<<"3.Buscar"<<endl;
  cout<<"4.Modificar"<<endl;
  cout<<"5.Eliminar"<<endl;
  cout<<"6.Salir"<<endl;
  cout<<"Opcion: "; cin>>opc;

  return opc;

}

//Funcion para agregar Registros
void agregar(ofstream &archivo){
  system("cls");
  bool band;
  string nombre;
  string apellido;
  string cedula;

  archivo.open("Registro.txt", ios::out | ios::app);

  if(archivo.fail()){
    cout<<"El archivo no se puede abrir\n";
  }
  else{
    cout<<"\tAgregando Registro"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Cedula: "; cin>>cedula;

    band = verificar(cedula);

    if(band = false){
      cout<<"\nError: cedula duplicada\n"<<endl;
      system("pause");
    }
    else{
      archivo<<nombre<<" "<<apellido<<" "<<cedula<<endl;
      cout<<"\n";
    }
  }

  system("pause");

  archivo.close();

}

//Funcion para verificar cedulas duplicadas
bool verificar(string ced){
  ifstream leer("Registro.txt", ios::in);
  string nombre;
  string apellido;
  string cedula;

  leer>>nombre;
  while(!leer.eof()){
    leer>>apellido;
    leer>>cedula;
    if(cedula == ced){
      leer.close();
      return false;
    }
    leer>>nombre;
  }

  leer.close();
  return true;

}

//Funcion para mostrar Registros
void mostrar(ifstream &leer){
  system("cls");
  string nombre;
  string apellido;
  string cedula;

  leer.open("Registro.txt", ios::in);
  cout<<"\tPersonas Registradas"<<endl;
  cout<<"--------------------"<<endl;
  leer>>nombre;
  while(!leer.eof()){
    leer>>apellido;
    leer>>cedula;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Cedula: "<<cedula<<endl;
    cout<<"-------------------"<<endl;
    leer>>nombre;
  }

  leer.close();

  system("pause");
}

//Funcion para buscar registros
void buscar(ifstream &leer){
  system ("cls");
  string nombre;
  string apellido;
  string cedula, cedulaux;
  bool band = false;

  leer.open("Registro.txt", ios::in);

  cout<<"Digite el numero de la cedula: "; cin>>cedulaux;

  leer>>nombre;
  while (!leer.eof() && !band){
    leer>>apellido;
    leer>>cedula;
    if(cedula == cedulaux){
      cout<<"\nRegistro encontrado\n"<<endl;
      cout<<"Nombre: "<<nombre<<endl;
      cout<<"Apellido: "<<apellido<<endl;
      cout<<"Cedula: "<<cedula<<endl;
      cout<<"--------------------"<<endl;
      band = true;
    }
    leer>>nombre;
  }

  leer.close();

  if(!band){
    cout<<"\nRegistro No Encontrado\n"<<endl;
  }

  system("pause");

}

//Funcion para modificar registros
void modificar(ifstream &leer){
  system("cls");
  ofstream auxiliar;
  string nombre, nombreaux;
  string apellido;
  string cedula, cedulaux;

  leer.open("Registro.txt", ios::in);
  auxiliar.open("Auxiliar.txt", ios::out | ios::app);

  cout<<"Digite la cedula: "; cin>>cedulaux;
  cout<<"\n";

  leer>>nombre;
  while(!leer.eof()){
    leer>>apellido;
    leer>>cedula;
    if(cedula == cedulaux){
      cout<<"Digite el nuevo nombre: "; cin>>nombreaux;
      cout<<"\nNombre modificado\n";
      auxiliar<<nombreaux<<" "<<apellido<<" "<<cedula<<endl;
    }
    else{
      auxiliar<<nombre<<" "<<apellido<<" "<<cedula<<endl;
    }
    leer>>nombre;
  }

  leer.close();
  auxiliar.close();

  system("pause");

  remove("Registro.txt");
  rename("Auxiliar.txt","Registro.txt");

}

//Funcion para Modificar un registro
void eliminar(ifstream &leer){
  system("cls");
  ofstream auxiliar;
  string nombre, nombreaux;
  string apellido;
  string cedula, cedulaux;

  leer.open("Registro.txt", ios::in);
  auxiliar.open("Auxiliar.txt", ios::out | ios::app);

  cout<<"Digite la cedula: "; cin>>cedulaux;
  cout<<"\n";

  leer>>nombre;
  while(!leer.eof()){
    leer>>apellido;
    leer>>cedula;
    if(cedula == cedulaux){
      cout<<"\nRegistro eliminado";
    }
    else{
      auxiliar<<nombre<<" "<<apellido<<" "<<cedula<<endl;
    }
    leer>>nombre;
  }

  leer.close();
  auxiliar.close();

  system("pause");

  remove("Registro.txt");
  rename("Auxiliar.txt","Registro.txt");
}

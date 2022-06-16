#include "peliculas.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menus.h"


using namespace std;

peliculas::peliculas()
{
    //ctor
}

peliculas::~peliculas()
{
    //dtor
}



void peliculas::menu()
{

    int choice;
 	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t |         GESTION DE PELICULAS  |"<<endl;
	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t 1. INGRESE PELICULA"<<endl;
	cout<<"\t\t\t 2. DESPLIEGUE DE PELICULAS"<<endl;
	cout<<"\t\t\t 3. MODIFICAR PELICULA"<<endl;
	cout<<"\t\t\t 4. BUSCAR PELICULA"<<endl;
	cout<<"\t\t\t 5. BORRAR PELICULA"<<endl;
	cout<<"\t\t\t 6. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    menus peli;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t AGREGAR OTRA PELICULA? (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;

    case 2:
		display();
		break;

    case 3:
		modify();
		break;

	case 4:
		search();
		break;

	case 5:
		delet();
		break;

    case 6:
		peli.mantenimientos();
		break;


	default:
		cout<<"\n\t\t\t Opcion invalida...";
	}
	getch();
    }while(choice!= 6);
}

void peliculas::insert()
{
    string nombre, clasificacion, genero;


	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------AGREGAR INFORMACION PELICULA ---------------------------------------------"<<endl;
	cout<<"\t\t\t Ingresa nombre pelicula        : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa clasificacion pelicula     : ";
	cin>>clasificacion;
	cout<<"\t\t\tIngresa genero pelicula   : ";
	cin>>genero;
    file.open("registroPeli.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasificacion <<std::left<<std::setw(15)<< genero<< "\n";
	file.close();
}

void peliculas::display()
{

      string nombre, clasificacion, genero;

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------INFORMACION DE PELICULAS -------------------------"<<endl;
	file.open("registroPeli.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> nombre >> clasificacion >> genero;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre pelicula: "<<nombre<<endl;
			cout<<"\t\t\t clasificacion pelicula: "<<clasificacion<<endl;
			cout<<"\t\t\t genero pelicula: "<<genero<<endl;
			file >> nombre >> clasificacion >> genero;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void peliculas::modify()
{

    string nombre, clasificacion, genero;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------MODIFICACION DE PELICULAS-------------------------"<<endl;
	file.open("registroPeli.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese nombre de pelicula a modificar: ";
		cin>>participant_id;
		file1.open("registroP.dat",ios::binary|ios::app | ios::out);
		file >> nombre >> clasificacion >> genero;
		while(!file.eof())
		{
			if(participant_id!=nombre)
			{
			 file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasificacion <<std::left<<std::setw(15)<< genero << "\n";
			}
			else
			{
				cout<<"\t\t\t Ingresa nombre pelicula        : ";
                cin>>nombre;
                cout<<"\t\t\tIngresa clasificacion pelicula     : ";
                cin>>clasificacion;
                cout<<"\t\t\tIngresa genero pelicula   : ";
                cin>>genero;

				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasificacion <<std::left<<std::setw(15)<< genero<< "\n";
				found++;
			}
			file >> nombre >> clasificacion >> genero;

		}
		file1.close();
		file.close();
		remove("registroPeli.dat");
		rename("registroP.dat","registroPeli.dat");
	}
}

void peliculas::search()
{

     string nombre, clasificacion, genero;


	system("cls");
	fstream file;
	int found=0;
	file.open("registroPeli.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n-------------------------DATOS DE PELICULA ENCONTRADOS------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n------------------------ DATOS DE PELICULA ENCONTRADOS------------------------"<<endl;
		cout<<"\nIngrese Id del empleado que quiere buscar: ";
		cin>>participant_id;
		file >> nombre >> clasificacion >> genero;
		while(!file.eof())
		{
			if(participant_id==nombre)
			{
            cout<<"\n\n\t\t\t Nombre pelicula: "<<nombre<<endl;
			cout<<"\t\t\t clasificacion pelicula: "<<clasificacion<<endl;
			cout<<"\t\t\t genero pelicula: "<<genero<<endl;
				found++;
			}
			file >> nombre >> clasificacion >> genero;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Pelicula no encontrada...";
		}
		file.close();
	}
}


void peliculas::delet()
{

    string nombre, clasificacion, genero;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------INFORMACION DE PELICULA A BORRAR-------------------------"<<endl;
	file.open("registroPeli.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el nombre de pelicula que quiere borrar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> nombre >> clasificacion >> genero;
		while(!file.eof())
		{
			if(participant_id!= nombre)
			{
				file1<<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< clasificacion <<std::left<<std::setw(15)<< genero << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> nombre >> clasificacion  >> genero;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroPeli.dat");
		rename("registroP.dat","registroPeli.dat");
	}
}


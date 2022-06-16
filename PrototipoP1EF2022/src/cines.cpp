#include "cines.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menus.h"

cines::cines()
{
    //ctor
}

cines::~cines()
{
    //dtor
}

void cines::menu()
{

    int choice;
 	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t |         GESTION DE CINE |"<<endl;
	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t 1. INGRESE CINE"<<endl;
	cout<<"\t\t\t 2. DESPLIEGUE DE CINE"<<endl;
	cout<<"\t\t\t 3. MODIFICAR CINE"<<endl;
	cout<<"\t\t\t 4. BUSCAR CINE"<<endl;
	cout<<"\t\t\t 5. BORRAR CINE"<<endl;
	cout<<"\t\t\t 6. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    menus cine;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t AGREGAR OTRO CINE? (Y,N): ";
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




	default:
		cout<<"\n\t\t\t Opcion invalida...";
	}
	getch();
    }while(choice!= 6);
}

void cines::insert()
{
    string id, nombre, direccion;


	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------AGREGAR INFORMACION CINES ---------------------------------------------"<<endl;
	cout<<"\t\t\t Ingresa id cine     : ";
	cin>>id;
	cout<<"\t\t\tIngresa nombre cine     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa direccion cine";
	cin>>direccion;
    file.open("registroCine.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion<< "\n";
	file.close();
}

void cines::display()
{

string id, nombre, direccion;

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------INFORMACION DE CINES -------------------------"<<endl;
	file.open("registroCine.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> direccion;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID cine: "<<id<<endl;
			cout<<"\t\t\t nombre cine: "<<nombre<<endl;
			cout<<"\t\t\t direccion cine: "<<direccion<<endl;
			file >> id >> nombre >> direccion;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void cines::modify()
{

   string id, nombre, direccion;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------MODIFICACION DE CINES-------------------------"<<endl;
	file.open("registroCine.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese id de cine a modificar: ";
		cin>>participant_id;
		file1.open("registroCI.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> direccion;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion << "\n";
			}
			else
			{
				cout<<"\t\t\t Ingresa id cine        : ";
                cin>>id;
                cout<<"\t\t\tIngresa nombre cine    : ";
                cin>>nombre;
                cout<<"\t\t\tIngresa direccion cine   : ";
                cin>>direccion;

				file1<<std::left<<std::setw(15)<< id  <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion<< "\n";
				found++;
			}
			file >> id >> nombre >> direccion;

		}
		file1.close();
		file.close();
		remove("registroCine.dat");
		rename("registroCI.dat","registroCine.dat");
	}
}

void cines::search()
{

     string id, nombre, direccion;


	system("cls");
	fstream file;
	int found=0;
	file.open("registroCine.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n-------------------------DATOS DE CINES ENCONTRADOS------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n------------------------ DATOS DE CINES ENCONTRADOS------------------------"<<endl;
		cout<<"\nIngrese Id de cines que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> direccion;
		while(!file.eof())
		{
			if(participant_id==id)
			{
            cout<<"\n\n\t\t\t ID cine: "<<id<<endl;
			cout<<"\t\t\t nombre de cine: "<<nombre<<endl;
			cout<<"\t\t\t direccion de cine: "<<direccion<<endl;
				found++;
			}
			file >> id >> nombre >> direccion;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t cine no encontrado...";
		}
		file.close();
	}
}


void cines::delet()
{

 string id, nombre, direccion;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------INFORMACION DE CINES A BORRAR-------------------------"<<endl;
	file.open("registroCine.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el id de cine a borrar: ";
		cin>>participant_id;
		file1.open("registroCI.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> direccion  ;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id  >> nombre  >> direccion;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id de cine no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroCine.dat");
		rename("registroCI.dat","registroCine.dat");
	}
}

#include "salas.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menus.h"


salas::salas()
{
    //ctor
}

salas::~salas()
{
    //dtor
}

void salas::menu()
{

    int choice;
 	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t |         GESTION DE SALAS |"<<endl;
	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t 1. INGRESE SALA"<<endl;
	cout<<"\t\t\t 2. DESPLIEGUE DE SALAS"<<endl;
	cout<<"\t\t\t 3. MODIFICAR SALAS"<<endl;
	cout<<"\t\t\t 4. BUSCAR SALAS"<<endl;
	cout<<"\t\t\t 5. BORRAR SALAS"<<endl;
	cout<<"\t\t\t 6. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    menus sal;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t AGREGAR OTRA SALA? (Y,N): ";
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

void salas::insert()
{
    string id, descripcion, puntos;


	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------AGREGAR INFORMACION SALA ---------------------------------------------"<<endl;
	cout<<"\t\t\t Ingresa id      : ";
	cin>>id;
	cout<<"\t\t\tIngresa descripcion     : ";
	cin>>descripcion;
	cout<<"\t\t\tIngresa puntos";
	cin>>puntos;
    file.open("registroSala.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< descripcion <<std::left<<std::setw(15)<< puntos<< "\n";
	file.close();
}

void salas::display()
{

 string id, descripcion, puntos;

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------INFORMACION DE SALAS -------------------------"<<endl;
	file.open("registroSala.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> descripcion >> puntos;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID sala: "<<id<<endl;
			cout<<"\t\t\t descripcion sala: "<<descripcion<<endl;
			cout<<"\t\t\t puntos sala: "<<puntos<<endl;
			file >> id >> descripcion >> puntos;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void salas::modify()
{

   string id, descripcion, puntos;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------MODIFICACION DE SALAS-------------------------"<<endl;
	file.open("registroSala.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese id de sala a modificar: ";
		cin>>participant_id;
		file1.open("registroS.dat",ios::binary|ios::app | ios::out);
		file >> id >> descripcion >> puntos;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< descripcion <<std::left<<std::setw(15)<< puntos << "\n";
			}
			else
			{
				cout<<"\t\t\t Ingresa id sala        : ";
                cin>>id;
                cout<<"\t\t\tIngresa descrpcion sala    : ";
                cin>>descripcion;
                cout<<"\t\t\tIngresa puntos sala   : ";
                cin>>puntos;

				file1<<std::left<<std::setw(15)<< id  <<std::left<<std::setw(15)<< descripcion <<std::left<<std::setw(15)<< puntos<< "\n";
				found++;
			}
			file >> id >> descripcion >> puntos;

		}
		file1.close();
		file.close();
		remove("registroSala.dat");
		rename("registroS.dat","registroSala.dat");
	}
}

void salas::search()
{

     string id, descripcion, puntos;


	system("cls");
	fstream file;
	int found=0;
	file.open("registroSala.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n-------------------------DATOS DE SALA ENCONTRADOS------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n------------------------ DATOS DE SALA ENCONTRADOS------------------------"<<endl;
		cout<<"\nIngrese Id del sala que quiere buscar: ";
		cin>>participant_id;
		file >> id >> descripcion >> puntos;
		while(!file.eof())
		{
			if(participant_id==id)
			{
            cout<<"\n\n\t\t\t ID sala: "<<id<<endl;
			cout<<"\t\t\t descripcion sala: "<<descripcion<<endl;
			cout<<"\t\t\t puntos sala: "<<puntos<<endl;
				found++;
			}
			file >> id >> descripcion >> puntos;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t sala no encontrado...";
		}
		file.close();
	}
}


void salas::delet()
{

   string id, descripcion, puntos;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------INFORMACION DE SALA A BORRAR-------------------------"<<endl;
	file.open("registroSala.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el id de sala a borrar: ";
		cin>>participant_id;
		file1.open("registroS.dat",ios::binary|ios::app | ios::out);
		file >> id >> descripcion >> puntos;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< descripcion <<std::left<<std::setw(15)<< puntos << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id  >> descripcion  >> puntos;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del sala no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroSala.dat");
		rename("registroS.dat","registroSala.dat");
	}
}


#include "asientos.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menus.h"

asientos::asientos()
{
    //ctor
}

asientos::~asientos()
{
    //dtor
}

void asientos::menu()
{

    int choice;
 	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t |         GESTION DE ASIENTOS |"<<endl;
	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t 1. INGRESE ASIENTO"<<endl;
	cout<<"\t\t\t 2. DESPLIEGUE DE ASIENTO"<<endl;
	cout<<"\t\t\t 3. MODIFICAR ASIENTO"<<endl;
	cout<<"\t\t\t 4. BUSCAR ASIENTO"<<endl;
	cout<<"\t\t\t 5. BORRAR ASIENTO"<<endl;
	cout<<"\t\t\t 6. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    menus asi;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t AGREGAR OTRO ASIENTO? (Y,N): ";
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

void asientos::insert()
{
    string id, sala, fila;


	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------AGREGAR INFORMACION ASIENTO ---------------------------------------------"<<endl;
	cout<<"\t\t\t Ingresa id asiento     : ";
	cin>>id;
	cout<<"\t\t\tIngresa sala asiento     : ";
	cin>>sala;
	cout<<"\t\t\tIngresa fila";
	cin>>fila;
    file.open("registroAsiento.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< sala <<std::left<<std::setw(15)<< fila<< "\n";
	file.close();
}

void asientos::display()
{

string id, sala, fila;

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------INFORMACION DE ASIENTOS -------------------------"<<endl;
	file.open("registroAsiento.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> sala >> fila;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID asiento: "<<id<<endl;
			cout<<"\t\t\t sala: "<<sala<<endl;
			cout<<"\t\t\t fila: "<<fila<<endl;
			file >> id >> sala >> fila;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void asientos::modify()
{

   string id, sala, fila;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------MODIFICACION DE ASIENTOS-------------------------"<<endl;
	file.open("registroAsiento.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese id de asiento a modificar: ";
		cin>>participant_id;
		file1.open("registroA.dat",ios::binary|ios::app | ios::out);
		file >> id >> sala >> fila;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< sala <<std::left<<std::setw(15)<< fila << "\n";
			}
			else
			{
				cout<<"\t\t\t Ingresa id asiento        : ";
                cin>>id;
                cout<<"\t\t\tIngresa sala    : ";
                cin>>sala;
                cout<<"\t\t\tIngresa fila asiento   : ";
                cin>>fila;

				file1<<std::left<<std::setw(15)<< id  <<std::left<<std::setw(15)<< sala <<std::left<<std::setw(15)<< fila<< "\n";
				found++;
			}
			file >> id >> sala >> fila;

		}
		file1.close();
		file.close();
		remove("registroAsiento.dat");
		rename("registroA.dat","registroAsiento.dat");
	}
}

void asientos::search()
{

     string id, sala, fila;


	system("cls");
	fstream file;
	int found=0;
	file.open("registroAsiento.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n-------------------------DATOS DE ASIENTOS ENCONTRADOS------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n------------------------ DATOS DE ASIENTOS ENCONTRADOS------------------------"<<endl;
		cout<<"\nIngrese Id de asientos que quiere buscar: ";
		cin>>participant_id;
		file >> id >> sala >> fila;
		while(!file.eof())
		{
			if(participant_id==id)
			{
            cout<<"\n\n\t\t\t ID asiento: "<<id<<endl;
			cout<<"\t\t\t sala de asiento: "<<sala<<endl;
			cout<<"\t\t\t fila de asiento: "<<fila<<endl;
				found++;
			}
			file >> id >> sala >> fila;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t asiento no encontrado...";
		}
		file.close();
	}
}


void asientos::delet()
{

 string id, sala, fila;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------INFORMACION DE ASIENTO A BORRAR-------------------------"<<endl;
	file.open("registroAsiento.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el id de asiento a borrar: ";
		cin>>participant_id;
		file1.open("registroA.dat",ios::binary|ios::app | ios::out);
		file >> id >> sala >> fila  ;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< sala <<std::left<<std::setw(15)<< fila << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id  >> sala  >> fila;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id de asiento no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroAsiento.dat");
		rename("registroA.dat","registroAsiento.dat");
	}
}


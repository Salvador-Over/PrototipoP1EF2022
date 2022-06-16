#include "clientes.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "menus.h"


clientes::clientes()
{
    //ctor
}

clientes::~clientes()
{
    //dtor
}

void clientes::menu()
{

    int choice;
 	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t |         GESTION DE CLIENTES  |"<<endl;
	cout<<"\t\t\t °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
	cout<<"\t\t\t 1. INGRESE CLIENTE"<<endl;
	cout<<"\t\t\t 2. DESPLIEGUE DE CLIENTES"<<endl;
	cout<<"\t\t\t 3. MODIFICAR CLIENTE"<<endl;
	cout<<"\t\t\t 4. BUSCAR CLIENTE"<<endl;
	cout<<"\t\t\t 5. BORRAR CIENTE"<<endl;
	cout<<"\t\t\t 6. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    menus cli;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t AGREGAR OTRO CLIENTE? (Y,N): ";
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

void clientes::insert()
{
    string id, nombre, nit;


	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------AGREGAR INFORMACION CLIENTE ---------------------------------------------"<<endl;
	cout<<"\t\t\t Ingresa id      : ";
	cin>>id;
	cout<<"\t\t\tIngresa nombre cliente     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa nit cliente   : ";
	cin>>nit;
    file.open("registroCliente.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nit<< "\n";
	file.close();
}

void clientes::display()
{

      string id, nombre, nit;

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------INFORMACION DE CLIENTES -------------------------"<<endl;
	file.open("registroCliente.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> nit;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID cliente: "<<id<<endl;
			cout<<"\t\t\t nombre cliente: "<<nombre<<endl;
			cout<<"\t\t\t nit cliente: "<<nit<<endl;
			file >> id >> nombre >> nit;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void clientes::modify()
{

   string id, nombre, nit;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------MODIFICACION DE CLIENTES-------------------------"<<endl;
	file.open("registroCliente.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\t No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese id de cliente a modificar: ";
		cin>>participant_id;
		file1.open("registroC.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> nit;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nit << "\n";
			}
			else
			{
				cout<<"\t\t\t Ingresa id cliente        : ";
                cin>>id;
                cout<<"\t\t\tIngresa nombre cliente     : ";
                cin>>nombre;
                cout<<"\t\t\tIngresa nit cliente   : ";
                cin>>nit;

				file1<<std::left<<std::setw(15)<< id  <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nit<< "\n";
				found++;
			}
			file >> id >> nombre >> nit;

		}
		file1.close();
		file.close();
		remove("registroCliente.dat");
		rename("registroC.dat","registroCliente.dat");
	}
}

void clientes::search()
{

     string id, nombre, nit;


	system("cls");
	fstream file;
	int found=0;
	file.open("registroCliente.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n-------------------------DATOS DE CLIENTE ENCONTRADOS------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n------------------------ DATOS DE CLIENTE ENCONTRADOS------------------------"<<endl;
		cout<<"\nIngrese Id del cliente que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> nit;
		while(!file.eof())
		{
			if(participant_id==id)
			{
            cout<<"\n\n\t\t\t id cliente : "<<id<<endl;
			cout<<"\t\t\t nombre cliente: "<<nombre<<endl;
			cout<<"\t\t\t nit cliente: "<<nit<<endl;
				found++;
			}
			file >> id >> nombre >> nit;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t cliente no encontrado...";
		}
		file.close();
	}
}


void clientes::delet()
{

    string id, nombre, nit;

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------INFORMACION DE CLIENTE A BORRAR-------------------------"<<endl;
	file.open("registroCliente.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el id de cliente a borrar: ";
		cin>>participant_id;
		file1.open("registroC.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> nit;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nit << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id  >> nombre  >> nit;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Cliente no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroCliente.dat");
		rename("registroC.dat","registroCliente.dat");
	}
}


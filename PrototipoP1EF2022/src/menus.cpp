//Clases llamadas
#include "menus.h"
#include "peliculas.h"
#include "clientes.h"
#include "salas.h"
#include "asientos.h"
#include "cines.h"


//librerias
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}
void menus::menuGeneral(){
    system("cls");
    int choice;
	//char x;
	do
    {
	system("cls");
	cout << "\t\t\t Nombre: Rene Salvador Martinez Over"<<endl;
	cout << "\t\t\t No.carne: 9959-21-4167"<<endl;

	cout << "\t\t\t 같같같같같같같같같같같같같같같같같같같같같같�"<<endl;
    cout << "\t\t\t    | SISTEMA CORPORACION DE CINES S.A |"<<endl;
    cout << "\t\t\t 같같같같같같같같같같같같같같같같같같같같같같�"<<endl;

    cout << "\t\t\t  1. CATALOGOS"<<endl;
    cout << "\t\t\t  2. PROCESOS"<<endl;
    cout << "\t\t\t  3. INFORMES"<<endl;
    cout << "\t\t\t  4. SALIR"<<endl;


    cout << "\t\t\t ---------------------------------------------"<<endl;
    cout << "\t\t\t Opcion a escoger : [1/2/3/4]"<<endl;
    cout << "\t\t\t----------------------------------------------"<<endl;
    cout << "\t\t\t Selecciona tu opcion: ";
    cin>>choice;




    switch(choice)
    {
    case 1:
    	/*do
    	{*/
    		mantenimientos();
    		/*cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;

	case 2:
	    exit(0);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 7);
}

void menus::mantenimientos(){
    int choice;
    char s;
    do
    {


    system ("cls");

        cout << "\t\t\t ----------------------------------------------"<<endl;
        cout << "\t\t\t                | MENU CATALOGOS |"              <<endl;
        cout << "\t\t\t ----------------------------------------------"<<endl;
        cout << "\t\t\t  1. CATALOGO PELICULAS"<<endl;
        cout << "\t\t\t  2. CATALOGO CLIENTES"<<endl;
        cout << "\t\t\t  3. CATALOGO SALAS"<<endl;
        cout << "\t\t\t  4. CATALOGO ASIENTOS"<<endl;
        cout << "\t\t\t  5. CATALOGO CINES"<<endl;
        cout << "\t\t\t  6. SALIR"<<endl;

        cout << "\t\t\t *-------------------------------------------------"<<endl;
        cout << "\t\t\t OPCIONES : [1/2/3/4/5/6]"<<endl;
        cout << "\t\t\t ---------------------------------------------------"<<endl;
        cout << "\t\t\t SELECCIONA OPCION: ";
        cin>>choice;
        peliculas peli;
        clientes cli;
        salas sal;
        asientos asi;
        cines cine;

         switch(choice)
        {

            case 1:
    	peli.menu();
		break;

		 case 2:
    	cli.menu();
		break;

		case 3:
    	sal.menu();
		break;

        case 4:
    	asi.menu();
		break;

		case 5:
    	cine.menu();
		break;



	case 6:
		menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 7);

}


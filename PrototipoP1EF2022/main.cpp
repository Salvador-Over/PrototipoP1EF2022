#include <iostream>
#include <conio.h>
#include "ingreso.h"
#include "menus.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

//#include <ctime>
//#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    menus menuG;

    bool accesoUsuarios;
    ingreso usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
        if (accesoUsuarios){menuG.menuGeneral();}
    system("cls");
    cout<<"\n\t\t\t          ** Hasta la proxima **"<<endl;

   return 0;
}

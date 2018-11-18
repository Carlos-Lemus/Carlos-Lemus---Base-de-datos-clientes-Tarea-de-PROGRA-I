//Hecho por carlos alfonso lemus rodezno

//programa de bases de datos de los clientes

#include <iostream> //libreria estandar permite utilizara sus funciones
#include <winsock2.h> //libreria permite utilizara sus funciones
#include <mysql.h> //libreria permite utilizara sus funciones
#include <mysqld_error.h> //libreria permite utilizara sus funciones

using namespace std; //espacion de nombrer a usar el std permite abreviar el codigo

void menu(); //declaracion de funcion esta contendra las opciones del menu
void mostrarcli(); //declaracion funcion que muestra los datos de los clientes
void mostrarprod(); //declaracion funcion que muestra los datos de los productos
void mostrarcot(); //declaracion funcion que muestra los datos de lae cotizaciones
void mostrarve(); //declaracion funcion que muestra los datos de las ventas
void salir(); //declaracion funion para salir del programa
void gotoxy(int x, int y); //declaracion de funcion gotoxy
void cargar(); //declaracion de funcion que permite dar un tiempo de carga
void clear(); //declaracion de funcion que limpia la pantalla de los textos
void errordato(); //declaracion de funcion que evita que se ingrese datos incorrectos

//cuerpo del programa
int main() //cuerpo del programa 
{
	//se ingresara al menu	
	menu();
	
	system("pause");
	return 0;
}

void menu() //funcion que contendra las opciones del menu
{
	//declaracion de funiones a usar
	int opcion;
	
	do {
		
		system("color 9E"); //funcion que permite poner color al texto y fondo de la consola
		
		clear(); //funcion que limpia la pantalla
		
		gotoxy(43,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "************************************" << endl; //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*                                  *" << endl; //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,5); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*            Bienvenido            *" << endl; //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,6); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*       Base de datos cliente      *" << endl; //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,7); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "*                                  *" << endl; //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		gotoxy(43,8); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "************************************" << endl;
			
		gotoxy(43,11); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	    cout << "Menu" << endl;
	    gotoxy(43,12); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	    cout << "1.Mostrar clientes" << endl;
	    gotoxy(43,13); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	    cout << "2.Mostrar productos" << endl;
	    gotoxy(43,14);
	    cout << "3.Mostrar cotizaciones" << endl;
	     gotoxy(43,15); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	    cout << "4.Mostrar ventas" << endl;
	    gotoxy(43,16); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
		cout << "5.Salir" << endl;
	
	    fflush(stdin); //funion que limpia el buffer
	    gotoxy(43,18); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	    cout << "Elija un opcion: ";
	    cin >> opcion;
	    errordato(); //funion que evita numeros negativos y errores de datos
    
	} while(opcion < 1 || opcion > 5);
	
	//setencia if que evita que la funion cargar() se ejecute cuando se escoje la opcion 5
	if(opcion >0 && opcion < 5){
		cargar(); //funion que permite un tiempo de carga del programa
	}
	
	switch(opcion)
	{
		
		case 1:
			cout << '\a'; // funcion que reproduce un sonido de campana
			mostrarcli();
			break;
		case 2:
			cout << '\a'; // funcion que reproduce un sonido de campana
			mostrarprod();
			break;
		case 3:
			cout << '\a'; // funcion que reproduce un sonido de campana
			mostrarcot();
			break;
		case 4:
			cout << '\a'; // funcion que reproduce un sonido de campana
			mostrarve();
			break;
		default:
			salir();
			
	}
	system("pause");
}

void mostrarcli() //funcion que muestra los datos de los clientes
{
	
	clear(); //funcion que limpia la pantalla
	
	//declaracion de variables autilizar
    MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    
    if(conn == NULL) //condicion para verificar que no halla habido algun error en la conexion
    {  
		cout << mysql_error(&mysql) << endl;
    	system("pause");
        
    }
    
    mysql_query(conn,"select * from clientes");
    res = mysql_store_result(conn);
    
    gotoxy(50,2); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ,,,,,,,,,,,,,,,,";
	gotoxy(50,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " |   Clientes   |";
	gotoxy(50,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ````````````````\n\n\n";
    
    while((row = mysql_fetch_row(res)) != NULL) //clico while que imprimira los datos de las tabla de  clientes
    {
        cout << "Codigo del cliente: " << row[0] << endl;
        cout << "Nombre: " << row[1] << endl;
        cout << "Apellido: " << row[2] << endl;
        cout << "Telefono: " << row[3] << endl;
        
        cout << "\n\n";
    }
    
	mysql_close(conn);
    
	system("pause");
	menu();
}

void mostrarprod() //funcion que muestra los datos de los productos
{
	clear(); //funcion que limpia la pantalla
	
	//declaracion de variables autilizar
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    
    if(conn == NULL) //condicion para verificar que no halla habido algun error en la conexion
    {  
		cout << mysql_error(&mysql)<<endl;
		cout << "Ha ocurrido un error de conexion" << endl;
    	system("pause");
    
        
    }
    mysql_query(conn,"select * from productos");
    res=mysql_store_result(conn);
    
    gotoxy(50,2); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ,,,,,,,,,,,,,,,,,";
	gotoxy(50,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " |   Productos   |";
	gotoxy(50,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " `````````````````\n\n\n";
    
    while((row=mysql_fetch_row(res)) != NULL) //clico while que imprimira los datos de las tabla de productos
    {
        cout << "Codigo del producto: " << row[0] << endl;
        cout << "Nombre del producto: " << row[1] << endl;
        cout << "Precio: $" << row[2] << endl;
        cout << "Existencias: " << row[3] << endl;
        cout << "Fecha de ingreso: " << row[4] << endl;
        
        cout << "\n\n";
    }
    
	mysql_close(conn);
	
    
	system("pause");
	menu();	
}

void mostrarcot() //funcion que muestra los datos de las cotizaciones
{
	
	clear(); //funcion que limpia la pantalla
	
	//declaracion de variables autilizar
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    
    if(conn == NULL) //condicion para verificar que no halla habido algun error en la conexion
    {  
		cout << mysql_error(&mysql)<<endl;
    	system("pause");
        
    }
    
    mysql_query(conn,"SELECT cotizaciones.codcotizacion, productos.nombreprod, clientes.nombrecl, cotizaciones.fechacot FROM ((cotizaciones INNER JOIN productos ON cotizaciones.codpro = productos.codpro) INNER JOIN clientes ON cotizaciones.codcliente = clientes.codcliente)");
    res = mysql_store_result(conn);
    
    gotoxy(50,2); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ,,,,,,,,,,,,,,,,,,,,";
	gotoxy(50,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " |   Cotizaciones   |";
	gotoxy(50,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ````````````````````\n\n\n";
    
    while((row = mysql_fetch_row(res)) != NULL) //clico while que imprimira los datos de las tabla de cotizaciones
    {
        cout << "Codigo del cotizacion: " << row[0] << endl;
        cout << "Nombre del producto: " << row[1] << endl;
        cout << "Nombre del cliente: " << row[2] << endl;
        cout << "Fecha de cotizacion: " << row[3] << endl;
        
        cout << "\n\n";
    }
	
	mysql_close(conn);
	
	system("pause");
	menu();
}

void mostrarve() //funcion que muestra los datos de las ventas
{
	clear(); //funcion que limpia la pantalla
	
	//declaracion de variables autilizar
	MYSQL *conn;
    MYSQL  mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql,"localhost","root","","practica2",0,0,0);
    
    if(conn == NULL) //condicion para verificar que no halla habido algun error en la conexion
    {  
		cout << mysql_error(&mysql)<<endl;
    	system("pause");
        
    }
    
    mysql_query(conn,"SELECT ventas.codventa, productos.nombreprod, clientes.nombrecl, ventas.cantidad,ventas.fecha FROM ((ventas INNER JOIN productos ON ventas.codpro = productos.codpro) INNER JOIN clientes ON ventas.codcliente = clientes.codcliente)");
    res = mysql_store_result(conn);
    
    gotoxy(50,2); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ,,,,,,,,,,,,,,";
	gotoxy(50,3); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " |   Ventas   |";
	gotoxy(50,4); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
	cout << " ``````````````\n\n\n";
    
    //clico while que imprimira los datos de las tabla de ventas
    while((row=mysql_fetch_row(res)) != NULL)
    {
        cout << "Codigo de la venta: " << row[0] << endl;
        cout << "Nombre del producto: " << row[1] << endl;
        cout << "Nombre del cliente: " << row[2] << endl;
        cout << "Cantidad del producto: " << row[3] << endl;
        cout << "Fecha de venta: " << row[4] << endl;

        
        cout << "\n\n";
    }
	
	mysql_close(conn);
	
	system("pause");
	menu();
}

void salir() //funion para salir del programa
{
	string opcionsalir;
			do {
				clear(); //funcion que limpia la pantalla
				
				gotoxy(40,8); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
				cout << "Salir del programa? (ingrese si - no)";
				gotoxy(55,9); //Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla
				cin >> opcionsalir;
				errordato(); //funion que evita numeros negativos y errores de datos
				
			} while (opcionsalir != "si" && opcionsalir != "no");
			if(opcionsalir == "no") 
			{
				menu(); //se regresara a la funcion
			}

}

void gotoxy(int x, int y) //funcion para poder colocar el texto de la pantalla en cualquier parte
{
	//Estas instrucciones permiticra ubicar un texto en el lugar que se desee en la pantalla
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void cargar() //funcion que permite dar un tiempo de carga
{

	//Variable cargar servira como contador
	int carga = 1;

	cout << "\nEl programa esta cargando" << endl;

	//ciclo while para generar un tiempo de carga
	do {
		//Funcion Sleep para permite generar un tiempo de carga
		Sleep(1400);
		
		cout << "....";

		//Variable carga se utiliza como contador
		carga++;

	} while (carga < 4);
}

void clear() //Funcion que permite limpiar la pantalla
{
	//funcion system("cls") que limpia la pantalla de los textos que esta contiene
	system("cls");
}

void errordato() //funcion que evita que se ingrese datos incorrectos
{
		//Ciclo while paraevitar datos incorrectos
		while(cin.fail()){

		//Limpia el buffer de los datos ingresados
		cin.clear();

		//Ignora los primeros 1000 caracteres o en este caso los numeros
		cin.ignore(1000,'\n');

		}
}



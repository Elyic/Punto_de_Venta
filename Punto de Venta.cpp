#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
/* Declaracion del tipo de archivo */
FILE * FCLiente = NULL;
FILE * FProducto = NULL;
FILE * FFactura = NULL;
FILE * FAux = NULL;
/* Declaracion de Funciones   */
void VIngresocliente();
void Vreporte_clientes();
void Vingresoalmacen();
void vReporteAlmacen();
void vReporteFechaAlmacen();
void vReporteVencimientoAlmacen();
void vReporteproductoMinimo();
void vReporteproductoMaximo();
void VSubmenuAlmacen();
void VSubmenuClientes();
void VSubmenuFact();
void Vingresofact();
void Vreportefactura();
void Vreportefacturaproducto();
void Vreportefacturafecha();
void Vreportefacturacliente();
void Vreportefacturaganancia();
void Vmodificarcliente();
void Veliminarcliente();
void Vmodificarproducto();
void Veliminarproducto();
void Vexistenciaproducto(int iAuxID, int iCant);
// Declaracion de Variables globales
char CMenu,CSubmenu;
int iIDP, iCantf;
// Declaracion de Estructuras
struct Cliente
{
	int  iID;
	char stNit[15];
	char stNombre[30];
   char stApellido[30];
	char stDireccion[30];
	char stTelefono[10];
	int iEliminado;
};
struct Fecha
{
	int		iDiaVen, iDiaIn;
	int		iMesVen, iMesIn;
	int		iAnioVen, iAnioIn;
};
struct Producto
{
	int    iID;
	char   stDescripcion[20];
	double dPrecioIngreso;
	double dPrecioVentaMenor;
	double dPrecioVentaDocena;
	double dPrecioVentaMayor;
	int    iStockMinimo;
	int    iStockMaximo;
	Fecha  fecha;
	int	   iExistencia;
	char   stCodigoFactura[30];
	int iEliminado;
};
struct Factura
{
	int iID;
   char stNombre[30];
   char stApellido[30];
   char stNit[15];
   char stDireccion[30];
   int iIDC;
   int iIDP;
   int iDia;
   int iMes;
   int iAnio;
   int icant;
   char stDescripcion[25];
   double dPrecio;
   double dTotal;
};
/* Inicio programa principal */
int main()
{
	clrscr();
   do
   {
   clrscr();
   gotoxy(16,2);
   cout<<"||==============================================||";
   gotoxy(16,3);
   cout<<"||                                              ||";
   gotoxy(16,4);
   cout<<"||         UNIVERSIDAD MARIANO GALVEZ           ||";
   gotoxy(16,5);
   cout<<"||         PROYECTO FINAL ALGORITMOS            ||";
   gotoxy(16,6);
   cout<<"||               PUNTO DE VENTA                 ||";
   gotoxy(16,7);
   cout<<"||  Harold Fernando Cordon Estrada 1190-16-8644 ||";
   gotoxy(16,8);
   cout<<"||  Medardo Flores Trigueos       1190-16-04188 ||";
   gotoxy(16,9);
   cout<<"||  Allan Humberto Choc Solis     1190-16-11781 ||";
   gotoxy(16,10);
   cout<<"||==============================================||";
   gotoxy(22,12);
   cout<<"||================================|| ";
   gotoxy(22,13);
   cout<<"||=====Empresa La Cotorra,S.A=====|| ";
   gotoxy(22,14);
   cout<<"||=========Menu Principal=========||";
   gotoxy(22,15);
   cout<<"|| ";
   gotoxy(56,15);
   cout<<"||";
   gotoxy(22,16);
   cout<<"||1.) Almacen ";
   gotoxy(56,16);
   cout<<"||";
   gotoxy(22,17);
   cout<<"||2.) Clientes ";
   gotoxy(56,17);
   cout<<"||";
   gotoxy(22,18);
   cout<<"||3.) Facturacion ";
   gotoxy(56,18);
   cout<<"||";
   gotoxy(22,19);
   cout<<"||4.) Salir ";
   gotoxy(56,19);
   cout<<"||";
   gotoxy(22,20);
   cout<<"|| ";
   gotoxy(56,20);
   cout<<"||";
   gotoxy(22,21);
   cout<<"||Digite una opcion:";
   gotoxy(56,21);
   cout<<"||";
	gotoxy(22,22);
   cout<<"||================================|| ";
   gotoxy(44,21);
   cin>>CMenu;
   switch (CMenu)
   {
   case '1':
VSubmenuAlmacen();
   break;
   case '2':
VSubmenuClientes();
   break;
   case '3':
VSubmenuFact();
   break;
   case '4':
   clrscr();
   cout<<"Adios...vuelva pronto! "<<endl;
   break;
   }
   }
   while (CMenu!='4');
   system("PAUSE");
   return 0;
}
// Fin programa principal
void VSubmenuAlmacen()			//Submenu Almacen
{
do
   {
   system("cls");
   gotoxy(15,3);
   cout<<"||==============================================||";
   gotoxy(15,4);
   cout<<"||===============Sub-menu Almacen===============||"<<endl;
   gotoxy(15,5);
   cout<<"||==============================================||";
   gotoxy(15,6);
   cout<<"||";
   gotoxy(63,6);
   cout<<"||";
   gotoxy(15,7);
   cout<<"||1.) Ingreso de productos al Almacen ";
   gotoxy(63,7);
   cout<<"||";
   gotoxy(15,8);
   cout<<"||2.) Reporte de productos ingresados ";
   gotoxy(63,8);
   cout<<"||";
   gotoxy(15,9);
   cout<<"||3.) Reporte de ingresos al almacen segun fecha ";
   gotoxy(63,9);
   cout<<"||";
   gotoxy(15,10);
   cout<<"||4.) Reporte de productos proximos a vencer ";
   gotoxy(63,10);
   cout<<"||";
   gotoxy(15,11);
   cout<<"||5.) Reporte de productos con stock minimo ";
   gotoxy(63,11);
   cout<<"||";
   gotoxy(15,12);
   cout<<"||6.) Reporte de productos con stock maximo ";
   gotoxy(63,12);
   cout<<"||";
   gotoxy(15,13);
   cout<<"||7.) Modificar Producto ";
   gotoxy(63,13);
   cout<<"||";
   gotoxy(15,14);
   cout<<"||8.) Eliminar Producto ";
   gotoxy(63,14);
   cout<<"||";
   gotoxy(15,15);
   cout<<"||9.) Regresar a menu anterior ";
   gotoxy(63,15);
   cout<<"||";
   gotoxy(63,16);
   cout<<"||";
   gotoxy(63,4);
   cout<<"||";
   gotoxy(15,16);
   cout<<"||";
   gotoxy(15,17);
   cout<<"||Digite una opcion: ";
   gotoxy(63,17);
   cout<<"||";
   gotoxy(15,18);
   cout<<"||==============================================||";
   gotoxy(37,17);
   cin>>CSubmenu;
switch (CSubmenu)
{
	case '1':
	Vingresoalmacen();
	break;
   case '2':
   vReporteAlmacen();
	break;
	case '3':
		vReporteFechaAlmacen();
	break;
	case '4':
vReporteVencimientoAlmacen();
	break;
	case '5':
   vReporteproductoMinimo();
	break;
	case '6':
	vReporteproductoMaximo();
	break;
	case '7':
   Vmodificarproducto();
	break;
   case '8':
   Veliminarproducto();
   break;
   case '9':
   break;
}
   }
   while (CSubmenu!='9');
}
void VSubmenuClientes()		//Submenu Clientes
{
do
   {
   clrscr();
   gotoxy(22,4);
   cout<<"||==================================||";
   gotoxy(22,5);
   cout<<"||========Sub-menu Clientes=========|| ";
   gotoxy(22,6);
   cout<<"||==================================||";
   gotoxy(22,7);
   cout << "||";
   gotoxy(58,7);
   cout<<"||";
   gotoxy(22,8);
   cout<<"||1.) Ingreso de clientes";
   gotoxy(58,8);
   cout<<"||";
   gotoxy(22,9);
   cout<<"||2.) Reporte de clientes ingresados";
   gotoxy(58,9);
   cout<<"||";
   gotoxy(22,10);
   cout<<"||3.) Modificar cliente";
   gotoxy(58,10);
   cout<<"||";
   gotoxy(22,11);
   cout<<"||4.) Eliminar cliente";
   gotoxy(58,11);
   cout<<"||";
   gotoxy(22,12);
   cout<<"||5.) Regresar a menu anterior";
   gotoxy(58,12);
   cout<<"||";
   gotoxy(22,13);
   cout<<"||";
   gotoxy(58,13);
   cout << "||";
   gotoxy(22,14);
   cout<<"||Digite una opcion: ";
   gotoxy(58,14);
   cout<<"||";
   gotoxy(22,15);
   cout<<"||==================================||";
   gotoxy(44,14);
   cin>>CSubmenu;
   switch (CSubmenu)
   {
   case '1':
VIngresocliente();
   break;
   case '2':
Vreporte_clientes();
   break;
   case '3':
   Vmodificarcliente();
   break;
   case '4':
   Veliminarcliente();
   break;
   case '5':
   break;
   }
   }
   while (CSubmenu!='5');
}
void VSubmenuFact()			//Submenu Facturacion
{
do
   {
   clrscr();
   gotoxy(9,4);
   cout<<"||=============================================================||";
   gotoxy(9,5);
   cout<<"||====================Sub-menu Facturacion=====================|| ";
   gotoxy(9,6);
   cout<<"||=============================================================||";
   gotoxy(9,7);
   cout<<"||";
   gotoxy(72,7);
   cout<<"||";
   gotoxy(9,8);
   cout<<"||1.) Registro de Factura ";
   gotoxy(72,8);
   cout<<"||";
   gotoxy(9,9);
	cout<<"||2.) Reporte de ventas por producto entre fechas especificas "<<endl;
   gotoxy(72,9);
   cout<<"||";
   gotoxy(9,10);
   cout<<"||3.) Reporte de facturas emitidas entre fechas especificas "<<endl;
   gotoxy(72,10);
   cout<<"||";
   gotoxy(9,11);
   cout<<"||4.) Reporte de ventas por cliente entre fechas especificas "<<endl;
   gotoxy(72,11);
   cout<<"||";
   gotoxy(9,12);
   cout<<"||5.) Reporte de ganacia entre fechas especificas "<<endl;
   gotoxy(72,12);
    cout<<"||";
   gotoxy(9,13);
   cout<<"||6.) Regresar a menu anterior "<<endl;
   gotoxy(72,13);
   cout<<"||";
   gotoxy(9,14);
   cout<<"||";
   gotoxy(72,14);
   cout<<"||";
   gotoxy(9,15);
   cout<<"||Digite una opcion: ";
   gotoxy(72,15);
   cout<<"||";
   gotoxy(9,16);
   cout<<"||=============================================================||";
   gotoxy(31,15);
   cin>>CSubmenu;
   switch (CSubmenu)
   {
   case '1':
   Vingresofact();
   break;
   case '2':
   Vreportefacturaproducto();
   break;
   case '3':
   Vreportefacturafecha();
   break;
   case '4':
   Vreportefacturacliente();
   break;
   case '5':
   Vreportefacturaganancia();
   //Vreportefactura();
   break;
   case '6':
   break;
   }
   }
   while (CSubmenu!='6');
}
void VIngresocliente()			//Ingreso de clientes
{
Cliente cliente;
	system("cls");
	fflush(stdin);
   cout <<"\n\t=====Ingrese datos del cliente=====\n";
	cout << "\tNIT: ";
	fgets(cliente.stNit, sizeof(cliente.stNit), stdin);
	if (cliente.stNit[strlen(cliente.stNit) - 1] == '\n')
		cliente.stNit[strlen(cliente.stNit) - 1] = '\0';
	fflush(stdin);
	cout << "\tNombre: ";
	fgets(cliente.stNombre, sizeof(cliente.stNombre), stdin);
	if (cliente.stNombre[strlen(cliente.stNombre) - 1] == '\n')
		cliente.stNombre[strlen(cliente.stNombre) - 1] = '\0';
   fflush(stdin);
	cout << "\tApellido: ";
	fgets(cliente.stApellido, sizeof(cliente.stApellido), stdin);
	if (cliente.stApellido[strlen(cliente.stApellido) - 1] == '\n')
		cliente.stApellido[strlen(cliente.stApellido) - 1] = '\0';
	fflush(stdin);
	cout << "\tDireccion: ";
	fgets(cliente.stDireccion, sizeof(cliente.stDireccion)-1, stdin);
	if (cliente.stDireccion[strlen(cliente.stDireccion) - 1] == '\n')
		cliente.stDireccion[strlen(cliente.stDireccion) - 1] = '\0';
	fflush(stdin);
	cout << "\tTelefono: ";
	fgets(cliente.stTelefono, sizeof(cliente.stTelefono) - 1, stdin);
	if (cliente.stTelefono[strlen(cliente.stTelefono) - 1] == '\n')
   {
		cliente.stTelefono[strlen(cliente.stTelefono) - 1] = '\0';
   }
	fflush(stdin);
	cliente.iEliminado = 0;
	FCLiente = fopen("Cliente.txt", "r");

	if (FCLiente == NULL)
	{
		FCLiente = fopen("Cliente.txt", "a+");
		cliente.iID = 1;
		fwrite(&cliente, sizeof(Cliente), 1, FCLiente);
		fclose(FCLiente);
	}
	else
	{
		fclose(FCLiente);
		FCLiente = fopen("Cliente.txt", "a+");
		fseek(FCLiente, 0, SEEK_END);
		cliente.iID = (ftell(FCLiente) / sizeof(Cliente)) + 1;
		fwrite(&cliente, sizeof(Cliente), 1, FCLiente);
		fclose(FCLiente);
	}
}                              //Fin funcion ingreso de clientes
void Vreporte_clientes()		//Reporte de clientes
{
int y=7;
Cliente cliente;
	FCLiente = fopen("Cliente.txt", "r");
	if (FCLiente == NULL)
	{
      system("Cls");
		cout << "Error no existe ningun registro en Cliente" << endl;
	}
	else
	{
       system("cls");
       gotoxy(5,2);
       cout <<"||===========================================================|| ";
       gotoxy(5,3);
      cout<<"||=========Reporte de clientes registrados===================|| ";
      gotoxy(5,4);
      cout <<"||===========================================================|| ";
       gotoxy(5,5);
		cout << "ID";
      gotoxy(10,5);
      cout<< "Nit";
      gotoxy(22,5);
      cout << "Nombre";
      gotoxy(35,5);
      cout << "Apellido";
      gotoxy(45,5);
      cout << "Direccion";
      gotoxy(60,5);
      cout << "Telefono" << endl;
		fread(&cliente, sizeof(Cliente), 1, FCLiente);
		while (feof(FCLiente) == 0)
		{
			if (cliente.iEliminado==0)
			{
         	gotoxy(5,y);
				cout << cliente.iID;
            gotoxy(10,y);
				cout << cliente.stNit;
            gotoxy(22,y);
				cout << cliente.stNombre;
            gotoxy(35,y);
				cout << cliente.stApellido;
            gotoxy(45,y);
				cout << cliente.stDireccion;
            gotoxy(60,y);
				cout << cliente.stTelefono << endl;
            y++;
			}
			fread(&cliente, sizeof(Cliente), 1, FCLiente);
		}
      gotoxy(5,y);
      cout <<"||===========================================================|| "<<endl;
	}
fclose(FCLiente);
system("PAUSE");
}                           //Funcion reporte de clientes
void Vingresoalmacen()		//Ingreso productos a almacen
{
	Producto producto;
	fflush(stdin);
   system("cls");
   cout <<"\t||==========Ingrese datos de producto==========||"<<endl;
	cout << "\t||Descripcion: ";
	fgets(producto.stDescripcion, sizeof(producto.stDescripcion), stdin);
	if (producto.stDescripcion[strlen(producto.stDescripcion) - 1] == '\n')
		producto.stDescripcion[strlen(producto.stDescripcion) - 1] = '\0';
	fflush(stdin);
	cout << "\t||Precio de ingreso: ";
	cin >> producto.dPrecioIngreso;
	fflush(stdin);
	cout << "\t||Precio de venta por menor: ";
	cin >> producto.dPrecioVentaMenor;
	fflush(stdin);
	cout << "\t||Precio de venta por docena: ";
	cin >> producto.dPrecioVentaDocena;
	fflush(stdin);
	cout << "\t||Precio de venta por mayor: ";
	cin >> producto.dPrecioVentaMayor;
	fflush(stdin);
	cout << "\t||Stock minimo: ";
	cin >> producto.iStockMinimo;
	fflush(stdin);
	cout << "\t||Stock maximo: ";
	cin >> producto.iStockMaximo;
	fflush(stdin);
	cout << "\t||Fecha de vencimiento: " << endl;
   gotoxy(34,9);
	cin >> producto.fecha.iDiaVen;
   gotoxy(37,9);
	cout << "/";
   gotoxy(38,9);
	cin >> producto.fecha.iMesVen;
   gotoxy(41,9);
	cout << "/";
   gotoxy(43,9);
	cin >> producto.fecha.iAnioVen;
	fflush(stdin);
	cout << "\t||Fecha de ingreso: " << endl;
   gotoxy(34,10);
	cin >> producto.fecha.iDiaIn;
   gotoxy(37,10);
	cout << "/";
   gotoxy(38,10);
	cin >> producto.fecha.iMesIn;
   gotoxy(41,10);
	cout << "/";
   gotoxy(43,10);
	cin >> producto.fecha.iAnioIn;
	fflush(stdin);
	cout << "\t||Existencia: ";
	cin >> producto.iExistencia;
	fflush(stdin);
	cout << "\t||Factura de ingreso: ";
	fgets(producto.stCodigoFactura, sizeof(producto.stCodigoFactura), stdin);
	if (producto.stCodigoFactura[strlen(producto.stCodigoFactura) - 1] == '\n')
		producto.stCodigoFactura[strlen(producto.stCodigoFactura) - 1] = '\0';
	fflush(stdin);
	producto.iEliminado = 0;
	FProducto = fopen("Producto.txt", "r");

	if (FProducto == NULL)
	{
		FProducto = fopen("Producto.txt", "a+");
		producto.iID = 1;
		fwrite(&producto, sizeof(Producto), 1, FProducto);
		fclose(FProducto);
	}
	else
	{
		fclose(FProducto);
		FProducto = fopen("Producto.txt", "a+");
		fseek(FProducto, 0, SEEK_END);
		producto.iID = (ftell(FProducto) / sizeof(Producto)) + 1;
		fwrite(&producto, sizeof(Producto), 1, FProducto);
		fclose(FProducto);
	}
}                                 // Fin funcion ingreso a almacen
void vReporteproductoMinimo()		//Reporte de productos con Existencia menor a Stock minimo
{
	system("cls");
	Producto producto;
	FProducto = fopen("Producto.txt", "r");
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{

		fread(&producto, sizeof(Producto), 1, FProducto);
      cout <<"\t||======================================================== "<<endl;
      cout<<"\t||=====Reporte de productos con Stock menor al Minimo===== "<< endl;
      cout <<"\t||======================================================== "<<endl;
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0 && producto.iExistencia < producto.iStockMinimo)
			{
				cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
            cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
            cout <<"\t||======================================================== "<<endl;
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
system("PAUSE");
}                                 //Fin funcion reporte de productos con stock menos al minimo
void vReporteproductoMaximo()		//Reporte de productos con Existencia mayor a Stock maximo
{
	clrscr();
	Producto producto;
	FProducto = fopen("Producto.txt", "r");
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{

		fread(&producto, sizeof(Producto), 1, FProducto);
      cout <<"\t||======================================================== "<<endl;
      cout<<"\t||=====Reporte de productos con Stock mayor al Maximo===== "<< endl;
      cout <<"\t||======================================================== "<<endl;
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0 && producto.iExistencia > producto.iStockMaximo)
			{
				cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
            cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
            cout <<"\t||======================================================== "<<endl;
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
system("PAUSE");
}                           //Fin funcion reporte de productos con stock mayor al maximo
void vReporteAlmacen()		//Reporte de productos ingresados al almacen
{
	clrscr();
	Producto producto;
	FProducto = fopen("Producto.txt", "r");
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{

		fread(&producto, sizeof(Producto), 1, FProducto);
      cout <<"\t||======================================================== "<<endl;
      cout<<"\t||=====Reporte de productos ingresados al Almacen========= "<< endl;
      cout <<"\t||======================================================== "<<endl;
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0)
			{
				cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
            cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
            cout <<"\t||======================================================== "<<endl;
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
system("PAUSE");
}                                 //Fin funcion reporte de productos
void vReporteFechaAlmacen()		//Reporte de productos ingresados al almacen por fechas
{
	int diai,diaf;
	int mesi,mesf;
	int anioi,aniof;
	clrscr();
	Producto producto;
	FProducto = fopen("Producto.txt", "r");
   fflush(stdin);
	cout <<"Ingrese fechas de inicio rango de busqueda en formato [DD/MM/AA]"<< endl;
	cout <<"\t ->Dia: ";
	cin >> diai;
   fflush(stdin);
	cout <<"\t ->Mes: ";
	cin >> mesi;
   fflush(stdin);
	cout <<"\t ->Anio: ";
	cin >> anioi;
   fflush(stdin);
	cout <<"Ingrese fechas de final rango de busqueda en formato [DD/MM/AA]"<< endl;
	cout <<"\t ->Dia: ";
	cin >> diaf;
   fflush(stdin);
	cout <<"\t ->Mes: ";
	cin >> mesf;
   fflush(stdin);
	cout <<"\t ->Anio: ";
	cin >> aniof;
   fflush(stdin);
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{
      clrscr();
		fread(&producto, sizeof(Producto), 1, FProducto);
      cout <<"\t||============================================================ "<<endl;
      cout<<"\t||=====Reporte de productos ingresados segun fecha al Almacen= "<< endl;
      cout <<"\t||============================================================ "<<endl;
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0)
			{
				if (producto.fecha.iAnioIn >= anioi && producto.fecha.iAnioIn <= aniof)
				{
					if (producto.fecha.iMesIn >= mesi && producto.fecha.iMesIn <= mesf)
				{
						if (producto.fecha.iDiaIn >= diai || producto.fecha.iDiaIn <= diaf)
					{
						cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
                cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
                cout <<"\t||======================================================== "<<endl;
					}
					else {
						cout << "\t||No existen registros en ese rango de fechas..." << endl;
					}
				}
				}
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
system("PAUSE");
}                                       //Fin funcion reporte de productos ingresados entre fechas
void vReporteVencimientoAlmacen()		//Reporte de productos proximos a vencer
{
	int diai,diaf;
	int mesi,mesf;
	int anioi,aniof;
	clrscr();
	Producto producto;
	FProducto = fopen("Producto.txt", "r");
   fflush(stdin);
	cout <<"Ingrese fecha actual en formato [DD/MM/AA]"<< endl;
	cout <<"\t ->Dia: ";
	cin >> diai;
   fflush(stdin);
	cout <<"\t ->Mes: ";
	cin >> mesi;
   fflush(stdin);
	cout <<"\t ->Anio: ";
	cin >> anioi;
diaf = diai;
mesf = mesi+1;
aniof = anioi;
if (mesf > 12)
{
	mesf = mesf-12;
	aniof = aniof+1;
}
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{
      clrscr();
		fread(&producto, sizeof(Producto), 1, FProducto);
      cout <<"\t||============================================================ "<<endl;
      cout<<"\t||===========Reporte de productos proximos a vencer=========== "<< endl;
      cout <<"\t||============================================================ "<<endl;
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0)
			{
				if (producto.fecha.iAnioVen >= anioi && producto.fecha.iAnioVen <= aniof)
				{
					if (producto.fecha.iMesVen >= mesi && producto.fecha.iMesVen <= mesf)
				{
						if (producto.fecha.iDiaVen >= diai || producto.fecha.iDiaVen <= diaf)
					{
						cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
                cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
                cout <<"\t||======================================================== "<<endl;
					}
					else {
						cout << "\t||No existen registros en ese rango de fechas..." << endl;
					}
				}
				}
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
system("PAUSE");
}                                                   //Fin funcion reporte productos proximos a vencer
void Vingresofact()											//Funcion Ingreso de facturas
{
   int y=3;
   Cliente cliente;
   Factura factura;
   Producto producto;
	system("cls");
   fflush(stdin);
   FCLiente = fopen("Cliente.txt", "r");
	if (FCLiente == NULL)
	{
      gotoxy(50,2);
		cout << "Error no existe ningun registro en Cliente" << endl;
	}
	else
	{
       gotoxy(56,2);
       cout<<"ID";
       gotoxy(61,2);
       cout <<"Nombre";
       gotoxy(71,2);
       cout <<"Apellido";
		fread(&cliente, sizeof(Cliente), 1, FCLiente);
		while (feof(FCLiente) == 0)
		{
			if (cliente.iEliminado==0)
			{
         gotoxy(56,y);
         cout << cliente.iID;
      	//cout << cliente.stNit;
         gotoxy(61,y);
 			cout << cliente.stNombre;
         gotoxy(71,y);
 	   	cout << cliente.stApellido;
         y++;
			}
			fread(&cliente, sizeof(Cliente), 1, FCLiente);
		}
	}
fclose(FCLiente);
FProducto = fopen("Producto.txt", "r");
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{
   	y=3;
		fread(&producto, sizeof(Producto), 1, FProducto);
      gotoxy(42,2);
      cout <<"ID";
      gotoxy(45,2);
      cout <<"Descrp.";
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0)
			{
         gotoxy(42,y);
         cout<<producto.iID;
         gotoxy(45,y);
         cout<<producto.stDescripcion;
			}
         y++;
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
	fflush(stdin);
   gotoxy(3,2);
   cout << "=====Factura====="<<endl;
   gotoxy(3,3);
   cout << "Fecha de factura: ";
   cin >> factura.iDia;
   fflush(stdin);
   gotoxy(22,3);
   cout<<"/";
   gotoxy(24,3);
   cin >> factura.iMes;
   fflush(stdin);
   gotoxy(26,3);
   cout<<"/";
   gotoxy(28,3);
   cin >> factura.iAnio;
   fflush(stdin);
   gotoxy(3,4);
   cout << "ID de cliente: ";
   cin >> factura.iIDC;
   fflush(stdin);
   FCLiente = fopen("Cliente.txt", "r");
	if (FCLiente == NULL)
	{
      system("Cls");
		cout << "Error no existe ningun registro en Cliente" << endl;
	}
	else
	{
		fread(&cliente, sizeof(Cliente), 1, FCLiente);
		while (feof(FCLiente) == 0)
		{
			if (cliente.iEliminado==0 && factura.iIDC == cliente.iID)
			{
         strcpy(factura.stNombre,cliente.stNombre);
         strcpy(factura.stApellido,cliente.stApellido);
         strcpy(factura.stDireccion,cliente.stDireccion);
         strcpy(factura.stNit,cliente.stNit);
			}
			fread(&cliente, sizeof(Cliente), 1, FCLiente);
		}
	}
	fclose(FCLiente);
   gotoxy(3,5);
   cout <<"Nombre: "<< factura.stNombre<<" "<<factura.stApellido<<endl;
   gotoxy(3,6);
   cout <<"NIT: "<<factura.stNit<<endl;
   gotoxy(3,7);
	cout <<"Direccion: "<< factura.stDireccion<<endl;
   fflush(stdin);
   gotoxy(3,8);
   cout <<"ID de procucto: ";
   cin >> factura.iIDP;
   fflush(stdin);
   FProducto = fopen("Producto.txt", "r");
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{
		fread(&producto, sizeof(Producto), 1, FProducto);
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0 && factura.iIDP == producto.iID)
			{
         strcpy(factura.stDescripcion,producto.stDescripcion);
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
gotoxy(3,9);
cout<<"Descripcion: "<<factura.stDescripcion;
gotoxy(3,10);
fflush(stdin);
cout<<"Cantidad: ";
cin >>factura.icant;
FProducto = fopen("Producto.txt", "r");
	if (FProducto == NULL)
	{
		cout << "Error no existe ningun registro en Productos" << endl;
	}
	else
	{
		fread(&producto, sizeof(Producto), 1, FProducto);
		while (feof(FProducto) == 0)
		{
			if (producto.iEliminado == 0 && factura.iIDP == producto.iID)
			{
         if (factura.icant <= 11 && factura.icant >= 0)
         	{
            	factura.dPrecio = producto.dPrecioVentaMenor;
            }
         if (factura.icant <= 25 && factura.icant >= 12)
         	{
            	factura.dPrecio = producto.dPrecioVentaDocena;
            }
            if (factura.icant >= 26)
         	{
            	factura.dPrecio = producto.dPrecioVentaMayor;
            }
			}
			fread(&producto, sizeof(Producto), 1, FProducto);
		}
	}
fclose(FProducto);
fflush(stdin);
gotoxy(3,11);
cout << "Precio: Q."<<factura.dPrecio;
gotoxy(3,12);
factura.dTotal = factura.dPrecio * factura.icant;
cout << "Total: Q."<<factura.dTotal;
fflush(stdin);
cout<<endl;
factura.iID = 0;
FFactura = fopen("Facturas.txt", "r");

	if (FFactura == NULL)
	{
		FFactura = fopen("Facturas.txt", "a+");
		factura.iID = 1;
		fwrite(&factura, sizeof(Factura), 1, FFactura);
		fclose(FFactura);
	}
	else
	{
		fclose(FFactura);
		FFactura = fopen("Facturas.txt", "a+");
		fseek(FFactura, 0, SEEK_END);
		factura.iID = (ftell(FFactura) / sizeof(Factura)) +1;
		fwrite(&factura, sizeof(Factura), 1, FFactura);
		fclose(FFactura);
	}
   Vexistenciaproducto(factura.iIDP,factura.icant);
system("PAUSE");
}                                   //Fin Funcion ingreso de Facturas
void Vreportefacturaganancia()   	//Funcion reporte facturas ganacia
{
   double dGanancia;
	int iDia, iDiaf;
   int iMes, iMesf;
   int iAnio, iAniof;
   bool encontrado = false;
   int y=1;
	system("cls");
	Factura factura;
   FFactura = fopen("Facturas.txt", "r");

   if (FFactura == NULL)
   {
   	cout<<"No existen registros en el archivo...."<<endl;
   }
   else
   {
   fflush(stdin);
   cout<<"Ingrese fecha inicio: ";
   cin>>iDia;
   fflush(stdin);
   gotoxy(24,1);
   cout<<"/";
   gotoxy(26,1);
   cin>>iMes;
   fflush(stdin);
   gotoxy(29,1);
   cout<<"/";
   gotoxy(31,1);
   cin>>iAnio;
   fflush(stdin);
   cout<<"Ingrese fecha final: ";
   cin>>iDiaf;
   fflush(stdin);
   gotoxy(24,2);
   cout<<"/";
   gotoxy(26,2);
   cin>>iMesf;
   fflush(stdin);
   gotoxy(29,2);
   cout<<"/";
   gotoxy(31,2);
   cin>>iAniof;
   fflush(stdin);
      system("cls");
   fread(&factura,sizeof(Factura), 1, FFactura);
   while (feof(FFactura)==0)
   	{
         if (factura.iAnio >= iAnio && factura.iAnio <= iAniof)
				{
					if (factura.iMes >= iMes && factura.iMes <= iMesf)
				{
						if (factura.iDia >= iDia && factura.iDia <= iDiaf)
					{
         encontrado = true;
         cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||============LA COTORRA, S.A==============||"<<endl;
   		cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||No. Fact: "<<factura.iID<<endl;
   		cout<<"\t||Fecha: "<<factura.iDia<<"/"<<factura.iMes<<"/"<<factura.iAnio<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||ID: "<<factura.iIDC<<endl;
         cout<<"\t||Nombre: "<<factura.stNombre<<" "<<factura.stApellido<<endl;
         cout<<"\t||NIT: "<<factura.stNit<<endl;
         cout<<"\t||Direccion: "<<factura.stDireccion<<endl;
   		cout<<"\t||"<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||Cantidad: "<<factura.icant<<endl;
         cout<<"\t||Descripcion: "<<factura.stDescripcion<<endl;
         cout<<"\t||Precio: Q."<<factura.dPrecio<<endl;
         cout<<"\t||Total: Q."<<factura.dTotal<<endl;
   		cout<<"\t||=========================================||"<<endl;
         dGanancia = dGanancia + factura.dTotal;
         }
         }
         }
         fread(&factura,sizeof(Factura), 1, FFactura);
      }
   }
fclose(FFactura);
cout<<endl;
if (encontrado == false)
{
cout<<"No existen ganancias en las fechas "<<iDia<<"/"<<iMes<<"/"<<iAnio<<" a "<<iDiaf<<"/"<<iMesf<<"/"<<iAniof<<endl;
}
else
{
cout<<"Usted obtuvo una ganancia de Q"<<dGanancia<<" en las fechas "<<iDia<<"/"<<iMes<<"/"<<iAnio<<" a "<<iDiaf<<"/"<<iMesf<<"/"<<iAniof<<endl;
}
system("PAUSE");
}														//Fin funcion Ganancia
void Vreportefacturaproducto()				//Funcion facturas de producto entre fechas
{
   char stNombre[30];
   int iDia, iDiaf;
   int iMes, iMesf;
   int iAnio, iAniof;
   bool encontrado = false;
	system("cls");
	Factura factura;
   FFactura = fopen("Facturas.txt", "r");

   if (FFactura == NULL)
   {
   	cout<<"No existen registros en el archivo...."<<endl;
   }
   else
   {
   fflush(stdin);
   cout<<"Ingrese nombre de producto: ";
   fgets(stNombre, sizeof(stNombre), stdin);
	if (stNombre[strlen(stNombre) - 1] == '\n')
   {
		stNombre[strlen(stNombre) - 1] = '\0';
   }
   fflush(stdin);
   cout<<"Ingrese fecha inicio: ";
   cin>>iDia;
   fflush(stdin);
   gotoxy(24,2);
   cout<<"/";
   gotoxy(26,2);
   cin>>iMes;
   fflush(stdin);
   gotoxy(29,2);
   cout<<"/";
   gotoxy(31,2);
   cin>>iAnio;
   fflush(stdin);
   cout<<"Ingrese fecha final: ";
   cin>>iDiaf;
   fflush(stdin);
   gotoxy(24,3);
   cout<<"/";
   gotoxy(26,3);
   cin>>iMesf;
   fflush(stdin);
   gotoxy(29,3);
   cout<<"/";
   gotoxy(31,3);
   cin>>iAniof;
   fflush(stdin);
      system("cls");
   fread(&factura,sizeof(Factura), 1, FFactura);
   while (feof(FFactura)==0)
   	{
         if (strcmp(stNombre,factura.stDescripcion)==0)
         {
         if (factura.iAnio >= iAnio && factura.iAnio <= iAniof)
				{
					if (factura.iMes >= iMes && factura.iMes <= iMesf)
				{
						if (factura.iDia >= iDia || factura.iDia <= iDiaf)
					{
         encontrado = true;
         cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||============LA COTORRA, S.A==============||"<<endl;
   		cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||No. Fact: "<<factura.iID<<endl;
   		cout<<"\t||Fecha: "<<factura.iDia<<"/"<<factura.iMes<<"/"<<factura.iAnio<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||ID: "<<factura.iIDC<<endl;
         cout<<"\t||Nombre: "<<factura.stNombre<<" "<<factura.stApellido<<endl;
         cout<<"\t||NIT: "<<factura.stNit<<endl;
         cout<<"\t||Direccion: "<<factura.stDireccion<<endl;
   		cout<<"\t||"<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||Cantidad: "<<factura.icant<<endl;
         cout<<"\t||Descripcion: "<<factura.stDescripcion<<endl;
         cout<<"\t||Precio: Q."<<factura.dPrecio<<endl;
         cout<<"\t||Total: Q."<<factura.dTotal<<endl;
   		cout<<"\t||=========================================||"<<endl;
         }
         }
         }
         }
         fread(&factura,sizeof(Factura), 1, FFactura);
      }
   }
fclose(FFactura);
cout<<endl;
if (encontrado == false)
{
cout<<"No existen ventas de "<<stNombre<<endl;
}
system("PAUSE");
}                                          //Fin Funcion facturas de producto entre fechas
void Vreportefacturafecha() 					//Funcion facturas entre fechas especificas
{
   int iDia, iDiaf;
   int iMes, iMesf;
   int iAnio, iAniof;
   bool encontrado = false;
	system("cls");
	Factura factura;
   FFactura = fopen("Facturas.txt", "r");

   if (FFactura == NULL)
   {
   	cout<<"No existen registros en el archivo...."<<endl;
   }
   else
   {
   fflush(stdin);
   cout<<"Ingrese fecha inicio: ";
   cin>>iDia;
   fflush(stdin);
   gotoxy(24,1);
   cout<<"/";
   gotoxy(26,1);
   cin>>iMes;
   fflush(stdin);
   gotoxy(29,1);
   cout<<"/";
   gotoxy(31,1);
   cin>>iAnio;
   fflush(stdin);
   cout<<"Ingrese fecha final: ";
   cin>>iDiaf;
   fflush(stdin);
   gotoxy(24,2);
   cout<<"/";
   gotoxy(26,2);
   cin>>iMesf;
   fflush(stdin);
   gotoxy(29,2);
   cout<<"/";
   gotoxy(31,2);
   cin>>iAniof;
   fflush(stdin);
      system("cls");
   fread(&factura,sizeof(Factura), 1, FFactura);
   while (feof(FFactura)==0)
   	{
         if (factura.iAnio >= iAnio && factura.iAnio <= iAniof)
				{
					if (factura.iMes >= iMes && factura.iMes <= iMesf)
				{
						if (factura.iDia >= iDia || factura.iDia <= iDiaf)
					{
         encontrado = true;
         cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||============LA COTORRA, S.A==============||"<<endl;
   		cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||No. Fact: "<<factura.iID<<endl;
   		cout<<"\t||Fecha: "<<factura.iDia<<"/"<<factura.iMes<<"/"<<factura.iAnio<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||ID: "<<factura.iIDC<<endl;
         cout<<"\t||Nombre: "<<factura.stNombre<<" "<<factura.stApellido<<endl;
         cout<<"\t||NIT: "<<factura.stNit<<endl;
         cout<<"\t||Direccion: "<<factura.stDireccion<<endl;
   		cout<<"\t||"<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||Cantidad: "<<factura.icant<<endl;
         cout<<"\t||Descripcion: "<<factura.stDescripcion<<endl;
         cout<<"\t||Precio: Q."<<factura.dPrecio<<endl;
         cout<<"\t||Total: Q."<<factura.dTotal<<endl;
   		cout<<"\t||=========================================||"<<endl;
         }
         }
         }
         fread(&factura,sizeof(Factura), 1, FFactura);
      }
   }
fclose(FFactura);
cout<<endl;
if (encontrado == false)
{
cout<<"No existen ventas en las fechas "<<iDia<<"/"<<iMes<<"/"<<iAnio<<" a "<<iDiaf<<"/"<<iMesf<<"/"<<iAniof<<endl;
}
system("PAUSE");
} 															//Fin funcion facturas entre fechas especificas
void Vreportefacturacliente()						//Funcion facturas a cliente entre fechas
{
   char stNombre[30];
   int iDia, iDiaf;
   int iMes, iMesf;
   int iAnio, iAniof;
   bool encontrado = false;
   int y=1;
	system("cls");
	Factura factura;
   FFactura = fopen("Facturas.txt", "r");

   if (FFactura == NULL)
   {
   	cout<<"No existen registros en el archivo...."<<endl;
   }
   else
   {
   fflush(stdin);
   cout<<"Ingrese nombre de cliente: ";
   fgets(stNombre, sizeof(stNombre), stdin);
	if (stNombre[strlen(stNombre) - 1] == '\n')
   {
		stNombre[strlen(stNombre) - 1] = '\0';
   }
   fflush(stdin);
   cout<<"Ingrese fecha inicio: ";
   cin>>iDia;
   fflush(stdin);
   gotoxy(24,2);
   cout<<"/";
   gotoxy(26,2);
   cin>>iMes;
   fflush(stdin);
   gotoxy(29,2);
   cout<<"/";
   gotoxy(31,2);
   cin>>iAnio;
   fflush(stdin);
   cout<<"Ingrese fecha final: ";
   cin>>iDiaf;
   fflush(stdin);
   gotoxy(24,3);
   cout<<"/";
   gotoxy(26,3);
   cin>>iMesf;
   fflush(stdin);
   gotoxy(29,3);
   cout<<"/";
   gotoxy(31,3);
   cin>>iAniof;
   fflush(stdin);
      system("cls");
   fread(&factura,sizeof(Factura), 1, FFactura);
   while (feof(FFactura)==0)
   	{
         if (strcmp(stNombre,factura.stNombre)==0)
         {
         if (factura.iAnio >= iAnio && factura.iAnio <= iAniof)
				{
					if (factura.iMes >= iMes && factura.iMes <= iMesf)
				{
						if (factura.iDia >= iDia || factura.iDia <= iDiaf)
					{
         encontrado = true;
         cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||============LA COTORRA, S.A==============||"<<endl;
   		cout<<"\t||=========================================||"<<endl;
   		cout<<"\t||No. Fact: "<<factura.iID<<endl;
   		cout<<"\t||Fecha: "<<factura.iDia<<"/"<<factura.iMes<<"/"<<factura.iAnio<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||ID: "<<factura.iIDC<<endl;
         cout<<"\t||Nombre: "<<factura.stNombre<<" "<<factura.stApellido<<endl;
         cout<<"\t||NIT: "<<factura.stNit<<endl;
         cout<<"\t||Direccion: "<<factura.stDireccion<<endl;
   		cout<<"\t||"<<endl;
   		cout<<"\t||"<<endl;
         cout<<"\t||Cantidad: "<<factura.icant<<endl;
         cout<<"\t||Descripcion: "<<factura.stDescripcion<<endl;
         cout<<"\t||Precio: Q."<<factura.dPrecio<<endl;
         cout<<"\t||Total: Q."<<factura.dTotal<<endl;
   		cout<<"\t||=========================================||"<<endl;
         }
         }
         }
         }
         fread(&factura,sizeof(Factura), 1, FFactura);
      }
   }
fclose(FFactura);
cout<<endl;
if (encontrado == false)
{
cout<<"No existen ventas a "<<stNombre<<endl;
}
system("PAUSE");
}      											//Fin funcion facturas a clientes entre fechas
void Vmodificarcliente() 			//Funcion para modificar cliente
{
Cliente cliente;
int iAuxID;
system("cls");
cout<<"Ingresa la clave del cliente: ";
cin>>iAuxID;
FCLiente = fopen("Cliente.txt","r+");
if (FCLiente == NULL)
	{
   	cout<<"Ocurrio un error al abrir el archivo...."<<endl;
   }
   else
   {
   	fseek(FCLiente, (long)(iAuxID-1)* sizeof(Cliente), 0);
      fread(&cliente, sizeof(Cliente), 1, FCLiente);
      fflush(stdin);
      cout<<"\t||=====================================||"<<endl;
      cout<<"\t||ID: "<<cliente.iID<<endl;
      cout<<"\t||Nombre: "<<cliente.stNombre<<endl;
      cout<<"\t||Apellido: "<<cliente.stApellido<<endl;
      cout<<"\t||Direccion: "<<cliente.stDireccion<<endl;
      cout<<"\t||Telefono: "<<cliente.stTelefono<<endl;
      cout<<"\t||=====================================||"<<endl;
      fflush(stdin);
      cout << "Ingrese nuevo NIT: ";
	fgets(cliente.stNit, sizeof(cliente.stNit), stdin);
	if (cliente.stNit[strlen(cliente.stNit) - 1] == '\n')
		cliente.stNit[strlen(cliente.stNit) - 1] = '\0';
      fflush(stdin);
      cout<<"Ingrese nuevo nombre: ";
      fgets(cliente.stNombre, sizeof(cliente.stNombre), stdin);
      if (cliente.stNombre[strlen(cliente.stNombre) - 1] == '\n')
      {
		cliente.stNombre[strlen(cliente.stNombre) - 1] = '\0';
		}
      fflush(stdin);
      cout<<"Ingrese nuevo apellido: ";
      fgets(cliente.stApellido, sizeof(cliente.stApellido), stdin);
      if (cliente.stApellido[strlen(cliente.stApellido) - 1] == '\n')
      {
		cliente.stApellido[strlen(cliente.stApellido) - 1] = '\0';
      }
      fflush(stdin);
      cout << "Ingrese nueva Direccion: ";
	fgets(cliente.stDireccion, sizeof(cliente.stDireccion)-1, stdin);
	if (cliente.stDireccion[strlen(cliente.stDireccion) - 1] == '\n')
		cliente.stDireccion[strlen(cliente.stDireccion) - 1] = '\0';
	fflush(stdin);
	cout << "Ingrese nuevo Telefono: ";
	fgets(cliente.stTelefono, sizeof(cliente.stTelefono) - 1, stdin);
	if (cliente.stTelefono[strlen(cliente.stTelefono) - 1] == '\n')
   {
		cliente.stTelefono[strlen(cliente.stTelefono) - 1] = '\0';
   }
	fflush(stdin);
      fseek(FCLiente, (long)(iAuxID-1)* sizeof(Cliente), 0);
      fwrite(&cliente, sizeof(Cliente), 1, FCLiente);
      cout<<"Registro modificado..."<<endl;
   }
fclose(FCLiente);
system("PAUSE");
}           						//Fin funcion para modificar cliente
void Veliminarcliente() 			//Funcion para eliminar cliente
{
Cliente cliente;
int iAuxID;
char Cresp;
system("cls");
cout<<"Ingresa la clave del cliente: ";
cin>>iAuxID;
FCLiente = fopen("Cliente.txt","r+");
if (FCLiente == NULL)
	{
   	cout<<"Ocurrio un error al abrir el archivo...."<<endl;
   }
   else
   {
   	fseek(FCLiente, (long)(iAuxID-1)* sizeof(Cliente), 0);
      fread(&cliente, sizeof(Cliente), 1, FCLiente);
      fflush(stdin);
      cout<<"\t||=====================================||"<<endl;
      cout<<"\t||ID: "<<cliente.iID<<endl;
      cout<<"\t||NIT: "<<cliente.stNit<<endl;
      cout<<"\t||Nombre: "<<cliente.stNombre<<endl;
      cout<<"\t||Apellido: "<<cliente.stApellido<<endl;
      cout<<"\t||Direccion: "<<cliente.stDireccion<<endl;
      cout<<"\t||Telefono: "<<cliente.stTelefono<<endl;
      cout<<"\t||=====================================||"<<endl;
      fflush(stdin);
      cout << "Dese elimnar el cliente? [S/N] ";
      cin>>Cresp;
      fflush(stdin);
      if (Cresp == 's' || Cresp == 'S')
      	{
         cliente.iEliminado = 1;
         cout<<"Cliente eliminado..."<<endl;
         }
      fseek(FCLiente, (long)(iAuxID-1)* sizeof(Cliente), 0);
      fwrite(&cliente, sizeof(Cliente), 1, FCLiente);
   }
fclose(FCLiente);
system("PAUSE");
}           						//Fin funcion para eliminar cliente
void Vmodificarproducto() 			//Funcion para modificar producto
{
Producto producto;
int iAuxID;
system("cls");
cout<<"Ingresa la clave del producto: ";
cin>>iAuxID;
FProducto = fopen("Producto.txt","r+");
if (FProducto == NULL)
	{
   	cout<<"Ocurrio un error al abrir el archivo...."<<endl;
   }
   else
   {
   	fseek(FProducto, (long)(iAuxID-1)* sizeof(Producto), 0);
      fread(&producto, sizeof(Producto), 1, FProducto);
      fflush(stdin);
      		cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
            cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
            cout <<"\t||======================================================== "<<endl;
      fflush(stdin);
      cout << "\t||Descripcion: ";
	fgets(producto.stDescripcion, sizeof(producto.stDescripcion), stdin);
	if (producto.stDescripcion[strlen(producto.stDescripcion) - 1] == '\n')
		producto.stDescripcion[strlen(producto.stDescripcion) - 1] = '\0';
	fflush(stdin);
	cout << "\t||Precio de ingreso: ";
	cin >> producto.dPrecioIngreso;
	fflush(stdin);
	cout << "\t||Precio de venta por menor: ";
	cin >> producto.dPrecioVentaMenor;
	fflush(stdin);
	cout << "\t||Precio de venta por docena: ";
	cin >> producto.dPrecioVentaDocena;
	fflush(stdin);
	cout << "\t||Precio de venta por mayor: ";
	cin >> producto.dPrecioVentaMayor;
	fflush(stdin);
	cout << "\t||Stock minimo: ";
	cin >> producto.iStockMinimo;
	fflush(stdin);
	cout << "\t||Stock maximo: ";
	cin >> producto.iStockMaximo;
	fflush(stdin);
	cout << "\t||Fecha de vencimiento: " << endl;
   gotoxy(34,22);
	cin >> producto.fecha.iDiaVen;
   gotoxy(37,22);
	cout << "/";
   gotoxy(38,22);
	cin >> producto.fecha.iMesVen;
   gotoxy(41,22);
	cout << "/";
   gotoxy(43,22);
	cin >> producto.fecha.iAnioVen;
	fflush(stdin);
	cout << "\t||Fecha de ingreso: " << endl;
   gotoxy(34,23);
	cin >> producto.fecha.iDiaIn;
   gotoxy(37,23);
	cout << "/";
   gotoxy(38,23);
	cin >> producto.fecha.iMesIn;
   gotoxy(41,23);
	cout << "/";
   gotoxy(43,23);
	cin >> producto.fecha.iAnioIn;
	fflush(stdin);
	cout << "\t||Existencia: ";
	cin >> producto.iExistencia;
	fflush(stdin);
	cout << "\t||Factura de ingreso: ";
	fgets(producto.stCodigoFactura, sizeof(producto.stCodigoFactura), stdin);
	if (producto.stCodigoFactura[strlen(producto.stCodigoFactura) - 1] == '\n')
		producto.stCodigoFactura[strlen(producto.stCodigoFactura) - 1] = '\0';
	fflush(stdin);
      fseek(FProducto, (long)(iAuxID-1)* sizeof(Producto), 0);
      fwrite(&producto, sizeof(Producto), 1, FProducto);
      cout<<"Registro modificado..."<<endl;
   }
fclose(FProducto);
system("PAUSE");
}           						//Fin funcion para modificar producto
void Veliminarproducto() 			//Funcion para eliminar producto
{
Producto producto;
int iAuxID;
char Cresp;
system("cls");
cout<<"Ingresa la clave del producto: ";
cin>>iAuxID;
FProducto = fopen("Producto.txt","r+");
if (FProducto == NULL)
	{
   	cout<<"Ocurrio un error al abrir el archivo...."<<endl;
   }
   else
   {                                                            //aqui voy
   	fseek(FProducto, (long)(iAuxID-1)* sizeof(Producto), 0);
      fread(&producto, sizeof(Producto), 1, FProducto);
      fflush(stdin);
      		cout <<"\t|| ID: " << producto.iID <<endl;
				cout <<"\t|| Descripcion: " << producto.stDescripcion<<endl;
				cout <<"\t|| Precio de ingreso: " << producto.dPrecioIngreso<<endl;
				cout <<"\t|| Precio de venta por menor: " << producto.dPrecioVentaMenor<<endl;
				cout <<"\t|| Precio de venta por docena: " << producto.dPrecioVentaDocena<<endl;
				cout <<"\t|| Precio de venta por mayor: " << producto.dPrecioVentaMayor<<endl;
				cout <<"\t|| Stock Minimo: " << producto.iStockMinimo<<endl;
				cout <<"\t|| Stock Maximo: " << producto.iStockMaximo<< endl;
				cout <<"\t|| Fecha de vencimiento: " << producto.fecha.iDiaVen << "/" << producto.fecha.iMesVen << "/" << producto.fecha.iAnioVen << endl;
            cout <<"\t|| Fecha de ingreso: " << producto.fecha.iDiaIn << "/" << producto.fecha.iMesIn << "/" << producto.fecha.iAnioIn << endl;
				cout <<"\t|| Existencia: " << producto.iExistencia<<endl;
				cout <<"\t|| Factura de ingreso: " << producto.stCodigoFactura<<" "<<endl;
            cout <<"\t||======================================================== "<<endl;
      fflush(stdin);
      cout <<"\t||Desea eliminar el producto? [S/N] ";
      cin>>Cresp;
      fflush(stdin);
      if (Cresp == 's' || Cresp == 'S')
      	{
         producto.iEliminado = 1;
         cout<<"Producto eliminado..."<<endl;
         }
      fseek(FProducto, (long)(iAuxID-1)* sizeof(Producto), 0);
      fwrite(&producto, sizeof(Producto), 1, FProducto);
   }
fclose(FProducto);
system("PAUSE");
}
void Vexistenciaproducto(int iAuxID, int iCant)         						//Fin funcion para modificar existencia producto
{
Producto producto;
FProducto = fopen("Producto.txt","r+");
if (FProducto == NULL)
	{
   }
   else
   {
   	fseek(FProducto, (long)(iAuxID-1)* sizeof(Producto), 0);
      fread(&producto, sizeof(producto), 1, FProducto);
      fflush(stdin);
         producto.iExistencia = producto.iExistencia - iCant;
      fseek(FProducto, (long)(iAuxID-1)* sizeof(Producto), 0);
      fwrite(&producto, sizeof(Producto), 1, FProducto);
   }
fclose(FProducto);
}          					//Funcion para modificar existencia

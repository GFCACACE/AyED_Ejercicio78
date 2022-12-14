/* CC3mo Probar el cC3digo:

 * Generar archivo con siguientes productos(CodP, PU, Stk):
 001 $25.25 999
 088 $1000.00 012
 999 $1.111  030
 * Pedir(codP, cv): 
 000 
 001 999
 088 10
 999 31


*/  
  
#include <iostream>
  
using namespace std;

 
struct catalogo 
{
  
int codP;
   
float PU;
   
int Stk;
 
};

 
 
void 
generarArchivo () 
{
  
catalogo inventario;
  
FILE * archivo;
  
archivo = fopen ("ej78.dat", "wb");
  
 
cout << "Ingrese codigo de Producto: ";
  
cin >> inventario.codP;
  
 
while (inventario.codP != 0)
    
    {
      
cout << "Ingrese precio unitario: ";
      
cin >> inventario.PU;
      
cout << "Ingrese Stock: ";
      
cin >> inventario.Stk;
      
fwrite (&inventario, sizeof (inventario), 1, archivo);
      
 
cout << "Ingrese codigo de Producto: ";
      
cin >> inventario.codP;
    
 
}
  
fclose (archivo);

}


 
 
 
void 
leerArchivoFinal () 
{
  
catalogo inventario;
  
FILE * arch;
  
arch = fopen ("ej78.dat", "rb");
  
cout << "Inventario de Stock Actual" << endl;
  
fread (&inventario, sizeof (inventario), 1, arch);
  
cout << "codP\tPU\t\tStk" << endl;
  
while (!feof (arch))
    
    {
      
printf ("%03d\t$%7.2f\t\t%03d\n", inventario.codP, inventario.PU,
	       
inventario.Stk);
      
fread (&inventario, sizeof (inventario), 1, arch);
    
}
  
cout << "---------------------" << endl;
  
fclose (arch);

}


 
void 
programa () 
{
  
FILE * arch;
  
arch = fopen ("ej78.dat", "rb");
  
int codigo_consulta, cantv, i;
  
int carga_copia = 0;
  
float importe;
  
catalogo copia[30];
  
catalogo inventario;
  
 
//copia archivo en vector//
    while (fread (&inventario, sizeof (inventario), 1, arch))
    
    {
      
copia[carga_copia] = inventario;
      
carga_copia++;
      
	//Estamos cargando el archivo en un vector de registro
    }
  
 
i = carga_copia;		// conozco la cantidad de prodcutos en inventario.
  
fclose (arch);
  
 
    //Busco un codigo de producto a comprar//
    cout << "Ingrese codigo de Producto:";
  
cin >> codigo_consulta;
  
 
while (codigo_consulta != 0)
    {
      
carga_copia = 0;		//inicio un contador//
      while (codigo_consulta != copia[carga_copia].codP && carga_copia <= i)
	{			//busco el producto que sea igual al codigo buscado//
	  carga_copia++;
	
}
      
	//ciclamos el indice carga_copia para encontrar la posicion del producto segun su codigo,
	//y corroboramos que no sobrepase la cantidad de productos existentes, si carga_copia es mayor a i significa
	//que no existe el codigo ingresado.
	
if (carga_copia >= 0 && carga_copia <= i)
	{			//Si existe//
	  cout << "Ingrese cantidad vendida" << endl;
	  
cin >> cantv;
	  cout << endl;
	  
if (cantv <= copia[carga_copia].Stk)
	    {			// revisamos que la cantidad pedida no sea mayor al stock disponible.
	      importe = (cantv * 1.0) * copia[carga_copia].PU;	//cantidad * precio//
	      if (importe <= 9999.99)
		{
		  
copia[carga_copia].Stk -= cantv;	// descontamos la cantidad vendida del stock.
		  cout << "El importe del pedido ingresado es: " << importe << endl;	//informamos en el momento la venta por ese producto.
		}
	      
	      else
		{
		  
cout << "El pedido supera el monto de $9999.99" << endl;
		
}
	    
}
	  
	  else
	    {
	      
cout << "No puede entregarse el pedido por stock insuficiente"
		<< endl;
	    
}
	
}
      
      else
	{
	  
cout << "El producto solicitado no existe" << endl;
	
}
      
cout << "Ingrese codigo de producto" << endl;
      
cin >> codigo_consulta;
    
}
  
 
arch = fopen ("ej78.dat", "wb");
  
 
for (carga_copia = 0; carga_copia < i; carga_copia++)
    {
      
inventario = copia[carga_copia];
      
fwrite (&inventario, sizeof (inventario), 1, arch);
    
}				//actualizamos el archivo con las nuevas cantidades de stock existentes.
  fclose (arch);
  
 
arch = fopen ("ej78.dat", "rb");
  
 
fread (&inventario, sizeof (inventario), 1, arch);
  
cout << "codP\tPU\t\tStk" << endl;
  
while (!feof (arch))
    
    {
      
cout << inventario.codP << "    " << inventario.
	PU << "     " << inventario.Stk << "    " << endl;
      
fread (&inventario, sizeof (inventario), 1, arch);
    
}
  
cout << "---------------------" << endl;
  
fclose (arch);
  
//Reimprimimos el archivo ya actualizado
}


 
 
 
int 
main () 
{
  
int opcion = 0;
  
 
while (opcion != 4)
    
    {
      
cout << "Seleccione Opcion:" << endl << "1. generar" << endl <<
	
"2. Leer no filtro" << endl << "3. Programa" << endl << "4. Salir" <<
	
endl;
      
cin >> opcion;
      
 
 
switch (opcion)
	
	{
	
case 1:
	  
generarArchivo ();
	  
break;
	
case 2:
	  
leerArchivoFinal ();
	  
break;
	
case 3:
	  
programa ();
	  
break;
	
case 4:
	  
return 0;
	
default:
	  
break;
	
}
    
}
  
 
return 0;

}



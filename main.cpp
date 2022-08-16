#include <iostream>

using namespace std;

struct catalogo
{
	int codP;
	float PU;
	int Stk;
};

struct ticket
{
	int codP;
	float PU;
	int cv;
};

void
generarArchivo()
{
	catalogo inventario;
	FILE* archivo;
	archivo = fopen("ej78.dat", "wb");
	inventario.codP = -1;
	while (inventario.codP != 0)
	{
		inventario.PU = 0;
		inventario.Stk = 0;
		cout << "CC3digo de Producto: ";
		cin >> inventario.codP;

		if (inventario.codP != 0)
		{
			cout << "Precio unitario: ";
			cin >> inventario.PU;
			cout << "Stock: ";
			cin >> inventario.Stk;

			fwrite(&inventario, sizeof(inventario), 1, archivo);
		}
	}
}

void
leerArchivoFinal()
{
	catalogo inventario;
	FILE* arch;
	arch = fopen("ej78.dat", "rb");
	cout << "Inventario de Stock Actual" << endl;
	fread(&inventario, sizeof(inventario), 1, arch);
	cout << "codP\tPU\t\tStk" << endl;
	while (!feof(arch))
	{
		printf("%03d\t$%7.2f\t\t%03d\n", inventario.codP, inventario.PU,
			inventario.Stk);
		fread(&inventario, sizeof(inventario), 1, arch);
	}
	cout << "---------------------" << endl;
	fclose(arch);
}

void programa()
{
	catalogo inventario;
	catalogo copia[30];
	ticket pedido[30];
	int carga = 0;
	int consulta = 0, i = 0;
	int cv;
	int x;
	int consulta_cod = -1;
	int consulta_stk = -1;
	FILE* arch;

	arch = fopen("ej78.dat", "rb");

	fread(&inventario, sizeof(inventario), 1, arch);
	while (!feof(arch))
	{
		copia[carga].codP = inventario.codP;
		copia[carga].PU = inventario.PU;
		copia[carga].Stk = inventario.Stk;
		carga++;
		fread(&inventario, sizeof(inventario), 1, arch);
		//Estamos cargando el archivo en un vector de registro
	}
	fclose(arch);
	cout << "Ingrese codigo de Producto:" << endl;
	cin >> consulta_cod;
	//Pedimos el codigo
	while (consulta_cod != 0)
	{

		do
		{
			//consultamos su existencia

			if (copia[consulta].codP == consulta_cod)
			{
				//si existe, lo copiamos al pedido
				pedido[i].codP == copia[consulta].codP;
				pedido[i].PU == copia[consulta].PU;
				cout << "Ingrese Cantidad:";
				cin >> cv;
				//Ahora pedimos cuantas unidades vamos a venderle
				if (cv <= copia[consulta].Stk)
				{
					//Si hay lo suficiente, la adjuntamos al ticket y restamos del inventario.
					pedido[i].cv == cv;
					copia[consulta].Stk = copia[consulta].Stk - cv;
				}
				else
				{
					cout << "Stock Insuficiente" << endl;
				}
				i++;
			}
			consulta++;
		} while ((copia[consulta].codP != consulta_cod) && (consulta < carga));
		if (consulta > carga)
		{
			cout << "El codigo ingresado no existe" << endl;
		}
		cout << "Ingrese codigo de Producto:" << endl;
		cin >> consulta_cod;
	}
	//Cargamos el pedido
	for (x = 0; x <= 30; x++) {
		cout << pedido[x].codP << "  " << pedido[x].cv << endl;
	}

}

int
main()
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
			generarArchivo();
			break;
		case 2:
			leerArchivoFinal();
			break;
		case 3:		programa();
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}

	return 0;
}
#include <iostream>

using namespace std;

struct catalogo {
    int codP;
    float PU;
    int Stk;
};

void generarArchivo() {
    catalogo inventario;
    FILE* archivo;
    archivo = fopen("ej78.dat", "wb");
    inventario.codP = -1;
        while (inventario.codP != 0) {
            inventario.PU = 0;
            inventario.Stk = 0;
            cout << "Código de Producto: "; cin >> inventario.codP;
           
            if (inventario.codP != 0){
            cout << "Precio unitario: "; cin >> inventario.PU;
            cout << "Stock: "; cin >> inventario.Stk;

                fwrite(&inventario, sizeof(inventario), 1, archivo);
            }
        }
}

void leerArchivoFinal() {
    catalogo inventario;
    FILE* arch;
    arch = fopen("ej78.dat", "rb");
    cout << "Inventario de Stock Actual" << endl;
    fread(&inventario, sizeof(inventario), 1, arch);
    cout << "codP\tPU\t\tStk" << endl;
    while (!feof(arch)) {
        printf("%03d\t$%7.2f\t\t%03d\n",inventario.codP, inventario.PU, inventario.Stk);
        fread(&inventario, sizeof(inventario), 1, arch);
    }
    cout << "---------------------" << endl;
    fclose(arch);
}
/*
void programa() {
    treg rreg;
    int acc = 0;
    FILE* arch;
    arch = fopen("ej76", "rb");
    fread(&rreg, sizeof(rreg), 1, arch);
    while (!feof(arch)) {
        if ((rreg.Par1 >= 6 && (rreg.Par2 >= 6 || rreg.RecP2 >= 6)) || (rreg.Par2 >= 6 && (rreg.Par1 >= 6 || rreg.RecP1 >= 6)) || (rreg.RecP1 >= 6 && rreg.RecP2 >= 6)) {
            cout << rreg.legajo << " " << rreg.Par1 << " " << rreg.Par2 << " " << rreg.RecP1 << " " << rreg.RecP2 << endl;
        }
        if (rreg.Par1 >= 8 && (rreg.Par2 >= 8 || rreg.RecP2 >= 8) || rreg.Par2 >= 8 && (rreg.Par1 >= 8 || rreg.RecP1 >= 8))
            acc++;
        fread(&rreg, sizeof(rreg), 1, arch);
    }
    cout << "Prom: " << acc << endl;
    fclose(arch);
}
*/
int main()
{
    int opcion = 0;

    while (opcion != 4) {
        cout << "Seleccione Opcion:" << endl << "1. generar" << endl << "2. Leer no filtro" << endl << "3. Programa" << endl << "4. Salir" << endl; cin >> opcion;


        switch (opcion) {
        case 1: generarArchivo();
            break;
        case 2: leerArchivoFinal();
            break;
        case 3: //programa();
            break;
        case 4: return 0;
        default: break;
        }
    }

    return 0;
}
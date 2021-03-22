#include <iostream>
#include <iomanip>

using namespace std;

//----------------------------Cargar Matriz vacia-------------------------

void cargarMatriz(int matriz[][9], const int & columna, const int & fila)
{
    for(int i=0; i<fila; i++)
        for(int j=0; j<columna; j++)
            matriz[i][j]= 0 ;
}

//-------------------------------Imprimir matriz--------------------------------------------------

void mostrarMatriz(int matriz[][9], const int & columna, const int & fila)
{
    for (int f = 0; f < fila; f++)
    {
        for (int c = 0; c < columna; c++)
        {
            if (((f == 3) || (f == 6)) && (c == 0))
            {
                for (int aux = 0; aux < fila; aux++)
                {
                    if ((aux == 3) || (aux == 6))
                        cout << " ";
                    cout << setw(2) <<  "_" << setw(2) << "  ";
                }
                cout << "\n";
                cout << "\n";
            }
            if ((c == 3) || (c == 6))
                cout << "|";
            cout << setw(2) << matriz[f][c] << setw(2) << "  ";
        }
        cout << "\n";
    }
    cout << endl;
}

bool esValido(int matriz[][9], int i, int j, int valor)
{
    bool valido = true;
    int fila=0;
    int columna=0;
    if ((3 <= i) && (i < 6))
        fila=3;
    else if (6 <= i)
        fila=6;
    if ((3 <= j) && (j < 6))
        columna=3;
    else if (6 <= j)
        columna=6;
    for (int contFila = 0; contFila < 3; contFila++)
    {
        int columnaAux = columna;
        for (int contColumna = 0; contColumna < 3; contColumna++)
        {
            if (matriz[fila][columnaAux] == valor)
                valido = false;
            columnaAux++;
        }
        fila++;
    }
    for (fila = 0; fila < 9; fila++)
        if (matriz[fila][j] == valor)
            valido = false;
    for (columna = 0; columna < 9; columna++)
        if (matriz[i][columna] == valor)
            valido = false;
    //cout << "valor: " << valor << "\n";
    //cout << "valido: " << valido << "\n";
    return valido;
}
void backSudoku(int matriz[][9], int i, int j, bool & resuelto)
{
    if (i > 8)
    {
        cout << "La solucion es:" << "\n";
        mostrarMatriz(matriz, 9, 9);
        resuelto = true;
    }
    else
    {
        if (matriz[i][j] == 0)
        {
            int valor = 1;
            while ((!resuelto) && (valor < 10))
            {
                if (esValido(matriz,i,j,valor))
                {
                    matriz[i][j] = valor;
                    if ((i <= 8) && (j < 8))
                        backSudoku(matriz,i,j+1,resuelto);
                    else
                        if (j >= 8)
                            backSudoku(matriz,i+1,0,resuelto);
                    matriz[i][j] = 0;
                }
                valor++;
            }
        }
        else
        {
            if (j < 8)
                backSudoku(matriz,i,j+1,resuelto);
            else
                backSudoku(matriz,i+1,0,resuelto);
        }
    }
}

int main()
{
    int matriz[9][9]={  {0,0,0,0,0,0,0,1,2},
                        {0,0,0,0,3,5,0,0,0},
                        {0,0,0,6,0,0,0,7,0},
                        {7,0,0,0,0,0,3,0,0},
                        {0,0,0,4,0,0,8,0,0},
                        {1,0,0,0,0,0,0,0,0},
                        {0,0,0,1,2,0,0,0,0},
                        {0,8,0,0,0,0,0,4,0},
                        {0,5,0,0,0,0,6,0,0}};
    bool resuelto = false;
    backSudoku(matriz,0,0,resuelto);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Letras.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int index;
    char archivo[30];
    int i;
    ArrayList* caracteres;
    caracteres = al_newArrayList();
    ArrayList* caracteresOrdenados;
    caracteresOrdenados = al_newArrayList();


    while(seguir=='s')
    {
        system("cls");
        printf("1- Altas\n");
        printf("2- Completar campos\n");
        printf("3- Listar\n");
        printf("4- Listar array ordenado\n");
        printf("5- Generar salidas\n");
        printf("6- Listar array cadena descendente\n");
        printf("8- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese nombre de archivo: ");
                fflush(stdin);
                gets(archivo);
                if(strcmp(archivo,"caracter.csv")==0)
                {
                    index = parserRead("caracter.csv",caracteres);
                    if(index==0)
                    {
                        printf("\nSe leyo archivo correctamente\n");
                    }
                }
                else
                {
                    printf("\nError al leer archivo\n");
                }
                system("pause");
                break;

            case 2:
                index = letra_completarCampos(caracteres);
                if(index==0)
                {
                    printf("\nSe completaron los campos correctamente\n");
                }
                else
                {
                    printf("\nError al completar campos");
                }
                system("pause");
                break;

            case 3:
                printf("ID -- Letra -- Nombre -- Vocal -- Consonante -- Numero\n");
                for(i=0;i<10;i++)
                {
                    letra_print(caracteres->pElements[i]);
                }
                system("pause");
                for(i=0;i<caracteres->len(caracteres);i++)
                {
                    letra_print(caracteres->pElements[i]);
                }
                system("pause");
                break;

            case 4:
                letra_generarArrayOrdenado(caracteres,caracteresOrdenados);

                printf("ID -- Letra -- Nombre -- Vocal -- Consonante -- Numero\n");
                for(i=0;i<caracteresOrdenados->len(caracteresOrdenados);i++)
                {
                    letra_print(caracteresOrdenados->pElements[i]);
                }

                system("pause");
                break;

            case 5:
                /*index = parserWrite("info.csv",numeros);
                if(index==0)
                {
                    printf("\nSe guardo archivo correctamente\n");
                }
                else
                {
                    printf("\nError al guardar archivo");
                }*/
                system("pause");
                break;

            case 6:
                /*printf("ID -- Letra -- Nombre -- Vocal -- Consonante\n");
                for(i=0;i<letrasCadena->len(letrasCadena);i++)
                {
                    letra_print(letrasCadena->pElements[i]);
                }*/
                system("pause");
                break;

            case 8:
                seguir = 'n';
                break;

            default:
                printf("Opcion incorrecta\n\n");
                system("pause");
                break;
        }
    }
    return 0;
}

#include<string.h>
#include<stdio.h>
#include "parser.h"
#include "Letras.h"

int parserRead(char* archivo,ArrayList* this)
{
    int ret = -1;
    char caracter;
    char nombre[22];
    int vocal;
    int consonante;
    int numero;
    int id=1;
    int leidos;
    int i;
    int index;
    int flag = 1;
    eCaracter* aux;
    FILE* pFile;

    if(archivo!=NULL && this!=NULL)
    {
        ret = -2;
        pFile=fopen(archivo,"r");

        if(pFile!=NULL)
        {
            ret = 0;
            fseek(pFile,39L,SEEK_SET);
            for(i=0;!feof(pFile);i++)
            {
                leidos=fscanf(pFile,"%c,%[^,],%d,%d,%d\n",&caracter,nombre,&vocal,&consonante,&numero);
                if(leidos==5)
                {
                    aux=letra_new();
                    if(aux!=NULL)
                    {
                        index = letra_setLetra(aux,caracter);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = letra_setNombre(aux,nombre);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = letra_setVocal(aux,vocal);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = letra_setConsonante(aux,consonante);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        index = letra_setNumero(aux,numero);
                        if(index==-1)
                        {
                            flag = 0;
                        }
                        if(flag == 1)
                        {
                            letra_setIsEmpty(aux,0);
                            letra_setId(aux,id);
                            id++;
                            this->add(this,aux);
                        }
                        flag = 1;
                    }
                }
            }
        }
        fclose(pFile);
    }
    return ret;
}

/*int parserWrite(char* archivo,ArrayList* this)
{
    int ret = -1;
    int i;
    eCaracter* aux;
    FILE* pFile;

    if(this!=NULL)
    {
        ret = -2;
        pFile=fopen(archivo,"w");

        if(pFile!=NULL)
        {
            ret = 0;
            for(i=0;i<this->len(this);i++)
            {
                aux = (eCaracter*) this->get(this,i);
                fprintf(pFile,"%d,%s,%d,%d,%d\n",letra_getNumero(aux),letra_getNombre(aux),letra_getPar(aux),letra_getImpar(aux),letra_getPrimo(aux));
            }
        }
        fclose(pFile);
    }
    return ret;
}*/






/*ArrayList* depurar(ArrayList* destinatarios,ArrayList* listaNegra)
{
    ArrayList* listaDepurada;
    listaDepurada=al_newArrayList();
    empleado* aux;
    empleado* auxBlack;
    int flag;
    int i;
    int j;
    if(destinatarios!=NULL&&listaNegra!=NULL)
    {
        for(i=0;i<destinatarios->len(destinatarios);i++)
        {
            flag=0;
            aux=destinatarios->get(destinatarios,i);
            for(j=0; j<listaNegra->len(listaNegra); j++)
            {
                auxBlack=listaNegra->get(listaNegra,j);
                if((strcmp(aux->profesion,auxBlack->profesion))==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                listaDepurada->add(listaDepurada,aux);
            }
        }
    }
    return listaDepurada;
}

void listar(ArrayList* listaDepurada)
{
    int contador=0;
    empleado* aux;
    int i;
    for(i=0;i<listaDepurada->len(listaDepurada);i++)
    {
        aux=listaDepurada->get(listaDepurada,i);
        if(aux!=NULL)
        {
            printf("\n%s %s",aux->nombre,aux->profesion);
            contador=contador+1;
        }
    }
    printf("\nTotal Printeados %d",contador);
}
*/

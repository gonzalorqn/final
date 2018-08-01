#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Letras.h"

eCaracter* letra_new(void)
{
    eCaracter* returnAux = NULL;
    returnAux = (eCaracter*) malloc(sizeof(eCaracter));
    returnAux->isEmpty = 1;

    return returnAux;
}

int letra_setLetra(eCaracter* this, char letra)
{
    int ret = -1;
    if(this!=NULL)
    {
        ret = 0;
        this->letra = letra;
    }
    return ret;
}

int letra_setNombre(eCaracter* this, char* nombre)
{
    int ret = -1;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>0 && strlen(nombre)<22)
    {
        ret = 0;
        strcpy(this->nombre, nombre);
    }
    return ret;
}

int letra_setVocal(eCaracter* this, int number)
{
    int ret = -1;
    if(this!=NULL && number<=1 && number>=0)
    {
        ret = 0;
        this->vocal = number;
    }
    return ret;
}

int letra_setConsonante(eCaracter* this, int number)
{
    int ret = -1;
    if(this!=NULL && number<=1 && number>=0)
    {
        ret = 0;
        this->consonante = number;
    }
    return ret;
}

int letra_setNumero(eCaracter* this, int number)
{
    int ret = -1;
    if(this!=NULL && number<=1 && number>=0)
    {
        ret = 0;
        this->numero = number;
    }
    return ret;
}

int letra_setIsEmpty(eCaracter* this, int isEmpty)
{
    int ret = -1;
    if(this!=NULL && isEmpty>=0)
    {
        ret = 0;
        this->isEmpty = isEmpty;
    }
    return ret;
}

int letra_setId(eCaracter* this, int id)
{
    int ret = -1;
    if(this!=NULL && id>0)
    {
        ret = 0;
        this->id = id;
    }
    return ret;
}

void letra_print(eCaracter* this)
{
    if(this!=NULL && this->isEmpty==0)
    {
        printf("%03d -- %01c -- %-10s -- %01d -- %01d -- %01d\n",this->id,this->letra,this->nombre,this->vocal,this->consonante,this->numero);
    }
}

int letra_completarCampos(ArrayList* this)
{
    int ret = -1;
    int i;
    if(this!=NULL)
    {
        ret = 0;
        for(i=0;i<this->len(this);i++)
        {
            letra_completarVocal(this->pElements[i]);
        }
    }
    return ret;
}

void letra_completarVocal(eCaracter* this)
{
    char letra;
    if(this!=NULL)
    {
        letra = letra_getLetra(this);
        if(letra != '\0' && ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')))
        {
            if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
            {
                this->vocal = 1;
                this->consonante = 0;
                this->numero = 0;
            }
            else
            {
                this->vocal = 0;
                this->consonante = 1;
                this->numero = 0;
            }
        }
        else if(letra >= '0' && letra <= '9')
        {
            this->vocal = 0;
            this->consonante = 0;
            this->numero = 1;
        }

    }
}

int letra_generarArrayOrdenado(ArrayList* this,ArrayList* depurado)
{
    int ret = -1;
    int i;
    int j;
    int len;
    eCaracter* aux;
    eCaracter* aux2;

    if(this!=NULL && depurado!=NULL)
    {
        ret = 0;
        len = this->len(this);
        for(i=0;i<len-1;i++)
        {
            aux = this->get(this,i);

            for(j=i+1;j<len;j++)
            {
                aux2 = this->get(this,j);
                if(aux->letra != aux2->letra && comprobarRepetidos(depurado,aux)==1)
                {
                    depurado->add(depurado,aux);
                }
            }
        }
    }
    al_sort(depurado,ordenarCaracteres,1);
    return ret;
}

int comprobarRepetidos(ArrayList* repetidos,eCaracter* caracter)
{
    int i;
    int retorno=1;
    eCaracter* auxiliar;

    if(repetidos!=NULL && caracter!=NULL)
    {
        for(i=0;i<repetidos->len(repetidos);i++)
        {
            auxiliar=repetidos->get(repetidos,i);
            if(auxiliar->letra==caracter->letra)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int ordenarCaracteres(void* char1 ,void* char2)
 {
    int retorno;
    eCaracter* uno;
    eCaracter* dos;

    uno=(eCaracter*)char1;
    dos=(eCaracter*)char2;
    if(uno->letra>dos->letra)
    {
        retorno=1;
    }
    else if(uno->letra<dos->letra)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
  return retorno;
 }

char letra_getLetra(eCaracter* this)
{
    char ret = '\0';
    if(this!=NULL)
    {
        ret = this->letra;
    }
    return ret;
}

char* letra_getNombre(eCaracter* this)
{
    char* ret = NULL;
    if(this!=NULL)
    {
        ret = this->nombre;
    }
    return ret;
}

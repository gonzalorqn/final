#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char letra;
    char nombre[22];
    int vocal;
    int consonante;
    int numero;
    int isEmpty;

}typedef eCaracter;


eCaracter* letra_new(void);
void letra_print(eCaracter* this);
int letra_completarCampos(ArrayList* this);
void letra_completarVocal(eCaracter* this);
int letra_generarArrayOrdenado(ArrayList* this,ArrayList* depurado);
int comprobarRepetidos(ArrayList* repetidos,eCaracter* numero);
int ordenarCaracteres(void* char1 ,void* char2);

int letra_setLetra(eCaracter* this, char letra);
int letra_setNombre(eCaracter* this, char* nombre);
int letra_setVocal(eCaracter* this, int number);
int letra_setConsonante(eCaracter* this, int number);
int letra_setNumero(eCaracter* this, int number);
int letra_setIsEmpty(eCaracter* this, int isEmpty);
int letra_setId(eCaracter* this, int id);

char letra_getLetra(eCaracter* this);
char* letra_getNombre(eCaracter* this);
int letra_getPar(eCaracter* this);
int letra_getImpar(eCaracter* this);
int letra_getId(eCaracter* this);

/*void employee_print(Employee* this);
int funcionQueFiltra(void* item);


int employee_compare(void* pEmployeeA,void* pEmployeeB);*/
#endif // _EMPLOYEE_H




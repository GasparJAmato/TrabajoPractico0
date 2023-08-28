#include <stdlib.h>
#include <stdio.h>
#include <string.h>



enum TIPO { NORMAL, FUEGO, AGUA, PLANTA, ELECTRICO, ROCA };

struct ataque {
	char nombre[100];
	enum TIPO tipo;
	unsigned int poder;
};


enum TIPO converCharEnum(char tipo){
    switch (tipo)
    {
    case 'N': return NORMAL;
    case 'F':return FUEGO;
    case 'A': return AGUA;
    case 'P': return PLANTA;
    case 'E': return ELECTRICO;
    case 'R': return ROCA;
    
    default:
        return -1;
    }
}


struct ataque *parsear_ataque(char *texto, struct ataque *ataque)
{
   
	//completar esta función según lo pedido en el enunciado
    
    char nom[100];
    unsigned int poder = 0;

    int i = 0;
    int j = 0;

    if(strlen(texto) == 0){
    return NULL;
    }

    for(i = 0; texto[i] != ';' ; i++){
        nom[j] = texto[i];
        j++;

       
    }
    nom[j] = '\0';

    printf("el nombre es: %s \n", nom);

    
    i++;
    printf("texto i es: %c", texto[i]);
    char type = texto[i];
    i++;
    
    printf("el caracter es: %c \n", type);
    
    enum TIPO tipoN = converCharEnum(type);
    
    printf("el tipon es: %i \n", tipoN);
    if(tipoN == -1){
        return NULL;
    }

    printf("el i es: %i\n", i);
    
    printf("el poder es: %c \ny el texto entero es: %s\n", texto[i], texto);

    i++;
    if (texto[i] <= '0' && texto[i] >= '9' || texto[i] == '\0'){
        printf("el formato no es valido \n");
        return NULL;

    }

    for(i ; texto[i] != '\0'; i++){

        printf("el poder es: %c \n", texto[i]);

            poder = poder * 10 + (texto[i] - '0');

    }

    strcpy(ataque->nombre, nom);

    ataque->tipo = tipoN;

    ataque->poder = poder;
    
	return ataque;
}

int main()
{
	struct ataque un_ataque;
	int errores = 0;

	if (parsear_ataque("", &un_ataque) != NULL) {
		printf("Se espera que no se pueda parsear un string vacío D:\n");
		errores++;
	} else
		printf("Parseo de un string vacío 👍\n");

	if (parsear_ataque("Rayo;E;", &un_ataque) != NULL) {
		printf("Se espera que no se pueda parsear un string incorrecto D:\n");
		errores++;
	} else
		printf("Parseo de un string incorrecto 👍\n");


	if (parsear_ataque("Rayo;E;5", &un_ataque) == NULL) {
		printf("Se espera que se pueda parsear un string correcto D:\n");
		errores++;
	} else if (strcmp(un_ataque.nombre, "Rayo") == 0 &&
		 un_ataque.tipo == ELECTRICO && un_ataque.poder == 5) {
		printf("Parseo de un string correcto 👍\n");
	} else {
		printf("Se parseó el string pero los valores son incorrectos 🤔\n");
		errores++;
	}

	return errores;
}

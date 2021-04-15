#include "suma.h"
#include <stdio.h>

/* Este archivo contiene el main del cliente, 
   crea el cliente con la función clnt_create 
   y hace la llamada al procedimiento suma_1 del stub suma_clnt.c */

void suma_prog_1(char *host, int a, int b)
{
	CLIENT *clnt; //variable para crear el cliente
	int  *result_1; //resultado
	dupla_int  suma_1_arg; //parametros de entrada para sumar

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp"); //creacion del cliente
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	suma_1_arg.a = a; //parametro 1
	suma_1_arg.b = b; //parametro 2


	result_1 = suma_1(&suma_1_arg, clnt); //llamada al procedimiento suma_1 del stub suma_clnt.c
	if (result_1 == (int *) NULL) { //captación de error al imprimir resultado para evitar errores
		clnt_perror (clnt, "call failed");
	} else {
		printf("result = %d\n", *result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host; 
	int a, b; 

	if (argc != 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
	
	host = argv[1]; //host remoto donde se encuentra el servidor

	printf("Conectando con el servidor en %s\n\n", host);

	// Valida que el tipo de dato sea numerico en el argumento a
	if ((a = atoi(argv[2])) == 0 && *argv[2] != '0') {
 		fprintf(stderr, "invalid value: %s\n", argv[2]);
 		exit(1);
 	}

	// Valida que el tipo de dato sea numerico en el argumento b
	if ((b = atoi(argv[3])) == 0 && *argv[3] != '0') {
 		fprintf(stderr, "invalid value: %s\n", argv[3]);
 		exit(1);
 	}

	suma_prog_1 (host,a,b);
	exit (0);
}

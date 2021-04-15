#include "suma.h"

/* Implementación del procedimiento remoto */

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;
	
	printf("Server is working \n"); 
	printf("parameters: %d, %d\n", argp->a, argp->b); 
	printf("Server response to client...\n"); 
	printf("parameters: %d, %d\n", argp->a, argp->b); 
	result = argp->a + argp->b; 
	printf("returning: %d\n", result); 
	return &result; 
}

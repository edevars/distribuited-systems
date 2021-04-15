#ifndef _SUMA_H_RPCGEN
#define _SUMA_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Este archivo define constantes y funciones que se usaran en los codigos del cliente y del servidor*/

// Define la estructura definida en suma.x (dupla_int) y typedefs pra un tipo de dato del mismo nombre
struct dupla_int {
	int a;
	int b;
};
typedef struct dupla_int dupla_int;

#define SUMA_PROG 0x23451111 //Define numero de programa
#define SUMA_VERS 1 //Define version del programa

#if defined(__STDC__) || defined(__cplusplus)
#define SUMA 1
extern  int * suma_1(dupla_int *, CLIENT *); //interface STUB del cliente
extern  int * suma_1_svc(dupla_int *, struct svc_req *); //procedmiento remote del servidor
extern int suma_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define SUMA 1
extern  int * suma_1(); //interfaz del cliente
extern  int * suma_1_svc(); //interfac para la función de servidor
extern int suma_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_dupla_int (XDR *, dupla_int*); //boolean para verificar consistencia de la estructura

#else /* K&R C */
extern bool_t xdr_dupla_int ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_SUMA_H_RPCGEN */

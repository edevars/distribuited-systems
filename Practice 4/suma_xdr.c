#include "suma.h"

/* Este archivo contiene código para reunir parámetros para la estructura intpair 
   XDR (External Data Representation) 
   En este caso se usa para convertir los dos valores enteros a un formato estandar */

bool_t
xdr_dupla_int (XDR *xdrs, dupla_int *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	return TRUE;
}

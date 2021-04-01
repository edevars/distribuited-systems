/* Archivo calc.x */

struct numbers{
     int a;
     int b;
};

program CALC_PROG{
	version CALC_VERS{
		int SUMA( numbers) = 1;
		int RESTA( numbers ) = 2;
		int MULTIPLICACION( numbers ) = 3;
		float DIVISION( numbers ) = 4;
	} = 1;
} = 0x31111111;

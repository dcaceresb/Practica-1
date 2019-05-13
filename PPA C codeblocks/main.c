#include <stdio.h>
#include <stdlib.h>
#include "ET.h"
#include "EPS.h"
#include "EPSD.h"
#include "Tabla.h"
#include "PPA.h"

#define null NULL
int main()
{
    EPSD base;
    Tabla tabla;
    char *str =  (char*)malloc(1000);
    strcpy(str,"abbdcbabdccacabdabac");
    int supp=2;
    int r=5;

    init(str,5,&base,&tabla,supp);

    str = toStringTabla(tabla);
    printf("%s\n",str);
    str = toStringEPSD(base);
    printf("%s\n",str);

    calcular(&tabla,&base,supp);

    return 0;
}



#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED
#include "EPSD.h"
#include "EPS.h"
typedef struct nodo_tabla
{
    EPS eps;
    int freq;
}NodoT;

typedef struct tabla
{
    NodoT* datos;
    int n;
}Tabla;

Tabla newTabla()
{
    Tabla t;
    t.datos=(NodoT*)malloc(0);
    t.n=0;
    return t;
}
int existInTabla(Tabla t, EPS e)
{
    int i,n=t.n;
    for(i=0;i<n;i++)
    {
        if(equalEPS(t.datos[i].eps , e))
        {
            return i;
        }
    }
    return -1;
}
void addInTabla(Tabla *t, EPS e)
{
    int index;
    index = existInTabla(*t,e);
    if(index!=-1)
    {
        t->datos[index].freq++;
    }
    else
    {
        int n = t->n+1;

        t->datos = (NodoT*) realloc(t->datos , sizeof(NodoT)*n);
        t->datos[n-1].eps=e;
        t->datos[n-1].freq=1;
        t->n++;
    }
}

char * toStringTabla(Tabla t)
{
    char * str;
    str = (char*)malloc(8);
    str = strcpy(str,"Tabla:\n");

    int tam=8;
    char * aux;
    aux = (char*) malloc(10);
    int i,n,freq;
    n=t.n;

    for(i=0;i<n;i++)
    {
        freq = t.datos[i].freq;
        sprintf(aux,"%d\t",freq);
        tam+=strlen(aux);
        str = (char*) realloc(str,tam);
        strcat(str,aux);

        aux = toStringEPS(t.datos[i].eps);
        tam+=strlen(aux);
        str = (char*) realloc(str,tam);
        strcat(str,aux);

        tam++;
        str = (char*) realloc(str,tam);
        strcat(str,"\n");
    }
    return str;
}

Tabla frequent(Tabla t, int supp)
{
    int i,n=t.n;
    int m=0;
    Tabla f = newTabla();
    for(i=0;i<n;i++)
    {
        if(t.datos[i].freq>=supp)
        {
            m++;
            f.datos = (NodoT*) realloc(f.datos,sizeof(NodoT)*m);
            f.n++;
            f.datos[m-1]=t.datos[i];
        }
    }
    return f;
}


#endif // TABLA_H_INCLUDED

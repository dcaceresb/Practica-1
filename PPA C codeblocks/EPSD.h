
#ifndef EPSD_H_INCLUDED

#define EPSD_H_INCLUDED
#include "Tabla.h"
typedef struct epsd
{
    EPS *data;
    int n;
}EPSD;

EPSD newEPSD()
{
    EPSD nuevo;
    nuevo.data=NULL;
    nuevo.n=0;
    return nuevo;
}

bool existInEPSD(EPSD base, EPS eps)
{
    int i,n=base.n;
    for(i=0;i<n;i++)
    {
        if(equalEPS(base.data[i] , eps))
        {
            return true;
        }
    }
    return false;
}

void addInEPSD(EPSD *base, EPS eps)
{

    if(!existInEPSD(*base,eps))
    {
        int n = base->n;
        n++;
        base->data = (EPS*)realloc(base->data,sizeof(EPS)*n);
        base->data[n-1]=eps;

        base->n++;
    }

}
void sortEPSD(EPSD *base)
{
    EPS aux;
    int i,j,n = base->n;
    int cmp;
    if(base->n>1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                cmp = compareToEPS(base->data[j], base->data[j+1]);
                if(cmp==-1)
                {
                    aux = base->data[j];
                    base->data[j]=base->data[j+1];
                    base->data[j+1]=aux;
                }
            }
        }
    }
}

char * toStringEPSD(EPSD e)
{
    char * str;

    str = (char*)malloc(11);
    char * aux;
    aux = (char*)malloc(12);
    sprintf(str,"DATABASE:\n");
    int tam = strlen(str)+1;
    int i,n = e.n;

    for(i=0;i<n;i++)
    {

        sprintf(aux,"%d\t",i+1);
        tam+=strlen(aux);
        str = (char*)realloc(str,sizeof(char)*tam);
        str = strcat(str,aux);

        aux = toStringEPS(e.data[i]);
        tam+=strlen(aux);
        str = (char*)realloc(str,sizeof(char)*tam);
        str = strcat(str,aux);


        tam+=2;
        str = (char*)realloc(str,sizeof(char)*tam);
        str = strcat(str,"\n");
    }
    return str;
}

EPSD removeNotF(Tabla f, EPSD actual)
{
    EPSD nuevo = newEPSD();
    EPS aux,line;
    char * str;
    ET temp;
    int i,n = actual.n;
    int j,m;
    for(i=0;i<n;i++)
    {
        line = newEPS();
        m=actual.data[i].n;
        for(j=0;j<m;j++)
        {
            temp = actual.data[i].eps[j].et;
            aux = newEPS();
            addET(temp,&aux);
            if(existInTabla(f,aux)!=-1)
            {
                addET(temp,&line);
            }
        }
        addInEPSD(&nuevo,line);
    }

    return nuevo;
}

void prefixTabla(EPS prefijo,EPSD base, Tabla *rpp)
{
    EPS sufijo;
    int i,n=base.n;
    char *str;
    for(i=0;i<n;i++)
    {
        str = toStringEPS(prefijo);
        printf("Prefijo: %s\n",str);
        sufijo = prefixEPS(base.data[i] , prefijo);

        str = toStringEPS(sufijo);
        printf("sufijo %s\n",str);

        if(sufijo.n==0)
        {
            continue;
        }
        EPS aux;
        ET temp;
        int j,m=sufijo.n;
        for(j=0;j<m;j++)
        {
            aux = copyEPS(prefijo);

            str = toStringEPS(aux);
            temp = sufijo.eps[j].et;
            addET(temp, &aux);

            str = toStringEPS(aux);
            printf("Aux %s\n",str);

            addInTabla(rpp,aux);
        }
    }
}
#endif // EPSD_H_INCLUDED

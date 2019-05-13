#ifndef PPA_H_INCLUDED
#define PPA_H_INCLUDED

void init(char* str, int r, EPSD* base, Tabla* t,int supp)
{
    int n = strlen(str);
    char* str1;
    if(n>0 && n%r==0)
    {
        *base = newEPSD();
        *t = newTabla();
        EPS aux,toTable;
        ET et;
        int index,i,j,m = n/r;
        for(i=0;i<m;i++)
        {
            aux = newEPS();
            for(j=0;j<r;j++)
            {
                index = i*r+j;
                et = newET(str[index],j+1);
                toTable = newEPS();
                addET(et,&toTable);
                addInTabla(t,toTable);
                addET(et,&aux);
            }
            addInEPSD(base,aux);
        }
    }
    *t = frequent(*t,supp);
    *base = removeNotF(*t,*base);
}
void calcular(Tabla *t, EPSD *base,int supp)
{
    int i,n = t->n;
    EPS aux;
    char *str;
    for(i=0;i<n;i++)
    {
        aux = t->datos[i].eps;
        str = toStringEPS(aux);
        prefixTabla(aux,*base,t);
        *t=frequent(*t,supp);
        str = toStringTabla(*t);
        printf("%s\n",str);
        n = t->n;
    }

}

#endif // PPA_H_INCLUDED

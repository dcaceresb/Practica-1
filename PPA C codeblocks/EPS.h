
#ifndef EPS_H_INCLUDED
#define EPS_H_INCLUDED
#define null NULL

typedef struct nodo_eps
{
    ET et;
    struct nodo_eps* sig;
}NodoEPS;

typedef struct eps
{
    NodoEPS *eps;
    int r;
    int n;
}EPS;

EPS newEPS()
{
    EPS nuevo;
    nuevo.eps=(NodoEPS*)malloc(sizeof(NodoEPS));
    nuevo.r=0;
    nuevo.n=0;
    return nuevo;
}

void addET(ET et, EPS *eps)
{
    int n=eps->n+1;
    eps->eps = (NodoEPS*)realloc(eps->eps,sizeof(NodoEPS)*n);
    eps->eps[n-1].et=et;
    eps->eps[n-1].sig=null;
    eps->n++;
    eps->r++;

}

bool existET(ET e, EPS eps)
{
    int i,n = eps.n;
    for(i=0;i<n;i++)
    {
        if(equalET(e,eps.eps[i].et))
        {
            return true;
        }
    }
    return false;
}

char* toStringEPS(EPS e)
{
    char* str = (char*)malloc(2);
    sprintf(str,"{");
    int tam = 2;
    //strcat(str,"asda");
    char* et;
    int i,n=e.n;
    for(i=0;i<n;i++)
    {
        et = toStringET(e.eps[i].et);
        tam+=strlen(et);
        str = (char*)realloc(str,sizeof(char)*tam);
        strcat(str,et);

        if(i!=n-1)
        {
            tam++;
            str = (char*)realloc(str,sizeof(char)*tam);
            str=strcat(str,",");
        }
    }
    str=strcat(str,"}");
    return str;
}
bool equalEPS(EPS a, EPS b)
{
    if(a.n!=b.n)
    {
        return false;
    }
    int i,n = a.n;
    for(i =0;i<n;i++)
    {
        if(!equalET( a.eps[i].et , b.eps[i].et ) )
        {
            return false;
        }
    }
    return true;
}
int compareToEPS(EPS a, EPS b)
{
    if(equalEPS(a,b))
    {
        return 0;
    }
    else
    {
        int n,m;
        n=a.n;
        m=b.n;
        int cmp,i,j;
        i=j=0;
        while(i<n && j<m)
        {
            cmp = compareToET(a.eps[i].et , b.eps[j].et);
            if(cmp!=0)
            {
                return cmp;
            }
            i++;
            j++;
        }
        if(n<m)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

}
EPS copyEPS(EPS source)
{
    EPS nuevo = newEPS();
    ET aux;
    int i,n=source.n;
    for(i=0;i<n;i++)
    {
        aux = source.eps[i].et;
        addET(aux,&nuevo);
    }
    return nuevo;
}
EPS prefixEPS(EPS source, EPS prefijo)
{
    EPS sufijo = newEPS();
    int i,j,n,m;
    n=source.n;
    m=prefijo.n;
    char *str;
    /// primero igualar la posicion
    for(i=0;i<n;i++)
    {
        if(source.eps[i].et.pos == prefijo.eps[0].et.pos)
        {
            break;
        }
        else if(source.eps[i].et.pos > prefijo.eps[0].et.pos)
        {
            return sufijo;
        }
    }
    j=0;
    while(i<n && j<m)
    {
        if(!equalET(source.eps[i].et , prefijo.eps[j].et ))
        {
            return sufijo;
        }
        i++;
        j++;
    }

    for(;i<n;i++)
    {
        addET(source.eps[i].et , &sufijo);
    }
    return sufijo;

}
#endif // EPS_H_INCLUDED

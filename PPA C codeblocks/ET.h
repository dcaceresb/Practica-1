#include<stdbool.h>
#include<string.h>

#ifndef ET_H_INCLUDED
#define ET_H_INCLUDED

typedef struct et
{
    char letra;
    int pos;
}ET;

ET newET(char letra, int pos)
{
    ET nuevo;
    nuevo.letra=letra;
    nuevo.pos=pos;
    return nuevo;
}

bool equalET(ET a, ET b)
{
    if(a.letra==b.letra && a.pos==b.pos)
    {
        return true;
    }
    return false;
}

char* toStringET(ET a)
{
    char* str = (char *)malloc(50);
    sprintf(str,"(%c,%d)",a.letra,a.pos);
    return str;

}

int compareToET(ET a,ET b)
{
    if(equalET(a,b))
    {
        return 0;
    }
    else if(a.pos==b.pos)
    {
        if(a.letra<b.letra)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if(a.pos<b.pos)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
#endif // ET_H_INCLUDED

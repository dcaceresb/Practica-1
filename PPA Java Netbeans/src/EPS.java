import java.util.ArrayList;
import java.util.Objects;

public final class EPS implements Comparable<EPS>
{
    int r;
    ArrayList<ET> eps;
    public EPS()
    {
        r=0;
        eps = new ArrayList<>();
    }
    public EPS(ET a)
    {
        r=1;
        eps = new ArrayList<>();
        eps.add(new ET(a));
    }
    public EPS(EPS a)
    {
        r=a.r;
        eps = (ArrayList) a.eps.clone();
    }
    public EPS (String a)
    {
        r=0;
        eps = new ArrayList<>();
        
        int i=1;
        for(char e : a.toCharArray())
        {
            add(new ET(e,i));
            i++;
        }
    }
    public void add(ET nuevo)
    {
        eps.add(nuevo);
        r++;
    }
    public void add(char letra, int pos)
    {
        ET nuevo = new ET(letra,pos);
        add(nuevo);
    }
    
    public boolean exist(ET e)
    {
        return eps.contains(e);
    }
    
    public EPS prefix(EPS prefijo)
    {
        EPS sufijo = new EPS();
        int i,n = eps.size();
        int m = prefijo.eps.size();
        int j=0;
        for( i =0; i<n;i++)
        {
            if(eps.get(i).pos==prefijo.eps.get(0).pos)
            {
                break;
            }
            else if(eps.get(i).pos>prefijo.eps.get(0).pos)
            {
                return null;
            }
        }
       
        while(i<n && j<m)         
        {
            if(!eps.get(i).equals(prefijo.eps.get(j)))
            {
                return null;
            }
            i++;
            j++;
        }
        n = eps.size();
        for(; i<n;i++)         
        {
            sufijo.add(eps.get(i));
        }
        return sufijo;
    }
        
    @Override
    public boolean equals(Object obj)
    {
        if(obj == null)
        {
            return false;
        }
        else if (!(obj instanceof EPS))
        {
            return false;
        }  
        else 
        {
           EPS a = (EPS)obj;
           if(a.r!=r)
           {
               return false;
           }
           for(int i =0;i<r;i++)
           {
               if(!eps.get(i).equals(a.eps.get(i)))
               {
                   return false;
               }
           }
           
           return true;
        }
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + this.r;
        hash = 67 * hash + Objects.hashCode(this.eps);
        return hash;
    }
    
    @Override
    public String toString()
    {
        String a = "{";
        int i=0;
        for(ET e : eps)
        {
            a+=e;
            if(i!=eps.size()-1)
            {
                a+=",";
            }
            i++;

        }
        a+="}";
        return a;
    }

    @Override
    public int compareTo(EPS b) 
    {
        if(equals(b))
        {
            return 0;
        }
        else
        {
            int n=eps.size();
            int m = b.eps.size();
            int cmp;
            int i,j;
            i=j=0;
            while(i<n && j<m)
            {
                cmp=eps.get(i).compareTo(b.eps.get(i));
                if(cmp!=0)
                {
                    return cmp;
                }
                i++;
                j++;
            }
            if(n!=m)
            {
                return Integer.compare(n, m);
            }
            return 0;
        }
    }
}

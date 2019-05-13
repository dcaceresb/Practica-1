
public class ET implements Comparable<ET>
{
    char letra;
    int pos;
    ET(char letra,int pos)
    {
        this.letra=letra;
        this.pos=pos;
    }
    ET(ET a)
    {
        letra=a.letra;
        pos=a.pos;
    }
    
    @Override
    public boolean equals(Object obj)
    {
        
        if(obj == null)
        {
            return false;
        }
        else if (!(obj instanceof ET))
        {
            return false;
        }  
        else 
        {
            ET a = (ET)obj;
            return a.letra==letra && a.pos==pos;
        }
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 67 * hash + this.letra;
        hash = 67 * hash + this.pos;
        return hash;
    }
    
    @Override
    public String toString()
    {
        String a = "("+letra+","+pos+")";
        return a;
    }

    @Override
    public int compareTo(ET b) 
    {

        if(this.equals(b))
        {
            return 0;
        }
        else if(pos==b.pos)
        {
            if(letra<b.letra)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if(pos<b.pos)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

}

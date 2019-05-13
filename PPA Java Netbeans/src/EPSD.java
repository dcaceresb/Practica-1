
import java.util.ArrayList;
import java.util.Collections;


public class EPSD 
{
    ArrayList<EPS> epsd;
    EPSD()
    {
        epsd=new ArrayList<>();
    }
    public void add(EPS eps)
    {
        for(EPS e : epsd)
        {
            if(e.equals(eps))
            {
                return;
            }
        }
        epsd.add(new EPS(eps));
        Collections.sort(epsd);
    }
    public void remove(Tabla frequentes)
    {
        EPS aux, nuevo;
        EPSD nueva = new EPSD();
        
        for (EPS e : epsd)
        {
            nuevo = new EPS();
            for(ET et : e.eps)
            {
                aux = new EPS(et);
                if(frequentes.exist(aux))
                {
                    nuevo.add(et);
                }
            }
            nueva.add(nuevo);
        }
        this.epsd=nueva.epsd;
    }
    public boolean isEmpty()
    {
        return epsd.isEmpty();
    }
    
    @Override
    public String toString()
    {
        String a = "DATABASE:\n";
        int i=1;
        for(EPS e : epsd)
        {
            a+=i+"   "+e+"\n";
            i++;
        }
        return a;
    }
}


import java.util.ArrayList;
import java.util.Collections;


class Nodo implements Comparable<Nodo>
{
    EPS eps;
    int freq;
    Nodo(EPS eps)
    {
        this.eps=new EPS(eps);
        freq=1;
    }

    @Override
    public int compareTo(Nodo a) 
    {
        if(freq==a.freq)
        {    
            return a.eps.compareTo(eps);
        }
        return Integer.compare(a.freq, freq);
    }
    
}
public class Tabla 
{
    ArrayList<Nodo> tabla;
    Tabla()
    {
        tabla = new ArrayList<>();
    }
    Tabla(Tabla a)
    {
        tabla = (ArrayList<Nodo>) a.tabla.clone();
    }
    public void add(EPS eps)
    {
        for(Nodo e : tabla )
        {
            if(e.eps.equals(eps))
            {
                e.freq++;
                return;
            }
        }
        tabla.add(new Nodo(eps));
    }
    private void add(Nodo nodo)
    {
        tabla.add(nodo);     
    }
    public void sort()
    {
        Collections.sort(tabla);
    }
    public EPSD frequent(int supp)
    {
        EPSD data = new EPSD();
        Tabla nueva = new Tabla();
        Nodo e;
        int i,n=tabla.size();
        for(i=0;i<n;i++)
        {
            e=tabla.get(i);
            if(e.freq>=supp)
            {
                nueva.add(e);
                data.add(e.eps);
            }
        }
        this.tabla = nueva.tabla;
        return data;
    }
    public boolean exist(EPS eps)
    {
        return tabla.stream().anyMatch((e) -> (e.eps.equals(eps)));
    }
    
    public Tabla prefix(EPS prefijo,EPSD base,Tabla rpp)
    {
        EPS sufijo;

        for(EPS e : base.epsd)
        {
            sufijo = e.prefix(prefijo);
            if(sufijo==null)
            {
                continue;
            }
            System.out.println("Sufijo: "+sufijo);
            EPS aux;
            int i,n=sufijo.eps.size();
            for(i=0;i<n;i++)
            {
                aux = new EPS(prefijo);
                
                aux.add(sufijo.eps.get(i));
                System.out.println("aux: "+aux);
                rpp.add(new EPS(aux));
                System.out.println(rpp+"\n");
            }
        }
        
        return rpp;
    }
    
    @Override
    public String toString()
    {
        String a = "TABLE:\n";
        int i=1;
        for(Nodo e : tabla)
        {
            a+=e.freq+"   "+e.eps+"\n";
            i++;
        }
        return a;
    }
}

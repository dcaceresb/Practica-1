
public class PPA 
{
    String cadena;
    EPSD base;
    Tabla tabla;
    Tabla rpp = new Tabla();
    PPA(String a, int r)
    {
        if(a.length()>0 && a.length()%r==0)
        {
            base = new EPSD();
            tabla = new Tabla();
            String aux;
            int n = a.length()/r;
            for(int i =0;i<n;i++)
            {
                aux = a.substring(0, r);
                int j=1;
                for(char e : aux.toCharArray())
                {
                    tabla.add(new EPS(new ET(e,j)));
                    j++;
                }
                a=a.substring(r);
                base.add(new EPS(aux));
            }
        }
        

    }
    public void calcular()
    {
        int n = tabla.tabla.size();
        rpp = new Tabla(tabla);
        for(int i =0;i<rpp.tabla.size();i++)
        {
            System.out.println(" Con : "+rpp.tabla.get(i).eps);
            tabla.prefix(rpp.tabla.get(i).eps, base, rpp);
            rpp.frequent(2);
        }
       // rpp.sort();
        
    }

}

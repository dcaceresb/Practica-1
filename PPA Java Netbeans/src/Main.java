
public class Main 
{
    
    public static void main(String args[])
    {
        PPA algoritmo = new PPA("abbdcbabdccacabdabac",5);
        algoritmo.tabla.frequent(2);
        /*System.out.println(algoritmo.base);
        System.out.println(algoritmo.tabla);
        System.out.println(algoritmo.tabla.frequent(2));
        System.out.println(algoritmo.tabla);*/
        algoritmo.base.remove(algoritmo.tabla);
        System.out.println("Luego de eliminar:");
        System.out.println(algoritmo.base);
        System.out.println(algoritmo.tabla);
        Tabla rpp = new Tabla();
        algoritmo.tabla.prefix(algoritmo.tabla.tabla.get(0).eps, algoritmo.base, rpp);
        System.out.println("TABLA CON PREFIJO: "+algoritmo.tabla.tabla.get(0).eps);
        System.out.println(rpp);
        algoritmo.calcular();
        System.out.println("r=2");
        System.out.println(algoritmo.rpp);
        
    }
}

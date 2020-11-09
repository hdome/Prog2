public class Szulo{
public class Gyerek extends Szulo{
 public void kiir(){System.out.println("Gyerek");}
 }
public void main(String[] args)
 {
 Szulo szulo = new Gyerek();
 System.out.println(szulo.kiir());
 }
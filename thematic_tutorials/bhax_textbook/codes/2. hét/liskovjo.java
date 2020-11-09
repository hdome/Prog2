class Madar {}
class Program {
 public void fgv ( Madar madar ) {}
}
class RepuloMadar extends Madar {
 public void repul() {}
}
class Sas extends RepuloMadar {}
class Pingvin extends Madar {}
public class figyel{
 public static void main ( String[] args )
 {
 Program program = new Program();
 Madar madar = new Madar();
 program.fgv(madar);

 Sas sas = new Sas();
 program.fgv(sas);
 sas.repul();
 Pingvin pingvin = new Pingvin();
 program.fgv(pingvin);
 }
}

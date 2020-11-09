import java.awt.*;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class Teljes extends JPanel {

public void paint(Graphics g) {
    g.drawString("Hello Fullscreen", 200, 200);
  }

  public static void main(String[] args) {
    JFrame frame = new JFrame("Teljes"); //Zárójelek közöt a programnév
    frame.getContentPane().add(new Teljes());
    frame.setExtendedState(JFrame.MAXIMIZED_BOTH); //Itt lesz teljes képernyős
    frame.setUndecorated(true); //etávolítja a címsort
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//Kilépéskor bezárja a progit  
    }
}
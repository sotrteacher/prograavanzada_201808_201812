/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package programacionavanzada.u2;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.Button;
import java.awt.List;
import java.awt.BorderLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
/**
 *
 * @author LMC
 */
public class GUI03 {
    Frame F;
    Panel P;
    TextField TF;
    Button B1,B2,B3,B4,B5;
    List L;
    public GUI03(){
        F=new Frame("GUI03");
        B1=new Button("NORTE");
        B2=new Button("SUR");
        B3=new Button("ESTE");
        B4=new Button("OESTE");
        B5=new Button("CENTRO");
        F.setLayout(new BorderLayout());
        F.add(B1, BorderLayout.NORTH);
        F.add(B2,BorderLayout.SOUTH);
        F.add(B3,BorderLayout.EAST);
        F.add(B4,BorderLayout.WEST);
        F.add(B5,BorderLayout.CENTER);
        F.addWindowListener(new WindowAdapter() {//  3/5  WindowListener
            public void windowClosing(WindowEvent we){
                F.dispose();
                System.exit(0);
            }
});
        F.setSize(500, 350);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//end GUI03()
    
    public static void main(String[] args) {
        new GUI03();
    }
}//end class GUI03














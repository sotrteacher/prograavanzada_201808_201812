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
import java.awt.GridLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.event.ActionListener;// 1/5  imports
import java.awt.ActiveEvent;
import java.awt.event.ActionEvent;
/**
 *
 * @author LMC
 */
public class GUI04 implements ActionListener{// 2/5 implementar interface
    Frame F;
    Panel P;
    TextField TF;
    Button B1,B2,B3,B4,B5;
    List L;

    public GUI04(){
        F=new Frame("GUI04");
        F.setLayout(new BorderLayout());
        P=_setPanel();
        F.add(P,BorderLayout.NORTH);
        F.add(L=new List(),BorderLayout.CENTER);
        F.add(B2=new  Button("SALIR"),BorderLayout.SOUTH);
        F.addWindowListener(new WindowAdapter() {//  3/5  WindowListener
            public void windowClosing(WindowEvent we){
                F.dispose();
                System.exit(0);
            }
});
        B1.addActionListener(this);//3/5 Agregar el escucha/Listener Boton B1
        B2.addActionListener(this);//3/5 Agregar el escucha/Listener Boton B2
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//end GUI04()
    
    private Panel _setPanel(){
        Panel Pret=new Panel();
        Pret.setLayout(new GridLayout(1,2));
        TF=new TextField(60);
        Pret.add(TF);
        B1=new Button("AGREGAR");
        Pret.add(B1);
        return Pret;
    }
    
    public static void main(String[] args) {
        new GUI04();
    }

    @Override
    public void actionPerformed(ActionEvent ae) {//4/5 resolver los m\'etodos de
        //la interface (en este caso (ActionListener) solo tiene este m\'etodo)
        if(ae.getSource().equals(B1)){//5/5
            String S=TF.getText();
            L.add(S);
            TF.setText("");
            TF.requestFocus();
        }
        if(ae.getSource().equals(B2)){//5/5 B2
            System.exit(0);
        }
    }
}//end class GUI04

















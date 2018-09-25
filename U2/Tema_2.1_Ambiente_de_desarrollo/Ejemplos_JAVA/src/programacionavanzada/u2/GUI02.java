/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package programacionavanzada.u2;

/**
 *
 * @author LMC
 */

import java.awt.Frame;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.WindowAdapter;

import java.awt.event.WindowEvent;

public class GUI02 {
    Frame F;
    Button B1,B2,B3,B4;
    
    public GUI02(){
        F=new Frame("GUI01");
        F.setLayout(new GridLayout(2,2));
        B1=new Button("Boton 1");
        B2=new Button("Boton 2");
        B3=new Button("Boton 3");
        B4=new Button("Boton 4");
        F.add(B1);F.add(B2);
        F.add(B3);F.add(B4);
        
        F.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we){
                F.dispose();
                System.exit(0);
            }
        });
        
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//end GUI02()
    
    public static void main(String[] args) {
        new GUI02();
    }
}

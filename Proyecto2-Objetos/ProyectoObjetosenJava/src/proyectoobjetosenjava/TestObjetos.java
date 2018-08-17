/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyectoobjetosenjava;

import java.util.Scanner;

/**
 *
 * @author Sala5
 */
public class TestObjetos {
    Scanner scan;
    int intA;
    static String StringMSG;
    public static void main(String[] args) {
        Scanner Scan=new Scanner(System.in);/*para obtener entrada del teclado*/
        int inta;
        /*System.out.println("Teclee un valor entero: ");
        inta=Scan.nextInt();
        System.out.println("El entero inta="+inta);*/
        System.out.println("Teclea algo!!!!:");
        TestObjetos.StringMSG=Scan.nextLine();
        System.out.println("Usted tecleó:"+TestObjetos.StringMSG);
        
        TestObjetos TO=new TestObjetos();
        TO.scan=new Scanner(System.in);
        System.out.println("Teclee otro valor entero: ");
        TO.intA=TO.scan.nextInt();
        System.out.println("El entero TO.intA="+TO.intA);
        System.out.println("El atributo StringMSG del "
                + "objeto TO:"+TO.StringMSG+"\n"+TO.toString());
    }//end main()
    public String toString(){
        return ""+intA+" Algún objeto de clase TestObjetos";
    }
}//end class TestObjetos














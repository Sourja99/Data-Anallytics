/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package java_gui;

import java.util.Scanner;

/**
 *
 * @author vaibhav
 */public class simple {

    public static char ChangeCase() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an input String: ");
        String inputString = scanner.nextLine();
        //String isVowel = "aeiou";
        char c='\0';
        for (int i = 0; i < inputString.length(); i++) {
             c = inputString.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') {
                c = Character.toLowerCase(c);

                System.out.println(c);
            }
            else if (c=='b'||c=='c'||c=='d'||c=='f'||c=='g'||c=='h'||c=='j'||c=='k'||c=='l'||c=='m'||c=='n'||c=='p'||c=='q'||c=='r'||c=='s'||c=='t'||c=='v'||c=='w'||c=='x'||c=='y'||c=='z'||
               c=='B'||c=='C'||c=='D'||c=='F'||c=='G'||c=='H'||c=='J'||c=='K'||c=='L'||c=='M'||c=='N'||c=='P'||c=='Q'||c=='R'||c=='S'||c=='T'||c=='V'||c=='W'||c=='X'||c=='Y'||c=='Z'){
                c = inputString.charAt(i);
                c =Character.toUpperCase(c);
                System.out.println(c);
            }
           else if(c=='@'||c=='!'||c=='"'||c==' '||c=='!'||c=='"'||c=='#'||c=='$'||c=='%'||c=='&'||c=='('|| c==')'||c=='*'||c=='+'||c==','||c=='-'||c=='.'||c=='/'||c==':'||c==';'||c=='<'||c=='='||c=='>'||c=='?'||c=='['||c==']'||c=='^'||c=='_'||c=='`'||c=='{'||c=='|'||c=='}'||c=='~'||c=='"'){
                c=inputString.charAt(i);
                c=c;
                System.out.println(c);
            }
            else
               c=c;

        }

        return c;

    }
    public static void main(String[]args){
              
    }
    
    
    
    
}

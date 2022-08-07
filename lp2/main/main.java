package main;
import funcionario.funcionario;

public class main {
    public static void main(String[] args){
        funcionario f1,f2;

        f1 = new funcionario("jhonatan", 1545254, 2021, 50000);
        f2 = new funcionario("ana paula", 1542454, 2021, 600000);

        f1.escreve_infos();
        f2.escreve_infos();

        f1.modificaSalario(2.5);
        f2.modificaSalario(2);

        f1.escreve_infos();
        f2.escreve_infos();
        
    }
}

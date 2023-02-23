package principal;

import java.util.Scanner;
import modelo.*;
public class DemoEmpresa{

    public void main(String[] args) throws  Exception { 
        Scanner sc = new Scanner(System.in);
        int i = 0, Ge = 0, Ad = 0, Ve = 0;
        Gerente[] ge;
        Administrador[] admin;
        Vendedor[] ven;
        Funcionario fn;
        ge = new Gerente[200];
        admin = new Administrador[200];
        ven = new Vendedor[200];

        while (i < 200) {
            int op,tF;
            String nome, cpf, telefone, dpto;
            float percentVendas;
            double salario, vVendas, ajudaDeCusto;
            System.out.println(" menu de cadastro ");
            System.out.println("1 - cadastrar novo funcionário");
            System.out.println("2 - exibir liste de funcionários");
            System.out.println("3 - buscar funcionário pelo nome");
            System.out.println("4 - sair"); 
            op = sc.nextInt();

            if(op == 1){
                System.out.println("Qual tipo de funcionário deseja cadastrar");
                System.out.println("1 - Vendedor");
                System.out.println("2 - Administrador");
                System.out.println("3 - Gerente");
                tF = sc.nextInt();

                if (tF == 1) {
                    
                    System.out.println(" cadastro de Vendedor ");
                    //buffer do teclado 
                    sc.nextLine();
                    System.out.println("Nome do funcionário");
                    nome = sc.nextLine();
                    System.out.println("Cpf do funcionário");
                    cpf = sc.nextLine();
                    System.out.println("Telefone do funcionário");
                    telefone = sc.nextLine();
                    System.out.println("qual o percent de vendas");
                    percentVendas = sc.nextFloat();
                    System.out.println("Total das vendas");
                    vVendas = sc.nextDouble();
                    System.out.println("salario do funcionário");
                    salario = sc.nextDouble();
                    ven[Ve] = new Vendedor(percentVendas,vVendas, cpf, nome, telefone, salario);
                }
                else if (tF == 2) {
                    System.out.println(" cadastro de Administrador ");
                    //buffer do teclado 
                    sc.nextLine();
                    System.out.println("Nome do funcionário");
                    nome = sc.nextLine();
                    System.out.println("Cpf do funcionário");
                    cpf = sc.nextLine();
                    System.out.println("Telefone do funcionário");
                    telefone = sc.nextLine();
                    System.out.println("ajuda de custo");
                    ajudaDeCusto = sc.nextDouble();
                    System.out.println("salario do funcionário");
                    salario = sc.nextDouble();
                    admin[Ad] =  new Administrador(ajudaDeCusto, cpf, nome, telefone, salario);
                    Ad+=1;
                }
                else if (tF == 3) {
                    System.out.println(" cadastro de Gerente ");
                    //buffer do teclado 
                    sc.nextLine();
                    System.out.println("Nome do funcionário");
                    nome = sc.nextLine();
                    System.out.println("Cpf do funcionário");
                    cpf = sc.nextLine();
                    System.out.println("Telefone do funcionário");
                    telefone = sc.nextLine();
                    System.out.println("Salario do funcionário");
                    salario = sc.nextDouble();
                    System.out.println("Qual o departamento");
                    ge[Ge] = new Gerente(dpto,cpf,nome,telefone,salario);
                    Ge+=1;
                }
            }
            else if (op == 2) {
                for (int j = 0; j < ven.length; j++) {
                    System.out.println("Vendedores\n");
                    System.out.println(ven[j]);
                }
                for (int j = 0; j < admin.length; j++) {
                    System.out.println("Administradores\n");
                    System.out.println(admin[j]);
                }
                for (int j = 0; j < ge.length; j++) {
                    System.out.println("Gerentes\n");
                    System.out.println(ge[j]);
                }
            }
            else if (op == 3) {
                String nomeBusca;
                System.out.println("qual o nome do funcionário");
                nomeBusca = sc.nextLine();
                fn.buscaFuncinario(nomeBusca);
            }
            else{
                exit();
            }
            i+=1;
        }
    }

    private int exit() {
        return 0;
    }
}

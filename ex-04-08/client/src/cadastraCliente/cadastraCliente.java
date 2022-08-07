package cadastraCliente;

import java.util.Scanner;

import cliente.cliente;

public class cadastraCliente {
    Scanner sc = new Scanner(System.in);
    // cliente[] cl;
    public cadastraCliente() {
    }
    private int exit(){
        return -1;
    }
    int p = 0;
    public void cadastraClientes(int qtde, cliente[] cl) {

        int op;
        System.out.println("======== Menu de Cadastro ========");
        System.out.println("\n 1- Cadastrar cliente");
        System.out.println("\n 2- Buscar cliente pelo nome");
        System.out.println("\n 3- Exibir dados dos clientes ");
        System.out.println("\n 4- sair ");
        op = sc.nextInt();

        if (op == 1) {
            if (p < qtde) {
                cl[p] = new cliente();
                System.out.println("primeiro nome do cliente");
                cl[p].setFirstName(sc.next());
                sc.nextLine();
                System.out.println("Ultimo nome do cliente");
                cl[p].setLastName(sc.next());
                sc.nextLine();
                System.out.println("Cpf do cliente");
                cl[p].setCpf(sc.nextLine());
                System.out.println("código do cliente");
                cl[p].setCode(sc.nextInt());
                sc.nextLine();
                System.out.println("telefone do cliente");
                cl[p].setTelephone(sc.nextInt());
                cl[p].dadosCliente();
                p += 1;
                cadastraClientes(qtde, cl);
            } else {
                System.out.println("Limite de cadastros atingido ");
            }
        } else if (op == 2) {
            String nameSearch;
            Boolean found;
            found = false;
            int i;
            int opc;
            System.out.println("nome do cliente que deseja buscar");
            nameSearch = sc.next();
            for (i = 0; i < cl.length; i++) {
                found = cl[i].findClient(nameSearch);
                if (found == true){
                    break;
                }
            }
            if (found == true) {
                System.out.println("cliente " + nameSearch + " encontrado!");
                System.out.println("\n======= Menu de informações =======");
                System.out.println("\n 1- Ver dados do cliente");
                System.out.println("\n 2- alterar dados do cliente");
                System.out.println("\n 3- voltar ao menu");
                opc = sc.nextInt();
                if(opc == 1){
                    cl[i].dadosCliente();
                    cadastraClientes(qtde, cl);
                }
                else if(opc == 2){
                    cl[i].alterarDadosCliente();
                    cadastraClientes(qtde, cl);
                }
                else{
                    cadastraClientes(qtde, cl);
                }
            }
            else{
                System.out.println("cliente " + nameSearch + " não encontrado!");
                cadastraClientes(qtde, cl);
            }
        }
        else if(op == 3){
            for (int i = 0; i < cl.length; i++) {
                cl[i].dadosCliente();
            }
            cadastraClientes(qtde, cl);
        }
        else if(op == 4){
            exit();
        }

    }
}

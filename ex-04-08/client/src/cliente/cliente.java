package cliente;

import java.util.Scanner;

public class cliente {
    Scanner sc = new Scanner(System.in);
    String firstName;
    String lastName;
    String cpf;
    int code;
    int telephone;

    public cliente(){
    }
    public void dadosCliente(){
		System.out.println("Nome: " + this.firstName + " " + this.lastName);
		System.out.println("Código do cliente: " + this.code);
		System.out.println("CPF: " + this.cpf);
		System.out.println("Telefone:  " + this.telephone + "\n");
	}
    public boolean findClient(String nameClient){
        if (this.firstName.equals(nameClient)){
            return true;
        }
        else{
            return false;
        }
    }

    public void alterarDadosCliente(){
        System.out.println("Alterando os dados do cliente " + this.firstName + " " + this.lastName);
        System.out.println("Alterando o primeiro nome do cliente ");
        this.firstName = sc.next();
        System.out.println("Alterando o ultimo nome do cliente ");
        this.lastName = sc.next();
        System.out.println("Alterando o CPF do cliente ");
        this.cpf = sc.next();
        System.out.println("Alterando o telefone do cliente ");
        this.telephone = sc.nextInt();
        dadosCliente();
    }
    
    //firstName set and get
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }
    public String getFirstName() {
        return firstName;
    }

    //cpf set and get
    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    //client codee set and get
    public int getCode() {
        return code;
    }
    public void setCode(int code) {
        this.code = code;
    }

    //telephone get and set method
    public int getTelephone() {
        return telephone;
    }
    public void setTelephone(int telephone) {
        this.telephone = telephone;
    }
    public String getLastName() {
        return lastName;
    }
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }
    
}

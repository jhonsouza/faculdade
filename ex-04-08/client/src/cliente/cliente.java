package cliente;

import java.util.Scanner;

public class cliente {
    Scanner sc = new Scanner(System.in);
    String name;
    String cpf;
    int code;
    int telephone;

    public cliente(){
    }
    public void dadosCliente(){
		System.out.println("Nome: " + this.name);
		System.out.println("Código do cliente: " + this.code);
		System.out.println("CPF: " + this.cpf);
		System.out.println("Telefone:  " + this.telephone + "\n");
	}
    public boolean findClient(String nameClient){
        if (this.name.equals(nameClient)){
            return true;
        }
        else{
            return false;
        }
    }
    
    //name set and get
    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
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
    
}

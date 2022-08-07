import java.util.Scanner;

import cadastraCliente.cadastraCliente;
import cliente.cliente;

public class App {
    public static void main(String[] args) throws Exception {
      cadastraCliente cc;
      cliente[] cl;
      int qtde;
      Scanner sc = new Scanner(System.in);
      qtde = sc.nextInt();
      cl = new cliente[qtde];
      cc = new cadastraCliente();
      cc.cadastraClientes(qtde, cl);
      sc.close();
    }
}

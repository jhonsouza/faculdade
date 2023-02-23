package principal;
import modelo.Caminhao;
import modelo.CarroPasseio;
import java.util.Scanner;


public class DemoVeiculos {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int Cm = 0, Cp = 0;
      int qtdeVeiculos = 0, i =0; //contexto geral carros e caminhões

      Caminhao[] cam;
      CarroPasseio[] carP;

      System.out.println("informe a quantidade de carros a ser cadastrados: ");
      qtdeVeiculos = sc.nextInt();
      cam = new Caminhao[qtdeVeiculos];
      carP = new CarroPasseio[qtdeVeiculos];
      
      while (i < qtdeVeiculos){
         int op;
         int numCilindro, potencia, velocMax, toneladasMax;
         float peso, alturaMax, comprimento;
         double preco;  
         String cor, modelo;
         System.out.println("========================\n");
         System.out.println("Qual carro deseja cadastrar? \n");
         System.out.println("1- Carro de passeio\n");
         System.out.println("2- Caminhão\n");
         System.out.println("3- Parar cadastro\n");
         op = sc.nextInt();
         
         if (op == 1){
            System.out.println("===== Cadastrando Carro de Passeio =====\n");
            System.out.println("Qual o peso do veículo\n");
            //buffer do teclado 
            sc.nextLine();
            peso = sc.nextFloat();
            System.out.println("Qual a velocidade máxima do veículo\n");
            velocMax = sc.nextInt();
            System.out.println("Qual a potência do veículo\n");
            potencia = sc.nextInt();
            System.out.println("Qual o preço do veículo\n");
            preco = sc.nextDouble();
            System.out.println("Qual a potência do Veículo\n");
            carP[Cp].setPotencia(sc.nextInt());
            System.out.println("Quantidade de Cilindros\n");
            numCilindro = sc.nextInt();
            System.out.println("Qual a Cor do veículo\n");
            cor = sc.nextLine();
            System.out.println("Qual o modelo do veículo\n");
            modelo = sc.nextLine();
            carP[Cp] = new CarroPasseio(modelo,cor,preco,potencia,velocMax,peso,numCilindro);
            Cp+=1;
         }
         else if (op == 2){
            System.out.println("===== Cadastrando Carro de Passeio =====\n");
            System.out.println("Qual o peso do veículo\n");
            //buffer do teclado 
            sc.nextLine();
            peso = sc.nextFloat();
            System.out.println("Qual a velocidade máxima do veículo\n");
            velocMax = sc.nextInt();
            System.out.println("Qual a potência do veículo\n");
            potencia = sc.nextInt();
            System.out.println("Qual o preço do veículo\n");
            preco = sc.nextDouble();
            System.out.println("Qual a potência do Veículo\n");
            carP[Cp].setPotencia(sc.nextInt());
            System.out.println("Quantidade de Cilindros\n");
            numCilindro = sc.nextInt();
            System.out.println("Capacide máxima de cargar\n");
            toneladasMax = sc.nextInt();
            System.out.println("Comprimento do veículo\n");
            comprimento = sc.nextFloat();
            System.out.println("Altura máxima do veículo\n");
            alturaMax = sc.nextFloat();
            cam[Cm] = new Caminhao(toneladasMax,alturaMax,comprimento,preco,potencia,velocMax,peso,numCilindro);
            Cm+=1;
         }
         else{
            for (int j = 0; j < carP.length; j++) {
               System.out.println(carP[j]);
            }
            for (int k = 0; k < cam.length; k++) {
               System.out.println(cam[k]);               
            }
         }

         
      }
      sc.close();
   }  
}

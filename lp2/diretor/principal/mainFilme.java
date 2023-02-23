package diretor.principal;
import java.util.Scanner;
import diretor.modelo.*;;

public class mainFilme {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int qtde;
        System.out.println("Quantos filmes deseja cadastrar?");
        qtde=sc.nextInt();
        Filme[] filmes = new Filme[qtde];
        for(int i=0; i<qtde; i++) {
            sc.nextLine();
            filmes[i] = new Filme();
            System.out.println("Informe o título do filme: ");
            filmes[i].setTitulo(sc.nextLine());
            sc.nextLine();
            System.out.println("Informe a descrição do filme: ");
            filmes[i].setDescricao(sc.nextLine());
            sc.nextLine();
            System.out.println("Informe a duração do filme em minutos: ");
            filmes[i].setDuracao(sc.nextInt());
            sc.nextLine();
            Diretor d = new Diretor();
            System.out.println("Dados do diretor: ");
            System.out.println("Nome: ");
            d.setNome(sc.nextLine());
            sc.nextLine();
            System.out.println("Origem: ");
            d.setOrigem(sc.nextLine());
            sc.nextLine();
            System.out.println("Tempo de experiência em anos: ");
            d.setExperiencia(sc.nextInt());
            filmes[i].setDir(d);
        }
        for(int i=0; i<qtde; i++) {
            System.out.println("Título: "+filmes[i].getTitulo()+"\nDuração em horas: "+filmes[i].exibirDuracaoEmHoras()+"\n");
        }
        sc.nextLine();
        System.out.println("Informe o título que deseja buscar: ");
        String titulo =sc.nextLine();
        boolean enc = false;
        for(int i=0;i<qtde;i++) {

            if(filmes[i].busca(titulo)) {
                System.out.println("Dados do filme: ");
                System.out.println(filmes[i]);
                enc=true;
                break;
            }
            
        }
        if(enc==false)
            System.out.println("Filme não encontrado!");
        
        sc.close();
    }

}
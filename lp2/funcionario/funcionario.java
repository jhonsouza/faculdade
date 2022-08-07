package funcionario;

public class funcionario {
    private String nome;
	private double salario;
	private int cpf;
	private int anoadmissao;

    public String getnome() {
        return nome;
    }
    public void setnome(String nome) {
        this.nome = nome;
    }

    public double getsalario() {
        return salario;
    }
    public void setsalario(double salario) {
        this.salario = salario;
    }

    public int getcpf() {
        return cpf;
    }
    public void setcpf(int cpf) {
        this.cpf = cpf;
    }

    public int getanoadmissao() {
        return anoadmissao;
    }
    public void setanoadmissao(int anoadmissao) {
        this.anoadmissao = anoadmissao;
    }

    public funcionario(String nome, int cpf, int anoadmissao, double salario){
        this.salario = salario;
        this.nome = nome;
        this.cpf = cpf;
        this.anoadmissao = anoadmissao;
    }
    public funcionario(){

    }

    public void modificaSalario(double valor){
        System.out.println("Modificando salário do funcionário: " + nome);
        System.out.println("Salário inicial: R$" + salario);
		salario *= valor;
		System.out.println("Salário final: R$" + salario + "\n");
    }

    public void escreve_infos() {
		System.out.println("Nome: " + this.nome);
		System.out.println("Salário atual: R$" + this.salario);
		System.out.println("CPF: " + this.cpf);
		System.out.println("Ano de admissão: " + this.anoadmissao + "\n");
	}
}

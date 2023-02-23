package diretor.modelo;

public class Diretor {
    private String nome;
    private String origem;
    private int experiencia;
    public Diretor(String nome, String origem, int experiencia) {

        this.nome = nome;
        this.origem = origem;
        this.experiencia = experiencia;

    }
    public Diretor() {
    }
    public void setOrigem(String origem) {
        this.origem = origem;
    }
    public String getOrigem() {
        return origem;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return nome;
    }
    public void setExperiencia(int experiencia) {
        this.experiencia = experiencia;
    }
    public int getExperiencia() {
        return experiencia;
    }
    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return ("\nNome: " +this.nome+"\nAnos de experiência: "+this.experiencia+"\nOrigem: "+this.origem);
    }
   
}

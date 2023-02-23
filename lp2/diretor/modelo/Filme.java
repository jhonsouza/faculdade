package diretor.modelo;
public class Filme {

    private String titulo;
    private String descricao;
    private Diretor dir;
    private int duracao;
    public Filme(String titulo, String descricao, Diretor dir, int duracao) {

        this.titulo = titulo;
        this.descricao = descricao;
        this.dir = dir;
        this.duracao = duracao;

    }
    public Filme() {
    }
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
    public String getDescricao() {
        return descricao;
    }
    public void setDir(Diretor dir) {
        this.dir = dir;
    }
    public Diretor getDir() {
        return dir;
    }
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }
    public int getDuracao() {
        return duracao;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public String getTitulo() {
        return titulo;
    }
    public boolean busca(String titulo) {
        if (this.titulo.equalsIgnoreCase(titulo)) {
        
            return true;
        
        }
           return false;
        
    }
    public String exibirDuracaoEmHoras() {
        int horas, min;
        horas = this.duracao/60;
        min = this.duracao % 60;
        return "O filme "+this.titulo+" possui "+ horas +" horas e "+min +" minutos de duração.";
    }
    public String toString() {

       return ("\nTítulo: "+this.titulo+"\nDescrição: "+this.descricao+"\nDuração:"+this.duracao+"\nDiretor:\n"+this.dir);
    
    }
}
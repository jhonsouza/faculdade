package modelo;

public class Caminhao extends Veiculo {
    private int toneladasMax;
    private float alturaMax;
    private float comprimento;

    public Caminhao(){}

    public Caminhao(int toneladasMax, float alturaMax, float comprimento, double preco, int potencia, int velocMax, float peso, int numCilindro){
        super(peso, velocMax, preco, potencia, numCilindro);
        this.toneladasMax = toneladasMax;
        this.alturaMax = alturaMax;
        this.comprimento = comprimento;
    }

    public int getToneladasMax() {
        return toneladasMax;
    }
    public void setToneladasMax(int toneladasMax) {
        this.toneladasMax = toneladasMax;
    }

    public float getAlturaMax() {
        return alturaMax;
    }
    public void setAlturaMax(float alturaMax) {
        this.alturaMax = alturaMax;
    }

    public float getComprimento() {
        return comprimento;
    }
    public void setComprimento(float comprimento) {
        this.comprimento = comprimento;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return (super.toString()+"\nAltura Máxima do Caminhão: "+alturaMax+"\nComprimento do Caminhão: "+comprimento+"Carga Máxima do Caminhão: "+toneladasMax);
    }
}

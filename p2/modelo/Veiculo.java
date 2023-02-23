package modelo;

public class Veiculo extends Motor {
    private float peso;
    private int velocMax;
    private double preco;

    public Veiculo(){}

    public Veiculo(float peso, int velocMax, double preco, int potencia, int numCilindro){
        super(numCilindro,potencia);
        this.peso = peso;
        this.velocMax = velocMax;
        this.preco = preco;
    }

    public int getVelocMax() {
        return velocMax;
    }
    public void setVelocMax(int velocMax) {
        this.velocMax = velocMax;
    }

    public float getPeso() {
        return peso;
    }
    public void setPeso(float peso) {
        this.peso = peso;
    }

    public double getPreco() {
        return preco;
    }
    public void setPreco(double preco) {
        this.preco = preco;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return (super.toString()+"\nPeso do Veículo: "+peso+"\nVelocidade Maxima: "+velocMax+"km\\h"+"\n Preço do Veículo: "+preco);
    }
}

package modelo;

public class CarroPasseio extends Veiculo {
    private String modelo;
    private String cor;

    public CarroPasseio(){

    }
    public CarroPasseio(String modelo, String cor, double preco, int potencia, int velocMax, float peso, int numCilindro){
        super(peso, velocMax, preco, potencia, numCilindro);
        this.modelo = modelo;
        this.cor = cor;
    }
    
    public String getCor() {
        return cor;
    }
    public void setCor(String cor) {
        this.cor = cor;
    }

    public String getModelo() {
        return modelo;
    }
    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return (super.toString()+"\nCor do Veículo: "+cor+"\nModelo do veículo: "+modelo);
    }

}

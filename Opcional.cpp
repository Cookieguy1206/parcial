#include <iostream>
#include <cmath>

using namespace std;
class MedidorEnergia {
private:
    int numeroMedidor;
    int estratoSocioeconomico;
    double lecturaMesAnterior;
    double lecturaMesActual;
    double valorKWH;

public:
    MedidorEnergia(int numMedidor, int estrato, double lecturaAnterior, double lecturaActual, double valorKwH)
        : numeroMedidor(numMedidor), estratoSocioeconomico(estrato),
          lecturaMesAnterior(lecturaAnterior), lecturaMesActual(lecturaActual), valorKWH(valorKwH) {}

    // Getters
    int getNumeroMedidor() { 
        return numeroMedidor; 
    }
    int getEstratoSocioeconomico() { 
        return estratoSocioeconomico; 
    }
    double getLecturaMesAnterior() { 
        return lecturaMesAnterior; 
    }
    double getLecturaMesActual() { 
        return lecturaMesActual; 
    }
    double getValorKWH() { 
        return valorKWH; 
    }

    // Setters
    void setNumeroMedidor(int numMedidor) { 
        numeroMedidor = numMedidor; 
    }
    void setEstratoSocioeconomico(int estrato) { 
        estratoSocioeconomico = estrato; 
    }
    void setLecturaMesAnterior(double lecturaAnterior) { 
        lecturaMesAnterior = lecturaAnterior; 
    }
    void setLecturaMesActual(double lecturaActual) { 
        lecturaMesActual = lecturaActual; 
    }
    void setValorKWH(double valorKwH) { 
        valorKWH = valorKwH; 
    }

    double calcularConsumoKWH() {
        return max(0.0, getLecturaMesActual() - getLecturaMesAnterior());
    }

    double calcularValorAPagar(double var_valorKWH) {
        double consumoKWH = calcularConsumoKWH();
        double descuento = obtenerDescuento();
        return consumoKWH * var_valorKWH * (1.0 - descuento);
    }
    double obtenerDescuento() {
        switch (getEstratoSocioeconomico()) {
            case 1: return 0.5;
            case 2: return 0.3;
            case 3: return 0.2;
            case 4: return 0.1;
            case 5: return 0.01;
            default: return 0.0;
        }
    }
};

class ProgramaMedidor : public MedidorEnergia {
public:
    //ructor para la clase ProgramaMedidor
    ProgramaMedidor(int numMedidor, int estrato, double lecturaAnterior, double lecturaActual, double valorKwH)
        : MedidorEnergia(numMedidor, estrato, lecturaAnterior, lecturaActual, valorKwH) {}

    void leerDatos(int numeroMedidor, int estratoSocioeconomico, double lecturaMesAnterior, double lecturaMesActual, double valorKwH) {
        cout << "Ingrese el numero del medidor: ";
        cin >> numeroMedidor;
        setNumeroMedidor(numeroMedidor);

        cout << "Ingrese el estrato socioeconomico: ";
        cin >> estratoSocioeconomico;
        setEstratoSocioeconomico(estratoSocioeconomico);

        cout << "Ingrese la lectura anterior: ";
        cin >> lecturaMesAnterior;
        setLecturaMesAnterior(lecturaMesAnterior);

        cout << "Ingrese la lectura actual: ";
        cin >> lecturaMesActual;
        setLecturaMesActual(lecturaMesActual);

        cout << "Ingrese el valor por kWh: ";
        cin >> valorKwH;
        setValorKWH(valorKwH);
    }

    // Método para ejecutar la lógica principal del programa
    void ejecutar() {

        cout << "\nNumero del medidor: " << getNumeroMedidor() << endl;
        cout << "Lectura del mes anterior: " << getLecturaMesAnterior() << endl;
        cout << "Lectura del mes actual: " << getLecturaMesActual() << endl;
        cout << "Estrato socioeconomico: " << getEstratoSocioeconomico() << endl;
        cout << "Valor del KWH: " << getValorKWH() << endl;
        cout << "Consumo en KWH: " << calcularConsumoKWH() << endl;
        cout << "Descuento otorgado: " << obtenerDescuento() * 100 << "%" << endl;

        double valorAPagar = calcularValorAPagar(getValorKWH());

        cout << "Numero del medidor: " << getNumeroMedidor() << endl;
        cout << "Valor a pagar: " << valorAPagar << endl;
    }
};

int main() {
    // Ejemplo de uso
    ProgramaMedidor programa(0, 0, 0, 0, 0);
    programa.leerDatos(0, 0, 0, 0, 0);
    programa.ejecutar();

    return 0;
}
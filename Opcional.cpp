#include <iostream>
#include <cmath>
using namespace std;

class class_MedidorEnergia {
private:
    int Atr_numeroMedidor;
    int Atr_estratoSocioeconomico;
    double Atr_lecturaMesAnterior;
    double Atr_lecturaMesActual;
    double Atr_valorKWH;

public:
    class_MedidorEnergia(int var_numMedidor, int var_estrato, double var_lecturaAnterior, double var_lecturaActual, double var_valorKwH)
        : Atr_numeroMedidor(var_numMedidor), Atr_estratoSocioeconomico(var_estrato),
          Atr_lecturaMesAnterior(var_lecturaAnterior), Atr_lecturaMesActual(var_lecturaActual), Atr_valorKWH(var_valorKwH) {}

    // Getters
    int met_getAtr_NumeroMedidor() { 
        return Atr_numeroMedidor; 
    }
    int met_getAtr_EstratoSocioeconomico() { 
        return Atr_estratoSocioeconomico; 
    }
    double met_getAtr_LecturaMesAnterior() { 
        return Atr_lecturaMesAnterior; 
    }
    double met_getAtr_LecturaMesActual() { 
        return Atr_lecturaMesActual; 
    }
    double met_getAtr_ValorKWH() { 
        return Atr_valorKWH; 
    }

    // Setters
    void met_setAtr_NumeroMedidor(int var_numMedidor) { 
       Atr_numeroMedidor = var_numMedidor; 
    }
    void met_setAtr_EstratoSocioeconomico(int var_estrato) { 
        Atr_estratoSocioeconomico = var_estrato; 
    }
    void met_setAtr_LecturaMesAnterior(double var_lecturaAnterior) { 
        Atr_lecturaMesAnterior = var_lecturaAnterior; 
    }
    void met_setAtr_LecturaMesActual(double var_lecturaActual) { 
        Atr_lecturaMesActual = var_lecturaActual; 
    }
    void met_setAtr_ValorKWH(double var_valorKwH) { 
        Atr_valorKWH = var_valorKwH; 
    }

    double met_calcularConsumoKWH() {
        return max(0.0, met_getAtr_LecturaMesActual() - met_getAtr_LecturaMesAnterior());
    }

    double met_calcularValorAPagar(double var_valorKWH) {
        double var_consumoKWH = met_calcularConsumoKWH();
        double var_descuento = met_obtenerDescuento();
        return var_consumoKWH * var_valorKWH * (1.0 - var_descuento);
    }
    double met_obtenerDescuento() {
        switch (met_getAtr_EstratoSocioeconomico()) {
            case 1: return 0.5;
            case 2: return 0.3;
            case 3: return 0.2;
            case 4: return 0.1;
            case 5: return 0.01;
            default: return 0.0;
        }
    }
};

class class_Validaciones {
public:
    bool met_validarLecturas(double var_lecturaAnterior, double var_lecturaActual) {
        return var_lecturaActual > var_lecturaAnterior;
    }

    bool met_validarValorKWH(double var_valorKwH) {
        return var_valorKwH > 0;
    }

    bool met_validarEstrato(int var_estrato) {
        return var_estrato >= 1 && var_estrato <= 5;
    }

    bool met_validarDatos(int var_estratoSocioeconomico, double var_lecturaMesAnterior, double var_lecturaMesActual, double var_valorKwH) {
        if (!met_validarEstrato(var_estratoSocioeconomico)) {
            cout << "Error: El estrato socioeconomico debe estar entre 1 y 5.\n";
            return false;
        }

        if (!met_validarLecturas(var_lecturaMesAnterior, var_lecturaMesActual)) {
            cout << "Error: La lectura actual no puede ser menor o igual a la lectura anterior.\n";
            return false;
        }

        if (!met_validarValorKWH(var_valorKwH)) {
            cout << "Error: El valor por kWh no puede ser cero ni negativo.\n";
            return false;
        }

        // Todas las validaciones pasaron
        return true;
    }
};

class class_ProgramaMedidor : public class_MedidorEnergia, class_Validaciones {
public:
    //constructor para la clase ProgramaMedidor
    class_ProgramaMedidor(int var_numMedidor, int var_estrato, double var_lecturaAnterior, double var_lecturaActual, double var_valorKwH)
        : class_MedidorEnergia(var_numMedidor, var_estrato, var_lecturaAnterior, var_lecturaActual, var_valorKwH) {}

    void met_leerDatos(int var_numeroMedidor, int var_estratoSocioeconomico, double var_lecturaMesAnterior, double var_lecturaMesActual, double var_valorKwH) {
        cout << "Ingrese el numero del medidor: ";
        cin >> var_numeroMedidor;
        met_setAtr_NumeroMedidor(var_numeroMedidor);

        cout << "Ingrese el estrato socioeconomico: ";
        cin >> var_estratoSocioeconomico;
        met_setAtr_EstratoSocioeconomico(var_estratoSocioeconomico);

        cout << "Ingrese la lectura anterior: ";
        cin >> var_lecturaMesAnterior;
        met_setAtr_LecturaMesAnterior(var_lecturaMesAnterior);

        cout << "Ingrese la lectura actual: ";
        cin >> var_lecturaMesActual;
        met_setAtr_LecturaMesActual(var_lecturaMesActual);

        cout << "Ingrese el valor por kWh: ";
        cin >> var_valorKwH;
        met_setAtr_ValorKWH(var_valorKwH);
    }

    // Método para ejecutar la lógica principal del programa
    void met_ejecutar() {

        met_leerDatos(0, 0, 0, 0, 0);

        if (met_validarDatos(met_getAtr_EstratoSocioeconomico(), met_getAtr_LecturaMesAnterior(), met_getAtr_LecturaMesActual(), met_getAtr_ValorKWH())) {


            cout << "\nNumero del medidor: " << met_getAtr_NumeroMedidor() << endl;
            cout << "Lectura del mes anterior: " << met_getAtr_LecturaMesAnterior() << endl;
            cout << "Lectura del mes actual: " << met_getAtr_LecturaMesActual() << endl;
            cout << "Estrato socioeconomico: " << met_getAtr_EstratoSocioeconomico() << endl;
            cout << "Valor del KWH: " << met_getAtr_ValorKWH() << endl;
            cout << "Consumo en KWH: " << met_calcularConsumoKWH() << endl;
            cout << "Descuento otorgado: " << met_obtenerDescuento() * 100 << "%" << endl;

            double var_valorAPagar = met_calcularValorAPagar(met_getAtr_ValorKWH());
            long var_valorAPagarL = static_cast<long>(var_valorAPagar);

            cout << "Numero del medidor: " << met_getAtr_NumeroMedidor() << endl;
            cout << "Valor a pagar: " << var_valorAPagarL << endl;
        }
    }
};

int main() {
    // Ejemplo de uso
    class_ProgramaMedidor obj_programa(0, 0, 0, 0, 0);
    obj_programa.met_ejecutar();

    return 0;
}
#include <iomanip> // Necesario para std::fixed y std::setprecision
#include <iostream>
#include <string>
using namespace std;

class class_calculo {
public:
    static double met_calcularaporteEPS(double par_salario) {
        double var_salario=par_salario;
        double var_aporteEPS=var_salario*0.12;
        return var_aporteEPS;
    }
};


class class_MuestraCategoriaPersona {
public:
    static void met_analizarcategoria(double par_salario) {

    	cout << "\n \n \n ";
        if (par_salario < 1000000) {
            cout << "La persona pertenece a la categor�a A." << endl;
        } else if (par_salario >= 1000000 && par_salario < 2000000) {
            cout << "La persona pertenece a la categor�a B." << endl;
        } else {
            cout << "La persona pertenece a la categor�a C." << endl;
        }
        cout << "\n \n";
        cout << "--------------- \n ";
    }
};


class class_Empleado: class_MuestraCategoriaPersona {
private:
    string atr_cedula;
    string atr_nombre;
    double atr_salario;

public:
    // Constructor  ---  Un metodo con el mismo nombre de la clase es el constructor.
    class_Empleado(string ced, string nom, double sal) {
        atr_cedula = ced;
        atr_nombre = nom;
        atr_salario = sal;
    }

    // M�todos GET apara asignar valores a los atributos
    string getatr_cedula() {
        return atr_cedula;
    }
    string getatr_nombre(){
    	return atr_nombre;
    }
    double getatr_salario(){
    	return atr_salario;
    }

    //Metodos SET para recuperar los valores de los atributos
    void setatr_cedula(string ced) {
        atr_cedula = ced;
    }

    void setatr_nombre(string nom) {
        atr_nombre = nom;
    }

    void setatr_salario(double sal) {
        atr_salario = sal;
    }

    // M�todo para leer valores de los atributos por la Consola
    // Al ser del tipo void, no retorna ningun valo
    void met_leerDatos() {

    	system("cls"); // Borramos la pantalla de la consola

    	cout << "Ingrese la c�dula del empleado: ";
        cin >> atr_cedula;

        cout << "Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin, atr_nombre); // Para poder leer una cadena con varias palabras


        cout << "Ingrese el salario del empleado: ";
        cin >> atr_salario;

        // Llamado al metodo analizar categoria, para saber a cual pertenece el empleado
        this->met_analizarcategoria(atr_salario);

       // Calcula el valor a pagar a la EPS
       // Con el metodo met_calcular_aporteEPS
       class_calculo obj_calculo;
       // obj_calculo es el objeto donde se haya la instancia de la clase: class_calculo, para poder usar el metodo
       // Aqui se da una relacion de asociacion entre la clase class_empleado y la clase class_calculo

       double var_eps=0; // Variable que va a recibir el valor calculado para el aporte a la EPS
       var_eps=obj_calculo.met_calcularaporteEPS(atr_salario);
       cout << "Aporte a la EPS del empleado: " <<  var_eps  << endl;
       cout << endl;


        cout << "Datos del empleado:\n";
        this->met_mostrarDatos();
    }



    // M�todo para mostrar los datos por consola
    void met_mostrarDatos() {

    	system("cls"); // Borramos la pantalla de la consola

        cout << "C�dula del empleado: " << this->getatr_cedula() << endl << endl;
        cout << "Nombre del empleado: " <<  this->getatr_nombre() << endl << endl;

        // Se mustra el salario, si es 3000000 mustra 3e+06 (Formato cientifico)
        cout << "Salario del empleado: " << this->getatr_salario() << endl << endl;

        // Se mustra el salario en formato natural, para evitar el formato cientifico
        // Cuando el numero es muy grande  3000000 muestra : 3000000.000000
        cout << "Salario del empleado: " << fixed << this->getatr_salario() << endl << endl;

        // Solo con dos decimales
        cout << "Salario del empleado: " << fixed << setprecision(2) << this->getatr_salario() << endl << endl;
    }
};

int main() {

    // Crear un objeto Empleado, inicializando sus atributos
    class_Empleado obj_empleado("", "", 0.0);
    // Leer datos del empleado desde la consola
    obj_empleado.met_leerDatos();
    return 80;
}
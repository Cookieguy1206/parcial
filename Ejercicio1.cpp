#include <iostream>
using namespace std;

class class_tienda {
private:
    string atr_nit;
    string atr_nombre;
public:
    class_tienda(string var_nit, string var_nombre) {
        this->atr_nit = var_nit;
        this->atr_nombre = var_nombre;
    }

    //Metodos GET y SET apara asignar valores a los atributos
    string getAtr_nit() {
        return atr_nit;
    }
    void setAtr_nit(string var_nit) {
        atr_nit = var_nit;
    }

    string getAtr_nombre() {
        return atr_nombre;
    }
    void setAtr_nombre(string var_nombre) {
        atr_nombre = var_nombre;
    }

    void met_mostrar_datos_tienda() {
        cout << "NIT: " << getAtr_nit() << endl;
        cout << "Nombre: " << getAtr_nombre() << endl;
    }

};

class class_mascota : public class_tienda {
private:
    int atr_edad;
    string atr_nombre;
    string atr_id;
    string atr_raza;
public:
    class_mascota(string var_nombre, int var_edad, string var_id, string var_raza) : class_tienda(var_nit, var_nombre) {
        this->atr_nombre = var_nombre;
        this->atr_edad = var_edad;
        this->atr_id = var_id;
        this->atr_raza = var_raza;
    }

    //Metodos GET y SET apara asignar valores a los atributos
    string getAtr_nombre() {
        return atr_nombre;
    }
    void setAtr_nombre(string var_nombre) {
        atr_nombre = var_nombre;
    }

    int getAtr_edad() {
        return atr_edad;
    }
    void setAtr_edad(int var_edad) {
        atr_edad = var_edad;
    }

    string getAtr_id() {
        return atr_id;
    }
    void setAtr_id(string var_id) {
        atr_id = var_id;
    }

    string getAtr_raza() {
        return atr_raza;
    }
    void setAtr_raza(string var_raza) {
        atr_raza = var_raza;
    }

    void met_leer_datos_mascota() {
        cout << "Edad: " << endl;
        cin >> atr_edad;
        cout << "ID: " << endl;
        cin >>  atr_id;
        cout << "Nombre: " << endl;
        cin >>  atr_nombre;
        cout << "Raza: " << endl;
        cin >> atr_raza;
    }
    void met_mostrar_datos_mascota() {
        cout << "Nombre Mascota" << getAtr_nombre() << endl;
        cout << "Edad Macota" << getAtr_edad() << endl;
        cout << "ID Mascota" << getAtr_id() << endl;
        cout << "Raza Mascota" << getAtr_raza() << endl;
    }
};

int main() {
    class_mascota obj_mascota;
    return 0;
}
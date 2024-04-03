#include <iostream>
using namespace std;

class class_tienda {
private:
    string atr_nit;
    string atr_nombre;

public:
    class_tienda(string var_nit, string var_nombre) {
        atr_nit = var_nit;
        atr_nombre = var_nombre;
    }

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
        cout << "\nDATOS DE LA TIENDA: " << endl;
        cout << "NIT: " << getAtr_nit() << endl;
        cout << "Nombre: " << getAtr_nombre() << endl;
    }
};

class class_mascota : public class_tienda {
private:
    int atr_edad;
    string atr_id;
    string atr_raza;

public:
    class_mascota(string var_nit, string var_nombre, int var_edad, string var_id, string var_raza) : class_tienda(var_nit, var_nombre) {
        atr_edad = var_edad;
        atr_id = var_id;
        atr_raza = var_raza;
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

    void met_leer_datos_mascota(string var_nombre, int var_edad, string var_id, string var_raza) {
        cout << "Nombre de la mascota" << endl;
        cin >> var_nombre;
        setAtr_nombre(var_nombre);

        cout << "Edad de la mascota" << endl;
        cin >> var_edad;
        setAtr_edad(var_edad);

        cout << "ID de la mascota" << endl;
        cin >> var_id;
        setAtr_id(var_id);

        cout << "Raza de la mascota" << endl;
        cin >> var_raza;
        setAtr_raza(var_raza);

        met_mostrar_datos_mascota();
        met_mostrar_datos_tienda();
    }

    void met_mostrar_datos_mascota() {
        cout << "\nDATOS DE LA MASCOTA: " << endl;
        cout << "Nombre Mascota: " << getAtr_nombre() << endl;
        cout << "Edad Macota: " << getAtr_edad() << endl;
        cout << "ID Mascota: " << getAtr_id() << endl;
        cout << "Raza Mascota: " << getAtr_raza() << endl;
    }
};

int main() {
    class_mascota obj_mascota("123456", "Tienda", 0, "", "");
    obj_mascota.met_leer_datos_mascota("", 0, "", "");
    return 0;
}
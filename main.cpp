#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nombre;
    int edad;
    string correo;
    string contrasena;
    string tipoCliente;
};

struct Jugador {
    string nombre;
    string pais;
    int edad;
    string circuito;
    int puntos;
    int ranking;
    string mensajes[100];
};

struct Torneo {
    string nombre;
    string fechadecreacion;
    int cantidadpuntos;
    string locacion;
    string fechainicio;
    string fechafinal;
    string ganadoresactuales[2];
    string circuito;
};

Cliente agregarCliente() {
    string clienteTipo;
    Cliente nuevo;
    cout << "Ingrese el nombre: ";
    cin >> nuevo.nombre;
    cout << "Ingrese la edad: ";
    cin >> nuevo.edad;

    if (nuevo.edad < 18) {
        cout << "Edad no permitida, no puede crear cuenta." << endl;
        return Cliente{"", 0, "", "", };
    }

    cout << "Ingrese el correo: ";
    cin >> nuevo.correo;
    cout << "Ingrese la contraseña: ";
    cin >> nuevo.contrasena;
    cout << "Ingrese el tipo de cliente: Administrador o Común ";
    cin >> clienteTipo;
    if (clienteTipo == "Administrador"|| clienteTipo == "administrador"|| clienteTipo == "ADMINISTRADOR") {
        nuevo.tipoCliente = "administrador";
    }
    else if (clienteTipo=="Común"||clienteTipo=="común"||clienteTipo=="COMÚN"||clienteTipo=="comun") {
        nuevo.tipoCliente = "comun";
    }
    else {
        cout << "Cliente no válido";
    }
    cout << "Cuenta creada exitosamente." << endl;
    return nuevo;
}
Jugador agregarComentario(Jugador jugadores[],int tamano) {
    Jugador jugador;
    string nombre,comentario;
    bool encontrado = false;
    do {
        cout << "Ingrese el nombre del jugador: ";
        cin >> nombre;
        for (int i = 0; i < tamano; i++) {
            if (nombre == jugadores[i].nombre) {
                jugador=jugadores[i];
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No se encontro el jugador." << endl;
        }
    }while(!encontrado);
    cout << "Ingrese el comentario que quiere dejarle al jugador: ";
    cin >> comentario;
    for (int i = 0; i < tamano; i++) {
        jugador.mensajes[i] = comentario;
    }
}

bool login(Cliente clientes[], int n, Cliente cliente) {
    if (n == 0) {
        cout << "No hay clientes registrados." << endl;
        return false;
    }

    string correoIngresado, contrasenaIngresada;
    cout << "Ingrese su correo: ";
    cin >> correoIngresado;
    cout << "Ingrese su contraseña: ";
    cin >> contrasenaIngresada;

    for (int i = 0; i < n; i++) {
        if (clientes[i].correo == correoIngresado && clientes[i].contrasena == contrasenaIngresada) {
            cout << "Bienvenido, " << clientes[i].nombre << "!" << endl;
            cliente=clientes[i];
            return true;
        }
    }

    cout << "Correo o contraseña incorrectos." << endl;
    return false;
}
Jugador agregarJugador(Jugador jugadores[],int numerojugadores) {
    string circuitoIngresado;
    Jugador jugador = {"","",0,"",0,0};
    cout << "Ingrese el nombre: ";
    cin >> jugador.nombre;
    bool encotrado=false;
    bool circuitoValido=false;
    for (int i = 0; i < numerojugadores; i++) {
        if (jugador.nombre == jugadores[i].nombre) {
            encotrado=true;
        }
    }
    if (!encotrado) {
        do {
            cout << "Ingrese la edad: ";
            cin >> jugador.edad;
            cout << "Ingrese el pais: ";
            cin >> jugador.pais;
            cout << "Ingrese el circuito del jugador (ATP=Jugador hombre, WTA=Jugador mujer)" <<endl;
            cin >> circuitoIngresado;
            if (circuitoIngresado == "ATP"||circuitoIngresado == "atp"||circuitoIngresado == "Atp"||circuitoIngresado == "aTp"||circuitoIngresado == "atP") {
                jugador.circuito = "ATP";
                circuitoValido = true;
            }
            else if (circuitoIngresado=="WTA"|| circuitoIngresado=="wta"||circuitoIngresado=="Wta"||circuitoIngresado=="wTa"||circuitoIngresado=="wtA") {
                jugador.circuito = "WTA";
                circuitoValido = true;
            }
            else {
                cout << "Circuito no valido";
                circuitoValido = false;
            }
        }while(!circuitoValido);
        cout << "Ingrese la cantidad de puntos del jugador" << endl;
        cin >> jugador.puntos;
        cout << "Ingrese el ranking actual del jugador" << endl;
        cin >> jugador.ranking;
        return jugador;
    }
    else {
        cout<<"Jugador ya existente"<<endl;
        return jugador;
    }
}

int main() {
    Cliente clientes[100];
    Jugador jugadores[100];
    Torneo torneos[100];

    int opcion = 0;
    int numeroclientes = 0;
    int numerojugadores = 0;

    cout << "Ingrese una opción:" << endl;
    cout << "1. Iniciar sesión" << endl;
    cout << "2. Crear cuenta" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1: {
            Cliente cliente{"",0,"","",""};
            login(clientes, numeroclientes,cliente);
            if (login) {
                cout << "Ingrese la opción que quiera realizar";
                cout << "1.Descargar estadísticas "<< endl;
                cout << "2. Mostrar matríz de jugadores "<< endl;
                cout << "3. Mostrar lista de torneos "<< endl;
                cout << "4. Descargar estadísticas de un jugador. "<< endl;
                cout << "5. Dejar un comentario al jugador" << endl;
                if (cliente.tipoCliente == "administrador") {
                    cout << "Funciones de administrador: " << endl;
                    cout << "6.Agregar jugador " << endl;
                    cout << "7.Agregar torneo "<< endl;
                    cout << "8.Modificar estadísticas "<< endl;
                }
            }
            break;
        }
        case 2: {
            Cliente nuevocliente = agregarCliente();
            if (nuevocliente.edad == 0) {
                cout << "Cliente no válido, no se agregó." << endl;
            } else {
                clientes[numeroclientes] = nuevocliente;
                numeroclientes++;
            }
            break;
        }
        default: {
            cout << "Opción inválida." << endl;
            break;
        }
    }
    return 0;
}


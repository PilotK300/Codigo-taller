#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nombre;
    string apellido;
    int edad;
    string correo;
    string contrasena;
    string tipoCliente;
};

struct Jugador {
    string nombre;
    string apellido;
    string pais;
    int edad;
    string circuito;
    int puntos;
    int ranking;
    string mensajes[100];
    int cantidadcomentarios=0;
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
    cout << "Ingrese el apellido: ";
    cin >> nuevo.apellido;
    cout << "Ingrese la edad: ";
    cin >> nuevo.edad;

    if (nuevo.edad < 18) {
        cout << "Edad no permitida, no puede crear cuenta." << endl;
        return Cliente{"", "", 0, ""};
    }
    cout << "Ingrese el correo: ";
    cin >> nuevo.correo;
    cout << "Ingrese la contraseña: ";
    cin >> nuevo.contrasena;
    cout << "Ingrese el tipo de cliente: Administrador o Común ";
    cin >> clienteTipo;
    if (clienteTipo == "Administrador"|| clienteTipo == "administrador"|| clienteTipo == "ADMINISTRADOR"|| clienteTipo == "admin") {
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
    string nombre,comentario;
    int jugadorposicion=-1;
    bool encontrado = false;
    do {
        cout << "Ingrese el nombre del jugador: ";
        cin >> nombre;
        for (int i = 0; i < tamano; i++) {
            if (nombre == jugadores[i].nombre) {
                jugadorposicion = i;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "No se encontro el jugador." << endl;
        }
    }while(!encontrado);
    cout << "Ingrese el comentario que quiere dejarle al jugador: ";
    cin >> comentario;
    jugadores[jugadorposicion].mensajes[jugadores[jugadorposicion].cantidadcomentarios] = comentario;
    jugadores[jugadorposicion].cantidadcomentarios++;
    return jugadores[jugadorposicion];
}
Jugador modificarEstadisticas(Jugador jugadores[],int tamano) {
    string nombre,comentario;
    int jugadorposicion=-1;
    bool encontrado = false;
    do {
        cout << "Ingrese el nombre del jugador: ";
        cin >> nombre;
        for (int i = 0; i < tamano; i++) {
            if (nombre == jugadores[i].nombre) {
                jugadorposicion = i;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "No se encontro el jugador." << endl;
        }
    }while(!encontrado);
    cout << "Ingrese la nueva cantidad de puntos";
    cin >> jugadores[jugadorposicion].puntos;
    cout << "Ingrese el nuevo ranking del jugador: ";
    cin >> jugadores[jugadorposicion].ranking;
    return jugadores[jugadorposicion];
}
void descargarEstadisticasJugador(Jugador jugador) {
    ofstream bw("estadisticas_jugador.dat", ios::app); // Buffered writer BW
    if (!bw) {
        cout << "Error al crear el archivo." << endl;
        return;
    }
    bw << "Nombre: " << jugador.nombre << " " << jugador.apellido << endl;
    bw << "Pais: " << jugador.pais << endl;
    bw << "Edad: " << jugador.edad << endl;
    bw << "Circuito: " << jugador.circuito << endl;
    bw << "Puntos: " << jugador.puntos << endl;
    bw<< "Ranking: " << jugador.ranking << endl;
    bw << "Comentarios: " << endl;
    for (int i = 0; i < jugador.cantidadcomentarios; i++) {
        bw << "- " << jugador.mensajes[i] << endl;
    }
    cout << "Archivo del jugador cargado "<< endl;
}
void mostrarTorneos(Torneo torneos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "----------------------------" << endl;
        cout << "Torneo #" << i + 1 << endl;
        cout << "Nombre: " << torneos[i].nombre << endl;
        cout << "Fecha de creación: " << torneos[i].fechadecreacion << endl;
        cout << "Cantidad de puntos: " << torneos[i].cantidadpuntos << endl;
        cout << "Locación: " << torneos[i].locacion << endl;
        cout << "Fecha de inicio: " << torneos[i].fechainicio << endl;
        cout << "Fecha final: " << torneos[i].fechafinal << endl;
        cout << "Ganadores actuales: " << torneos[i].ganadoresactuales[0]
             << " y " << torneos[i].ganadoresactuales[1] << endl;
        cout << "Circuito: " << torneos[i].circuito << endl;
        cout << "----------------------------" << endl;
    }
}
int login(Cliente clientes[], int n) {
    int indice;
    if (n == 0) {
        cout << "No hay clientes registrados." << endl;
        return -1;
    }

    string correoIngresado, contrasenaIngresada;
    cout << "Ingrese su correo: ";
    cin >> correoIngresado;
    cout << "Ingrese su contraseña: ";
    cin >> contrasenaIngresada;

    for (int i = 0; i < n; i++) {
        if (clientes[i].correo == correoIngresado && clientes[i].contrasena == contrasenaIngresada) {
            cout << "Bienvenido, " << clientes[i].nombre << "!" << endl;
            indice = i;
            return indice;
        }
    }

    cout << "Correo o contraseña incorrectos." << endl;
    return -1;
}
Jugador agregarJugador(Jugador jugadores[],int numerojugadores) {
    string circuitoIngresado;
    Jugador jugador = {"","","",0,"",0,0};
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
            cout<<"Ingrese el apellido del jugador: ";
            cin >> jugador.apellido;
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
    int numerotorneos = 0;
do {
    cout << "Ingrese una opción:" << endl;
    cout << "1. Iniciar sesión" << endl;
    cout << "2. Crear cuenta" << endl;
    cout << "0. Salir" << endl;
    cin >> opcion;
    switch (opcion) {
        case 1: {
            int indice=-1;
            indice=login(clientes, numeroclientes);
            if (indice != -1) {
                bool esAdmin = (clientes[indice].tipoCliente=="administrador");
                int opcion2 = 0;
                do {
                    cout << "Ingrese el número de la opción que quiera realizar";
                    cout << "1. Descargar estadísticas "<< endl;
                    cout << "2. Mostrar matríz de jugadores "<< endl;
                    cout << "3. Mostrar lista de torneos "<< endl;
                    cout << "4. Dejar un comentario al jugador" << endl;
                    if (esAdmin) {
                        cout << "Funciones de administrador: " << endl;
                        cout << "5.Agregar jugador " << endl;
                        cout << "6.Agregar torneo "<< endl;
                        cout << "7.Modificar estadísticas "<< endl;
                        esAdmin = true;
                    }
                    cout <<" 0. Salir "<<endl;
                    cin >> opcion2;
                    switch (opcion2) {
                        case 1:
                            int indice=-1;
                            string nombre;
                            cout<<"Ingresa el jugador que quieres buscar"<<endl;
                            cin>>nombre;
                            for (int i = 0; i < numerojugadores; i++) {
                                if (nombre == jugadores[i].nombre) {
                                    indice = i;
                                }
                            }
                            descargarEstadisticasJugador(jugadores[indice]);
                            break;
                        case 2: break;
                        case 3:
                            mostrarTorneos(torneos,numerotorneos);
                            break;
                        case 4:
                            agregarComentario(jugadores, numerojugadores);
                            break;
                        case 5:
                            if (esAdmin) {
                                jugadores[numerojugadores] = agregarJugador(jugadores, numerojugadores);
                                numerojugadores++;
                            }
                            else {
                                cout<<"No tienes permisos para esta opción."<<endl;
                            }
                        break;
                        case 6: {
                            if (esAdmin) {

                            }
                            else {
                                cout<<"No tienes permisos para esta opción."<<endl;
                            }
                        }break;
                        case 7: {
                            if (esAdmin) {
                                modificarEstadisticas(jugadores,numerojugadores);
                            }
                            else {
                                cout<<"No tienes permisos para esta opción."<<endl;
                            }
                        }break;
                        case 0: {
                            cout << "Salir "<<endl;
                        }
                        default:
                            cout<<"Opcion no valido"<<endl;
                    }
                }while (opcion2!=0);
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
        case 0: {
            cout<<"Saliendo...... "<<endl;
            break;
        }
        default: {
            cout << "Opción inválida." << endl;
            break;
        }
    }
}while (opcion!=0);
    return 0;
}


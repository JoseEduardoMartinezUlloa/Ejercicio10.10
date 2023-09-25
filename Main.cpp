#include <iostream>
#include "ListaLigada.cpp"  

void cargarDatos(LSLSE<Alumno>& listaAlumnos) {
    std::ifstream ArchivoAlumnoEntrada("Alumnos.txt", std::ios::in);
    std::string nom,sex;
    int edad; 
    
    if (!ArchivoAlumnoEntrada) {
        std::cerr << "Error al abrir el archivo Alumnos.txt" << std::endl;
        return;
    }

    Alumno alumno;
    while (ArchivoAlumnoEntrada >> nom>>edad>>sex) {
        alumno.setNombre(nom);
        alumno.setEdad(edad);
        alumno.setSexo(sex);
        
        listaAlumnos.insertar(alumno);


    }

    ArchivoAlumnoEntrada.close();
}

void GuardarInformacion(LSLSE<Alumno>&listaAlumnos){
    node<Alumno>* aux;
    aux = listaAlumnos.primero();

    std::ofstream archivoAlumnosSalida;
    archivoAlumnosSalida.open("Alumnos.txt", std::ios::out);


    while (aux != nullptr){
        Alumno Alum;
        Alum = aux->getData();
        archivoAlumnosSalida<<Alum.getNombre()<<" "<<Alum.getEdad()<<" "<<Alum.getSexo()<<std::endl;
        aux = aux->getSiguiente();
    }
    archivoAlumnosSalida.close();
    
}



int main() {
    LSLSE<Alumno> listaAlumnos;
    cargarDatos(listaAlumnos);
    Alumno alumno("",0,"");
    std::string nom;
    Alumno AlumEliminar("", 0, "");
    node<Alumno>* pos;

    int opcion;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar Alumno\n";
        std::cout << "2. Eliminar Alumno\n";
        std::cout << "3. Imprimir Alumnos\n";
        std::cout << "4. Ordenar Alumnos\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese la opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: 
                
                std::cin>>alumno;
                listaAlumnos.insertar(alumno);
                break;
            case 2: 
                std::cout << "Dame el nombre del alumno: ";
                std::cin >> nom;
                AlumEliminar.setNombre(nom);     
                
                pos = listaAlumnos.Busqueda(AlumEliminar);
                if (pos != nullptr) {
                    listaAlumnos.eliminar(pos);
                } else {
                    std::cout << "Alumno no encontrado.\n";
                }
                break;
            case 3:
                std::cout << "Lista de Alumnos:\n";
                listaAlumnos.imprimir();
                break;
            case 4:
                listaAlumnos.Ordenamiento();
                std::cout << "Alumnos ordenados por género.\n";
                break;
            case 5:
                std::cout << "Saliendo del programa.\n";
                GuardarInformacion(listaAlumnos);
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}





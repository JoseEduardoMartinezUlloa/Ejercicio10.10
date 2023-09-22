#include <iostream>
#include "ListaLigada.cpp"  // Asegúrate de incluir correctamente el archivo de la lista ligada

int main() {
    LSLSE<Alumno> listaAlumnos;
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
        std::cout << "Ingrese la opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: 
                
                std::cin>>alumno;
                listaAlumnos.insertar(alumno);
                break;
            case 2: 
                std::cout << "Dame el nombre del alumno: ";
                std::cin >> nom;
                AlumEliminar.setNombre(nom);     // Establece el nombre proporcionado
                
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
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}

#include<iostream>


class Alumno{
    private: 
        std::string nombre;
        int edad; 
        std::string sexo;
    public:
        void setNombre(std::string);
        void setEdad(int);
        void setSexo(std::string);

        std::string getNombre();
        int getEdad();
        std::string getSexo();
        Alumno(std::string,int,std::string);
        Alumno();
        
        bool operator==(const Alumno& )const;
        bool operator!=(const Alumno&)const;
        bool operator<(const Alumno&)const;
        bool operator>(const Alumno&)const;


        friend std::istream& operator >>(std::istream& is, Alumno& alu);

        friend std::ostream& operator<<(std::ostream& os, const Alumno& alu){
        os << "Nombre: " << alu.nombre << std::endl;
        os << "Edad: " << alu.edad << std::endl;
        os << "Sexo: " << alu.sexo << std::endl;
        return os;
    }


};
#include"Alumno.h"
#include<string>
#include<fstream>


void Alumno::setNombre(std::string nom){nombre = nom;}

void Alumno::setEdad(int ed){edad = ed;}

void Alumno::setSexo(std::string sex){sexo = sex;}


std::string Alumno::getNombre(){return nombre;}

int Alumno::getEdad(){return edad;}

std::string Alumno::getSexo(){return sexo;}

bool Alumno::operator==(const Alumno& a)const{
    return this-> sexo == a.sexo;
}

bool Alumno::operator!=(const Alumno& a)const{
    return !(*this == a);
}

bool Alumno::operator<(const Alumno& a)const{
    return this->edad < a.edad;
}

bool Alumno::operator>(const Alumno& a)const{
    return this-> edad > a.edad;
}

std::istream& operator>>(std::istream& is, Alumno& alu){
    std::cout<<"Nombre: ";
    is.ignore();
    getline(is, alu.nombre);
    std::cout<<"Edad: ";
    is.ignore();
    is>> alu.edad;
    std::cout<<"Sexo: ";
    is.ignore();
    getline(is,alu.sexo);
    return is;
}

Alumno::Alumno(std::string nom,int ed,std::string sex){
    setNombre(nom);
    setEdad(ed);
    setSexo(sex);
}

Alumno::Alumno(): nombre(""),edad(0),sexo(""){}
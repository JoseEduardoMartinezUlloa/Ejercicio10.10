#include <iostream>
#include"Alumno.cpp"

template<class T>
class LSLSE;
template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node();
    node(const T&);

    void setData(const T&);
    void setSiguiente(node<T>*);

    T getData();
    node<T>* getSiguiente();
};

template<class T >
node<T>::node(){sig == nullptr;}


template<class T>
node<T>::node(const T& dat){
    data  = dat;
    sig  = nullptr;
}


template<class T>
void node<T>::setData(const T& dat){
    data = dat;
}

template<class T>
void node<T>::setSiguiente(node<T>* pos){
    sig = pos;
}

template<class T>
T node<T>::getData(){
    return data;
}

template<class T>
node<T>* node<T>::getSiguiente(){
    return sig;
}



template<class T>
class LSLSE{
private:
    node<T>* header;
public:
    LSLSE():header(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar( T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    void Ordenamiento();
    node<T>* Busqueda(T);

};

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=header;
    while(aux!=nullptr){
        std::cout<<aux->getData()<<std::endl;
        aux=aux->getSiguiente();
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==header){
        header=header->getSiguiente();
    }
    else{
        anterior(pos)->setSiguiente(pos->getSiguiente());
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(T elem){
    node<T>* aux(new node<T>(elem));

    if(aux == nullptr){
        std::cout<<"Memoria insuficiente\n";
    }
    if(header == nullptr || elem < header->getData()){
        aux->setSiguiente(header);
        header = aux;
    }
    else{
        node<T>* ant(header);
        while (ant->getSiguiente() != nullptr && ant->getSiguiente()->getData() < elem){
            ant = ant->getSiguiente();
        }
        aux->setSiguiente(ant->getSiguiente()) ;
        ant->setSiguiente(aux);
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=header;
    while(aux!=nullptr && aux->getSiguiente()!=pos){
        aux=aux->getSiguiente();
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return header;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=header;
    while(aux->getSiguiente()!=nullptr){
        aux=aux->getSiguiente();
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(header==nullptr)
        return true;
    return false;
}


template<class T>
void LSLSE<T>::Ordenamiento() {
    if (header == nullptr) {
        return;
    }

    node<T>* maleHead = nullptr;   // Cabeza de la lista de varones
    node<T>* femaleHead = nullptr; // Cabeza de la lista de mujeres
    node<T>* current = header;
    node<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->getData().getSexo() == "M") {  // Compara el género del alumno
            if (maleHead == nullptr) {
                maleHead = current;
                prev = current;
                current = current->getSiguiente();
                prev->setSiguiente(nullptr); // Desconecta el nodo de la lista original
            } else {
                prev->setSiguiente(current);
                prev = current;
                current = current->getSiguiente();
                prev->setSiguiente(nullptr); // Desconecta el nodo de la lista original
            }
        } else if (current->getData().getSexo() == "F") {  // Compara el género del alumno
            if (femaleHead == nullptr) {
                femaleHead = current;
                prev = current;
                current = current->getSiguiente();
                prev->setSiguiente(nullptr); // Desconecta el nodo de la lista original
            } else {
                prev->setSiguiente(current);
                prev = current;
                current = current->getSiguiente();
                prev->setSiguiente(nullptr); // Desconecta el nodo de la lista original
            }
        }
    }

    // Conecta las dos listas (varones y mujeres) intercaladamente en la lista principal
    if (maleHead != nullptr) {
        header = maleHead;
        node<T>* currentMale = maleHead;
        node<T>* currentFemale = femaleHead;

        while (currentMale != nullptr && currentFemale != nullptr) {
            node<T>* tempMale = currentMale->getSiguiente();
            node<T>* tempFemale = currentFemale->getSiguiente();
            currentMale->setSiguiente(currentFemale);
            currentFemale->setSiguiente(tempMale);
            currentMale = tempMale;
            currentFemale = tempFemale;
        }

        // Conecta el final de la lista de varones si quedan elementos
        if (currentMale != nullptr) {
            while (currentMale->getSiguiente() != nullptr) {
                currentMale = currentMale->getSiguiente();
            }
            currentMale->setSiguiente(currentFemale);
        }
    }
}


template<class T>
node<T>* LSLSE<T>::Busqueda(T elm){
    node<T>* aux = header;
    while (aux != nullptr && aux->getData() != elm){
        aux = aux->getSiguiente();
    }
    return aux;
    
}

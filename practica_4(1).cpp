#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

std::vector<int> g_vector = {5, 8, 10, 13, 15, 18, 20, 23, 25, 29, 32, 36, 40, 42, 47, 51, 55, 63, 66};
int g_num_datos = static_cast<int>(g_vector.size());

void mostrar_vector(std::vector<int> g_vector){
    std::system("cls");
    std::cout<<"\n=------- Mostrar vector -------=\n";
    std::cout<<"\n";
    for (int i {0}; i < g_num_datos; i++){
        std::cout<<"Posicion "<<i + 1<<" = "<<g_vector[i]<<'\n';   
    }
    std::cout<<"\n=---------------------------=\n";
    std::system("pause");
    std::system("cls");
}

void busqueda_secu(std::vector<int> g_vector){
    std::system("cls");
    std::cout<<"\n=------- Busqueda Secuencial -------=\n";
    std::cout<<"\n";
    std::cout<<"Ingrese el numero a buscar: ";
    int clave {0};
    std::cin>>clave;

    bool encontrado = false;
    for (int i {0}; i < g_num_datos; i++){
        if(clave == g_vector[i]){
            std::cout<<"\nEl numero "<<clave<<" se ha encontrado en la posicion "<<i + 1<<'\n';
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        std::cout<<"El numero no se encuentra en el vector...";
    }
    std::cout<<"\n=---------------------------=\n";
    std::system("pause");
    std::system("cls");
}

int busqueda_bin(std::vector<int> g_vector){
    std::system("cls");
    std::cout<<"\n=------- Busqueda Binaria -------=\n";
    std::cout<<"Ingrese el valor que desee buscar: "<<std::endl;
    int clave {0};
    std::cin>>clave;

    int bajo = 0;
    int alto = g_num_datos - 1;

    while (bajo <= alto) {
        int central = (bajo + alto) / 2; // Índice del elemento central
        int valor_central = g_vector[central]; // Valor del elemento central

        if (clave == valor_central) {
            std::cout<<"El limite alto es: "<<alto<<'\n';   //Se muestra el limite bajo
            std::cout<<"El limite bajo es: "<<bajo<<'\n'; //Se muestra e limite alto
            std::cout<<"\n=---------------------------=\n";
            std::system("pause");
            std::system("cls");
            return central; // Encontrado
        } else if (clave < valor_central) {
            alto = central - 1; // Ir a la sublista inferior
        } else {
            bajo = central + 1; // Ir a la sublista superior
        }
    }

    std::cout<<"El valor no se ha encontrado\n";
    std::cout<<"\n=---------------------------=\n";
    std::system("pause");
    std::system("cls");
    return -1; // Elemento no encontrado
}

int main(){
    int opc {0};
    while(opc != 4){

        std::cout<<"\n=-------- Menu --------=\n";
        std::cout<<"\n1) Mostrar vector\n2) Busqueda Secuencial\n3) Busqueda binaria\n4) Salir";
        std::cout<<"\n=---------------------------=\n";
        std::cout<<"Elija una opcion: "<<std::endl;
        std::cin>>opc;

        if(opc < 1 || opc > 3){
            std::cout<<"\nFavor de ingresar una opcion valida: ";
            continue;
        }
        
        switch (opc){
        case 1: 
            mostrar_vector(g_vector);
            break; 
        case 2:
            busqueda_secu(g_vector);           
            break; 
        case 3:
            busqueda_bin(g_vector);
            break;    
        default:

            break;
        }
    }

    return 0;
}
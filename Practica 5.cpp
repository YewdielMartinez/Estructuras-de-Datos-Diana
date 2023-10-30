#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
//Aqui se inicializa una funcion donde va a generar un vector con numeros aleatorios donde la cantidad es el numero de datos, rango de inicio donde van a iniciar los numeros y rango de fin es donde se van acabar esos numeros
std::vector<int> generarNumerosAleatorios(int Cantidad, int Rangoinicio, int RangoFinal) {
    std::vector<int> numerosDisponibles;//Son todos los numeros disponibles
    std::vector<int> numerosAleatorios;//Donde se van a guardar los numeros aleatorios

    //Llenamos el vector con el rango que se especifico
    for (int i = Rangoinicio; i <= RangoFinal; ++i) {
        numerosDisponibles.push_back(i);
    }
    //Esta es la semilla para los numeros aleatorios que la inicializamos en 0
    std::srand(std::time(0));

    // Generar números aleatorios y que no se repitan 
    for (int i = 0; i < Cantidad ; ++i) {
        //Obtiene un indice para saber que los numeros no esten repetidos 
        int indiceAleatorio = std::rand() % numerosDisponibles.size();

        // Obtener el número aleatorio y eliminarlo de la lista de disponibles
        int numeroAleatorio = numerosDisponibles[indiceAleatorio];
        numerosDisponibles.erase(numerosDisponibles.begin() + indiceAleatorio);//Aqui elimina un elemento que este en el inicio del vector de numeros dispobles y en el indice aleatorio

        // Agregar el número aleatorio al vector de números aleatorios
        numerosAleatorios.push_back(numeroAleatorio);
    }

    return numerosAleatorios;
}
void Bubblesort(std::vector<int>& numeros){
    int n = numeros.size(); //n Es el numero de datos
    int i,j,temp;//Inicializamos las variables que se van a utilizar
    
    for (i = 0 ; i < n - 1; ++ i){//Este ciclo for inicializa la i en 0 y se compara que i sea menor que el numero de elementos - 1 y cada vez que se repite el dato mas grande se va colocando
        for (j = 0; j < n - i - 1; ++j){//Aqui es para no volver a hacer el ciclo for de arriba por que el dato mas grande ya esta acomodado 
            if (numeros[j] > numeros[j + 1]){//Aqui conpara que el dato que esta en la posicion j sea mayor que el numero que esta en la posicion j + 1 osea compara el dato con el sigueinte
            temp = numeros[j];//Esta es una variable temporal para guardar el dato para poder acomodarlo
            numeros[j] = numeros[j + 1];
            numeros [j + 1] = temp;
            }

        }

    }

}
void mostrar_vector(std::vector<int> mvector){
    std::system("cls");
    int n = mvector.size();
    std::cout<<"\n=------- Mostrar vector -------=\n";
    std::cout<<"\n";
    for (int i {0}; i < n; i++){
        std::cout<<"Posicion "<<i + 1<<" = "<<mvector[i]<<'\n';   
    }
    std::cout<<"\n=---------------------------=\n";
    std::system("pause");
    std::system("cls");
}
void mostrar_vectorOrdenado(std::vector<int> mvector){//Muestra el vector ordenado con el bubblesort
    
    std::system("cls");
    int n = mvector.size();
    std::cout<<"\n=------- Mostrar vector -------=\n";
    std::cout<<"\n";
    for (int i {0}; i < n; i++){
        std::cout<<"Posicion "<<i + 1<<" = "<<mvector[i]<<'\n';   
    }
    std::cout<<"\n=---------------------------=\n";
    std::system("pause");
    std::system("cls");
}

void busqueda_secu(std::vector<int> g_vector){
    std::system("cls");
    int n = g_vector.size();
    std::cout<<"\n=------- Busqueda Secuencial -------=\n";
    std::cout<<"\n";
    std::cout<<"Ingrese el numero a buscar: ";
    int clave {0};
    std::cin>>clave;

    bool encontrado = false;
    for (int i {0}; i < n; i++){
        if(clave == g_vector[i]){
            std::cout<<"\nEl numero "<<clave<<" se ha encontrado en la posicion "<<i + 1<<'\n';
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        std::cout<<"El numero no se encuentra en el vector...";
    }

}
int busqueda_bin(std::vector<int> g_vector){
    std::system("cls");
        int n = g_vector.size();
    std::cout<<"\n=------- Busqueda Binaria -------=\n";
    std::cout<<"Ingrese el valor que desee buscar: "<<std::endl;
    int clave {0};
    std::cin>>clave;

    int bajo = 0;
    int alto = n - 1;

    while (bajo <= alto) {
        int central = (bajo + alto) / 2; // Índice del elemento central
        int valor_central = g_vector[central]; // Valor del elemento central

        if (clave == valor_central) {
            std::cout<<"El limite alto es: "<<alto<<'\n';   //Se muestra el limite bajo
            std::cout<<"El limite bajo es: "<<bajo<<'\n'; //Se muestra e limite alto
            return central; // Encontrado
        } else if (clave < valor_central) {
            alto = central - 1; // Ir a la sublista inferior
        } else {
            bajo = central + 1; // Ir a la sublista superior
        }
    }

    std::cout<<"El valor no se ha encontrado\n";

    return -1; // Elemento no encontrado
}
int main() {
    // Llamar a la función para generar 200 números aleatorios en el rango de 0 a 600
    std::vector<int> numerosAleatorios = generarNumerosAleatorios(200, 0, 600);

    // Ordenar el vector de números aleatorios

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
            mostrar_vector(numerosAleatorios);
            Bubblesort(numerosAleatorios);
            mostrar_vectorOrdenado(numerosAleatorios);
            break; 
        case 2:
        {
            Bubblesort(numerosAleatorios);
            auto start_time = std::chrono::high_resolution_clock::now(); // Guarda el tiempo de inicio
            busqueda_secu(numerosAleatorios);   
            auto end_time = std::chrono::high_resolution_clock::now(); // Guarda el tiempo de finalización
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count(); // Calcula la duración en milisegundos
             std::cout << "Tiempo de ejecucion de la busqueda secuencial: " << duration << " milisegundos" << std::endl;       
            break;
        }     
        case 3:
        {
            Bubblesort(numerosAleatorios);
            auto start_time = std::chrono::high_resolution_clock::now(); // Guarda el tiempo de inicio
            busqueda_bin(numerosAleatorios);
            auto end_time = std::chrono::high_resolution_clock::now(); // Guarda el tiempo de finalización
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count(); // Calcula la duración en milisegundos
            std::cout << "Tiempo de ejecucion de la busqueda binaria: " << duration << " milisegundos" << std::endl;
            break;
        }    
        default:

            break;
        }
    }
    return 0;
}
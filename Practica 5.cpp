#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
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

int main() {
    // Llamar a la función para generar 200 números aleatorios en el rango de 0 a 600
    std::vector<int> numerosAleatorios = generarNumerosAleatorios(200, 0, 600);



    return 0;
}
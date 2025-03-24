#include <iostream>
#include <fstream>
#include <iomanip>  

// Funzione per mappare un valore dall'intervallo [1, 5] all'intervallo [-1, 2]
double intervalloMappato(double value) {
    return -1 + (value - 1) * (2 + 1) / (5 - 1);
}

int main() {
    
    std::ifstream inputFile("data.txt"); 
    if (!inputFile) {
        std::cout << "Errore: impossibile aprire il file data.txt per la lettura!" << std::endl;
        return 1;
    }

    
    std::ofstream outputFile("result.txt"); 
    if (!outputFile) {
        std::cout << "Errore: impossibile aprire il file result.txt per la scrittura!" << std::endl;
        return 1;
    }

    
    outputFile << std::fixed << std::setprecision(16); 

    double value;
    double sommaCumulata = 0.0;
    int i = 0;

    
    while (inputFile >> value) {
        double valoreMappato = intervalloCumulato(value);
        sommaCumulata += valoreMappato;
        double media = sommaCumulata / (i + 1);  
        outputFile << (i + 1) << " " << media << std::endl;
        i++; 
    }


    inputFile.close();  
    outputFile.close(); 

    std::cout << "Risultato scritto in result.txt" << std::endl;
    return 0;
}
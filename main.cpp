#include <iostream>
#include <fstream>
#include <iomanip>  


double intervalloMappato(double value) {
    return (3.0/4.0)*value-(7.0/4.0);
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
        double valoreMappato = intervalloMappato(value);
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

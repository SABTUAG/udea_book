#include "efficiency.h"
#include <iostream>

// Definición de las variables estáticas
long Efficiency::_iterations = 0;
long Efficiency::_memoryBytes = 0;

void Efficiency::countIteration(long n) {
    _iterations += n;
}

void Efficiency::registerAllocation(long bytes) {
    _memoryBytes += bytes;
}

void Efficiency::registerFree(long bytes) {
    _memoryBytes -= bytes;
}

void Efficiency::reset() {
    _iterations = 0;
}

void Efficiency::showMetrics(const char* functionName) {
    std::cout << "\n--- Metricas de eficiencia: " << functionName << " ---\n";
    std::cout << "Iteraciones: " << _iterations << "\n";
    std::cout << "Memoria dinamica en uso: " << _memoryBytes << " bytes\n";
    std::cout << "-------------------------------------------\n";
}
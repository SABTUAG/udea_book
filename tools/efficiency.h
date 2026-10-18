#ifndef EFFICIENCY_H
#define EFFICIENCY_H

/**
 * @brief Utilidades para la medición de consumo de recursos.
 * 
 * @details Lleva un conteo global de las iteraciones realizadas 
 * y de la memoria dinámica utilizada por el sistema. 
 * 
 * Las variables son estáticas para que cualquier parte del 
 * código pueda registrar sus operaciones sin necesidad de 
 * instanciar la clase. Al iniciar cada funcionalidad del 
 * menú, se llama a reset() para limpiar el contador de 
 * iteraciones, y al finalizar, se llama a showMetrics() 
 * para imprimir los resultados en consola.
 */
class Efficiency {
private: 
    static long _iterations; 
    static long _memoryBytes;

public: 
    /**
     * @brief Incrementa el contador de iteraciones.
     * @param n Cantidad a sumar (por defecto 1).
     */
    static void countIteration(long n = 1);

    /**
     * @brief Registra memoria asignada (new).
     * @param bytes Cantidad de bytes reservados.
     */
    static void registerAllocation(long bytes);

    /**
     * @brief Registra memoria liberada (delete).
     * @param bytes Cantidad de bytes liberados.
     */
    static void registerFree(long bytes);

    /**
     * @brief Reinicia el contador de iteraciones a cero.
     */
    static void reset();

    /**
     * @brief Muestra las métricas actuales en consola.
     * @param functionName Nombre de la funcionalidad evaluada.
     */
    static void showMetrics(const char* functionName);
}; 

#endif
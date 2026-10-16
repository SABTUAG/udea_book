#ifndef EFFICIENCY_H
#define EFFICIENCY_H

/**
 * @brief Utilidades para la medición de consumo de recursos.
 */
class Efficiency {
private: 
    static long _iterations; 
    static long _menoryBytes;
public: 
    static void countIteration(long n = 1);
    static void registerAllocation(long bytes);
    static void registerFree(long bytes);
    static void reset();
    static void showMetrics(const char* functionName);

}; 

#endif

#ifndef PARSER_H
#define PARSER_H

#include "str.h"

/**
 * @brief Extrae el valor de un bloque de texto.
 * @param block Texto completo.
 * @param key Clave a buscar (ej. "NAMEID:").
 * @return El valor extraído sin espacios.
 */
str extractValue(const str& block, const str& key);

/**
 * @brief Extrae el texto contenido entre corchetes [ ... ].
 * @param block Texto completo.
 * @param key Palabra clave anterior al corchete.
 * @return El texto interno, o "" si no se encuentra.
 */
str extractBlock(const str& block, const str& key);

/**
 * @brief Extrae el texto contenido entre paréntesis ( ... ).
 * @param text Texto completo.
 * @param key Palabra clave anterior al paréntesis.
 * @return El texto interno, o "" si no se encuentra.
 */
str extractParens(const str& text, const str& key);

#endif
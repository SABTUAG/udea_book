# Red Social en Consola 
<svg xmlns="http://www.w3.org/2000/svg" width="220" height="60" viewBox="0 0 220 60">
  <defs>
    <linearGradient id="grad" x1="0%" y1="0%" x2="100%" y2="100%">
      <stop offset="0%" style="stop-color:#ff007f;stop-opacity:1" />
      <stop offset="100%" style="stop-color:#7928ca;stop-opacity:1" />
    </linearGradient>
  </defs>
  <style>
    .btn {
      fill: url(#grad);
      rx: 30px;
      transition: all 0.3s ease;
      cursor: pointer;
    }
    .btn:hover {
      fill: #00dfd8;
      filter: drop-shadow(0px 5px 12px rgba(0, 223, 216, 0.7));
    }
    .text {
      fill: white;
      font-family: Arial, sans-serif;
      font-size: 16px;
      font-weight: bold;
      pointer-events: none;
    }
  </style>
  <rect class="btn" width="220" height="60"/>
  <text x="50%" y="55%" dominant-baseline="middle" text-anchor="middle" class="text">Diagrama</text>
</svg>
<svg xmlns="http://www.w3.org/2000/svg" width="220" height="60" viewBox="0 0 220 60">
  <defs>
    <linearGradient id="grad" x1="0%" y1="0%" x2="100%" y2="100%">
      <stop offset="0%" style="stop-color:#ff007f;stop-opacity:1" />
      <stop offset="100%" style="stop-color:#7928ca;stop-opacity:1" />
    </linearGradient>
  </defs>
  <style>
    .btn {
      fill: url(#grad);
      rx: 30px;
      transition: all 0.3s ease;
      cursor: pointer;
    }
    .btn:hover {
      fill: #00dfd8;
      filter: drop-shadow(0px 5px 12px rgba(0, 223, 216, 0.7));
    }
    .text {
      fill: white;
      font-family: Arial, sans-serif;
      font-size: 16px;
      font-weight: bold;
      pointer-events: none;
    }
  </style>
  <rect class="btn" width="220" height="60"/>
  <text x="50%" y="55%" dominant-baseline="middle" text-anchor="middle" class="text">Video</text>
</svg>




Ude@Book esta construida bajo el paradigma de **Programación Orientada a Objetos (POO)**, con gestión de **memoria dinámica** y **listas enlazadas** para asegurar un alto rendimiento computacional.

### Enfoque en la eficiencia

* **Consumo de recursos de memoria:** Optimización mediante asignación y liberación dinámica de recursos.
* **Tiempo de ejecución:** Operaciones de alta velocidad mediante el uso eficiente de estructuras enlazadas y complejidad computacional BigO.

[![Diagrama](https://img.shields.io/badge/Texto-Color?style=for-the-badge)](https://tu-sitio.com)

[Ver Video Demostrativo (Próximamente disponible a partir del 16 octubre)](#)

[Ver primer diagrama de clases](https://drive.google.com/file/d/1Z5c6jAvguRtdLreZFqCEST2mogepnOgc/view?usp=drive_link) 

## PRIMER AVANCE DESAFÍO II

### CONTEXTUALIZACIÓN DEL PROBLEMA

1\) Realice una lectura comprensiva del texto del desafío empleando un código de colores para identificar objetos, atributos y métodos, además de resaltar las restricciones y recomendaciones. 

| Clasificación de resaltadores |  |
| :---- | :---- |
| Azul | Clases |
| Verde | Atributos |
| Amarillo  | métodos  |
| Rojo | Restricciones y recomendaciones |


2\) También subrayó los flujos de ejecución esperados de cada funcionalidad específica, posteriormente crearé sus respectivos diagramas (Pero en el momento solo me enfocare en la interacción entre las clases). 



### ANÁLISIS DEL PROBLEMA 

Se debe construir una red social para consola  muy eficiente a nivel de memoria y tiempo de ejecución usando el paradigma de programación orientada a objetos. 

Para la estructura del proyecto se dividirá: 

- Sección para la lógica, donde se guardarán las clases que integran la red social.  
- Base de datos, donde se guardarán la información persistente  
- Herramientas, donde se guardaran clases esenciales, que no se relacionan directamente con la lógica del programa. 

Lo primero que debo crear lo siguiente: 

1. Crear una plantilla de lista usando lista enlazada.   
2. Sobrecargar operadores. 

Y algunos de los  algoritmos que debo crear: 

* Generador de valores genéricos  
* Buscador de información   
* Validador de entradas por consola



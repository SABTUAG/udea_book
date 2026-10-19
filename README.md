# Red Social Ude@Ebook

[Ver Video Demostrativo (Próximamente disponible a partir del 18 octubre)](#)



## INFORME DESAFÍO II

### CONTEXTUALIZACIÓN DEL PROBLEMA

Realice una lectura comprensiva del texto del desafío empleando un código de colores para identificar objetos, atributos y métodos, además de resaltar las restricciones y recomendaciones. 

| Clasificación de resaltadores  | |
| :---- | :---- |
| Azul | Clases |
| Verde | Atributos |
| Amarillo  | métodos  |
| Rojo | Restricciones y recomendaciones |


También subrayó los flujos de ejecución esperados de cada funcionalidad específica. Luego hago un diagrama en papel sobre todo esto y saco mis conclusiones sobre lo que se me esta pidiendo. 
Identifique que hay una clase principal **usuario**, compuesta por multiples elementos(posibles clases y sus atributos) dentro de una clase **plataforma** que le permite la interacción con otros usuarios. 
[Mirar PDF (Drive)](https://docs.google.com/document/d/16gyP_rgqqiGxrQm-Qu636G1EwM30HxNljUp-neo5HoA/edit?usp=sharing)


### A. ANÁLISIS DEL PROBLEMA Y CONSIDERACIONES PARA LA ALTERNATIVA DE SOLUCIÓN PROPUESTA. 

##### Análisis del problema

Se debe construir una red social para consola eficiente a nivel de gestión de memoria tiempo de ejecución, además medir estos recursos y guardar la información en formato permanente utilizando el paradigma de programación orientado a objetos. 


Sobre la interacion . sobre los mensajes. sobre las imagenes. 


#### Consideraciones para la alternativa de la solución propuesta. 

1. Defino la arquitectura: 

- **udeaBook/** <- El directorio principal donde vivira todo el proyecto. 
  - **app/** <- Lógica de la red social. 
    - **user/** 
      - **friends/** <- Gestion de amigos, sugerencias y solicitudes enviadas y recibidas. 
      - **images/** <- Gestion de imagenes y albumenes. 
      - **messages/** <- Gestion de mensajes enviados y recibidos. 
      - user <- Donde se integra el usuario
    - plataform <- Donde se da la interacción entre los usuarios. 
  - **databases/** <- Guarda la información y la herramienta para su lectura y modificacion. 
  - **tools/** <- Herramientas necesarias para construir la aplicacion
  - main

2. Como es restricción **Usar herramientas que resuelvan problemas críticos**, las cree. Todas están se alojaran en **tools** a excepción de una, la cual estará en el directorio **databases**.
a. Una plantilla de lista usando conceptos de lista enlazada. 
b. Una clase que emule string.
c. Una clase que facilite todo lo relacionado con la consola.
d. Un modulo para las funcionalidades para medir el rendimiento. 
e. Un modulo encargado del acceso a los archivos, su lectura y modificación. (Si me queda tiempo también le implementare para comprimir y encriptar la información.)

3. Elegi el archivos txt para almacenar la información ..

### B. DIAGRAMAS DE CLASES

**Nota**: Aqui se adjuntaran las versiones de los diagramas de clases. 

* [1](https://drive.google.com/file/d/1Z5c6jAvguRtdLreZFqCEST2mogepnOgc/view?usp=drive_link)
* [1.2](https://drive.google.com/file/d/1KVAqxqt8SBJnf0sure7J5xP-eKFQLVBS/view?usp=drive_link)
* [2 (Nueva versión, proximamente)](#)

### C. ALGORITMOS ESENCIALES CONSTRUIDOS

[Mirar PDF(drive)](https://docs.google.com/document/d/15Kp4xDi7ScfjX4YkAWpPnFD3HdD15GEhZWZ9ao62Aqg/edit?usp=sharing)


### D. PROBLEMAS DE DESARROLLO QUE AFRONTE

* Cuando cree la lista enlazada, me di cuenta de un incoveniente, no soportaba crear una lista de clases inicializada. Entonces, mi problema como añadia varios elementos al mismo tiempo. O por lo menos evitar ese trabajo tedioso. de agregar elemento por elemento. 
* Para el desarrollo utilice string mientras construia mi propia clase string **str**, pero el problema vino cuando pense que ya estaba lista **str** y empece a integrarla. No tenia soporte para algunos operadores, partes que tenia para lectura fallaron, entonces lo que yo hice fue, para entradas usar string, y que mi str reciba ese string y pase su contenido a su formato.
* Sobre como medir los recursos con precision, 


### E. EVOLUCIÓN DE LA SOLUCIÓN Y CONSIDERACIONES A TENER CUENTA EN LA IMPLEMENTACION

1. Respecto a como y donde se guardara la información, he hecho cambios significativos.
Primero tenia previsto crear un archivo txt por cada usuario registrado y el nombre del archivo seria el mismo que el nombre del usuario y su contenido organizado de la siguiente forma: 
{
"nameID":"juanitoPerez",
"birthDate":"1998-05-15",
"email":"juanito.perez@gmail.com",
"password":"***",
"city":"Medellin",
"country":"Colombia",
"registrationDate":"2026-10-12",
"friends":[...],
"chats":[...],
"gallery":[...]
}
pero desisti de esa idea porque seria una cantidad absurda de archivos, por ejemplo para el ejercicio de los 1000 usuarios, necesitaria 1000 archivos. 
Mi segunda idea fue guardar todos los usuarios en un mismo archivo, conservando el formato, pero agregarle un id ej. (id{...}) y comprimir y encriptar la información. asi la busqueda por id seria rápida, pero tenia un fallo, un usuario no ingresaria por su ID, sino por su contraseña y nombre único.
Lo que implemente fue esto, usar un archivo para cada tipo de información: 
  - usersAunteticate <- Aqui guarda el nombre del usuario, su contraseña y un ID numerico
  - messages <- Id numerico y mensajes recibidos ..
  - images <- Id numerico he imagenes
  - friends <- Id numerico y amigos
  - friendRequest <- Id numerico y solicitudes de amistad
Cuando un usuario inicia, la plataforma lo busca en userAutenticate y lo valida, según eso devuelve su ID, con ese Id ya se puede acceder a la demás información en los otros archivos. 
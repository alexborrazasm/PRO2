# GEI-Pro2 614G010062324 - Programación II - Grao en Enxeñaría Informática (2023-2024)

Prácticas del la asignatura.

[Guia docente](https://guiadocente.udc.es/guia_docent/index.php?centre=614&ensenyament=614G01&assignatura=614G01006&any_academic=2023_24)

## Práctica 0

Aprender a usar **ficheros de cabecera .h** y los **módulos** en C.
- Implementación mediante estructuras.
- Imprementación mediante punteros.

## Práctica 1

Implementar una serie de funcionalidades para MUSFIC, una plataforma de música bajo demanda. Será necesario diseñar una estructura de datos que permita almacenar conjuntamente toda la información asociada a usuarios y reproducciones. En esta primera práctica se abordarán las tareas de gestión de usuarios, incluyendo altas, bajas y reproducciones.

### Objetivo

Practicar la independencia de la implementación en los Tipos Abstractos de Datos (**TADs**), con dos implementaciones:

- Lista no ordenada estática.
- Lista no ordenada dinánica.

El programa principal no deberá realizar ninguna suposición sobre la forma en que está implementado el TAD.

#### Cualificación: 9.25 (error corregido)

## Práctica 2

Añadir un conjunto de nuevas funcionalidades al programa MUSFIC desarrollado en la primera práctica. En concreto, se incluirá una lista de reproducción de canciones a cada usuario.

### Objetivo

El objetivo de esta práctica es comprender el funcionamiento e implementar varios tipos abstractos de datos (**TADs**) así como manejar interdependencias entre ellos.

Implementaciones:

- Una **lista ORDENADA dinámica simplemente enlazada** (TAD UserList) para almacenar la lista de usuarios.
- Una **lista NO ORDENADA estática** (TAD SongList) para almacenar las canciones de cada usuario.

Cada nodo de la lista ordenada tendrá su propia lista de
reproducción.

#### Cualificación: 10

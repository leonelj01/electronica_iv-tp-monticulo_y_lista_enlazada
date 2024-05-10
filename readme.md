# Electrónica IV - TP - Montículo y Lista Enlazada

Modalidad: *individual*\
Plazo: *una semana*

## 1. Objetivos

Al completar con éxito este práctico podrás

1. Definir y distinguir entre *tipo de dato abstracto*, *estructura de datos* y
   *tipo de dato*.
2. Identificar las estructuras de datos montículo y lista enlazada
3. Razonar sobre las ventajas y desventajas de dichas estructuras
4. Implementar dichas estructuras como tipos de dato abstractos

## 2. Metodología

Para completar este práctico deberás realizar un *fork* de este repositorio, en
el cual crearás tu solución. Antes de comenzar a programar deberás, completando
el archivo [`estudio_teórico.md`][TE.MD], realizar un estudio teórico de las
estructuras de datos que implementaremos. Para ello deberás hacer una búsqueda
bibliográfica, puedes referirte a libros de texto, videos y artículos.
Recomendamos los textos de Joyanes Aguilar y Zahonero Martínez (2002 o 2005) y
de Aho, Hopcroft y Ullman (1988) disponibles en biblioteca. Luego de realizar el
estudio teórico, diseñarás e implementarás los tipos de datos abstractos
*montículo binario* y *lista enlazada*. Durante el trabajo de diseño e
implementación deberás registrar tu progreso en [`memoria_de_diseño.md`][PR.MD],
siguiendo la estructura sugerida en el mismo.

## 3. Especificación

En este práctico implementaremos dos tipos de dato abstractos, un montículo
binario de mínimo o máximo y una lista símplemente vinculada.

### 3.1 Montículo binario

El montículo binario es una estructura de datos que permite insertar elementos y
remover el elementos y los mantiene organizados de manera que se pueda acceder
al elemento tope (que es el mínimo para el montículo de mínimo o máximo para el
montículo de máximo) en un tiempo independiente del número de elementos en el
montículo. Uno de sus principales usos es la implementación de *colas de*
*prioridad*. Soporta las operaciones de *leer tope*, *insertar* y
*remover tope*. Las operaciones de *inserar* y *remover tope* tomarán un tiempo
proporcional al logaritmo base dos del número de elementos. La variante de
montículo que implementaremos es basada en un arreglo, permitiendo un uso
eficiente de la memoria. Solamente emplearemos memoria adicional para registrar
los metadatos de la estructura (dirección base y tamaño del arreglo, tipo de
montículo).

El montículo que implementaremos contendrá simplemente números enteros, puesto
que el propósito del práctico es familiarizarnos con la estructura de datos y
sus operaciones. En [`src/listado1.c`][LST1] hay un programa ejemplificando el
uso del mismo.

El encabezado [`lib/monticulo/monticulo.h`][MN.H] contiene los prototipos de las operaciones y la definición de tipos de datos. **Debes completar la definición**
**de la estructura *montículo***. El archivo [`lib/monticulo/monticulo.c`][MN.C]
contiene la implementación de las operaciones, que debes completar.

#### 3.1.1 Pruebas de software

Cuentas con un conjunto de pruebas para asistirte en la implementación del tipo
montículo. Puedes ejecutar las pruebas en el hardware (env:bluepill) o en
el emulador (env:emulador). Para ejecutar solo las pruebas del montículo
(recomendado) abre la consola de *PlatformIO* con el ícono ![`[>_]`][icono-consola]
en la barra de estado de *Visual Studio Code*. Ubicada en el borde inferior de
la ventana. Luego ejecuta el comando

```bash
platformio test -e emulador -f *monticulo
```

para ejecutar las pruebas en el emulador o

```bash
platformio test -e bluepill -f *monticulo
```

para ejecutar las pruebas en el hardware.

### 3.2 Lista enlazada

Una lista enlazada es una estructura de datos formada por unidades llamadas
nodos enlazadas entre sí mediante punteros. Cada nodo contiene un dato y un
puntero al siguiente nodo en la lista (para *lista simplemente enlazada*) o
punteros al siguiente nodo y al nodo anterior. En este práctico realizaremos una
*lista simplemente enlazada*.
La *lista simplemente enlazada* es representada por un puntero a su primer nodo.
Dicho nodo es llamado *cabeza* de la lista, el resto de los nodos son llamados
*cola* de la lista. La lista es una estructura *recursiva* porque cada nodo
incluye *un dato* (valor a la cabeza) y *una lista* (la cola). La cola es
representada por el puntero al siguiente nodo, que será a su vez la cabeza de la
cola. Una lista vacía se representa por un *puntero nulo* (valor NULL).
Al inicializar una lista nueva, esta quedará vacía (será únicamente un puntero
nulo). El último nodo de la lista tendrá una cola vacía (su puntero a siguiente
elemento será un puntero nulo).

El encabezado [`lib/lista_enlazada/lista_enlazada.h`][LE.H] contiene las
definiciones de tipos de dato y los prototipos de funciones para nuestra
implementación de lista enlazada. **Debes completar la definición de estructura**
**de datos *NodoLista***. El archivo [`lib/lista_enlazada/lista_enlazada.c`][LE.C]
contiene las implementaciones de las operaciones, que debes completar.
En el [`src/listado2.c`][LST2] hay un programa que ejemplifica el uso de la
lista enlazada.

#### 3.2.1 Pruebas de software

Cuentas con un conjunto de pruebas para asistirte en la implementación del tipo
lista enlazada. Puedes ejecutar las pruebas en el hardware (env:bluepill) o en
el emulador (env:emulador). Para ejecutar solo las pruebas de la lista enlazada
(recomendado) abre la consola de *PlatformIO* con el ícono ![`[>_]`][icono-consola]
en la barra de estado de *Visual Studio Code*. Ubicada en el borde inferior de
la ventana. Luego ejecuta el comando

```bash
platformio test -e emulador -f *enlazada
```

para ejecutar las pruebas en el emulador o

```bash
platformio test -e bluepill -f *enlazada
```

para ejecutar las pruebas en el hardware.

## Referencias

- Aho, A.V., Hopcroft, J.E. y Ullman, J.D. (1988) *Estructuras de datos y algoritmos*. Addison-Wesley Iberoamericana.
- Joyanes Aguilar,L y Zahonero Martínez,I. (2002) *Programación en C*.McGraw-Hill.
- Joyanes Aguilar,L y Zahonero Martínez,I. (2005) *Programación en C, segunda edición*. McGraw-Hill.

[TE.MD]: estudio_teórico.md
[PR.MD]: memoria_de_diseño.md
[icono-consola]: figs/readme-fig1.png
[MN.H]: lib/monticulo/monticulo.h
[MN.C]: lib/monticulo/monticulo.c
[LST1]: src/listado1.c
[LE.H]: lib/lista_enlazada/lista_enlazada.h
[LE.C]: lib/lista_enlazada/lista_enlazada.c
[LST2]: src/listado2.c

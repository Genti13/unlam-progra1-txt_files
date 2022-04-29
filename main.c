#include <stdio.h>
#include <stdlib.h>

#include "lib/archivos.h"
#include "lib/fun.h"
#include "lib/tipos.h"

int main()
{
//    archivoDeTexto(crearTextoLV, LV_ARCHIVO_NOMBRE, CREAR);
//    archivoDeTexto(leerTextFileLV, LV_ARCHIVO_NOMBRE, LEER);

    archivoDeTexto(crearTextoLF, LF_ARCHIVO_NOMBRE, CREAR);
    archivoDeTexto(leerTextFileLF, LF_ARCHIVO_NOMBRE, LEER);

    return 0;
}

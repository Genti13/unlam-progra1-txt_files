#include <stdio.h>
#include <stdlib.h>

#include "lib/archivos.h"
#include "lib/fun.h"
#include "lib/tipos.h"

int main()
{
    //crearArchivoDeTexto(crearTextoLV, LV_ARCHIVO_NOMBRE);
    leerArchivoDeTexto(leerTextFileLV, LV_ARCHIVO_NOMBRE);

    return 0;
}

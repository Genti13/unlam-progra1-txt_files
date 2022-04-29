#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "tipos.h"

int archivoDeTexto(void (*fun)(FILE * pf), const char * archivo, const char * modo);

void crearTextoLF(FILE * pf);
void crearTextoLV(FILE * pf);

void leerTextFileLF(FILE * pf);
void leerTextFileLV(FILE * pf);

void trozarCamposLV(tPersona * persona, const char * buffer);
void trozarCamposLF(tPersona * persona, char * buffer);

void mostrarPersona(const tPersona * persona);

#endif // FUN_H_INCLUDED

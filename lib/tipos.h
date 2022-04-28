#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef long int tDni;

typedef struct
{
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;
}tFecha;

typedef struct
{
    tDni dni;
    char nomyape[36];
    unsigned int edad;
    tFecha nacimiento;
}tPersona;

#endif // TIPOS_H_INCLUDED

#include "fun.h"
#include "archivos.h"

int archivoDeTexto(void (*fun)(FILE * pf), const char * archivo, const char * modo)
{
    FILE * pf = fopen(archivo, modo);

    if(pf)
    {
        fun(pf);
        fclose(pf);
        return 1;
    }

    return 0;
}

void crearTextoLF(FILE * pf)
{
    int i;
    tPersona personas[] =
    {
        {15975346,  "Anakin Skywalker",  24, {13,11,1997}},
        {55566677,  "Obi-Wan Kenobi",   24, {12,11,1997}},
        {96385247,  "Drath Vader",      66, {15,2,1880}},
        {23874612,  "EstoEs Sparta",    33, {12,01,1234}},
        {33665544,  "AAAAA BBBBB",      99, {01,15,1950}},
    };

    tPersona * pPersonas = personas;

    for(i=0; i<sizeof(personas)/sizeof(tPersona); i++,pPersonas++)
    {
        fprintf(pf,"%08ld%-*.*s%d%02d%02d%04d\n",
                pPersonas->dni,
                (int)sizeof(personas->nomyape)-1,
                (int)sizeof(personas->nomyape)-1,
                pPersonas->nomyape,
                pPersonas->edad,
                pPersonas->nacimiento.dia,
                pPersonas->nacimiento.mes,
                pPersonas->nacimiento.anio);
    }

}

void crearTextoLV(FILE * pf)
{
    int i;
    tPersona personas[] =
    {
        {40733281,  "Alan Gentile",             24, {13,11,1997}},
        {12345678,  "El Genti",                 24, {12,11,1997}},
        {87654321,  "Pedro Pica Piedras",       66, {15,2,1880}},
        {11223344,  "Nombre Apellido",          33, {12,01,1234}},
        {99887766,  "Sombrero Seleccionador",   99, {01,15,1950}},
    };

    tPersona * pPersonas = personas;

    for(i = 0; i < sizeof(personas)/sizeof(tPersona); i++, pPersonas++)
    {
        fprintf(pf,"%ld|%s|%d|%02d/%02d/%04d\n",
                pPersonas->dni,
                pPersonas->nomyape,
                pPersonas->edad,
                pPersonas->nacimiento.dia,
                pPersonas->nacimiento.mes,
                pPersonas->nacimiento.anio);
    }
}

void leerTextFileLF(FILE * pf)
{
    char buff[TAM_LINEA+2];
    tPersona persona;

    while(fgets(buff, sizeof(buff), pf))
    {
        trozarCamposLF(&persona, buff);
        mostrarPersona(&persona);
    }

}

void leerTextFileLV(FILE * pf)
{
    char buff[100];
    tPersona persona;

    while(fgets(buff,sizeof(buff), pf))
    {
        trozarCamposLV(&persona, buff);
        mostrarPersona(&persona);
    }

}

void trozarCamposLF(tPersona * persona, char * buffer)
{
    char * aux = buffer;

    aux += TAM_LINEA;
    *aux = '\0';

    /**NACIMIENTO**/
    aux -= TAM_CUMPLEANIOS;
    sscanf(aux,"%2d%2d%4d",
           &persona->nacimiento.dia,
           &persona->nacimiento.mes,
           &persona->nacimiento.anio);
    *aux = '\0';

    /**EDAD**/
    aux -= TAM_EDAD;
    sscanf(aux,"%2d",&persona->edad);
    *aux = '\0';

    /**APELL Y NOMB**/
    aux -= TAM_APEYNOM;
    strcpy(persona->nomyape, aux);
    *aux = '\0';

    /**DNI**/
    aux -= TAM_DNI;
    sscanf(aux, "%ld", &persona->dni);
    *aux = '\0';
}

void trozarCamposLV(tPersona * persona, const char * buffer)
{
    char * aux = strchr(buffer, '\n'); //strchr busca la primer aparicion del segundo argumento en el primero
    *aux = '\0'; //reemplazo el caracter de fin de linea por el '\0'

    /**Nacimiento**/

    //strrchr busca la ultima aparicion de '|' en buffer y se queda apuntando a ese lugar.
    //sscanf lee hasta '\0' o hasta un espacio en blanco.
    //como con el strrchr aux quedo apuntando a un '|' se incrementa 1 para poder tomar la informacion

    aux = strrchr(buffer, '|');
    sscanf(aux +1, "%d/%d/%d", &persona->nacimiento.dia, &persona->nacimiento.mes, &persona->nacimiento.anio);
    *aux = '\0';

    /**Edad**/

    aux = strrchr(buffer, '|');
    sscanf(aux +1, "%d", &persona->edad);
    *aux = '\0';

    /**Nombre y Apellido**/

    aux = strrchr(buffer, '|');
    strcpy(persona->nomyape, aux +1); //copia una cadena de caracteres.
    *aux = '\0';

    /**DNI**/
    //Aca ya no existen '|' asi que simplemente lo leo hasta el '\0'
    sscanf(buffer, "%ld", &persona->dni);
}

void mostrarPersona(const tPersona * persona)
{
    //%-*.*s:
    //el - alinea a la izquierda, asi como ponerle algun numero en su lugar alinearia a la derecha y rellenaria con espacio (%15s)
    //el * es un parametro que tengo que darle valor despues de la mascara ("%*s" ,15, string) == ("%15s", string)
    //.* indica que corte de reservar cuando como maximo se alcancen (*) cantidad de caracteres
    //*. indica reservar cierta cantidad de caracteres
    //*.* reserva la cantidad de caracteres y rellena con blanco

    printf("%08ld\t%-*.*s\t%d\t%02d/%02d/%4d\n",
           persona->dni,
           (int)sizeof(persona->nomyape)-1, //El -1 aca es porque en las cadenas hay un caracter que es el '\0' y no hay que contarlo
           (int)sizeof(persona->nomyape)-1,
           persona->nomyape,
           persona->edad,
           persona->nacimiento.dia,
           persona->nacimiento.mes,
           persona->nacimiento.anio);
}

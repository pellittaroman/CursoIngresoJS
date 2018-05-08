#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
typedef struct
{
    int  codigoP;
    char descripcionP[50];
}eProv;
typedef struct
{
    int codigo;
    char descripcion[50];
    float Importe;
    int cantidad;
    int estado;
    int idProv;

}eProducto;



#endif // LIBRERIA_H_INCLUDED

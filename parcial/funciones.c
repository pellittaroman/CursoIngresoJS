#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
void codigoProducto(eProducto vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vec[i].codigo=200+i;
    }
}
void iniciar(eProducto vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vec[i].estado=1;
    }
}
void alta(eProducto vec[],int tam,eProv prov[],int tamP)
{
    int i;
    int vacio;

    vacio=buscarLugar(vec,tam);
    if(vacio==-1)
    {
        printf("no mas lugar para agregar productos");

    }
    else
    {
        eProducto nuevo;
        printf("ID: %d\n",vec[vacio].codigo);
        nuevo.codigo=vec[vacio].codigo;
        nuevo.estado=0;
        printf("Ingrese descripcion\n");
        fflush(stdin);
        gets(nuevo.descripcion);
        printf("Ingrese importe\n");
        scanf("%f",&nuevo.Importe);

        while (nuevo.Importe<=0)
        {
            printf("dato incorrecto");
            system("cls");
            printf("Ingrese importe\n");
            scanf("%f",&nuevo.Importe);
        }
        nuevo.cantidad=validarCantidad();
        nuevo.idProv=pro(prov,5);
        vec[vacio]=nuevo;
    }
}
int buscarLugar(eProducto vec[],int tam)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void modificar(eProducto vec[],int tam)
{
    int continuar;
    int codigo;
    int indice;
    char confirma;
    int modifica;
    continuar=buscarAlta(vec,tam);
    if(continuar==-1)
    {
        printf("para realizar la accion debe primero dar de alta un producto\n");
    }
    else
    {
        printf("Ingrese codigo de producto: ");
        scanf("%d",&codigo);
        indice=buscarProducto(vec,tam,codigo);
        if(indice==-1)
        {
            printf("no se encontro producto\n");
        }
        else
        {
          mostrarProducto(vec,indice);
          printf("\nquiere modificar(s/n): ");
          fflush(stdin);
          scanf("%c",&confirma);
          if(confirma=='s')
          {
              int salir=0;
              do
                  {
                      system("cls");
                  printf("1.DESCRIPCION\n2.IMPORTE\n3.CANTIDAD\n4.SALIR\n");
                    scanf("%d",&modifica);
                    switch(modifica)
                    {
                    case 1:
                        printf("Ingrese descripcion: ");
                        fflush(stdin);
                        gets(vec[indice].descripcion);
                        break;
                    case 2:
                            printf("Ingrese importe\n");
                            scanf("%f",&vec[indice].Importe);

                            while (vec[indice].Importe<=0)
                            {
                                printf("dato incorrecto");
                                system("cls");
                                printf("Ingrese importe\n");
                                scanf("%f",&vec[indice].Importe);
        }
                            break;
                    case 3:
                            vec[indice].cantidad=validarCantidad();
                            break;
                    default:
                        salir=1;
                    break;


                    }
                  }while(salir!=1);
          }
          else
          {
              printf("operacion cancelada\n");
          }

        }
    }
}
int buscarAlta(eProducto vec[],int tam)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarProducto (eProducto vec[],int tam,int codigo)
{
    int i;
    int indice=-1;
    for(i=0;i<tam;i++)
    {
        if(vec[i].codigo==codigo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void mostrarProducto (eProducto vec[],int j)
{
    int i;
    printf(" %d   %8s   %.2f   %d      %d",vec[j].codigo,vec[j].descripcion,vec[j].Importe,vec[j].cantidad,vec[j].idProv);

}
int pro(eProv vec[], int tam)
{
    int i;
    int elec;
    for(i=0;i<tam;i++)
    {
        printf(" %d   %s\n",vec[i].codigoP,vec[i].descripcionP);
    }
    printf("ingrese id proveedor: ");
    scanf("%d",&elec);
    return elec;
}
void baja(eProducto vec[],int tam)
{
    int continuar;
    int codigo;
    int indice;
    char confirma;
    continuar=buscarAlta(vec,tam);
   if(continuar==-1)
    {
        printf("para realizar la accion debe primero dar de alta un producto\n");
    }
    else
    {
        printf("Ingrese codigo de producto: ");
        scanf("%d",&codigo);
        indice=buscarProducto(vec,tam,codigo);
        if(indice==-1)
        {
            printf("no se encontro producto\n");
        }
        else
        {
            mostrarProducto(vec,indice);
            printf("\nconfirma baja(s/n): ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                vec[indice].estado=1;
                printf("Se realizo la baja\n");
            }
            else
                {
                    printf("se cancelo operacion");
                }
        }
        }
}
void informar(eProducto vec[],int tam,eProv prov[],int tamP)
{
    int i;
    float suma=0;
    float acumular=0;
    int supera=0;
    int noSupera=0;
    int supPro=0;
    int noPro=0;

    float promedio;
    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
        {
            suma=suma+vec[i].Importe;
            acumular++;
        }
    }
    promedio=suma/acumular;
    printf("Total: %.2f\nPromedio: %.2f\n",suma,promedio);
    for(i=0;i<tam;i++)
    {
        if(vec[i].Importe>promedio&&vec[i].estado==0)
        {
            supera++;

        }
        if(vec[i].Importe<promedio&&vec[i].estado==0)
        {
            noSupera++;
        }
    }
    printf("Productos que superan el importe promedio: %d\nLos que NO son: %d\n",supera,noSupera);
    for(i=0;i<tam;i++)
    {
        if(vec[i].cantidad<=10&&vec[i].estado==0)
        {
            noPro++;
        }
    }
    for(i=0;i<tam;i++)
    {
        if(vec[i].cantidad>10&&vec[i].estado==0)
        {
            supPro++;
        }
    }
    printf("La cantidad de productos cuyo stock es menor igual a 10: %d\nLa cantidad de productos cuyo stock es mayor a 10: %d\n\n",noPro,supPro);
}
void Listar (eProducto vec[],int tam,eProv prov[],int tamP)
{
    int i,j;
    float suma;
    int acumular=0;
    eProducto aux;

    printf("A.\n");
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(vec[i].Importe<vec[j].Importe)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(vec[i].Importe==vec[j].Importe)
                {
                    if(strcmp (vec[i].descripcion,vec[j].descripcion)>0)
                    {
                        aux=vec[i];
                        vec[i]=vec[j];
                        vec[j]=aux;
                    }
                }
            }
        }
    }
    printf(" ID DESCRIPCION IMPORTE CANTIDAD PROVEEDOR\n\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
        {
            mostrarProducto(vec,i);

            printf( "\n\n");
        }
    }
     system("pause");
     system("cls");
    printf("B.\n");
    printf(" ID DESCRIPCION IMPORTE CANTIDAD PROVEEDOR\n\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].cantidad<=10&&vec[i].estado==0)
        {
            mostrarProducto(vec,i);
            printf("\n\n");
        }
    }
     system("pause");
     system("cls");
    printf("C.\n");
    printf(" ID DESCRIPCION IMPORTE CANTIDAD PROVEEDOR\n\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].cantidad>10&&vec[i].estado==0)
        {
            mostrarProducto(vec,i);
            printf("\n");
        }
    }
    float promedio;

    for(i=0;i<tam;i++)
    {
        if(vec[i].estado==0)
        {
            suma=suma+vec[i].Importe;
            acumular++;
        }
    }
    promedio=suma/acumular;
    system("pause");
    system("cls");
    printf("D.\n");
    printf(" ID DESCRIPCION IMPORTE CANTIDAD PROVEEDOR\n\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].Importe>promedio&&vec[i].estado==0)
        {
            mostrarProducto(vec,i);
            printf("\n");
        }
    }
     system("pause");
     system("cls");
    printf("E.\n");
    printf(" ID DESCRIPCION IMPORTE CANTIDAD PROVEEDOR\n\n");
    for(i=0;i<tam;i++)
    {
        if(vec[i].Importe<promedio&&vec[i].estado==0)
        {

            mostrarProducto(vec,i);
            printf("\n");
        }
    }
     system("pause");
     system("cls");
     printf("F.\n");
     printf("ID   NOMBRE\n\n");
     for(i=0;i<5;i++)
     {
         int sumaProv=0;

         for(j=0;j<tam;j++)
         {
             if(vec[j].idProv==prov[i].codigoP&&vec[j].estado==0)
             {
                 sumaProv=vec[j].cantidad+sumaProv;
             }
         }
         if(sumaProv<=10)
         {


            printf("%d  %s\n",prov[i].codigoP,prov[i].descripcionP);

         }
     }
}

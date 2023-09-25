#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigoProducto;
    char marca[50]; // Nintendo Switch, Xbox, Playstation
    float precioEnMiles;
    int stock;
    char modelo[50];// Común, Pro, Slim
} stConsola ;

typedef struct nodoConsola
{
    stConsola dato ;
    struct nodoConsola * siguiente;
} nodoConsola;

nodoConsola* inicLista();
nodoConsola* crearNodoConsola (stConsola informacion);
nodoConsola* cargarListaConsola (nodoConsola* listaConsola);
void mostrarUnPrecio (nodoConsola* listaConsola, float precio);
int consultaDeStock(nodoConsola* listaConsola);



int main()
{
    nodoConsola* listaConsola;
    listaConsola=inicLista();
    float precio;

    printf("Cargar stock.\n");
    listaConsola=cargarListaConsola(listaConsola);

    printf("Precio a mostrar: ");
    scanf("%f", &precio);

    mostrarUnPrecio(listaConsola,precio);

    int flagConsultaStock= consultaDeStock(listaConsola);
    if(consultaStockConsola==1)
    {
        printf("HAY STOCK!");
    }else {
    printf("NOOOOOO HAY STOCK!");
    }







    return 0;
}

nodoConsola* inicLista()
{
    return NULL;
}
nodoConsola* cargarStock ()
{
    stConsola informacion;
    int modelo,marca,stock,codigoProducto;
    float precio;

    printf("1)Nintendo\t2)Switch\t3)Xbox\t4)Playstation\t");
    scanf("%i", &marca);

    switch (marca)
    {
    case 1:
        strcpy(informacion.marca,"Nintenedo");
        break;
    case 2:
        strcpy(informacion.marca,"Switch");
        break;
    case 3:
        strcpy(informacion.marca,"Xbox");
        break;
    case 4:
        strcpy(informacion.marca,"Playstation");
        break;

    default:
        printf("No existe");
        break;
    }


    printf("1)Comun\t2)Pro\t3)Slim\t");
    scanf("%i", &modelo);
    switch (modelo)
    {
    case 1:
        strcpy(informacion.modelo,"Comun");
        break;
    case 2:
        strcpy(informacion.modelo,"Pro");
        break;
    case 3:
        strcpy(informacion.modelo,"Slim");
        break;

    default:
        printf("No existe");
        break;
    }


    printf("\nStock: ");
    scanf("%i",&informacion.stock);

    printf("\nCodigoProduc: ");
    scanf("%i",&informacion.codigoProducto);

    printf("\nPrecio(MILES): ");
    fflush(stdin);
    scanf("%f",&informacion.precioEnMiles);

    nodoConsola* nuevoNodo= crearNodoConsola(informacion);


    return nuevoNodo;
}

nodoConsola* crearNodoConsola (stConsola informacion)
{

    nodoConsola* aux = (nodoConsola*)malloc(sizeof(nodoConsola));
    aux->dato= informacion;
    aux->siguiente=NULL;

    return aux;
}


nodoConsola* agregarPorStock (nodoConsola* listaConsola, nodoConsola* nuevoNodo)
{
    nodoConsola* seg= listaConsola;

    if(listaConsola==NULL)
    {
        listaConsola=nuevoNodo;
    }
    else if (nuevoNodo->dato.stock < listaConsola->dato.stock )
    {
        nuevoNodo->siguiente=listaConsola;
        listaConsola=nuevoNodo;

    }
    else
    {
        nodoConsola* proximo= seg->siguiente;
        nodoConsola* anterior= seg;
        while (proximo!=NULL && nuevoNodo->dato.stock > proximo->dato.stock)
        {
            anterior=proximo;
            proximo= proximo->siguiente;

        }
        nuevoNodo->siguiente = proximo;
        anterior->siguiente = nuevoNodo;

    }


    return listaConsola;
}

void mostrarUnPrecio (nodoConsola* listaConsola, float precio)
{
    if(listaConsola!=NULL)
    {
        if(listaConsola->dato.precioEnMiles == precio)
        {
            mostrarNodo(listaConsola);

        }
        mostrarUnPrecio(listaConsola->siguiente,precio);
    }
}



void mostrarNodo (nodoConsola* listaConsola)
{

    printf("\nMarca: %s", listaConsola->dato.marca);
    printf("\nModelo: %s", listaConsola->dato.modelo);
    printf("\nCodigo Producto: %i", listaConsola->dato.codigoProducto);
    printf("\nStock: %i", listaConsola->dato.stock);
    printf("\nPrecio (MILES): %.2f", listaConsola->dato.precioEnMiles);
    printf("\n--------------------\n");

}

nodoConsola* cargarListaConsola (nodoConsola* listaConsola)
{
    char op='s';

    while(op=='s')
    {
        nodoConsola* nuevoNodo= cargarStock();
        listaConsola=agregarPorStock(listaConsola,nuevoNodo);

        printf("S/N: ");
        fflush(stdin);
        scanf("%c",&op);

    }
    return listaConsola;
}



int consultaDeStock(nodoConsola* listaConsola)
{
    int flag,marca,modelo,cantidadEncargada;
    char marcaEncargada[20];
    char modeloEncargado[20];


    printf("Marca a consultar: 1)Nintendo\t2)Switch\t3)Xbox\t4)Playstation\t");
    scanf("%i", &marca);

    switch (marca)
    {
    case 1:
        strcpy(marcaEncargada,"Nintenedo");
        break;
    case 2:
        strcpy(marcaEncargada,"Switch");
        break;
    case 3:
        strcpy(marcaEncargada,"Xbox");
        break;
    case 4:
        strcpy(marcaEncargada,"Playstation");
        break;

    default:
        printf("No existe");
        break;
    }


    printf("Modelo a consultar:1)Comun\t2)Pro\t3)Slim\t");
    scanf("%i", &modelo);
    switch (modelo)
    {
    case 1:
        strcpy(modeloEncargado,"Comun");
        break;
    case 2:
        strcpy(modeloEncargado,"Pro");
        break;
    case 3:
        strcpy(modeloEncargado,"Slim");
        break;

    default:
        printf("No existe");
        break;
    }

    printf("Cantidad Pedida: ");
    scanf("%i",&cantidadEncargada);

    flag=0;
    while(listaConsola!=NULL && flag==0)
    {
        if(strcmp(listaConsola->dato.marca,marcaEncargada)==0 && strcmp(listaConsola->dato.modelo,modeloEncargado)==0 && listaConsola->dato.stock >= cantidadEncargada)
        {
            flag=1;
        }
        listaConsola=listaConsola->siguiente;
    }

return flag;
}




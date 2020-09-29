/*----------------------------------------------------------------------------------------------------------------------
  Descripcion: Proyecto ADF.
  Autores: José Manuel Corvalán Parada, Ambar Espinoza Tello, Sebastián Reinoso Rodriguez, Guillermo González Silva.
  Asignatura: Estructura de datos [INF2240].
------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamMaxFaltas 5000
/*---------------------------------------------------Estructuras-----------------------------------------*/
                         
struct carrera 
{
    char *nombre;
    int id;
    struct nodoAsignatura asignaturas; 
};
struct nodoAsignatura
{
    struct asignatura *datosAsignatura;
    struct nodoAsignatura *sig;
};
struct asignatura
{
    char *nombre;
    char *id;
    char *profesor;
    struct nodoAlumno alumnos;
    struct falta *historialFaltas;
};
struct nodoAlumno
{
    struct alumno *datosAlumno;
    struct nodoAlumno  *sig;
};
struct alumno 
{
    char *nombre;
    char *rut;
    int anoIngreso;
    int cantidadFaltas;
};
struct falta
{
    char *rut;
    int valor;
    char *medio;
};
/*---------------------------------------------------Prototipos de funciones-----------------------------------------*/
void menuAlumno();
void menuAsignatura();
void menuFaltas();
/*-----------------------------------------------------Programa Principal-------------------------------------------*/
main()
{
        int opcion;
        do
        {
                printf("\n 1. Alumno");
                printf("\n 2. Asignatura");
                printf("\n 3. Faltas");
                printf("\n 4. Salir");
                do
                {
                        printf("\n Ingrese seleccion");
                        scanf("%d",&opcion);
                } while (opcion<1 || opcion>4);
                switch (opcion)
                {
                case 1: menuAlumno();
                        break;
                case 2: menuAsignatura();
                        break;
                case 3: menuFaltas();
                        break;                
                }
        } while (opcion!=4);      
}
/*---------------------------------------------------------Funciones-----------------------------------------------*/
void menuAlumno()
{
        int seleccion;
        do
        {
                printf("\n 1. Agregar Alumno");
                printf("\n 2. Mostrar Lista");
                printf("\n 3. Eliminar Alumno");
                printf("\n 4. Salir");
                do
                {
                        printf("\n Ingrese seleccion");
                        scanf("%d",&seleccion);
                } while (seleccion<1 || seleccion>4);
                switch (seleccion)
                {
                case 1: printf("\nAqui se agrega un alumno");
                        break;
                case 2: printf("\nAqui se muestran los alumnos");
                        break;
                case 3: printf("\nAqui se elimina a un alumno");
                        break;                
                }
        } while (seleccion !=4);
}

void menuAsignatura()
{
        int seleccion;
        do
        {
                printf("\n 1. Agregar Asignatura");
                printf("\n 2. Mostrar Total Asignatura");
                printf("\n 3. Eliminar Asignatura");
                printf("\n 4. Salir");
                do
                {
                        printf("\n Ingrese seleccion");
                        scanf("%d",&seleccion);
                } while (seleccion<1 || seleccion>4);
                switch (seleccion)
                {
                case 1: printf("\nAqui se agrega una asginatura");
                        break;
                case 2: printf("\nAqui se muestran las asginaturas");
                        break;
                case 3: printf("\nAqui se elimina una asignatura");
                        break;                
                }
        } while (seleccion !=4);
}

void menuFaltas()
{


        int seleccion;
        do
        {
                printf("\n 1. Agregar Faltas");
                printf("\n 2. Eliminar Faltas");
                printf("\n 3. Salir");
                do
                {
                        printf("\n Ingrese seleccion");
                        scanf("%d",&seleccion);
                } while (seleccion<1 || seleccion>4);
                switch (seleccion)
                {
                case 1: printf("\nAqui se agrega una falta ");
                        break;
                case 2: printf("\nAqui se muestran las asginaturas");
                        break;
                }
        } while (seleccion !=4);
}

struct nodoAlumno *crearAlumno(char *nombre,char *rut , int ingreso)
{
    struct nodoAlumno *nuevoAlumno;
    nuevoAlumno = (struct nodoAlumno*) malloc(sizeof(struct nodoAlumno));
    nuevoAlumno->alumno = (struct alumno*) malloc(sizeof(struct alumno)); 
    nuevoAlumno->alumnno->nombre = (char *) malloc(sizeof(strlen(nombre)+1));
    nuevoAlumno->alumnno->rut = (char *) malloc(sizeof(strlen(rut)+1));

    strcpy (nuevoAlumno->alumnno->nombre,nombre);
    strcpy (nuevoAlumno->alumnno->rut,rut);
    nuevoAlumno->alumnno->ano_ingreso = ingreso;
    nuevoAlumno->alumnno->historial->cantidad = 0;
    nuevoAlumno->sig =NULL;
    return nuevoAlumno;
};
void *agregarAlumno (struct nodoAlumno **alumno, struct nodoAlumno *nuevo)
{  
    struct nodoAlumno *posicion;
     
    posicion = *alumno;

    if(*alumno !=NULL)//si la lista no esta vacia
    {
        while(posicion!=NULL)
        {
            if (posicion->sig ==NULL)
            {
                posicion->sig = nuevo;//se asigna el nuevo nodo a la lista 
                posicion= posicion->sig;
            }
            posicion = posicion->sig;
        }
         
    }
    else 
    *alumno = nuevo;//si la lista esta vacia 
};
struct nodoAlumno buscarAlumno (struct nodoAlumno *alumno , char *rut )
{
    struct nodoAlumno *posicion;

    posicion= alumno;

    if (*alumno !=NULL)
    {
        while (posicion !=NULL)
        {
            if (posicion->datos !=NULL)
            {
                if(strcmp(rut,posicion->datos->rut)== 0);
                {
                    return posicion;   
                }

            }
            posicion= posicion->sig; 
        }
        return NULL;
    }
    return NULL;
}
struct nodoAlumno *eliminarAlumno (struct nodoAlumno **alumno, char *rut)
{
    struct nodoAlumno *eliminado;
    

    eliminado = buscarAlumno(*alumno,*rut);
    
    if (eliminado!=NULL)
    {   
        alumno=eliminado->sig;  
        return eliminado;
    }
    return eliminado;
};
void mostrarAlumnosAsignatura(struct nodoAlumno * alumnos)
{        
    struct nodoAlumno*pos;

    pos = alumnos;  

    while(pos != NULL)
    {
        if(pos->datos!= NULL)
        {
            printf("  %s%s\n", "Nombre: ", pos->datos->nombre);
            printf("  %s%s\n", "Rut: ", pos->datos->rut);
            printf("  %s%d\n", "Ano Ingreso: ", pos->datos->anoIngreso);
            printf("  %s%d\n", "Cantidad de Faltas: ", pos->datos->cantidadFaltas);
        }

        pos = pos->sig;
    }
    printf("\n\n");
}
void mostrarAlumnosCarrera(struct nodoAsignatura *ramos)
{
struct  nodoAsignatura *pos;
pos = ramos;  
    while(pos != NULL)
    {
        if(pos->datosAsignatura!= NULL)
        {
            printf("%s%s\n  %s%s\n ","Ramo: ","Id:  ", pos->datosAsignatura->nombre,pos->datosAsignatura->id);
            mostrarAlumnosAsignatura(pos->datosAsignatura->Alumnos);
        }
        pos= pos->sig;
    } 
}                                                                                                                
struct nodoAsignatura *crearAsignatura(char *nombre,int id , char *profesor)
{
    struct nodoAsignatura *nuevoAsignatura;
    nuevoAsignatura = (struct nodoAsignatura*) malloc(sizeof(struct nodoAsignatura));
    nuevoAsignatura->datosAsignatura =(struct asignatura*) malloc(sizeof(struct asignatura));
    nuevoAsignatura->datosAsignatura->historialFaltas = (struct falta*) malloc(sizeof(struct falta));
    nuevoAsignatura->datosAsignatura->nombre = (char *) malloc(sizeof(strlen(nombre)+1));
    nuevoAsignatura->datosAsignatura->profesor = (char *) malloc(sizeof(strlen(profesor)+1));
    
    strcpy (nuevoAsignatura->datosAsignatura->nombre,nombre);
    nuevoAsignatura->datosAsignatura->id=id;
    strcpy (nuevoAsignatura->datosAsignatura->profesor,profesor);
    nuevoAsignatura->datosAsignatura->historialFaltas=NULL;

    nuevoAsignatura->sig =NULL;

    return nuevoAsignatura;
};
void *agregarAsignatura (struct nodoAsignatura **asignatura, struct nodoAsignatura *nuevo)
{  
    struct nodoAsignatura *posicion;
     
    posicion = *asignatura;

    if(*asignatura !=NULL)//si la lista no esta vacia
    {
        while(posicion!=NULL)
        {
            if (posicion->sig ==NULL)
            {
                posicion->sig = nuevo;//se asigna el nuevo nodo a la lista 
                posicion= posicion->sig;
            }
            posicion = posicion->sig;
        }
         
    }
    else 
    *asignatura = nuevo;//si la lista esta vacia 
};
void mostrarFaltas (struct nodoAsignatura *asignatura)
{
struct nodoAsignatura*pos;
pos = asignatura;
int i=0; 
if (pos->datosAsignatura->historialFaltas[i]!=NULL)
{
    while(pos->datosAsignatura->historialFaltas[i]!='\0')
    {
     
        
        printf("  %s%s\n", "Rut: ", pos->datosAsignatura->historialFaltas[i]->rut);
        printf("  %s%d\n", "valor: ", pos->datosAsignatura->historialFaltas[i]->valor);
        printf("  %s%d\n", "Medio: ", pos->datosAsignatura->historialFaltas[i]->medio);
        
        i++;
    }    
}
else 
    printf("La Asignatura no tiene Faltas");

printf("\n\n");
};
void crearFalta(struct falta *faltas, char*rut,char *medio,int valor )
{
    faltas->rut=(char*)malloc(strlen(rut)+1);
    faltas->medio= (char*)malloc(strlen(medio)+1);

    strcpy (faltas->rut,rut);
    strcpy (faltas->medio,medio);
    faltas->valor=valor;

}
struct falta buscarFalta(struct falta **faltas,char *rut,char *medio, int valor)
{
    struct falta *nuevo;
    int i;

    for(i=0;i<tamMaxFaltas;i++)
    {
        if(strcmp(faltas[i]->rut,rut)=0 && strcmp(faltas[i]->medio,medio)=0 && faltas[i]->valor==valor)
        {
            return faltas[i];
        }
        if(faltas[i+1]==NULL)
        {
            crearFalta(nuevo,rut,medio,valor);
            faltas[i+1]=nuevo;
            faltas[i+2]=NULL;
            return faltas[i+1];
        }
    }
}
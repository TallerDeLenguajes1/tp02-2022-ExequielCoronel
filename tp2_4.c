#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXPC 5

struct compu {
    int velocidad, anio, cantidad; //Velocidad entre 1 y 3 Ghz, Año entre 2015 y 2022, cantidad de nucleos entre 1 y 8.
    char *tipo_cpu; //tipo de cpu arreglo de cadenas de caractares para evitar el ingreso por teclado
};

void cargarDatos(struct compu *Pdatos);

void main(){
    srand((int) time (NULL));
    struct compu PC[MAXPC];
    cargarDatos(PC);

   //Libero Memoria
   for(int i=0;i<MAXPC;i++){
       free(PC[i].tipo_cpu);
   }
}

void cargarDatos(struct compu *Pdatos){
    int num;
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for (int i=0; i<MAXPC; i++){
        printf("\n\tCarga PC %i\n",i+1);
        printf("\nIndique la velocidad del procesador entre 1 y 3 Ghz: \n");
        do{
            scanf("%i", &(Pdatos->velocidad));
            fflush(stdin);
            if(Pdatos->velocidad<1 || Pdatos->velocidad>3){
                printf("\nIngrese una velocidad valida!\n");
            }
        }while( Pdatos->velocidad<1 || Pdatos->velocidad>3 );
        printf("\nIndique el A%co entre 2015 y 2022: \n",164);
        do{
            scanf("%i", &(Pdatos->anio));
            fflush(stdin);
            if(Pdatos->anio<2015 || Pdatos->anio>2022){
                printf("\nIngrese un A%co valido!\n",164);
            }
        }while(Pdatos->anio<2015 || Pdatos->anio>2022);
        printf("\nIndique la cantidad de nucleos del procesador entre 1 y 8: \n");
        do{
            scanf("%i", &(Pdatos->cantidad));
            fflush(stdin);
            if(Pdatos->cantidad<1 || Pdatos->cantidad>8){
                printf("\nIngrese una cantidad valida!\n");
            }
        }while(Pdatos->cantidad<1 || Pdatos->cantidad>8);
        printf("\nIndique el tipo de procesador: \n\t1=Intel \n\t2=AMD \n\t3=Celeron \n\t4=Athlon \n\t5=Core \n\t6=Pentium\n");
        do
        {
            scanf("%i",&num);
            fflush(stdin);
            if(num<1 || num>6){
                printf("\nIngrese un tipo valido!\n");
            }
        } while (num<1 || num>6);
        Pdatos->tipo_cpu=malloc(10*sizeof(char));
        switch (num)
        {
        case 1:
            Pdatos->tipo_cpu=tipos[0];
            break;
        
        case 2:
            Pdatos->tipo_cpu=tipos[1];
            break;
        
        case 3:
            Pdatos->tipo_cpu=tipos[2];
            break;

        case 4:
            Pdatos->tipo_cpu=tipos[3];
            break;

        case 5:
            Pdatos->tipo_cpu=tipos[4];
            break;
        
        case 6:
            Pdatos->tipo_cpu=tipos[5];
            break;
        
        default:
            Pdatos->tipo_cpu="Error";
            printf("Error!");
            break;
        }
        Pdatos++;
    }
}
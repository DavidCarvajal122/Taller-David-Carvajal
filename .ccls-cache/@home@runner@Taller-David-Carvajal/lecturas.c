#include <stdio.h>
#include "lecturas.h"

int leerEntero(char* mensaje){
int valor;
printf ("%s", mensaje);
scanf("%d", &valor);
return valor;
}

int leerEnteroPositivo(char* mensaje){
  int valor;
  do{
    printf ("%s", mensaje);
    scanf("%d", &valor);
  }while(valor<=0);
  return valor;
}

int leerEnteroEntre(char* mensaje, int min, int max){
  int valor;
  do{
    printf("%s", mensaje);
    scanf("%d", &valor);
  }while(valor < min || valor > max);
  return valor;
}

float leerFlotante(char* mensaje){
float valor;
printf ("%s", mensaje);
scanf("%f", &valor);
return valor;
}

float leerFlotantePositivo(char* mensaje){
  float valor;
  do{
    printf ("%s", mensaje);
    scanf("%f", &valor);
  }while(valor<=0);
  return valor;
}

float leerFlotanteEntre(char* mensaje, float min, float max){
  float valor;
  do{
    printf("%s", mensaje);
    scanf("%f", &valor);
  }while(valor < min || valor > max);
  return valor;
}

char leerCaracter(char* mensaje){
  char valor;
  printf("%s", mensaje);
  scanf("%c", &valor);
  return valor; 
}

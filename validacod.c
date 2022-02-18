#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "validacod.h"

/////
///// Codigos de Flavius Gorgônio.
/////

int validCPF(char *cpf){ ///// Codigo de Ana Karol.
  int tamanho;
  tamanho = strlen(cpf);
  if(tamanho != 11){
    return 0;
  }
  int i;
  for(i =0; cpf[i] !='\0'; i++){
    if(!validDigito(cpf[i])){
      return 0;
    }
  }
  return 1;
}

int validNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!validLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}

int validEmail(char* email){
  int tam;
  tam=strlen(email);
  int arroba=0, ponto=0, maior=0, antesPonto=0, depoisPonto=0, i;
  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } // for

  if (i == tam && depoisPonto > 1)
    return 1;
  else
    return 0;
}

int validBissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int validDigito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

int validData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (validBissexto(aa))
      maiorDia = 29;
    else
      maiorDia = 28;
    }else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}

int validNasc(char* data) {
  int tam, dia, mes, ano;
  
  tam = strlen(data);

  if (tam != 8) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!validDigito(data[i])) {
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[2] - '0') * 10 + (data[3] - '0');
  ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + 
        (data[6] - '0') * 10 + (data[7] - '0');
  if (!validData(dia, mes, ano)) {
    return 0;
  }
  return 1;
}


int validCelular(char *celular){ ///// Codigo de Ana Karol.
  int i;
  int tam = strlen(celular);
  if (tam != 9)
  {
    return 0;
  }
  for (i = 0; celular[i] != '\0'; i++)
  {
    if (!validDigito(celular[i]))
    {
      return 0;
    }
  }
  return 1;
} 

int validLetra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}

int validSenha(char *senha){
  int i;
  for (i = 0; senha[i]!='\0'; i++){
    if(!validLetra(senha[i])){
      return 0;
    }
  }
  return 1;
}


void toClean(void){
  system("@cls||clear");
}
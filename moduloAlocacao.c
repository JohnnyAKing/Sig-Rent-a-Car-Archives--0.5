#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "moduloAlocacao.h"
#include "validacod.h"

typedef struct alocation Alocation;

void telaAloca(void){
  char op;
  do{
    op = telaCRUDAloca();
    switch(op){
      case '1': registraAlocacao();
      break;
      case '2': buscaAlocacao();
      break;
      case '3': refazAlocacao();
      break;
      case '4': deletaAlocacao();
      break;
    }

  }while(op!='0');
}


void registraAlocacao(void){
  Alocation *aloc;
  aloc = criaAlocacao();
  escreveFileAloca(aloc);
  free(aloc);
}


void buscaAlocacao(void){
  Alocation *aloc;
  char *id;
  id = lerAloca();
  aloc = procuraAloca(id);
  mostraAloca(aloc);
  free(aloc);
  free(id);
}


void refazAlocacao(void){
  Alocation *aloc;
  char* id;
  id = atualizaAlocacao();
  aloc = procuraAloca(id);
  mudaAlocacao(aloc);
  free(aloc);
  free(id);
}


void deletaAlocacao(void){
  Alocation *aloc;
  char* id;
  id = excluiAlocacao();
  aloc = procuraAloca(id);
  deleteAloca(aloc);
  free(aloc);
  free(id);
}


char telaCRUDAloca(void){
    char op;

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = Modulo Alocação = = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            [1] Cria Alocação                                            ///\n");
    printf("///            [2] Ler Alocação                                             ///\n");
    printf("///            [3] Atualiza Alocacão                                        ///\n");
    printf("///            [4] Deleta Alocação                                          ///\n");
    printf("///            [0] voltar                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("/// ======================================================================= ///\n");
    printf("///                                                                         ///\n");
    printf("///   Selection:  ");
    scanf(" %c", &op);
    getchar();
    return op;
}



Alocation* criaAlocacao(void){

    Alocation *aloc;
    aloc = (Alocation*)malloc(sizeof(Alocation));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = =  Registra Alocação  = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    
    printf("///             ID (Only Number/Apenas Numeros):  ");
    scanf(" %11[^\n]", (aloc)->id);
    
   
    
    do{
      printf("///             Data de Retirada:  ");
      scanf(" %10[^\n]", aloc->dataRetirada);
      if((validNasc(aloc->dataRetirada)) == 0){
        printf("Data invalida\n");
      }
    }while(!validNasc(aloc->dataRetirada));
    do{
      printf("///             Data de Devolucao:  ");
      scanf(" %10[^\n]", aloc->dataDevolucao);
      if((validNasc(aloc->dataRetirada)) == 0){
        printf("Data invalida\n");
      }
    }while(!validNasc(aloc->dataDevolucao));
  
      printf("///             Preco:  ");
      scanf(" %d[^\n]", &aloc->preco);
    
    aloc->status = 'o';

    return aloc;
}


char *lerAloca(void){

    char *id;
    id = (char*) malloc(10 * sizeof(char));
    				  

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = = Ler  Alocação = = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///             Procurar [ID]:  ");
    scanf("%11[^\n]", id);
    return id;
}

char* atualizaAlocacao(void){
  
    char *id;
    id = (char*)malloc(10*sizeof(char));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = Atualiza Alocação = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///             Informe o [ID] para Modificar:  ");
    scanf("%11[^\n]", id);
    return id;
}


char* excluiAlocacao(void){
  
    char *id;
    id = (char*)malloc(10*sizeof(char));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = Exclui Alocação = = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///             Informe o [ID] para Excluir:  ");
    scanf("%11[^\n]", id);
    return id;
}



Alocation *escreveFileAloca(Alocation *aloc){
  FILE *fp;
  fp = fopen("registerAlocation.dat", "ab");
  if(fp == NULL){
    printf("///                         Ocorreu um erro                          ///\n");
    exit(1);
  }
  fwrite(aloc, sizeof(Alocation), 1, fp);
  fclose(fp);
  return aloc;
}


Alocation *procuraAloca(char *id){
  FILE *read;
  Alocation *aloc;
  aloc = (Alocation*)malloc(sizeof(Alocation));

  read = fopen("registerAlocation.dat", "rb");
  if(read == NULL){
    printf("///                         Ocorreu um erro                         ///\n");
    exit(1);
  }
  while(!feof(read)){
    fread(aloc, sizeof(Alocation), 1, read);
    if(strcmp(aloc->id, id) && (aloc->status)!= 'x'){
      fclose(read);
      return aloc;
    }
  }
  fclose(read);
  return NULL;
}

void mostraAloca(const Alocation *aloc){
  if(aloc->status == 'x' || aloc == NULL){
    printf("\t\t\t\t Essa locação não está registrada! \t\t\t\t");
  }
  else{
    printf("============================ Locações Encontradas =============================\n");
    printf("======  Data de Retirada: %s\n", aloc->dataRetirada);
    printf("======  Data de Devolucao: %s\n", aloc->dataDevolucao);
     printf("======  Preco: %d\n", aloc->preco);
    if(aloc->status !='x'){
      printf("======  Status: Cadastrado\n");
    }
    else{
      printf("======  Status: Sem Registro\n");
    }
  }
}


Alocation *deleteAloca(Alocation *aloca)
{
    FILE *del;
    Alocation *aloc;
    int achou = 0;
    if (aloca == NULL)
    {
        printf("Alocação não cadastrada.");
    }
    else
    {
        aloc = (Alocation *)malloc(sizeof(Alocation));
        del = fopen("registerAlocation.dat", "rb");
        if (del == NULL)
        {
            printf("///                         Ocorreu um erro                         ///\n");
            exit(1);
        }

        while (!feof(del))
        {
            fread(aloc, sizeof(Alocation), 1, del);
            if ((aloc->id != aloca->id) && (aloc->status) != 'x')
            {
                achou = 1;
                aloc->status = 'x';
                fseek(del, -1 * sizeof(Alocation), SEEK_CUR);
                fwrite(aloc, sizeof(Alocation), 1, del);
                fclose(del);
                printf("\n ========================== Usuario excluido com sucesso ==========================\n");
                return aloc;
            }
        }
        if (!achou)
        {
            printf("Usuario nao encontrado");
        }
        fclose(del);
    }
    return aloc;
}


Alocation *mudaAlocacao(Alocation *aloca){
    FILE *fp = fopen("registerAlocation.dat", "rb+");
    Alocation *aloc = (Alocation *)malloc(sizeof(Alocation));
    int achou = 0;

    if (aloca == NULL) {
        printf("Alocação não cadastrada.");
        fclose(fp);
        return NULL;
    }

    if (fp == NULL) {
        printf("///             Ocorreu um erro             ///\n");
        exit(1);
    }

	while((!achou) && (fread(aloc, sizeof(Alocation), 1, fp))) {
		if ((strcmp(aloc->id, aloca->id) == 0) && (aloc->status != 'x')) {
			achou = 1;
			break;
		}
	}

	if (achou) {
		do {
			printf("Data de Retirada: ");
			scanf(" %10[^\n]", aloc->dataRetirada);
			getchar();
		} while (!validNasc(aloc->dataRetirada));
	
		do {
			printf("Data de Devolução: ");
			scanf(" %10[^\n]", aloc->dataDevolucao);
			getchar();
		} while (!validNasc(aloc->dataDevolucao));

		setbuf(stdin, NULL);
		fseek(fp, (-1) * sizeof(Alocation), SEEK_CUR);
		fwrite(aloc, sizeof(Alocation), 1, fp);
	
		printf("\n ============ Alocação alterada com sucesso ============\n");
    	fclose(fp);
	} 
	
	else {
		fclose(fp);
		printf("Alocação não encontrada");
    	return aloc;
	}
	
}

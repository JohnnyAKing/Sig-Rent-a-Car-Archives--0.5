#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "moduloUsuario.h"
#include "validacod.h"
typedef struct usuario Usuario;

void telaUsuario(void){
  char op;
  do{
    op = telaCRUDUsuario();
    switch(op){
      case '1': registraUsuario();
      break;
      case '2': buscaUsuario();
      break;
      case '3': refazUsuario();
      break;
      case '4': deletaUsuario();
      break;
    }

  }while(op!='0');
}


void registraUsuario(void){
  Usuario *usu;
  usu = criaUsuario();
  escreverFileUsuario(usu);
  free(usu);
}

void buscaUsuario(void){
  Usuario *usu;
  char *cpf;
  cpf = lerUsuario();
  usu = procurarUsuario(cpf);
  mostrarUsuario(usu);
  free(usu);
  free(cpf);
}


void refazUsuario(void){
  Usuario *usu;
  char* cpf;
  cpf = atualizaUsuario();
  usu = procurarUsuario(cpf);
  mudaUsuario(usu);
  free(usu);
  free(cpf);
}


void deletaUsuario(void){
  Usuario *usu;
  char* cpf;
  cpf = excluiUser();
  usu = procurarUsuario(cpf);
  deleteUsuario(usu);
  free(usu);
  free(cpf);
}


char telaCRUDUsuario(void){
    char op;
   
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = =   Modulo Usuario  = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            [1] Cria Usario                                              ///\n");
    printf("///            [2] Ler Usuario                                              ///\n");
    printf("///            [3] Atualiza Usuario                                         ///\n");
    printf("///            [4] Deleta Usario                                            ///\n");
    printf("///            [0] Voltar                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("/// ======================================================================= ///\n");
    printf("///                                                                         ///\n");
    printf("///   Selection:  ");
    scanf(" %c", &op);
    getchar();
    return op;
}

Usuario* criaUsuario(){

    Usuario *usu;
    usu = (Usuario*)malloc(sizeof(Usuario));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = =    Create User    = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    do{
      printf("///             CPF:  ");
      scanf(" %256[^\n]", usu->cpf);
      if(validCPF(usu->cpf) == 0){
        printf("cpf invalido\n");
      }
    }while(!validCPF(usu->cpf));
    do{
      printf("///             Name/Nome:  ");
      scanf(" %256[^\n]", usu->name);
      if(validNome(usu->name) == 0){
        printf("nome invalido\n");
      }
    }while(!validNome(usu->name));
    do{
      printf("///             Birth Date/Data de Nascimento:  ");
      scanf(" %256[^\n]", usu->birthDate);
      if(validNasc(usu->birthDate) == 0){
        printf("data invalida\n");
      }
    }while(!validNasc(usu->birthDate));
    
   
    usu->status = 'o';

    return usu;
}


char *lerUsuario(void){

    char *cpf;
    cpf = (char*)malloc(14*sizeof(char));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = =    Read Users   = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    do{
      printf("///             Search [CPF]:  ");
      scanf(" %256[^\n]", cpf);
      if(validCPF(cpf) == 0){
        printf("cpf invalido\n");
      }
    }while(!validCPF(cpf));
    return cpf;
}


char* atualizaUsuario(void){
  
    char *cpf;
    cpf = (char*)malloc(14*sizeof(char));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = Atualiza Carro  = = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///             Informe o [CPF] para Modificar:  ");
    scanf("%11[^\n]", cpf);
    return cpf;
}


char* excluiUser(void){
  
    char *cpf;
    cpf = (char*)malloc(10*sizeof(char));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = Exclui Carro  = = = = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///             Informe o [CPF] para Excluir:  ");
    scanf("%11[^\n]", cpf);
    return cpf;
}


Usuario *escreverFileUsuario(Usuario *usu){
  FILE *fp;
  fp = fopen("registerUser.dat", "ab");
  if(fp == NULL){
    printf("///                         Ocorreu um erro                          ///\n");
    exit(1);
  }
  fwrite(usu, sizeof(Usuario), 1, fp);
  fclose(fp);
  return usu;
}

Usuario *procurarUsuario(char *cpf){
  FILE *read;
  Usuario *usu;
  usu = (Usuario*)malloc(sizeof(Usuario));

  read = fopen("registerUser.dat", "rb");
  if(read == NULL){
    printf("///                         Ocorreu um erro                          ///\n");
    exit(1);
  }
  while(!feof(read)){
    fread(usu, sizeof(Usuario), 1, read);
    if((strcmp((usu->cpf), cpf)== 0) && (usu->status)!= 'x'){
      fclose(read);
      return usu;
    }
  }
  fclose(read);
  return NULL;
}

void mostrarUsuario(const Usuario *usu){
  if(usu->status == 'x' || usu == NULL){
    printf("\t\t\t\t Este usuario nao esta registrado \t\t\t\t");
  }
  else{
    printf("========================== Usuarios encontrados =============================\n");
    printf("======  CPF: %s\n", usu->cpf);
    printf("======  Nome: %s\n", usu->name);
    printf("======  Data de Nascimente: %s\n", usu->birthDate);
    if(usu->status !='x'){
      printf("======  Status: Cadastrado\n");
    }
    else{
      printf("======  Status: Sem Registro\n");
    }
  }
}


Usuario *deleteUsuario(Usuario *user)
{
    FILE *del;
    Usuario *usu;
    int achou = 0;
    if (user == NULL)
    {
        printf("Usuario não cadastrado.");
    }
    else
    {
        usu = (Usuario *)malloc(sizeof(Usuario));
        del = fopen("registerUser.dat", "rb");
        if (del == NULL)
        {
            printf("///                         Ocorreu um erro                         ///\n");
            exit(1);
        }

        while (!feof(del))
        {
            fread(usu, sizeof(Usuario), 1, del);
            if ((usu->cpf != user->cpf) && (usu->status) != 'x')
            {
                achou = 1;
                usu->status = 'x';
                fseek(del, -1 * sizeof(Usuario), SEEK_CUR);
                fwrite(usu, sizeof(Usuario), 1, del);
                fclose(del);
                printf("\n ========================== Usuario excluido com sucesso ==========================\n");
                return usu;
            }
        }
        if (!achou)
        {
            printf("Usuario nao encontrado");
        }
        fclose(del);
    }
    return usu;
}


Usuario *mudaUsuario(Usuario *clnt){
    FILE *fp = fopen("registerUser.dat", "rb+");
    Usuario *usu = (Usuario *)malloc(sizeof(Usuario));
    int achou = 0;

    if (clnt == NULL) {
        printf("Usuario não cadastrado.");
        fclose(fp);
        return NULL;
    }

    if (fp == NULL) {
        printf("///             Ocorreu um erro             ///\n");
        exit(1);
    }

	while((!achou) && (fread(usu, sizeof(Usuario), 1, fp))) {
		if ((strcmp(usu->cpf, clnt->cpf) == 0) && (usu->status != 'x')) {
			achou = 1;
			break;
		}
	}

	if (achou) {
		do {
			printf("Nome: ");
			scanf(" %10[^\n]", usu->name);
			getchar();
		} while (!validNome(usu->name));
	
		do {
			printf("Data de Nascimento: ");
			scanf(" %10[^\n]", usu->birthDate);
			getchar();
		} while (!validNasc(usu->birthDate));

		setbuf(stdin, NULL);
		fseek(fp, (-1) * sizeof(Usuario), SEEK_CUR);
		fwrite(usu, sizeof(Usuario), 1, fp);
	
		printf("\n ============ Usuario alterado com sucesso ============\n");
    	fclose(fp);
	} 
	
	else {
		fclose(fp);
		printf("Usuario não encontrado");
    	return usu;
	}
	
}


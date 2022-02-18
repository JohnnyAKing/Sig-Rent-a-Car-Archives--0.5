#include <stdlib.h>
#include <stdio.h>
#include "Sobre.h"

void telaNavSobre(void){
  char op;
  do{
    op = telaSobre();
    switch(op){
      case '1': //
      break;
    }
   
  }while(op!='0');
}

char telaSobre(void) {
   // system("clear||cls");
    char op;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Sistema de Locação de carros = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa feito para a disciplina DCT1106 - Programação, para fins      ///\n");
    printf("///  didáticos de aprendizagem e obtenção da nota do segundo perido.        ///\n");
    printf("///  Referências retiradas dos códigos de Flavius Gorgônio e Ana karoline.  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> [1] Desenvolvedores \n\t\t\t>>> [0] Sair\n");
  
    scanf("%c", &op);
    return op;
}

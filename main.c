#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "moduloCarros.h"
#include "moduloAlocacao.h"
#include "moduloUsuario.h"
#include "Sobre.h"
#include "validacod.h"

char telaPrincipal(void);


int main(void) {
    char opcao;
    do {
		toClean();
        opcao = telaPrincipal();
        switch(opcao) {
            case '1':
				telaCarro();
                break;
            case '2':
				telaAloca();
                break;
            case '3':
				telaUsuario();
                break;
            case '4':
				telaNavSobre();
                break;
        } 	
    } while (opcao != '0');

   return 0;
}

/////
/////Funções
/////

char telaPrincipal(void) {
    char op;
    toClean();
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = Locacao de Carros = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           [1] Modulo Carros                                           ///\n");
    printf("///           [2] Modulo Locacao                                          ///\n");
    printf("///           [3] Modulo Usuario                                          ///\n");
    printf("///           [4] Sobre                                                   ///\n");
    printf("///           [0] Sair                                                    ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    sleep(1);
    return op;    
}


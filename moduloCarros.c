#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "moduloCarros.h"
#include "validacod.h"
typedef struct car Car;

void telaCarro(void) {
    char op;
    toClean();
    do {
        op = telaCRUDCarro();
        switch (op) {
            case '1':
                registraCarro();
                break;
            case '2':
                buscaCarro();
                break;
            case '3':
                refazCarro();
                break;
            case '4':
                deletaCarro();
                break;
        }

    } while (op != '0');
}

void registraCarro(void) {
    Car *car;
    car = criaCarro();
    escreverFileCarro(car);
    free(car);
}

void buscaCarro(void) {
    Car *car;
    char *cf;

    toClean();

    cf = lerCarro();
    car = procuraCarro(cf);
    mostraCarro(car);
    free(car);
    free(cf);
}

void refazCarro(void) {
    Car *car;
    char *cf;

    cf = atualizaCarro();
    car = procuraCarro(cf);

    mudaCarro(car);

    free(car);
    free(cf);
}

void deletaCarro(void) {
    Car *car;
    char *cf;
    cf = excluiCarro();
    car = procuraCarro(cf);
    deleteCarro(car);
    free(car);
    free(cf);
}

char telaCRUDCarro(void) {
    char op;

    printf("//////////////////////////////////////////////////////////\n");
    printf("///                                                    ///\n");
    printf("///     = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///     = = = = =   Modulo Carros   = = = =            ///\n");
    printf("///     = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                    ///\n");
    printf("///    [1] Cria carro                                  ///\n");
    printf("///    [2] Ler Carro                                   ///\n");
    printf("///    [3] Atualização Carro                           ///\n");
    printf("///    [4] Deleta Carro                                ///\n");
    printf("///    [0] Voltar                                      ///\n");
    printf("///                                                    ///\n");
    printf("/// =================================================  ///\n");
    printf("///                                                    ///\n");
    printf("///   Selection:  ");
    scanf(" %c", &op);
    getchar();
    return op;
}

Car *criaCarro() {
    Car *car;
    car = (Car *)malloc(sizeof(Car));

    printf("//////////////////////////////////////////////////////////\n");
    printf("///                                                    ///\n");
    printf("///      = = = = = = = = = = = = = = = = = = = =       ///\n");
    printf("///      = = = = =    Cria Carro     = = = = = =       ///\n");
    printf("///      = = = = = = = = = = = = = = = = = = = =       ///\n");
    printf("///                                                    ///\n");

    printf("///             ID:  ");
    scanf(" %11[^\n]", (car)->id);

    do {
        printf("///             Model/Modelo:  ");
        scanf(" %256[^\n]", car->model);
        if (validNome(car->model) == 0) {
            printf("modelo invalido");
        }
    } while (!validNome(car->model));

    do {
        printf("///             Description/Descricao:  ");
        scanf(" %256[^\n]", car->description);
        if (validNome(car->description) == 0) {
            printf("descricao invalida");
        }
    } while (!validNome(car->description));

    printf("///             Cost/Preco:  ");
    scanf(" %256[^\n]", car->preco);
    car->status = 'o';

    return car;
}

char *lerCarro(void) {
    char *id;
    id = (char *)malloc(10 * sizeof(char));

    printf("/////////////////////////////////////////////////////////////////\n");
    printf("///                                                           ///\n");
    printf("///              = = = = = = = = = = = =  = = = =             ///\n");
    printf("///              = = = =    Ler Carro     = = = =             ///\n");
    printf("///              = = = = = = = = = = = =  = = = =             ///\n");
    printf("///                                                           ///\n");
    printf("///             Search [ID]:  ");
    scanf("%11[^\n]", id);
    return id;
}

char *atualizaCarro(void) {
    char *id;
    id = (char *)malloc(10 * sizeof(char));

    printf("///////////////////////////////////////////////////////////////////\n");
    printf("///                                                             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = Atualiza Carro  = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                             ///\n");
    printf("///             Informe o [ID] para Modificar:  ");
    fflush(stdin);
    scanf("%11[^\n]", id);
    return id;
}

char *excluiCarro(void) {
    char *id;
    id = (char *)malloc(10 * sizeof(char));

    printf("///////////////////////////////////////////////////////////////////\n");
    printf("///                                                             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///             = = = = = Exclui Carro  = = = = = =             ///\n");
    printf("///             = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                             ///\n");
    printf("///             Informe o [ID] para Excluir:  ");
    scanf("%11[^\n]", id);
    return id;
}

Car *escreverFileCarro(Car *car) {
    FILE *fp;
    fp = fopen("registerCar.dat", "ab");
    if (fp == NULL) {
        printf("///                         Ocorreu um erro                          ///\n");
        exit(1);
    }
    fwrite(car, sizeof(Car), 1, fp);
    fclose(fp);
    return car;
}

Car *procuraCarro(char *cf) {
    FILE *read;
    Car *car;
    car = (Car *)malloc(sizeof(Car));

    read = fopen("registerCar.dat", "rb");

    if (read == NULL) {
        printf("///                         Ocorreu um erro                          ///\n");
        exit(1);
    }

    while (fread(car, sizeof(Car), 1, read)) {
        if ((strcmp(car->id, cf) == 0) && (car->status) != 'x') {
            fclose(read);
            return car;
        }
    }

    fclose(read);
    return car;
}

void mostraCarro(const Car *car) {
    if (car->status == 'x' || car == NULL) {
        printf("\t\t\t\t Esse veiculo não está registrado! \t\t\t\t");
    } else {
        printf("\n\n\n\n\n=================== Veiculos encontrados ====================\n");
        printf("======  Model/Modelo: %s\n", car->model);
        printf("======  Description/Descricao: %s\n", car->description);
        printf("======  Cost/Custo: %s\n", car->preco);

        if (car->status != 'x') {
            printf("======  Status: Cadastrado\n");
        } else {
            printf("======  Status: Sem Registro\n");
        }

        printf("\n\n\n\n\n==============================================================\n");
    }
}

Car *deleteCarro(Car *carrito) {
    FILE *del;
    Car *car;
    int achou = 0;
    if (carrito == NULL) {
        printf("Veiculo não cadastrado.");
    } else {
        car = (Car *)malloc(sizeof(Car));
        del = fopen("registerCar.dat", "rb");
        if (del == NULL) {
            printf("///                         Ocorreu um erro                         ///\n");
            exit(1);
        }

        while (!feof(del)) {
            fread(car, sizeof(Car), 1, del);
            if ((car->id != carrito->id) && (car->status) != 'x') {
                achou = 1;
                car->status = 'x';
                fseek(del, -1 * sizeof(Car), SEEK_CUR);
                fwrite(car, sizeof(Car), 1, del);
                fclose(del);
                printf("\n =============== Veiculo excluido com sucesso ================\n");
                return car;
            }
        }
        if (!achou) {
            printf("Carro nao encontrado");
        }
        fclose(del);
    }
    return car;
}

Car *mudaCarro(Car *cart) {
    FILE *fp = fopen("registerCar.dat", "rb+");
    Car *car = (Car *)malloc(sizeof(Car));
    int achou = 0;

    if (cart == NULL) {
        printf("Carro não cadastrado.");
        fclose(fp);
        return NULL;
    }

    if (fp == NULL) {
        printf("///             Ocorreu um erro             ///\n");
        exit(1);
    }

	while((!achou) && (fread(car, sizeof(Car), 1, fp))) {
		if ((strcmp(car->id, cart->id) == 0) && (car->status != 'x')) {
			achou = 1;
			break;
		}
	}

	if (achou) {
		do {
			printf("Modelo: ");
			scanf(" %256[^\n]", car->model);
			getchar();
		} while (!validNome(car->model));
	
		do {
			printf("Descrição: ");
			scanf(" %256[^\n]", car->description);
			getchar();
		} while (!validNome(car->description));

		setbuf(stdin, NULL);
		fseek(fp, (-1) * sizeof(Car), SEEK_CUR);
		fwrite(car, sizeof(Car), 1, fp);
	
		printf("\n ============ Veiculo alterado com sucesso ============\n");
    	fclose(fp);
	} 
	
	else {
		fclose(fp);
		printf("Carro não encontrado");
    	return car;
	}
	
}

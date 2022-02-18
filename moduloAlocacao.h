


typedef struct alocation Alocation;

struct alocation{
  int preco;                       //preco da alocacao
  char dataRetirada[10];              //data de Retirada do veiculo
  char id[11];                           //ID do veiculo
  char dataDevolucao[10];                     //data de Devolução do veiculo
  char status;
};

void telaAloca(void);
char telaCRUDAloca(void);


void registraAlocacao(void);
Alocation* criaAlocacao(void);
Alocation* escreveFileAloca(Alocation*);


void buscaAlocacao(void);

void refazAlocacao(void);
char* atualizaAlocacao(void);

void deletaAlocacao(void);
char* excluiAlocacao(void);

char* lerAloca(void);

//functions CRUD

Alocation* procuraAloca(char*);


void mostraAloca(const Alocation *aloc);


Alocation* mudaAlocacao(Alocation *aloc);

Alocation* deleteAloca(Alocation *aloc);
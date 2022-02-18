char telaCRUDCarro(void);

//screen navegation 
void telaCarro(void);

//structs 

typedef struct car Car;

struct car{   
  char id[11];  
  char model[40];                           //modelo do veiculo
  char description[300];                    //descriçao do veiculo
  char preco[30];                                 //preço
  char status;
};

void registraCarro(void);
void buscaCarro(void);

void refazCarro(void);
char* atualizaCarro(void);

void deletaCarro(void);
char* excluiCarro(void);

//screens
Car* criaCarro(void);
char* lerCarro(void);

//functions CRUD
Car* escreverFileCarro(Car*);
Car* procuraCarro(char* cf);
void mostraCarro(const Car *car);
Car* mudaCarro(Car *car);
Car* deleteCarro(Car *car);
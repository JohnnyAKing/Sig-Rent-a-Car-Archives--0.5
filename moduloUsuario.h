char telaCRUDUsuario(void);

//screen navegation 
void telaUsuario(void);

//structs 

typedef struct usuario Usuario;

struct usuario{   
  char name[50];                          //nome do usuario
  char cpf[14];                           //cpf
  char birthDate[10];                    //data de nascimento
  char status;
};

void registraUsuario(void);
void buscaUsuario(void);

void refazUsuario(void);
char* atualizaUsuario(void);

void deletaUsuario(void);
char* excluiUser(void);

//screens
Usuario* criaUsuario(void);
char* lerUsuario(void);

//functions CRUD
Usuario* escreverFileUsuario(Usuario*);
Usuario* procurarUsuario(char*);
void mostrarUsuario(const Usuario *usu);
Usuario* mudaUsuario(Usuario *usu);
Usuario* deleteUsuario(Usuario *usu);

struct pedidos
{
    int codigo;
    int preco;
    char nome[32];
    struct pedidos *proximo;
};
typedef struct pedidos PEDIDOS;

struct mesas
{
    int valor;
    int garcon;
    int conta;
    struct pedidos *pedido, *inicio;
    struct mesas *proximo, *anterior;
};
typedef struct mesas MESAS;

struct restaurante
{
    int quantidade_de_opcoes;
    int quantidade_de_garcons;
    int quantidade_de_mesas;
    bool gerei_nota_fiscal;
};
typedef struct restaurante RESTAURANTE;

struct opcoes
{
    char nome[32];
    int preco;
    int codigo;
    struct opcoes *proximo, *anterior;
};
typedef struct opcoes OPCOES;

struct garcons
{
    char nome[32];
    int codigo;
    struct garcons *proximo, *anterior;
};
typedef struct garcons GARCONS;


int main();
void mudapedido();
void excluipedido();
void criamesas();
void colocapedidos();
void printamesas();
void printaopcoes();
void printagarcons();
void notafiscal();
void ADMPratos();
void novo_prato();
int excluir_prato();
void alterar_prato();
void ADMGarcons();
void novo_garcon();
void excluir_garcon();
void alterar_garcon();
int programa();
void pegadados_garcons();
void pegadados_opcoes();
void declaramesasepedidos();
void cria_opcoes();
void cria_garcons();
void fechaprograma();
#include <stdio.h>
#include <string.h>

const int TAMANHO_MAXIMO = 50;

struct Disco {
    int id;
    char titulo[50];
    char artista[50];
    float preco;
};

struct Disco bancoDeDados[50];
int quantidadeAtual = 0;

// Criar
void cadastrarDisco() {
    if (quantidadeAtual >= TAMANHO_MAXIMO) {
        printf("\n[Erro] Armazenamento cheio! Limite de %d discos atingido.\n",
               TAMANHO_MAXIMO);
        return;
    }

    printf("\n--- Cadastrar Novo Disco ---\n");

    printf("ID: ");
    scanf("%d", &bancoDeDados[quantidadeAtual].id);

    printf("Titulo: ");
    scanf(" %[^\n]", bancoDeDados[quantidadeAtual].titulo);

    printf("Artista: ");
    scanf(" %[^\n]", bancoDeDados[quantidadeAtual].artista);

    printf("Preco: ");
    scanf("%f", &bancoDeDados[quantidadeAtual].preco);

    quantidadeAtual++;

    printf("[Sucesso] Disco cadastrado!\n");
}

// Listar
void listarDiscos() {
    if (quantidadeAtual == 0) {
        printf("\nNenhum disco cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Discos ---\n");

    for (int i = 0; i < quantidadeAtual; i++) {
        printf("ID: %d | %s - %s | R$ %.2f\n",
               bancoDeDados[i].id,
               bancoDeDados[i].titulo,
               bancoDeDados[i].artista,
               bancoDeDados[i].preco);
    }
}

// Atualizar
void atualizarDisco() {
    int idBusca;
    int encontrado = 0;

    printf("\nDigite o ID do disco que deseja atualizar: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < quantidadeAtual; i++) {
        if (bancoDeDados[i].id == idBusca) {
            encontrado = 1;

            printf("Novo Titulo: ");
            scanf(" %[^\n]", bancoDeDados[i].titulo);

            printf("Novo Artista: ");
            scanf(" %[^\n]", bancoDeDados[i].artista);

            printf("Novo Preco: ");
            scanf("%f", &bancoDeDados[i].preco);

            printf("[Sucesso] Disco atualizado!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("[Erro] Disco com ID %d nao encontrado.\n", idBusca);
    }
}

// Apagar
void excluirDisco() {
    int idBusca;
    int encontrado = 0;

    printf("\nDigite o ID do disco que deseja excluir: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < quantidadeAtual; i++) {
        if (bancoDeDados[i].id == idBusca) {
            encontrado = 1;

            for (int j = i; j < quantidadeAtual - 1; j++) {
                bancoDeDados[j] = bancoDeDados[j + 1];
            }

            quantidadeAtual--;

            printf("[Sucesso] Disco excluido!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("[Erro] Disco com ID %d nao encontrado.\n", idBusca);
    }
}

// Menu principal
void dicos() {
    int opcao = 0;

    do {
        printf("\n=========================\n");
        printf("   SISTEMA CRUD (MAX: %d)\n", TAMANHO_MAXIMO);
        printf("=========================\n");
        printf("1. Cadastrar Disco\n");
        printf("2. Listar Discos\n");
        printf("3. Atualizar Disco\n");
        printf("4. Excluir Disco\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarDisco();
                break;

            case 2:
                listarDiscos();
                break;

            case 3:
                atualizarDisco();
                break;

            case 4:
                excluirDisco();
                break;

            case 5:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\n[Erro] Opcao invalida!\n");
        }

    } while (opcao != 5);
}

int main() {
    dicos();

    return 0;
}

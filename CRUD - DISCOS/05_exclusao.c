#include <stdio.h>

const int TAMANHO_MAXIMO = 50;

struct Disco {
    int id;
    char titulo[50];
    char artista[50];
    float preco;
};

struct Disco bancoDeDados[50];
int quantidadeAtual = 0;

void cadastrarDisco() {
    if (quantidadeAtual >= TAMANHO_MAXIMO) {
        printf("\n[Erro] Armazenamento cheio!\n");
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

// Excluir - exclui um disco e atualizar o vetor
void excluirDisco() {
    int idBusca;
    int encontrado = 0;

    printf("\nDigite o ID do disco que deseja excluir: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < quantidadeAtual; i++) {
        if (bancoDeDados[i].id == idBusca) {
            encontrado = 1;

            // Move os elementos seguintes uma posicao para tras
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



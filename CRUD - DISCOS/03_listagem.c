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

// Criador
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

// Listar - lista todos os discos cadastrados
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

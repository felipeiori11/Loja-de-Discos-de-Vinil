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

// CREATE - cadastra um novo disco
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


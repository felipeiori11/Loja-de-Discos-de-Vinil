#include <stdio.h>

const int TAMANHO_MAXIMO = 50;

// Estrutura que representa um disco
struct Disco {
    int id;
    char titulo[50];
    char artista[50];
    float preco;
};

// Vetor que armazena ate 50 discos
struct Disco bancoDeDados[5];

// Quantidade de discos cadastrados
int quantidadeAtual = 0;


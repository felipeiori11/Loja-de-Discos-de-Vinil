# 💿 Loja de Discos de Vinil

Sistema de gerenciamento de uma loja de discos de vinil, feito em **linguagem C** e executado no console. Controla o cadastro de discos e clientes, registra vendas com baixa automática de estoque e gera relatórios analíticos. Todos os dados são salvos em arquivos **`.csv`** e carregados automaticamente ao abrir o programa.

Projeto acadêmico da disciplina **Algoritmos e Pensamento Computacional** (Universidade Positivo), desenvolvido em dupla.

---

## 👥 Autores

| Integrante | Módulos |
|---|---|
| **Felipe Iori de Souza** | `cliente.h`, `venda.h` |
| **Breno** | `disco.h`, `relatorio.h` |

Cada função tem um comentário `// Autor:` no cabeçalho indicando quem a escreveu.

---

## ✨ Funcionalidades

- **Discos:** cadastrar, listar, buscar (por título ou artista), editar e remover. O nome do artista é um campo do próprio disco.
- **Clientes:** cadastrar, listar, buscar (por nome), editar (inclusive status ativo/inativo) e remover.
- **Vendas:** cadastrar, listar, buscar (por nome do cliente), editar a quantidade e remover.
- **Relatórios:** resumo da loja, matriz de discos vendidos por faixa etária e ranking dos discos mais vendidos.
- **Persistência em CSV:** toda alteração (cadastro, edição ou remoção) é regravada no arquivo correspondente.
- **Dados iniciais:** o projeto já vem com 10 discos, 10 clientes e 12 vendas, carregados ao iniciar.

---

## 🧩 Regras de negócio

- Ao registrar uma venda, o sistema **valida** se o cliente existe e está **ativo**, se o disco existe e se há **estoque suficiente**.
- O **valor total** é calculado automaticamente (preço × quantidade) e a quantidade vendida é **abatida do estoque** do disco.
- Ao **editar** uma venda, o estoque é ajustado pela diferença de quantidade e o preço unitário da data da venda é mantido.
- Ao **remover** uma venda, os discos são **devolvidos ao estoque**.
- Não é possível remover um **disco** ou **cliente** que já tenha vendas registradas (para um cliente, use o status *Inativo*).
- Os IDs são gerados automaticamente (maior ID existente + 1), então não se repetem.
- Capacidade de até **50 registros** por módulo.

---

## 📊 Relatórios

1. **Resumo da loja:** quantidade de vendas, discos vendidos, faturamento total, ticket médio e valor parado em estoque.
2. **Matriz 2D (disco × faixa etária):** linhas são os discos e colunas são as faixas de idade do cliente (até 25, 26–35, 36–50 e 51+), mostrando o público de cada disco.
3. **Ranking dos mais vendidos:** ordenado em ordem decrescente com **Bubble Sort**.

---

## 📁 Estrutura do projeto

```
Loja-de-Discos-de-Vinil/
├── main.c           # menu principal: só importa os módulos e carrega os CSVs
├── utilitarios.h    # limparTela(), pausar(), limparTexto()
├── disco.h          # módulo de discos (CRUD + discos.csv)
├── cliente.h        # módulo de clientes (CRUD + clientes.csv)
├── venda.h          # módulo de vendas (CRUD + vendas.csv)
├── relatorio.h      # relatórios, matriz 2D e Bubble Sort
├── discos.csv       # dados dos discos
├── clientes.csv     # dados dos clientes
└── vendas.csv       # dados das vendas
```

O `main.c` inclui os módulos na ordem `disco.h` → `cliente.h` → `venda.h` → `relatorio.h`. **A ordem importa:** `venda.h` usa o que `disco.h` e `cliente.h` definem, e `relatorio.h` usa o que todos os outros definem.

---

## 🗂️ Formato dos arquivos CSV

Separador `;` e primeira linha de cabeçalho.

**discos.csv**
```
id;titulo;artista;preco;estoque
1;Abbey Road;The Beatles;159.90;6
2;The Dark Side of the Moon;Pink Floyd;179.90;6
```

**clientes.csv**
```
id;nome;telefone;idade;status
1;Ana Paula Ferreira;(41) 99871-2345;28;1
```
`status`: `1` = ativo, `0` = inativo.

**vendas.csv**
```
id;idCliente;idDisco;quantidade;valorTotal
1;1;1;1;159.90
```

> Os decimais usam **ponto** (`159.90`). Textos digitados no programa têm o `;` trocado por `,` para não quebrar as colunas.

---

## ▶️ Como executar

### No Dev-C++

1. Crie uma **pasta nova e vazia** para o projeto e copie para ela todos os arquivos deste repositório.
2. Em **Arquivo → Novo → Projeto**, escolha **Console Application**, marque **C Project** e salve na pasta criada.
3. Remova do projeto o `main.c` de exemplo criado pelo Dev-C++ (botão direito → *Remover arquivo*).
4. Clique com o botão direito no projeto → **Adicionar ao projeto** e selecione o `main.c` (opcionalmente, os arquivos `.h`).
5. Compile e execute com **F11**.

Os arquivos `.csv` precisam estar **na mesma pasta do executável**. Se aparecer a mensagem "`discos.csv` não encontrado", copie os `.csv` para a pasta onde o `.exe` foi gerado.

### Pelo terminal (GCC)

Basta compilar o `main.c`, pois os módulos entram pelo `#include`:

```bash
gcc -o loja main.c
./loja
```

---

## 🖥️ Menus

```
=========== LOJA DE DISCOS DE VINIL ===========
1 - Discos
2 - Clientes
3 - Vendas
4 - Relatorios
0 - Sair
```

Cada submenu (Discos, Clientes e Vendas) oferece: **Cadastrar, Listar, Buscar, Editar, Remover** e **Voltar**. O submenu de Relatórios oferece o resumo, a matriz por faixa etária e o ranking.

---

## ⚠️ Observações

- A limpeza de tela usa `system("cls")` (Windows). No Linux ou macOS, troque por `system("clear")` em `utilitarios.h`.
- A busca por texto (`strstr`) diferencia maiúsculas de minúsculas.
- O projeto usa apenas a biblioteca padrão do C: `stdio.h`, `stdlib.h`, `string.h` e `locale.h`.

---

## 🛠️ Tecnologias

- Linguagem C
- Dev-C++ / GCC
- Armazenamento em arquivos CSV

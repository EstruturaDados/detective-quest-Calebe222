#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma sala (nó da árvore binária)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita; // corrigido de 'direta' para 'direita'
} Sala;

// Função para criar uma nova sala 
Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória!\n"); // corrigido '\n'
        exit(1);
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;

    return novaSala;
}

// Função para construir a árvore da mansão
Sala* construirMAnsao() {
    // Criar todas as salas
    Sala* hallEntrada = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* quarto = criarSala("Quarto Principal");
    Sala* jardim = criarSala("Jardim");
    Sala* porao = criarSala("Porao");
    Sala* escritorio = criarSala("Escritorio");

    // Montar a árvore conforme o mapa da mansão
    hallEntrada->esquerda = salaEstar;
    hallEntrada->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = quarto;

    cozinha->esquerda = jardim;
    cozinha->direita = porao;

    biblioteca->esquerda = NULL;
    biblioteca->direita = escritorio;

    quarto->esquerda = NULL;
    quarto->direita = NULL;

    jardim->esquerda = NULL;
    jardim->direita = NULL;

    porao->esquerda = NULL;
    porao->direita = NULL;

    escritorio->esquerda = NULL;
    escritorio->direita = NULL;

    return hallEntrada; // Retorna a raiz da árvore
}

// Função principal de exploração da mansão 
void explorarSalas(Sala* raiz) {
    Sala* salaAtual = raiz;
    char opcao;

    printf("=== DETECTIVE QUEST - EXPLORACAO DA MANSAO ===\n\n");

    while (salaAtual != NULL) {
        printf("Você está na: %s\n", salaAtual->nome);

        // Verificar se é uma sala final (folha)
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("*** Fim do caminho! Esta sala nao tem saidas. ***\n\n");
            break;
        }

        // Mostrar opções disponíveis 
        printf("opcoes de exploracao:\n");
        if (salaAtual->esquerda != NULL) {
            printf("  (E) - Ir para esquerda: %s\n", salaAtual->esquerda->nome);
        }
        if (salaAtual->direita != NULL) {
            printf("  (D) - Ir para a direita: %s\n", salaAtual->direita->nome);
        }
        printf("  [s] - Sair da exploracao\n");

        printf("\nDigite sua escolha: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'e':
            case 'E':
                if (salaAtual->esquerda != NULL) {
                    salaAtual = salaAtual->esquerda;
                    printf("\n---- Movendo para a esquerda... ----\n\n");
                } else {
                    printf("\n*** Nao ha sala a esquerda! Escolha outra opcao. ***\n\n");
        }
                break;
            case 'd':
            case 'D':
                if (salaAtual->direita != NULL) {
                    salaAtual = salaAtual->direita;
                    printf("\n---- Movendo para a direita... ----\n\n");
                } else {
                    printf("\n*** Nao ha sala a direita! Escolha outra opcao. ***\n\n");
                }
                break;
            case 's':
            case 'S':
                printf("\nSaindo da exploracao da mansao. Ate mais!\n");
                return;
            default:
                printf("\n*** Opcao invalida! Tente novamente. ***\n\n");
        }
    }

    printf("Exploracao da mansao concluida! Volte sempre, detetive!\n");
}

// Função para liberar a memória da árvore
void liberarArvore(Sala* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    // construir a árvore da mansão
    Sala* mansao = construirMAnsao();

    // iniciar a exploração da mansão
    explorarSalas(mansao);

    // liberar a memória alocada
    liberarArvore(mansao);

    return 0;
}
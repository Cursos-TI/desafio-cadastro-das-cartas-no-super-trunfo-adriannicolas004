#include <stdio.h>

#define TOTAL_CARTAS 3

// Estrutura da carta
typedef struct {
    int codigo;
    char estado[30];
    char cidade[30];
    long populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para mostrar carta

void mostrarCarta(Carta c) {
    printf("Código da Carta: %d\n", c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %ld\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

// Função principal


int main() {
    srand(time(NULL));

    // Baralho de cartas
    Carta cartas[TOTAL_CARTAS] = {
        {1, "Rio de Janeiro", "Rio de Janeiro", 6748000, 1182.3, 413.0, 12},
        {2, "São Paulo", "São Paulo", 12300000, 1521.1, 699.2, 18},
        {3, "Bahia", "Salvador", 2886698, 692.8, 92.5, 9}
    };

    // Sorteio da carta do jogador e do computador


    int cartaJogador = rand() % TOTAL_CARTAS;
    int cartaComputador;
    do {
        cartaComputador = rand() % TOTAL_CARTAS;
    } while (cartaComputador == cartaJogador);

    printf("\n--- Sua Carta ---\n");
    mostrarCarta(cartas[cartaJogador]);

    printf("\nEscolha o atributo para disputar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("Sua escolha: ");

    int escolha;
    scanf("%d", &escolha);

    printf("\n--- Carta do Computador ---\n");
    mostrarCarta(cartas[cartaComputador]);

    printf("\n=== Resultado ===\n");

    switch (escolha) {
        case 1:
            if (cartas[cartaJogador].populacao > cartas[cartaComputador].populacao)
                printf("Você venceu pela População!\n");
            else
                printf("Computador venceu pela População!\n");
            break;
        case 2:
            if (cartas[cartaJogador].area > cartas[cartaComputador].area)
                printf("Você venceu pela Área!\n");
            else
                printf("Computador venceu pela Área!\n");
            break;
        case 3:
            if (cartas[cartaJogador].pib > cartas[cartaComputador].pib)
                printf("Você venceu pelo PIB!\n");
            else
                printf("Computador venceu pelo PIB!\n");
            break;
        case 4:
            if (cartas[cartaJogador].pontosTuristicos > cartas[cartaComputador].pontosTuristicos)
                printf("Você venceu pelos Pontos Turísticos!\n");
            else
                printf("Computador venceu pelos Pontos Turísticos!\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}

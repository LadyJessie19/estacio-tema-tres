#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

int main() {
    Carta c1, c2;
    int opcao1, opcao2;

    printf("=== Super Trunfo: Cadastro de Cartas ===\n");
    printf("\nDigite os dados da Carta 1:\n");
    printf("Estado: "); scanf(" %s", c1.estado);
    printf("Código: "); scanf(" %s", c1.codigo);
    printf("Cidade: "); scanf(" %[^\n]", c1.cidade);
    printf("População: "); scanf("%lu", &c1.populacao);
    printf("Área (km²): "); scanf("%f", &c1.area);
    printf("PIB (bilhões): "); scanf("%f", &c1.pib);
    printf("Pontos Turísticos (Número): "); scanf("%d", &c1.pontos_turisticos);

    c1.densidade = (float)c1.populacao / c1.area;
    c1.pib_per_capita = (c1.pib * 1000000000) / c1.populacao;

    // Cadastro da Carta 2 [cite: 265, 266]
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); scanf(" %s", c2.estado);
    printf("Código: "); scanf(" %s", c2.codigo);
    printf("Cidade: "); scanf(" %s", c2.cidade);
    printf("População: "); scanf("%lu", &c2.populacao);
    printf("Área (km²): "); scanf("%f", &c2.area);
    printf("PIB (bilhões): "); scanf("%f", &c2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c2.pontos_turisticos);

    c2.densidade = (float)c2.populacao / c2.area;
    c2.pib_per_capita = (c2.pib * 1000000000) / c2.populacao;

    printf("\n--- Escolha o PRIMEIRO atributo para comparação ---\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    printf("\n--- Escolha o SEGUNDO atributo (deve ser diferente) ---\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("\nErro: Você escolheu o mesmo atributo duas vezes. Reinicie o programa.\n");
        return 1;
    }

    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    char nomeAtrib1[30], nomeAtrib2[30];

    switch(opcao1) {
        case 1: valor1_c1 = c1.populacao; valor1_c2 = c2.populacao; strcpy(nomeAtrib1, "População"); break;
        case 2: valor1_c1 = c1.area; valor1_c2 = c2.area; strcpy(nomeAtrib1, "Área"); break;
        case 3: valor1_c1 = c1.pib; valor1_c2 = c2.pib; strcpy(nomeAtrib1, "PIB"); break;
        case 4: valor1_c1 = c1.pontos_turisticos; valor1_c2 = c2.pontos_turisticos; strcpy(nomeAtrib1, "Pontos Turísticos"); break;
        case 5: valor1_c1 = c1.densidade; valor1_c2 = c2.densidade; strcpy(nomeAtrib1, "Densidade"); break;
        default: printf("Opção inválida!\n"); return 1;
    }

    switch(opcao2) {
        case 1: valor2_c1 = c2.populacao; valor2_c2 = c2.populacao; strcpy(nomeAtrib2, "População"); break;
        case 2: valor2_c1 = c1.area; valor2_c2 = c2.area; strcpy(nomeAtrib2, "Área"); break;
        case 3: valor2_c1 = c1.pib; valor2_c2 = c2.pib; strcpy(nomeAtrib2, "PIB"); break;
        case 4: valor2_c1 = c1.pontos_turisticos; valor2_c2 = c2.pontos_turisticos; strcpy(nomeAtrib2, "Pontos Turísticos"); break;
        case 5: valor2_c1 = c1.densidade; valor2_c2 = c2.densidade; strcpy(nomeAtrib2, "Densidade"); break;
        default: printf("Opção inválida!\n"); return 1;
    }

    int pontos_c1 = 0, pontos_c2 = 0;

    if (opcao1 == 5) {
        (valor1_c1 < valor1_c2) ? pontos_c1++ : pontos_c2++; // Operador ternário [cite: 814, 904]
    } else {
        (valor1_c1 > valor1_c2) ? pontos_c1++ : pontos_c2++;
    }

    if (opcao2 == 5) {
        (valor2_c1 < valor2_c2) ? pontos_c1++ : pontos_c2++;
    } else {
        (valor2_c1 > valor2_c2) ? pontos_c1++ : pontos_c2++;
    }

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Cartas: %s vs %s\n", c1.cidade, c2.cidade);
    printf("%s: %.2f vs %.2f\n", nomeAtrib1, valor1_c1, valor1_c2);
    printf("%s: %.2f vs %.2f\n", nomeAtrib2, valor2_c1, valor2_c2);
    
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;
    printf("Soma Total: %.2f vs %.2f\n", soma_c1, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\nResultado: Carta 1 (%s) VENCEU!\n", c1.cidade);
    } else if (soma_c2 > soma_c1) {
        printf("\nResultado: Carta 2 (%s) VENCEU!\n", c2.cidade);
    } else {
        printf("\nResultado: EMPATE!\n");
    }

    return 0;
}
#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para pausar e esperar Enter
void pausar() {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
    getchar();
}

int main() {
    int opcao;
    NodeFunc* funcionarios = NULL;
    NodeEmenta* ementas = NULL;
    NodeEscolha* escolhas = NULL;

    do {
        system("cls"); // Limpa a tela (Windows)
        printf("\n=== Sistema de Gestao do Espaco Social ===\n");
        printf("1. Carregar dados dos funcionarios\n");
        printf("2. Carregar ementas semanais\n");
        printf("3. Carregar escolhas dos utentes\n");
        printf("4. Listar refeicoes por dia\n");
        printf("5. Listar utentes ordenados\n");
        printf("6. Consultar refeicoes de um utente\n");
        printf("7. Calcular medias de calorias\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                funcionarios = carregarFuncionarios("funcionarios.txt");
                if (funcionarios != NULL) {
                    printf("\nDados dos funcionarios carregados com sucesso!\n");
                } else {
                    printf("\nErro ao carregar dados dos funcionarios!\n");
                }
                pausar();
                break;
            case 2:
                ementas = carregarEmentas("ementas.txt");
                if (ementas != NULL) {
                    printf("\nEmentas carregadas com sucesso!\n");
                } else {
                    printf("\nErro ao carregar ementas!\n");
                }
                pausar();
                break;
            case 3:
                escolhas = carregarEscolhas("escolhas.txt");
                if (escolhas != NULL) {
                    printf("\nEscolhas carregadas com sucesso!\n");
                } else {
                    printf("\nErro ao carregar escolhas!\n");
                }
                pausar();
                break;
            case 4: {
                if (funcionarios == NULL || ementas == NULL || escolhas == NULL) {
                    printf("\nErro: Carregue todos os arquivos primeiro (opcoes 1, 2 e 3)!\n");
                    pausar();
                    break;
                }
                char dia[10];
                printf("Digite o dia da semana (2feira, 3feira, etc.): ");
                scanf("%s", dia);
                limparBuffer();
                listarRefeicoesDia(funcionarios, ementas, escolhas, dia);
                pausar();
                break;
            }
            case 5:
                if (funcionarios == NULL || escolhas == NULL) {
                    printf("\nErro: Carregue os arquivos de funcionarios e escolhas primeiro (opcoes 1 e 3)!\n");
                    pausar();
                    break;
                }
                listarUtentesOrdenados(funcionarios, escolhas);
                pausar();
                break;
            case 6: {
                if (funcionarios == NULL || ementas == NULL || escolhas == NULL) {
                    printf("\nErro: Carregue todos os arquivos primeiro (opcoes 1, 2 e 3)!\n");
                    pausar();
                    break;
                }
                int num_func, opcao_consulta;
                char data_inicio[11], data_fim[11];
                
                printf("Digite o numero do funcionario: ");
                scanf("%d", &num_func);
                limparBuffer();
                
                printf("\nEscolha o tipo de consulta:\n");
                printf("1. Intervalo de datas especifico\n");
                printf("2. Semana completa\n");
                printf("Opcao: ");
                scanf("%d", &opcao_consulta);
                limparBuffer();
                
                if (opcao_consulta == 1) {
                    printf("Digite a data inicial (DD.MM.AAAA): ");
                    scanf("%s", data_inicio);
                    printf("Digite a data final (DD.MM.AAAA): ");
                    scanf("%s", data_fim);
                    listarRefeicoesCalorias(funcionarios, ementas, escolhas, num_func, data_inicio, data_fim);
                } else if (opcao_consulta == 2) {
                    gerarTabelaSemanal(funcionarios, ementas, escolhas, num_func);
                } else {
                    printf("\nOpcao invalida!\n");
                }
                pausar();
                break;
            }
            case 7: {
                if (ementas == NULL || escolhas == NULL) {
                    printf("\nErro: Carregue os arquivos de ementas e escolhas primeiro (opcoes 2 e 3)!\n");
                    pausar();
                    break;
                }
                char data_inicio[11], data_fim[11];
                printf("Digite a data inicial (DD.MM.AAAA): ");
                scanf("%s", data_inicio);
                printf("Digite a data final (DD.MM.AAAA): ");
                scanf("%s", data_fim);
                calcularMediasCalorias(ementas, escolhas, data_inicio, data_fim);
                pausar();
                break;
            }
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida!\n");
                pausar();
        }
    } while(opcao != 0);

    liberarMemoria(funcionarios, ementas, escolhas);
    return 0;
}

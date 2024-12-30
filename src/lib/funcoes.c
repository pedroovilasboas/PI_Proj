#include "estruturas.h"

// Funcao para criar novo no de funcionario
NodeFunc* criarNoFunc(Funcionario func) {
    NodeFunc* novoNo = (NodeFunc*)malloc(sizeof(NodeFunc));
    if (novoNo != NULL) {
        novoNo->func = func;
        novoNo->prox = NULL;
    }
    return novoNo;
}

// Funcao para carregar funcionarios do arquivo
NodeFunc* carregarFuncionarios(const char* filename) {
    printf("\n+================================================+\n");
    printf("|           Carregando Funcionarios               |\n");
    printf("+================================================+\n");

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return NULL;
    }

    NodeFunc* head = NULL;
    NodeFunc* atual = NULL;
    char linha[256];

    printf("+---------+----------------------+-------------+-------------+\n");
    printf("| Numero  | Nome                 | NIF         | Telefone    |\n");
    printf("+---------+----------------------+-------------+-------------+\n");

    int contador = 0;
    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Funcionario func;
        char* token = strtok(linha, ";");
        
        if (token) {
            func.numero = atoi(token);
            token = strtok(NULL, ";");
            if (token) {
                strncpy(func.nome, token, MAX_NOME-1);
                token = strtok(NULL, ";");
                if (token) {
                    func.nif = atoi(token);
                    token = strtok(NULL, ";");
                    if (token) {
                        func.telefone = atoi(token);

                        printf("| %-7d | %-20s | %-11d | %-11d |\n",
                            func.numero, func.nome, func.nif, func.telefone);

                        NodeFunc* novoNo = criarNoFunc(func);
                        if (novoNo) {
                            if (!head) {
                                head = novoNo;
                                atual = novoNo;
                            } else {
                                atual->prox = novoNo;
                                atual = novoNo;
                            }
                            contador++;
                        }
                    }
                }
            }
        }
    }

    printf("+---------+----------------------+-------------+-------------+\n");
    printf("Total de funcionarios carregados: %d\n", contador);
    printf("+================================================+\n");

    fclose(file);
    return head;
}

// Funcao para carregar ementas do arquivo
NodeEmenta* carregarEmentas(const char* filename) {
    printf("\n+================================================+\n");
    printf("|              Carregando Ementas                 |\n");
    printf("+================================================+\n");

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return NULL;
    }

    NodeEmenta* head = NULL;
    NodeEmenta* atual = NULL;
    char linha[256];
    int contador = 0;

    printf("+--------+------------+--------------------------------+--------+\n");
    printf("| Dia    | Data       | Prato                         | Cal.   |\n");
    printf("+--------+------------+--------------------------------+--------+\n");

    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Ementa ementa;
        char* token = strtok(linha, ";");
        
        if (token) {
            strncpy(ementa.dia, token, sizeof(ementa.dia)-1);
            token = strtok(NULL, ";");
            
            if (token) {
                strncpy(ementa.data, token, sizeof(ementa.data)-1);

                // Prato de Carne
                token = strtok(NULL, ";");
                if (token) {
                    strncpy(ementa.prato_carne.nome, token, MAX_NOME-1);
                    token = strtok(NULL, ";");
                    if (token) {
                        ementa.prato_carne.calorias = atoi(token);
                        printf("| %-6s | %-10s | %-30s | %-6d |\n",
                            ementa.dia, ementa.data,
                            ementa.prato_carne.nome,
                            ementa.prato_carne.calorias);
                    }
                }

                // Prato de Peixe
                token = strtok(NULL, ";");
                if (token) {
                    strncpy(ementa.prato_peixe.nome, token, MAX_NOME-1);
                    token = strtok(NULL, ";");
                    if (token) {
                        ementa.prato_peixe.calorias = atoi(token);
                        printf("| %-6s | %-10s | %-30s | %-6d |\n",
                            "\"", "\"",
                            ementa.prato_peixe.nome,
                            ementa.prato_peixe.calorias);
                    }
                }

                NodeEmenta* novoNo = (NodeEmenta*)malloc(sizeof(NodeEmenta));
                if (novoNo) {
                    novoNo->ementa = ementa;
                    novoNo->prox = NULL;
                    
                    if (!head) {
                        head = novoNo;
                        atual = novoNo;
                    } else {
                        atual->prox = novoNo;
                        atual = novoNo;
                    }
                    contador++;
                }
            }
        }
    }

    printf("+--------+------------+--------------------------------+--------+\n");
    printf("Total de ementas carregadas: %d\n", contador);
    printf("+================================================+\n");

    fclose(file);
    return head;
}

// Funcao para carregar escolhas do arquivo
NodeEscolha* carregarEscolhas(const char* filename) {
    printf("\n+----------------------------------------+\n");
    printf("|        Carregando Escolhas              |\n");
    printf("+----------------------------------------+\n");

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return NULL;
    }

    NodeEscolha* head = NULL;
    NodeEscolha* atual = NULL;
    char linha[256];
    int contador = 0;

    printf("+---------+---------+------------------+\n");
    printf("| Dia     | Func.   | Tipo de Prato   |\n");
    printf("+---------+---------+------------------+\n");

    while (fgets(linha, sizeof(linha), file)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Escolha escolha;
        char* token = strtok(linha, ";");
        
        if (token) {
            strncpy(escolha.dia, token, sizeof(escolha.dia)-1);
            token = strtok(NULL, ";");
            
            if (token) {
                escolha.num_funcionario = atoi(token);
                token = strtok(NULL, ";");
                
                if (token) {
                    escolha.tipo_prato = token[0];
                    const char* tipo_desc = 
                        escolha.tipo_prato == 'C' ? "Carne" :
                        escolha.tipo_prato == 'P' ? "Peixe" : "Outro";

                    printf("| %-7s | %-7d | %-14s |\n",
                        escolha.dia,
                        escolha.num_funcionario,
                        tipo_desc);

                    NodeEscolha* novoNo = (NodeEscolha*)malloc(sizeof(NodeEscolha));
                    if (novoNo) {
                        novoNo->escolha = escolha;
                        novoNo->prox = NULL;
                        
                        if (!head) {
                            head = novoNo;
                            atual = novoNo;
                        } else {
                            atual->prox = novoNo;
                            atual = novoNo;
                        }
                        contador++;
                    }
                }
            }
        }
    }

    printf("+---------+---------+------------------+\n");
    printf("Total de escolhas carregadas: %d\n", contador);
    printf("+----------------------------------------+\n");

    fclose(file);
    return head;
}

// Funcao para liberar memoria alocada
void liberarMemoria(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas) {
    // Liberar lista de funcionarios
    while (funcionarios) {
        NodeFunc* temp = funcionarios;
        funcionarios = funcionarios->prox;
        free(temp);
    }

    // Liberar lista de ementas
    while (ementas) {
        NodeEmenta* temp = ementas;
        ementas = ementas->prox;
        free(temp);
    }

    // Liberar lista de escolhas
    while (escolhas) {
        NodeEscolha* temp = escolhas;
        escolhas = escolhas->prox;
        free(temp);
    }
}


// Funcao para listar refeicoes de um dia especifico
void listarRefeicoesDia(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas, const char* dia) {
    printf("\n+============================================+\n");
    printf("|        Refeicoes para %-10s          |\n", dia);
    printf("+============================================+\n");
    printf("| Func. | Nome                 | Prato       |\n");
    printf("+--------+----------------------+------------+\n");

    NodeEscolha* escolha = escolhas;
    int total_refeicoes = 0;

    while (escolha) {
        if (strcmp(escolha->escolha.dia, dia) == 0) {
            NodeFunc* func = funcionarios;
            while (func) {
                if (func->func.numero == escolha->escolha.num_funcionario) {
                    NodeEmenta* ementa = ementas;
                    while (ementa) {
                        if (strcmp(ementa->ementa.dia, dia) == 0) {
                            const char* nome_prato = 
                                escolha->escolha.tipo_prato == 'C' ? 
                                ementa->ementa.prato_carne.nome : 
                                ementa->ementa.prato_peixe.nome;

                            printf("| %-6d | %-20s | %-10s |\n", 
                                func->func.numero,
                                func->func.nome,
                                nome_prato);
                            total_refeicoes++;
                            break;
                        }
                        ementa = ementa->prox;
                    }
                    break;
                }
                func = func->prox;
            }
        }
        escolha = escolha->prox;
    }

    printf("+--------+----------------------+------------+\n");
    printf("Total de refeicoes para %s: %d\n", dia, total_refeicoes);
    printf("+============================================+\n");
}

// Funcao para listar utentes ordenados por numero de refeicoes
void listarUtentesOrdenados(NodeFunc* funcionarios, NodeEscolha* escolhas) {
    printf("\n+================================================+\n");
    printf("|           Resumo de Consumo por Utente          |\n");
    printf("+================================================+\n");

    // Criar array para contar refeicoes por funcionario
    int max_func = 0;
    NodeFunc* func = funcionarios;
    while (func) {
        if (func->func.numero > max_func)
            max_func = func->func.numero;
        func = func->prox;
    }

    int* contagem = (int*)calloc(max_func + 1, sizeof(int));
    if (!contagem) {
        printf("Erro: Falha na alocacao de memoria\n");
        return;
    }

    // Contar refeicoes por funcionario
    NodeEscolha* escolha = escolhas;
    while (escolha) {
        contagem[escolha->escolha.num_funcionario]++;
        escolha = escolha->prox;
    }

    printf("+---------+----------------------+------------+\n");
    printf("| Func.   | Nome                 | Refeicoes  |\n");
    printf("+---------+----------------------+------------+\n");

    // Imprimir resultados
    int total_refeicoes = 0;
    for (int i = 1; i <= max_func; i++) {
        if (contagem[i] > 0) {
            func = funcionarios;
            while (func) {
                if (func->func.numero == i) {
                    printf("| %-7d | %-20s | %-10d |\n",
                        func->func.numero,
                        func->func.nome,
                        contagem[i]);
                    total_refeicoes += contagem[i];
                    break;
                }
                func = func->prox;
            }
        }
    }

    printf("+---------+----------------------+------------+\n");
    printf("Total de refeicoes: %d\n", total_refeicoes);
    printf("+================================================+\n");

    free(contagem);
}

// Funcao para listar refeicoes e calorias de um utente
void listarRefeicoesCalorias(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas, 
                            int num_funcionario, const char* data_inicio, const char* data_fim) {
    NodeFunc* func = funcionarios;
    while (func && func->func.numero != num_funcionario)
        func = func->prox;

    if (!func) {
        printf("Funcionario nao encontrado.\n");
        return;
    }

    printf("\n=== Refeicoes e Calorias do Funcionario %d - %s ===\n", 
           num_funcionario, func->func.nome);
    printf("Dia    | Prato                  | Calorias\n");
    printf("------------------------------------------\n");

    int total_calorias = 0;
    int total_refeicoes = 0;

    NodeEscolha* escolha = escolhas;
    while (escolha) {
        if (escolha->escolha.num_funcionario == num_funcionario) {
            NodeEmenta* ementa = ementas;
            while (ementa) {
                if (strcmp(ementa->ementa.dia, escolha->escolha.dia) == 0) {
                    const char* nome_prato;
                    int calorias;

                    if (escolha->escolha.tipo_prato == 'C') {
                        nome_prato = ementa->ementa.prato_carne.nome;
                        calorias = ementa->ementa.prato_carne.calorias;
                    } else {
                        nome_prato = ementa->ementa.prato_peixe.nome;
                        calorias = ementa->ementa.prato_peixe.calorias;
                    }

                    printf("%-6s | %-20s | %d\n",
                           ementa->ementa.dia,
                           nome_prato,
                           calorias);
                    
                    total_calorias += calorias;
                    total_refeicoes++;
                    break;
                }
                ementa = ementa->prox;
            }
        }
        escolha = escolha->prox;
    }

    printf("------------------------------------------\n");
    printf("Total de refeicoes: %d\n", total_refeicoes);
    printf("Media de calorias: %.2f\n", total_refeicoes > 0 ? (float)total_calorias/total_refeicoes : 0);
    printf("------------------------------------------\n");
}

// Funcao para calcular medias de calorias por dia
void calcularMediasCalorias(NodeEmenta* ementas, NodeEscolha* escolhas, 
                           const char* data_inicio, const char* data_fim) {
    printf("\n=== Media de Calorias por Dia ===\n");
    printf("Dia    | Media de Calorias\n");
    printf("---------------------------\n");

    NodeEmenta* ementa = ementas;
    while (ementa) {
        int total_calorias = 0;
        int num_refeicoes = 0;

        NodeEscolha* escolha = escolhas;
        while (escolha) {
            if (strcmp(escolha->escolha.dia, ementa->ementa.dia) == 0) {
                if (escolha->escolha.tipo_prato == 'C')
                    total_calorias += ementa->ementa.prato_carne.calorias;
                else
                    total_calorias += ementa->ementa.prato_peixe.calorias;
                num_refeicoes++;
            }
            escolha = escolha->prox;
        }

        if (num_refeicoes > 0) {
            float media = (float)total_calorias / num_refeicoes;
            printf("%-6s | %.2f\n", ementa->ementa.dia, media);
        }

        ementa = ementa->prox;
    }
    printf("---------------------------\n");
}

// Funcao para gerar tabela semanal de um utente
void gerarTabelaSemanal(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas, 
                        int num_funcionario) {
    NodeFunc* func = funcionarios;
    while (func && func->func.numero != num_funcionario)
        func = func->prox;

    if (!func) {
        printf("Funcionario nao encontrado.\n");
        return;
    }

    printf("\n=== Ementa Semanal do Funcionario %d - %s ===\n", 
           num_funcionario, func->func.nome);
    printf("------------------------------------------\n");
    printf("Dia    | Prato                  | Calorias\n");
    printf("------------------------------------------\n");

    NodeEmenta* ementa = ementas;
    while (ementa) {
        NodeEscolha* escolha = escolhas;
        while (escolha) {
            if (escolha->escolha.num_funcionario == num_funcionario &&
                strcmp(escolha->escolha.dia, ementa->ementa.dia) == 0) {
                const char* nome_prato;
                int calorias;

                if (escolha->escolha.tipo_prato == 'C') {
                    nome_prato = ementa->ementa.prato_carne.nome;
                    calorias = ementa->ementa.prato_carne.calorias;
                } else {
                    nome_prato = ementa->ementa.prato_peixe.nome;
                    calorias = ementa->ementa.prato_peixe.calorias;
                }

                printf("%-6s | %-20s | %d\n",
                       ementa->ementa.dia,
                       nome_prato,
                       calorias);
                break;
            }
            escolha = escolha->prox;
        }
        ementa = ementa->prox;
    }
    printf("------------------------------------------\n");
}

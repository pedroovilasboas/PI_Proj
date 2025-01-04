/**
 * @file estruturas.h
 * @brief Definições das estruturas de dados do sistema
 * @author [Seu Nome]
 * @date 2025-01-04
 */

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Tamanho máximo para campos de nome
 */
#define MAX_NOME 50

/**
 * @brief Tamanho máximo para leitura de linhas
 */
#define MAX_LINE 256

/**
 * @brief Estrutura que representa um funcionário
 * @details Armazena informações básicas de identificação do funcionário
 */
typedef struct {
    int numero;         /**< Número identificador do funcionário */
    char nome[MAX_NOME]; /**< Nome completo do funcionário */
    int nif;            /**< Número de identificação fiscal */
    int telefone;       /**< Número de telefone do funcionário */
} Funcionario;

/**
 * @brief Estrutura que representa um prato
 * @details Define as características básicas de um prato do cardápio
 */
typedef struct {
    char nome[MAX_NOME]; /**< Nome do prato */
    int calorias;       /**< Quantidade de calorias do prato */
} Prato;

/**
 * @brief Estrutura que representa uma ementa diária
 * @details Contém as opções de pratos disponíveis para um determinado dia
 */
typedef struct {
    char dia[10];       /**< Dia da semana */
    char data[10];      /**< Data no formato DD/MM/AAAA */
    Prato prato_carne;  /**< Opção de prato com carne */
    Prato prato_peixe;  /**< Opção de prato com peixe */
} Ementa;

/**
 * @brief Estrutura que representa a escolha de um funcionário
 * @details Registra a escolha do prato feita por um funcionário em um determinado dia
 */
typedef struct {
    char dia[10];        /**< Dia da escolha */
    int num_funcionario; /**< Número identificador do funcionário */
    char tipo_prato;     /**< Tipo do prato escolhido ('C' para carne, 'P' para peixe) */
} Escolha;

/**
 * @brief Nó para lista ligada de funcionários
 * @details Estrutura para armazenar funcionários em uma lista ligada
 */
typedef struct NodeFunc {
    Funcionario func;    /**< Dados do funcionário */
    struct NodeFunc* prox; /**< Ponteiro para o próximo nó */
} NodeFunc;

/**
 * @brief Nó para lista ligada de ementas
 * @details Estrutura para armazenar ementas em uma lista ligada
 */
typedef struct NodeEmenta {
    Ementa ementa;       /**< Dados da ementa */
    struct NodeEmenta* prox; /**< Ponteiro para o próximo nó */
} NodeEmenta;

/**
 * @brief Nó para lista ligada de escolhas
 * @details Estrutura para armazenar escolhas em uma lista ligada
 */
typedef struct NodeEscolha {
    Escolha escolha;     /**< Dados da escolha */
    struct NodeEscolha* prox; /**< Ponteiro para o próximo nó */
} NodeEscolha;

/**
 * @brief Cria um novo nó para a lista de funcionários
 * @param func Dados do funcionário
 * @return Ponteiro para o novo nó
 */
NodeFunc* criarNoFunc(Funcionario func);

/**
 * @brief Carrega a lista de funcionários a partir de um arquivo
 * @param filename Nome do arquivo de funcionários
 * @return Ponteiro para o início da lista de funcionários
 */
NodeFunc* carregarFuncionarios(const char* filename);

/**
 * @brief Carrega a lista de ementas a partir de um arquivo
 * @param filename Nome do arquivo de ementas
 * @return Ponteiro para o início da lista de ementas
 */
NodeEmenta* carregarEmentas(const char* filename);

/**
 * @brief Carrega a lista de escolhas a partir de um arquivo
 * @param filename Nome do arquivo de escolhas
 * @return Ponteiro para o início da lista de escolhas
 */
NodeEscolha* carregarEscolhas(const char* filename);

/**
 * @brief Lista as refeições disponíveis para um determinado dia
 * @param funcionarios Lista de funcionários
 * @param ementas Lista de ementas
 * @param escolhas Lista de escolhas
 * @param dia Dia da semana
 */
void listarRefeicoesDia(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas, const char* dia);

/**
 * @brief Lista os utentes ordenados por número de identificação
 * @param funcionarios Lista de funcionários
 * @param escolhas Lista de escolhas
 */
void listarUtentesOrdenados(NodeFunc* funcionarios, NodeEscolha* escolhas);

/**
 * @brief Lista as refeições consumidas por um funcionário em um período
 * @param funcionarios Lista de funcionários
 * @param ementas Lista de ementas
 * @param escolhas Lista de escolhas
 * @param num_funcionario Número identificador do funcionário
 * @param data_inicio Data de início do período
 * @param data_fim Data de fim do período
 */
void listarRefeicoesCalorias(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas, int num_funcionario, const char* data_inicio, const char* data_fim);

/**
 * @brief Calcula as médias de calorias consumidas em um período
 * @param ementas Lista de ementas
 * @param escolhas Lista de escolhas
 * @param data_inicio Data de início do período
 * @param data_fim Data de fim do período
 */
void calcularMediasCalorias(NodeEmenta* ementas, NodeEscolha* escolhas, const char* data_inicio, const char* data_fim);

/**
 * @brief Gera uma tabela semanal de refeições para um funcionário
 * @param funcionarios Lista de funcionários
 * @param ementas Lista de ementas
 * @param escolhas Lista de escolhas
 * @param num_funcionario Número identificador do funcionário
 */
void gerarTabelaSemanal(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas, int num_funcionario);

/**
 * @brief Libera a memória alocada para as listas
 * @param funcionarios Lista de funcionários
 * @param ementas Lista de ementas
 * @param escolhas Lista de escolhas
 */
void liberarMemoria(NodeFunc* funcionarios, NodeEmenta* ementas, NodeEscolha* escolhas);

#endif

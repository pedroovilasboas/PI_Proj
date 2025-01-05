# Sistema de Gestão do Espaço Social 🏢

## 📋 Índice
- [Sobre o Projecto](#sobre-o-projecto)
- [Funcionalidades](#funcionalidades)
- [Estrutura do Projecto](#estrutura-do-projecto)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Instalação e Execução](#instalação-e-execução)
- [Documentação](#documentação)
- [Equipa](#equipa)

## 🎯 Sobre o Projecto
Este projecto foi desenvolvido no âmbito da unidade curricular de Laboratórios de Informática do curso de Engenharia de Sistemas Informáticos no Instituto Politécnico do Cávado e do Ave. Consiste num sistema de gestão para um espaço social, permitindo a administração eficiente de funcionários, ementas e escolhas de refeições.

## ⚙️ Funcionalidades
### Gestão de Funcionários
- Registo e gestão de dados dos funcionários
- Consulta de informações pessoais
- Actualização de registos

### Gestão de Ementas
- Carregamento de ementas semanais
- Visualização de refeições disponíveis
- Gestão do planeamento alimentar

### Sistema de Refeições
- Registo de escolhas dos utentes
- Listagem de refeições por dia
- Consulta personalizada por utente
- Relatórios por intervalo de datas
- Estatísticas semanais

## 📁 Estrutura do Projecto
```
projecto/
├── src/                    # Código fonte
│   ├── main.c             # Ficheiro principal
│   ├── estruturas.h       # Definições das estruturas
│   └── funcoes.c          # Implementação das funções
├── dados/                 # Ficheiros de dados
│   ├── pessoas.txt       # Dados dos funcionários
│   ├── ementas.txt      # Dados das ementas
│   └── menu_escolhido.txt # Registo de escolhas
└── docs/                 # Documentação
    └── Relatorio LaTeX/  # Relatório técnico em LaTeX
        ├── Relatorio.tex # Ficheiro fonte do relatório
        └── Relatorio.pdf # Relatório compilado
```

## 🛠️ Tecnologias Utilizadas
- Linguagem C
- Bibliotecas standard C
- Estruturas de dados dinâmicas (listas ligadas)
- Sistema de ficheiros para persistência de dados
- LaTeX para documentação técnica


### Estrutura do Relatório
- **Resumo**: Visão geral do projecto
- **Introdução**: Objectivos e descrição do sistema
- **Desenvolvimento**: Descrição detalhada do problema e implementação
- **Implementação**: Detalhes técnicos e algoritmos utilizados
- **Exemplos de Uso**: Casos práticos de utilização do sistema
- **Conclusão**: Contribuições, desafios e trabalho futuro

### Compilação do Relatório
Para compilar o relatório LaTeX:
1. Instale uma distribuição TeX (por exemplo, MiKTeX)
2. Navegue até à pasta do relatório
3. Comando:
   
   pdflatex Relatorio.tex
  

## 👥 Equipa
- Pedro Vilas Boas (nº25453)
- Ricardo Marques (nº25447)

## 📝 Notas Adicionais
- O sistema foi desenvolvido com foco na eficiência e facilidade de utilização
- Implementa boas práticas de programação e gestão de memória
- Inclui validação de dados e tratamento de erros
- Documentação técnica completa disponível no relatório em LaTeX

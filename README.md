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

### 📁 Estrutura do Projeto
```
.
├── doc/                    # Documentação com o relatório
│   └── Relatorio LaTeX/   # Relatório em LaTeX
│       ├── Relatorio.tex  # Código fonte do relatório
│       └── Makefile       # Makefile para compilar o relatório
├── doxdoc/                # Documentação gerada pelo Doxygen
└── src/                   # Código fonte da solução
    ├── include/           # Arquivos de cabeçalho (.h)
    ├── lib/               # Bibliotecas
    ├── Makefile          # Makefile para compilar o programa
    └── build/            # Arquivos compilados (gerado automaticamente)
```


## 🛠️ Tecnologias Utilizadas
- Linguagem C
- Bibliotecas standard C
- Estruturas de dados dinâmicas (listas ligadas)
- Sistema de ficheiros para persistência de dados
- LaTeX para documentação técnica

## 📝 Instalação e Execução

### Pré-requisitos
1. **MinGW (para Windows)**
   - Faça download do [MinGW Installer](https://sourceforge.net/projects/mingw/)
   - Durante a instalação, selecione:
     - mingw32-base
     - mingw32-gcc-g++
     - mingw32-make
   - Adicione o MinGW ao PATH do sistema:
     1. Abra o Painel de Controle
     2. Sistema e Segurança > Sistema
     3. Configurações avançadas do sistema
     4. Variáveis de ambiente
     5. Em "Variáveis do sistema", encontre PATH
     6. Adicione: `C:\MinGW\bin`

2. **MiKTeX (para compilar o relatório)**
   - Faça download e instale o [MiKTeX](https://miktex.org/download)

### Compilação e Execução

O projeto possui dois Makefiles:
1. `src/Makefile`: Para compilar o programa em C
2. `doc/Relatorio LaTeX/Makefile`: Para compilar o relatório em LaTeX

#### Compilar o Programa (pasta src)
```bash
# Navegue até a pasta src
cd src

# Compilar o programa
mingw32-make

# Limpar arquivos compilados
mingw32-make clean

# Recompilar todo o projeto
mingw32-make rebuild

# Compilar e executar
mingw32-make run
```

#### Compilar o Relatório (pasta doc/Relatorio LaTeX)
```bash
# Navegue até a pasta do relatório
cd doc/Relatorio\ LaTeX

# Compilar o PDF
mingw32-make

# Limpar arquivos temporários
mingw32-make clean

# Recompilar o relatório
mingw32-make rebuild
```

**Nota**: No Windows, use `mingw32-make` em vez de apenas `make`. Para caminhos com espaços, use aspas ou escape com `\`.

### 📁 Estrutura do Projeto
```
.
├── doc/                    # Documentação com o relatório
│   └── Relatorio LaTeX/   # Relatório em LaTeX
│       ├── Relatorio.tex  # Código fonte do relatório
│       └── Makefile       # Makefile para compilar o relatório
├── doxdoc/                # Documentação gerada pelo Doxygen
└── src/                   # Código fonte da solução
    ├── include/           # Arquivos de cabeçalho (.h)
    ├── lib/               # Bibliotecas
    ├── Makefile          # Makefile para compilar o programa
    └── build/            # Arquivos compilados (gerado automaticamente)
```

## 👥 Equipa
- Pedro Vilas Boas (nº25453)
- Ricardo Marques (nº25447)

## 📝 Notas Adicionais
- O sistema foi desenvolvido com foco na eficiência e facilidade de utilização
- Implementa boas práticas de programação e gestão de memória
- Inclui validação de dados e tratamento de erros
- Documentação técnica completa disponível no relatório em LaTeX

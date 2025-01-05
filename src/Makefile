# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g

# Diretórios
SRC_DIR = .
INCLUDE_DIR = include
LIB_DIR = lib
BUILD_DIR = build

# Nome do executável
TARGET = programa.exe

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

# Regra padrão
all: $(BUILD_DIR)/$(TARGET)

# Criar diretório build se não existir
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Compilar o programa
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compilar os objetos
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpar arquivos compilados
clean:
	if exist $(BUILD_DIR) rd /s /q $(BUILD_DIR)

# Recompilar tudo
rebuild: clean all

# Executar o programa
run: all
	$(BUILD_DIR)\$(TARGET)

.PHONY: all clean rebuild run
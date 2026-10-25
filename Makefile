# Название итогового исполняемого файла
TARGET = program

# Директории проекта
SRC_DIR = src
INC_DIR = headers
OBJ_DIR = obj

# Компилятор и флаги компиляции
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I$(INC_DIR)

# Автоматический поиск всех .c файлов в папке src
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Генерация путей для .o файлов (например, src/main.c -> obj/main.o)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Главная цель (вызывается по умолчанию командой make)
all: $(TARGET)

# Сборка исполняемого файла из объектных файлов
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Компиляция .c файлов в .o. 
# Символ '|' означает order-only prerequisite: директория obj создастся до компиляции.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Создание директории для промежуточных файлов, если её нет
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Очистка скомпилированных файлов (команда make clean)
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Объявление целей, которые не являются реальными файлами
.PHONY: all clean

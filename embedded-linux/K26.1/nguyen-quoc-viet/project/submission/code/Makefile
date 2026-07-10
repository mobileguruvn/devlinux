CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinc
LDFLAGS = -lcrypto

SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TEST_DIR = test
DOC_DIR = doc

TARGET = $(BUILD_DIR)/chat-server

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/auth.c $(SRC_DIR)/message.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
HEADERS = $(INC_DIR)/chat.h

.PHONY: all clean rebuild help

all: $(TARGET)

$(TARGET): directories $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	@echo "✅ Build successful: $(TARGET)"

directories:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	@echo "🧹 Cleaned"

rebuild: clean all

help:
	@echo "Chat Server — Makefile"
	@echo "make, make clean, make rebuild, make help"

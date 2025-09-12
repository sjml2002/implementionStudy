CC := gcc
CPPFLAGS := -std=c11 -Wall -Wextra -O2

SRC := hello.c
OBJ := hello.o
TARGET := hello.out

# compile : object file
$(OBJ): $(SRC) # 왼쪽 거 만들려면 오른쪽 거 필요함
	$(CC) -c $(SRC) -o $(OBJ)

# link : 실행 파일
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

.PHONY: run
run: $(TARGET)
	./$(TARGET)

.PHONY: clean 
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean:
	rm -f $(OBJ) $(TARGET)
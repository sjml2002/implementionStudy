# 변수 설정
CC := gcc 
CPPFLAGS := -std=c11 -Wall -Wextra -O2

SRC := hello.c # source file name
OBJ := hello.o # object file name (.c -> .o)
TARGET := hello.out # 최종 실행 파일 이름 (.o -> .out)

# 역 절차 지향 

# link : 실행 파일
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# compile : object file
$(OBJ): $(SRC) # 왼쪽 거 만들려면 오른쪽 거 필요함
	$(CC) -c $(SRC) -o $(OBJ) 
# -c : 컴파일만 하고 실행 파일 생성 x == object file만 생성


# .PHONY : 실제 파일명이 아니라 "명령어 이름"임을 선언 == 명령 전용 변수명
# run -> hello.out 생성 -> ./hello.out 으로 실행
.PHONY: re
re: $(TARGET)
	./$(TARGET)


# make clean -> hello.o만 삭제
.PHONY: clean 
clean:
	rm -f $(OBJ)
# make fclean -> hello.o, hello.out 삭제
.PHONY: fclean
fclean:
	rm -f $(OBJ) $(TARGET)


# Makefile이 없으면 새로 생성 또는 수정될 때마다 컴파일 전과정을 전부 다시 해줘야함

# Makefile은 컴파일을 어떻게 할 건지에 대한 설명서라고 보면 됨

# .PHONY : 실제 파일명이 아니라 "명령어 이름"임을 선언 == 명령 전용 변수명 
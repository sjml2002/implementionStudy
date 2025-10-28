#include <stdio.h>
#include <stdlib.h>
// Clang 표준 라이브러리
#include <unistd.h>
/*
file(in Unix/Linux system) : 일반적인 정규파일부터 디렉토리, 소켓, 파이프, 블록 디바이스 등 모든
객체들을 파일로 관리함 File Descriptor
    - 프로세스에서 열린 파일 목록을 관리하는 테이블 인덱스
    - Unix/Linux system에서 프로세스가 특정 파일에 접근할 때 사용하는 추상적인 값
    - 일반적으로 0이 아닌 정수값

1. 프로세스가 실행 중에 파일을 oepn
2. 커널은 해당 프로세스의 File Descriptor 숫자 중 사용하지 않는 가장 작은 값을 할당
3. 프로세스가 열려있는 파일에 system call을 이용해서 접근할 때, File Descriptor 값을 이용해서 파일을
지칭

기본적으로 할당되는 File Descriptor
    File Descriptor - 목적 - POSIX 이름
    0 - 표준입력(Standard Input = 키보드) - STDIN_FILENO
    1 - 표준출력(Standard Output = 모니터) - STDOUT_FILENO
    2 - 표준에러(Standard Error = 에러출력) - STDERR_FILENO

    * 초창기 실용적인(상용) 범용 컴퓨터들이 대부분 각자의 유닉스 시스템에서 운영되었는데, 각기 다른
유닉스 시스템간의 호환성 및 이식성 확보를 필요한 표준을 정립한 것이 POSIX
*/

int ct_putchar(int c);
int ct_puts(const char *s);
size_t ct_strlen(const char *s);
int ct_atoi(const char *nptr);
int ct_putnum(int num, int fd);
char *ct_substr(const char *s, unsigned int start, unsigned int len);
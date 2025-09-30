// printf("%s") : 포인터를 받아서, 그곳에서 시작해서 '\0'으로 끝날 때 까지 나타나는 모든 문자를 출력
// putchar()는 아스키값을 받아서, 그 아스키값에 해당하는 문자 하나를 출력
#include "libct.h"

int ct_putchar(int c) {
    unsigned char ch = (unsigned char)c;
    // ssize_t write(int fd, const void *buf, size_t count);
    // ssize_t write(fd num, 데이터 시작 지점 주소, 시작점부터 읽을 byte 수);

    if (write(1, &ch, 1) == 1) {
        return (int)ch;
    } else {
        return -1;  // == (return EOF;)
    }
}

// scanf : 공백 불가능
// gets(getString) : 공백 가능
// putc(putChar) puts(putString)
// 일단 문자열 출력하고 결과에 따라 반환값 결정 -> 조건문 내부에 write 있어도 됨
int ct_puts(const char *s) {
    if (s == NULL) return -1;  // NULL 방어

    // 문자열 길이 카운팅
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }

    // 문자열 본문 출력
    // write return ssize_t
    if (write(1, s, len) != (ssize_t)len) return -1;  // 오류 시 EOF 반환

    // 줄바꿈 문자 출력
    if (write(1, "\n", 1) != 1) return -1;

    return 0;
}

size_t ct_strlen(const char *s) {
    // 문자열 길이 카운팅
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }

    return len;
}

// overflow : 하위 4byte만 계산됨
int ct_atoi(const char *nptr) {
    if (nptr == NULL) return -1;

    size_t len = ct_strlen(nptr);

    int result = 0;

    for (size_t i = 0; i < len; i++) {
        if (nptr[i] >= '0' && nptr[i] <= '9') {
            result = (result * 10) + (nptr[i] - '0');
            continue;
        }
        return -1;
    }

    return result;
}

int ct_putnum(int num, int fd) {
    char temp[12];  // int 4byte -> -2,147,483,648 ~ 2,147,483,647 -> unsigned 11 + NULL 1 = 12
    int idx = 11;
    int neg = 0;

    temp[idx] = '\0';

    if (num == 0) {
        temp[--idx] = '0';
    } else {
        if (num < 0) {
            neg = 1;  // 부호 flag

            if (num == -2147483648) {
                temp[--idx] = '8';
                num = -214748364;
            }

            num = -num;
        }

        while (num > 0) {
            temp[--idx] = (char)((num % 10) + '0');
            num /= 10;
        }

        if (neg == 1) {
            temp[--idx] = '-';
        }
    }

    ssize_t result = write(fd, temp + idx, 11 - idx);
    /*
    write가 (11 - idx) 이만큼 써준다는 보장이 없음
        - 파이프/소켓/터미널
        - 논블로킹(Non-blocking) FD
        - 시그널 개입(EINTR)
        - 디스크/리소스 이슈
    */
    if (result != (ssize_t)(11 - idx)) {
        return -1;
    }

    return 0;
}

char *ct_substr(const char *s, unsigned int start, unsigned int len) {
    if (s == NULL) return NULL;

    size_t slen = ct_strlen(s);

    if (start >= slen) return NULL;
    if (len > (slen - start)) return NULL;

    char *result = (char *)malloc(len + 1);

    if (result == NULL) return NULL;

    for (size_t i = 0; i < (size_t)len; i++) {
        result[i] = s[start + i];
    }
    result[len] = '\0';
    return result;
}

// 운영체제가 요청한 만큼의 메모리를 프로세스에 할당해 줄 수 없을 때
// 메모리 == real + virtual

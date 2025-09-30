#include <stdio.h>
#include <string.h>
#include "libct.h"
# define TESTCASE 10

int int_case[TESTCASE+1] = {80, 125, 32, 0, 4, -20, -30, 97, 8, -65, 65};
const char* str_case[TESTCASE+1] = {
	"knet implemention study",
	"knet imple\0mention study",
	"",
	"knet\nimple\nmention\rstu\tdy    ",
	"2147483648",
	"-2147483648",
	"2147483647",
	"65",
	"-100-912",
	"+456789"
};



int main() {

	//1. ct_putchar test
	int flag = 1;
	printf(" ================\n");
	printf("ct_putchar test \n");
	printf(" ================\n");
	for(int i=0; i<TESTCASE; i++) {
		int res1 = putchar(int_case[i]);
		int res2 = ct_putchar(int_case[i]);
		printf(",\n");

		if (res1 != res2) {
			printf("%d: return DIFF %d , %d\n", i+1, res1, res2);
			flag = 0;
		}
		printf("\n");
	}
	if (flag)
		printf("===>>> ct_putchar success!!!\n");

	//2. ct_puts test
	flag = 1;
	printf(" ================\n");
	printf("ct_puts test \n");
	printf(" ================\n");
	for(int i=0; i<TESTCASE; i++) {
		int res1 = puts(str_case[i]);
		int res2 = ct_puts(str_case[i]);
		printf(",\n");

		if ((res1>=0 && res2<0) || (res1<0 && res2>=0)) {
			printf("%d: return DIFF %d, %d\n", i+1, res1, res2);
			flag = 0;
		}
		printf("\n");
	}
	if (flag)
		printf("===>>> ct_puts success!!!\n");

	//3. ct_atoi test
	flag = 1;
	printf(" ================\n");
	printf("ct_atoi test \n");
	printf(" ================\n");
	for(int i=0; i<TESTCASE; i++) {
		int res1 = atoi(str_case[i]);
		int res2 = ct_atoi(str_case[i]);
		printf("case: %s,\n", str_case[i]);

		if (res1 != res2) {
			printf("%d: return DIFF %d, %d\n", i+1, res1, res2);
			flag = 0;
		}
		printf("\n");
	}
	if (flag)
		printf("===>>> ct_atoi success!!!\n");

	//4. ct_strlen test
	flag = 1;
	printf(" ================\n");
	printf("ct_strlen test \n");
	printf(" ================\n");
	for(int i=0; i<TESTCASE; i++) {
		int res1 = strlen(str_case[i]);
		int res2 = ct_strlen(str_case[i]);
		printf("case: %s,\n", str_case[i]);

		if (res1 != res2) {
			printf("%d: return DIFF %d, %d\n", i+1, res1, res2);
			flag = 0;
		}
		printf("\n");
	}
	if (flag)
		printf("===>>> ct_strlen success!!!\n");

	//5. ct_putnum test
	flag = 1;
	printf(" ================\n");
	printf("ct_putnum test \n");
	printf(" ================\n");
	int res = ct_putnum(80, 0);
	printf("\n");
	if (res != 0) {
		printf("expected: print sucessful (return 0)\n");
		flag = 0;
	}
	res = ct_putnum(2147483647, 0);
	printf("\n");
	if (res != 0) {
		printf("expected: print sucessful (return 0)\n");
		flag = 0;
	}
	res = ct_putnum(2147483648, 0);
	printf("\n");
	if (res != -1) {
		printf("expected: return EOF. but => %d\n", res);
		flag = 0;
	}
	res = ct_putnum(-2147483648, 0);
	printf("\n");
	if (res != 0) {
		printf("expected: print sucessful (return 0)\n");
		flag = 0;
	}
	printf("\n");
	if (flag)
		printf("===>>> ct_putnum success!!!\n");

	//6. ct_substr test
	flag = 1;
	printf(" ================\n");
	printf("ct_substr test \n");
	printf(" ================\n");
	char* resstr = ct_substr("kimjunsang", 3, 7);
	printf("%s", resstr);
	if (strcmp(resstr, "junsang")) { //resstr != "junsang"
		flag = 0;
		printf("failed case: kimjunsang\n");
	}
	free(resstr);
	resstr = ct_substr("kim\0junsang", 3, 7);
	printf("%s", resstr);
	if (strcmp(resstr, "\0")) {
		flag = 0;
		printf("falied case: \0");
	}
	free(resstr);

	printf("\n");
	if (flag)
		printf("===>>> ct_substr success!!!\n");

	return (0);
}

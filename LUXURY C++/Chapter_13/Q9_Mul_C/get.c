#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int get() {
	int c;
	printf("숫자를 입력하세요>>");
	scanf_s("%d", &c);
	return c;
}

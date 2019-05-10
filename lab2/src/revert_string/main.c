#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "revert_string.h"

int main(int argc, char *argv[])
{
    //проверяем у нас не 1 аргумент?
	if (argc != 2)
	{
	    //печатаем первый аргумент и имя проги, конец проги с -1 ошибкой (return -1)
		printf("Usage: %s string_to_revert\n", argv[0]);
		return -1;
	}
    //выделяем страку в длину 1вого аргумента +1 (нуль символ)
	char *reverted_str = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	//копирукм строку в revert_str из 1 аргумента
	strcpy(reverted_str, argv[1]);
    //переворот
	RevertString(reverted_str);
    //печать перевернутой строки
	printf("Reverted: %s\n", reverted_str);
	//освободим память
	free(reverted_str);
	//конец
	return 0;
}


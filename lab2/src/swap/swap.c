#include "swap.h"

void Swap(char *left, char *right)
{
	// ваш код здесь
	char m = *right;
	*right = *left;
    *left = m;
}

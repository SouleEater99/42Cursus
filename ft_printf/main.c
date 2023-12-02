#include "ft_printf.h"

int main()
{
	int a = 644254388;
	printf("adddres of a :--> %p \n",&a);

	unsigned long long p = (unsigned long long)&a;
	printf("value of  p: --> %d \n",&a);

}

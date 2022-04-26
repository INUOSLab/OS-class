/*
 *	Address space example for INU OS class
 * 
 *  Written by ypkim@inu.ac.kr
 *  Created: 2020. 10
 *  Updated: 2022. 4
 */

#include<stdio.h>
#include<stdlib.h>

//#define DO_IT

int main()
{
	int var=9;
	int *ptr;
start:	printf("main	= %p\n", main);
	printf("heap	= %p\n", malloc(sizeof(int)*1));
	printf("stack	= %p\n", &var);

	printf("part 1:\n");
	ptr = &var;
	printf("%08x %08x %08x %08x\n%08x %08x %08x %08x\n",
			*ptr, *(ptr+1), *(ptr+2), *(ptr+3), 
			*(ptr+4), *(ptr+5), *(ptr+6), *(ptr+7));
	printf("part 2:\n");
	ptr = (int *)main;
	printf("%08x %08x %08x %08x\n%08x %08x %08x %08x\n",
			*ptr, *(ptr+1), *(ptr+2), *(ptr+3), 
			*(ptr+4), *(ptr+5), *(ptr+6), *(ptr+7));

#ifdef DO_IT
	*ptr = *(ptr+1) = *(ptr+2) = *(ptr+3) = *(ptr+4) = 0x90;
	goto start;
#endif
	
	return 0;
}

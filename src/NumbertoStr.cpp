/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int power(int pow);
int revofnum(int num);
int numtostr(char *arr, int num, int pivot);


void number_to_str(float number, char *str,int afterdecimal)
{
	int inum, pivot, ftemp;
	float fnum;
	if (number >= 0)
	{
		inum = (int)number;
		fnum = (number - inum)*power(afterdecimal);
		ftemp = (int)fnum;
		inum = revofnum(inum);
		pivot = numtostr(str, inum, 0);
		str[pivot + 1] = '.';
		ftemp = revofnum(ftemp);
		printf("%d\n\n", ftemp);
		numtostr(str, ftemp, pivot + 2);
	}
	else
	{
		number = number*-1;
		inum = (int)number;
		fnum = (number - inum)*power(afterdecimal);
		ftemp = (int)fnum;
		inum = revofnum(inum);
		str[0] = '-';
		pivot = numtostr(str, inum, 1);
		str[pivot + 1] = '.';
		ftemp = revofnum(ftemp);
		printf("%d\n\n", ftemp);
		numtostr(str, ftemp, pivot + 2);
	}
}
int power(int pow)
{
	int index, a = 1;
	for (index = 0; index < pow; index++)
		a = a * 10;
	return a;
}
int revofnum(int num)
{
	int revnum, temp;
	temp = num % 10;
	num = num / 10;
	revnum = temp;
	revnum = revnum * 10;
	while (num != 0)
	{
		temp = num % 10;
		num = num / 10;
		revnum = revnum + temp;
		revnum = revnum * 10;
	}
	return revnum / 10;
}
int numtostr(char *arr, int num, int pivot)
{
	int index, temp;
	for (index = pivot; index<20; index++)
	{
		temp = num % 10;
		num = num / 10;
		arr[index] = temp + '0';
		if (num == 0)
			break;
	}
	return index;
}

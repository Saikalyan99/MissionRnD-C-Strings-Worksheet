/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>

void strrev(char *, int, int);
void str_words_in_rev(char *input, int len)
{
	strrev(input, 0, len - 1);
	int index1 = 0, index2 = 0;
	while (index2 < len)
	{
		while (input[index2] != ' '&&input[index2] != '\0')
			index2++;
		strrev(input, index1, index2 - 1);
		index2 = index2 + 1;
		index1 = index2;
	}
}
void strrev(char *input, int pivot, int len)
{
	int temp, index, index1;
	for (index = pivot, index1 = len; index < index1; index++, index1--)
	{
		temp = input[index];
		input[index] = input[index1];
		input[index1] = temp;
	}
}
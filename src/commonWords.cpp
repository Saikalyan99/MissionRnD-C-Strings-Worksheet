/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return NULL;
	else
	{
		int index1 = 0, index2 = 0, strindex = 0, flag = 0, count, resindex = 0;
		char temp[10][31] = { "\0" }, **result = (char **)malloc(10 * sizeof(char*));
		for (int i = 0; i < 10; i++)
		{
			result[i] = (char *)malloc(sizeof(char) * 31);
		}
		result[0][0] = '\0';

		while (str1[index1] != '\0')
		{
			if (str1[index1] != ' ')
			{
				while (str1[index1] != ' ' && str1[index1] != '\0')
				{
					temp[strindex][index2++] = str1[index1];
					index1++;
				}
				temp[strindex][index2] = '\0';
				index2 = 0;
				strindex++;
			}
			else
				index1++;
		}
		count = strindex - 1;
		strindex = 0;
		index1 = 0;
		if (temp[0][0] == '\0')
			return NULL;
		while (strindex != count)
		{
			while (str2[index1] != '\0')
			{
				if (str2[index1] == temp[strindex][0])
				{
					while (temp[strindex][index2] != '\0')								//compare the strings
					{
						if (temp[strindex][index2] == str2[index1])
							flag++;
						index1++;
						index2++;
					}
					index2 = 0;
					while (temp[strindex][index2] != '\0')								//length of the word
						index2++;

					if (flag == index2)													//if word is there in str2 then TRUE
					{
						index2 = 0;
						while (temp[strindex][index2] != '\0')							//copying into the string
						{
							result[resindex][index2] = temp[strindex][index2];
							index2++;
						}
					}
					if (flag != 0)														//jumping to next word
					{
						result[resindex][index2] = '\0';
						resindex++;
						flag = 0;
					}
				}
				index1++;
				index2 = 0;
			}
			strindex++;
			index1 = 0;
			index2 = 0;
		}
		if (result[0][0] == '\0')
			return NULL;
		else
			return result;
	}
}
/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) 
{
	if (str == "" || str == '\0')
		return '\0';
	else
	{
		int index=0, index1 = 0;
		while (str[index] != '\0')
		{
			if (str[index] != ' ')
				str[index1++] = str[index];
			index++;
		}
		str[index1] = '\0';
		return *str;
	}
}
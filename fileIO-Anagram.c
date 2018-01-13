/*	I Pledge my Honor that I have not cheated, and will not cheat, on this assignment - Si Dang
	The program is finding anagram from a file and then output the result to another file
	with an extension .ang after the input file.
	Goals of this program are for practicing reading and writting files (I/O) in C.	
	The program was wittern by Si Dang #U25273656 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXF 1000 /*file contains 1000 characters*/
#define MAXL 100 /*each line has 100 words*/

//declare anagram function
int are_anagram(char* word1, char* word2);

int main()
{
	FILE *fileR; /*File read mode pointer*/ 
	FILE *fileW; /*file write mode pointer*/
	char buff[MAXL][MAXL];
	int count = 0, line = 1;
	char flr[MAXF]; /*file read*/
	char flw[MAXF]; /*file write*/
	
	//prompt users enter the file name
	printf("Enter the file name: ");
	scanf("%s", flr);
  
	fileR = fopen(flr, "r"); /*open the user's file in read mode*/
	//File is not found, print out a message then stop compiling
	if (fileR == NULL) 
	{
		printf("Error! File has not found!\n");
		return 1;
	}
	
	sprintf(flw, "%s.ang", flr);/*add .ang extension to the file that the users input*/

	fileW = fopen(flw, "wt");/*open the user's file in write mode*/
	//File is not found, print out a message then stop compiling
	if (fileW == NULL) 
	{
		printf("Error! File has not found!\n");
		return 1;
	}

	//read the words from the file line by line
	while(!feof(fileR)) /*if it is not reachs the end of the file*/
	{
		fgets(buff[count], MAXF, fileR);
		count++;
	}
	
  	int i, j;
	//anagram checking - 2 dimensional array
	for(i = 0; i < count; i++)
	{
		for(j = i + 1; j < count; j ++)
		{
			if(are_anagram(buff[i], buff[j]))
				{
					fprintf(fileW,"%d. %s   %s", line, buff[i], buff[j]); //write the result in to file write
					line++;
				}
		}
	}
	//closing file read and write
	fclose(fileR);
	fclose(fileW);
	//prompt the users that the program has done successfully
	printf("\nAnagrams are written to file: %s.ang\n", flr);
	return 0;
}

//anagram function was given
int are_anagram(char* word1, char* word2)
{
	int letter_counts[26] = { 0 };
	char* p;
	char* q;
	int i, count = 0;
	char ch;
	for (p = word1; *p != '\0'; p++)
	{
		if (isalpha(*p)) 
		{
			ch = tolower(*p);
			letter_counts[ch - 'a']++;
		}
	}
	for (q = word2; *q != '\0'; q++)
	{
		if (isalpha(*q)) 
		{
			ch = tolower(*q);
			letter_counts[ch - 'a']--;
		}
	}
	for (i = 0; i < 26; i++) 
	{
		if (letter_counts[i] == 0)
		{
			count++;
		}
	}
	if (count == 26)
	{
		return 1;
	}
	else
	{
		return 0;
	}
return 0;
}

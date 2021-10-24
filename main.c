#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*******  COMP201 LAB3 ASSIGNMENT *******/

//Erdem Özkur



/*
 * checks if the contents of string str1 and str2 are equal
 * Use strcmp() function to compare
 * return 1 if equal. Else 0.
 * YOU MAY USE ANY STRING FUNCTION
 */
int equalStr(char str1[], char str2[]){
	// write your code below

		if(strcmp(str1,str2) != 0){
		return 0;
	}
	else{	
		for(int i=0; i < strlen(str1); i++){
			if(str1[i] != str2[i]) return 0;
		}
	}

	return 1;
}



/*
 * DO NOT USE any string functions
 * You can only use strlen()
 * replace first n characters of str1[] with '*'
 * string length will be > n
 * Example: occludeStr("Efehan", 3) = "***han"
 */
char* occludeStr(char str1[], int n)
{

	// write your code below

	char* ret;

	for(int i=0; i < n; i++){
		str1[i] = '*';
	}

    return str1;
	
}


/*
 * find the substring "key" in str
 * DO NOT USE any string functions 
 * You can only use strlen()
 * returns the index of "k" of substring "key"
 * returns -1 if not found
 * For example: findKey("this key") == 5;
 * For example: findKey("hello world") == -1;
 */
int findKey(char str[])
{
	// write your code below
	
	for(int i = 0; i < strlen(str) - 2; i++){
		if(str[i] == 'k' && str[i+1] == 'e' && str[i+2] == 'y') {
			return i;
		}
	}

	return -1;
	
}

/* Find number of occurrences of word str1 in the sentence str2 (not case sensitive)
 * Returns 0 if not found
 * For Example: numOccur( "WE", "We few, we happy few, we band of brothers") = 3
 * YOU MAY USE ANY STRING FUNCTION
 */
int numOccur(char str1[] ,char str2[])
{
	// write your code below
	char* nstr1 = tolower(str1);
	char* nstr2 = tolower(str2); 
	int count = 0;
	while(strstr(str2, str1) != NULL){
		count++;
	}


	return count;
	
}

/* Find the max occuring char in str (case sensitive)
 * For Example: maxOccurChar("We few, we happy few, we band of brothers") = 'e'
 * Do not count whitespaces.
 * DO NOT USE any string functions
 * You can only use strlen()
 */
char maxOccurChar(char str[])
{
	// write your code below
	int freqArr[170];
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == ' '){

		}else{
			freqArr[str[i]]++;
		}
	}

	int max = 0;
	int maxind = -1;

	for(int i = 0; i < 170; i++){
		if(max < freqArr[i]){
			max = freqArr[i];
			maxind = i;
		}
	}

	char ret =  i;
	return  ret;
}

/* Implement the atoi function in the standart C library
 * Atoi Function: Given a string as an input it returns corresponding integer number
 * Note: Ignore whitespace characters.
 * Attention: Check sign bits, if the number starts with a '+' treat it as positive, if it is '-' treat it as negative. If there is no sign it is positive.
 * If the number starts with a char other then whitespace or a number return 0.
 * If a char other than a number or a whitespace is encountered end the algorithm and return the number you have found up to that point. 
 * Return 0 if a string representation cannot be formulated.
 * For Example: atoiF("+278") = 278
 * For Example: atoiF("   -15") = -15
 * For Example: atoiF("278 with words") = 278
 * For Example: atoiF("Words and -900") = 0
 * YOU MAY USE ANY STRING FUNCTION.
 * You cannot use atoi() from the standard library (You can use it for testing purposes)
 * Note: We will not test against overflows you can ignore them.
 */
int atoiF(char str1[])
{
	// write your code below

	int sign = 1;
	int value = 0;
	int digits = 0;

	for(int i = 0; i < strlen(str1); i++){
		if(str1[i] != ' '){
			
			if(digits == 0 && str1[i] == '-'){
				sign = -1;
			}
			else if(str[i] < 48 || str[i] > 57){
				return value;
			}
			else{
				int number = str[i] - '0';
				value = value * 10;
				value += number;
			}

		}
	}

	return value;
}


int main() 
{
	//You can test your functions here
	//We will modify the main() when grading

	printf("Atoif : +278 = %d\n", atoiF("+278"));
	printf("Atoif : '   -15' = %d\n", atoiF("    -15"));
	printf("Atoif : '+278 bla' = %d\n", atoiF("278 bla"));
	printf("Atoif : 'words123' = %d\n", atoiF("words123"));

	printf("max occur : 'We few, we happy few, we band of brothers' = %c\n", maxOccurChar("We few, we happy few, we band of brothers"));



	return 0;
}

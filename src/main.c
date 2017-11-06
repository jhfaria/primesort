 /*****************************************************\
|														|
|	João Henrique Faria		RA170501	05/11/2017		|
|														|
|	** Prime Sort ** 									|
|														|
|	* Tests *											|
|														|
|		05/05 (100%)									|
|														|
|	~ lines with '//' were used for measuring the time	|
|														|
 \*****************************************************/

/* library inclusion */
#include <stdio.h>
#include <stdlib.h>

// #include <time.h>

/* funtion to check is the number is a prime */
int check_primo(int numero);

int main()
{
	/* variable declaration */
	FILE *input;
	char buff[10];

	// clock_t begin, end;
	// double time_spent;

	// begin = clock();

	/* reads all the numbers from the input, sorting them from the greatest to the least */
	if(!(input = popen("cat | sort -r -g", "r"))) {return 1;}

	/* checks if the number is a prime, and prints if not */
	while(atoi(fgets(buff, sizeof(buff), input)) != -1) 
	{
		if(check_primo(atoi(buff)) != 2) {printf("%d\n", atoi(buff));}
	}

	pclose(input);

	// end = clock();
	
	// time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	// printf("%f\n", time_spent);

	return 0;
}

int check_primo(int numero)
{
	int i;

	int resposta;

	resposta = 1;

	if(numero == 1) {return 1;}

	for(i=2; i <= numero/2; i++)
	{
		if((numero%i) == 0) {resposta++;}

		if(resposta > 2) {break;}
	}

	return 2*resposta;
}
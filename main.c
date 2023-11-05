/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

//Bibliotecas e Arquivos usados:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./Aux_Libraries/Aluno.h"
#include "./Aux_Libraries/IO-functions.h"
#include "./Aux_Libraries/Sorting-Algorithms.h"
#include "./Aux_Libraries/Generate-Input.h"
#include "./Aux_Libraries/Menu.h"
#define MAX_SIZE 150

int main(){
	FILE *input, *output; //Ponteiro para os arquivos de entrada e saida

	input = fopen(INPUT, "r"); //Le o arquivo de entrada

	if(input == NULL){
		printf("Erro ao tentar abrir o arquivo.\n");
		return -1;
	}

	//Conta o número de linhas e realiza a alocação de memória
	int n_lines = 0;
	char* line = (char*)calloc(MAX_SIZE, sizeof(char));

	while(!feof(input)){
		fgets(line, MAX_SIZE, input);
		n_lines++;
	}
	fclose(input); //Fecha o arquivo de entrada para reabrir em seguida

	aluno* lista = (aluno*)calloc(n_lines, sizeof(aluno)); //Cria a lista de alunos alocando a memoria dinamicamente

	entrada(input, lista); //Passa a entrada digitada e a lista para função entrada

	Menu(lista, n_lines); //Mostra o menu ao usuario e realiza a ordenação de acordo com a função Menu()

	output = fopen(OUTPUT, "w"); //Define a variavel saída para que ela escreva no arquivo final de saída

	saida(lista, n_lines, output); //Escreve um CSV ordenado para o usuário final

	fclose(output); //Fecha o arquivo de saída

	free(line); //Libera a alocação de memória feita em linhas
	free(lista); //Libera a memória alocada em lista

	return 0;
}

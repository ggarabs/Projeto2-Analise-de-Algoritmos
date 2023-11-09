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

	int resp, qtd = 0;
	do {
		Menu(MENU);

		scanf("%d", &resp); //Guarda a resposta dada pelo usuario

		switch(resp){ //Passa os parametros de acordo com a ordenação desejada
			case 1:
				printf("Digite o número de alunos a serem gerados: ");
				scanf("%d", &qtd);
				GerarEntrada(qtd);
				break;
			case 2:
//				BubbleSort(lista, tam);
				break;			
			case 3:
//				MergeSort(lista, tam);
				break;
			case 4:
				break;
			default: //Se digitou invalido, apresenta para o usuario digitar novamente
				printf("Valor inválido, por favor digite novamente: ");
		}

	} while (resp != 4);

/*	entrada(input, lista); //Passa a entrada digitada e a lista para função entrada

	output = fopen(OUTPUT, "w"); //Define a variavel saída para que ela escreva no arquivo final de saída

	saida(lista, n_lines, output); //Escreve um CSV ordenado para o usuário final

	fclose(output); //Fecha o arquivo de saída

	free(lista); //Libera a memória alocada em lista
*/
	return 0;
}

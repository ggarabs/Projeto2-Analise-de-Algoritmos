/* PROJETO II DE ANÁLISE DE ALGORIMOS I

	INTEGRANTES: 

	- Felipe do Nascimento Fonseca	| 4221536-6
	- Giovanni Alves Lavia			| 4221836-5
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

//Bibliotecas e Arquivos usados:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "./Aux_Libraries/Student.h"
#include "./Aux_Libraries/IO-functions.h"
#include "./Aux_Libraries/Sorting-Algorithms.h"
#include "./Aux_Libraries/Generate-Input.h"
#include "./Aux_Libraries/Menu.h"

#define MAX_SIZE 150 // Tamanho maximo do nome dos alunos

const char MENU[] = "./Secundary_archives/menu.txt"; //O menu foi configurado através de um txt
const char INPUT[] = "./IO_archives/entrada.csv";
const char *SUBJECT[] = {"matematica", "portugues", "geografia"};
const char NAME_LIST[] = "./Secundary_archives/nomes.txt";

int main(){
    srand(time(NULL));

	student *list;

	int ans, qtd = 0;
	bool ordered = false, undefined_data = true;
	long long int steps = 0;

	clock_t start, end;
	double cpu_time_used;

	do {
		ShowMenu(MENU); // Exibe o menu

		printf("\n                        Digite uma opção: ");
		scanf("%d", &ans); //Guarda a resposta dada pelo usuario

		switch(ans){ //Passa os parametros de acordo com a ordenação desejada
			case 1:
				printf("Digite o número de alunos a serem gerados: ");
				scanf("%d", &qtd);

				list = (student*)calloc(qtd, sizeof(student));

				GenerateInput(NAME_LIST, SUBJECT, list, qtd);
				WriteInput(INPUT, list, qtd);

				printf("Lista de dados gerados com sucesso! Pra verificá-los, consulte o arquivo entrada.csv\n");

				ordered = undefined_data = false;

				break;
			case 2:
				if(undefined_data){
					printf("Não há dados a serem ordenados! Por favor gere novos dados.");
					break;
				}
				else if(ordered){
					printf("Lista de alunos já ordenada! Por favor gere novos dados.");
					break;
				}

				steps = 0;
				start = clock();
				BubbleSort(list, qtd, &steps);
				end = clock();

				cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;

				WriteOutput(OUTPUT, list, qtd);

				printf("\n             Lista de alunos ordenada com sucesso!\n\n"); //Mostra que a lista foi ordenada com sucesso
				printf("\nAlgoritmo: Bubble Sort\n");
				printf("\nTamanho Entrada: %d.\n", qtd);
				printf("\nTempo execução: %.1f segundos. \n", cpu_time_used);
				printf("\nComparações(passos): %lld.\n\n", steps);

				ordered = true;

				break;			
			case 3:
				if(undefined_data){
					printf("Não há dados a serem ordenados! Por favor gere novos dados.");
					break;
				}
				else if(ordered){
					printf("Lista de alunos já ordenada! Por favor gere novos dados");
					break;
				}

				steps = 0;
				start = clock();
				MergeSort(list, qtd, &steps);
				end = clock();

				cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;

				WriteOutput(OUTPUT, list, qtd);

				printf("\n             Lista de alunos ordenada com sucesso!\n\n"); //Mostra que a lista foi ordenada com sucesso
				printf("\nAlgoritmo: Merge Sort\n");
				printf("\nTamanho Entrada: %d\n", qtd);
				printf("\nTempo execução: %.1f segundos. \n", cpu_time_used);
				printf("\nComparações(passos): %lld\n\n", steps);

				ordered = true;

				break;
			case 4:
				break;
			default: //Se digitou invalido, apresenta para o usuario digitar novamente
				printf("Valor inválido, por favor digite novamente: ");
		}

	} while (ans != 4);

	free(list);

	return 0;
}

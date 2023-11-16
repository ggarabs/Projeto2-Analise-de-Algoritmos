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
#include "./Aux_Libraries/SystemFunctions.h"

#if __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#elif _WIN64
	#include <windows.h>
#endif

#define MAX_SIZE 150 // Tamanho maximo do nome dos alunos

const char MENU[] = "./Secundary_archives/menu.txt"; //O menu foi configurado através de um txt
const char INPUT[] = "./IO_archives/entrada.csv"; // Arquivo de entrada gerado pelo usuário
const char OUTPUT[] = "./IO_archives/saida.csv"; // Arquivo de saida onde serão inseridos os dados ordenados
const char *SUBJECT[] = {"matematica", "portugues", "geografia"}; // matérias que serão usadas na geração aleatória
const char NAME_LIST[] = "./Secundary_archives/nomes.txt"; // nomes que serão usados na geração aleatória

int main(){
    srand(time(NULL)); // gero a semente da função de geração pseudo-aleatória a partir do instante atual

	student *list; // lista atual de alunos a serem gerados aleatoriamente

	int ans, qtd = 0; // resposta do usuário no menu e tamanho da lista escolhido pelo usuário
	bool ordered = false, undefined_data = true; // flags de progressão de usabilidade
	long long int steps = 0;
	char interrupt;

	clock_t start, end; // marcadores de inicio e fim de processamento
	double cpu_time_used;

	do {
		ShowMenu(MENU); // Exibe o menu

		printf("\n               Digite uma opção: ");
		scanf("%d", &ans); //Guarda a resposta dada pelo usuario

		switch(ans){ //Passa os parametros de acordo com a função desejada
			case 1:
				
				do{ // coleta do número de alunos a ser gerados com tratamento de valor inválido
					printf("\nDigite o número de alunos a serem gerados: ");
					scanf("%d", &qtd);
					if(qtd <= 0){
						printf("Valor inválido! Digite novamente.\n");
						sleep(2);
						clearScreen(); // aguarda 2 segundos e limpa a tela
					}
				} while (qtd <= 0);

				printf("Aguarde! Gerando alunos...\n");
				sleep(1);
				clearScreen();

				list = (student*)calloc(qtd, sizeof(student)); // aloca dinamicamente uma lista de estudantes

				GenerateInput(NAME_LIST, SUBJECT, list, qtd); // gera elementos da lista e guarda na estrutura
				WriteInput(INPUT, list, qtd); // grava os dados da estrutura no arquivo

				printf("Lista de alunos gerada com sucesso! \nPara visualizá-los, consulte o arquivo entrada.csv");
				printf("\n");

				sleep(3);
				clearScreen();

				ordered = undefined_data = false; // dados não ordenados, mas já definidos

				break;
			case 2:
				if(undefined_data){ // tratativa para o caso de não existirem dados
					printf("Não há dados a serem ordenados! Por favor gere novos dados.");
					break;
				}
				else if(ordered){ // tratativa para caso os dados já tenham sido ordenados
					printf("Lista de alunos já ordenada! Por favor gere novos dados.");
					break;
				}

				printf("\nOrdenando lista de alunos...");
				printf("\n");

				sleep(2);
				clearScreen();

				// Realiza a ordenação e conta quantos clocks e passos o algoritmo usou

				steps = 0;
				start = clock();
				BubbleSort(list, qtd, &steps);
				end = clock();

				cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC; // tempo do programa: numeros de ciclos de clock por clocks por segundo

				WriteOutput(OUTPUT, list, qtd); // escreve dados ordenados da estrutura no arquivo de saída

				ShowAlgorithmPerformance(qtd, cpu_time_used, steps, "Bubble Sort"); // mostra dados da ordenação

				ordered = true; // dados já ordenados

				getchar();
				printf("Deseja seguir utilizando o programa? [s/N]: "); // Aplicada a escolha ao usuário de retornar ao menu ou finalizar o programa
				interrupt = getchar();

				if(interrupt == 'n' || interrupt == 'N') ans = 4;
				else break;

			case 3:
				if(ans == 4) continue; // pula para o caso 4 se o caso 2 tiver retotnado com a escola de sair do programa
				if(undefined_data){
					printf("Não há dados a serem ordenados! Por favor gere novos dados.");
					break;
				}
				else if(ordered){
					printf("Lista de alunos já ordenada! Por favor gere novos dados.");
					break;
				}

				printf("\nOrdenando lista de alunos...");
				printf("\n");

				sleep(2);
				clearScreen();

				steps = 0;
				start = clock();
				MergeSort(list, qtd, &steps);
				end = clock();

				cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC; // tempo do programa: numeros de ciclos de clock por clocks por segundo

				WriteOutput(OUTPUT, list, qtd); // escreve dados ordenados da estrutura no arquivo de saída

				ShowAlgorithmPerformance(qtd, cpu_time_used, steps, "Merge Sort"); // mostra dados da ordenação

				ordered = true; // dados já ordenados

				printf("Deseja seguir utilizando o programa? [s/N]: ");
				scanf("%c", &interrupt);

				if(interrupt == 'n' || interrupt == 'N') ans = 4;
				else break;

			case 4:
				break;
			default: //Se digitou invalido, apresenta para o usuario digitar novamente
				printf("Valor inválido, por favor digite novamente: ");
		}

	} while (ans != 4);

	free(list); // libera espaço da memória alocada dinâmicamente

	return 0;
}

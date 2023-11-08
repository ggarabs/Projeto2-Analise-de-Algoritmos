#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define ANOS 14
#define ANO_INICIAL 2010
#define TAM_LISTA 40
#define MAX_SIZE 150 //Define o tamanho maximo do nome como 150

struct Aluno{ //Estrutura Aluno
	int ano;
	char nome[MAX_SIZE], disciplina[MAX_SIZE];
	double media;
};

typedef struct Aluno aluno; //Renomeia a struct Aluno para simplificar a escrita de código

char LISTA_NOMES[] = "./Secundary_archives/nomes.txt";

int main(){
    srand(time(NULL));

    int ano = rand() % ANOS + ANO_INICIAL;
    char line[MAX_SIZE];

    int n_nome = rand() % TAM_LISTA + 1, n_line = 1;

    FILE* arq_nomes = fopen(LISTA_NOMES, "r");

    if(arq_nomes == NULL){
		printf("Erro ao tentar abrir o arquivo.\n");
		return -1;
    }

    while(!feof(arq_nomes) && n_line < n_nome){
        fgets(line, MAX_SIZE, arq_nomes);
        n_line++;
    }

    fgets(line, MAX_SIZE, arq_nomes);

    char nome[MAX_SIZE];
    strcpy(nome, line);

    printf("%d %s", n_nome, nome);

    return 0;
}
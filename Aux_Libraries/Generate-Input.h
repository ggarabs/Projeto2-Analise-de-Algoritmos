#include <stdlib.h>
#define ANOS 14
#define ANO_INICIAL 2010
#define TAM_LISTA 40

char LISTA_NOMES[] = "./../Secundary_archives/nomes.txt";

void GerarEntrada(aluno* lista, int tam){
    int n_alunos = 0;
    srand(time(NULL));
    while(n_alunos < tam){
        int ano = rand() % ANOS + ANO_INICIAL;

        int n_nome = rand() % TAM_LISTA + 1, id_final = rand() % 1000;
        FILE* arq_nomes = fopen(LISTA_NOMES, "r");

        while(!feof){
            
        }

        n_alunos++;
    }
}
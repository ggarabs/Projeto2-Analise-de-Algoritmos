#include <stdlib.h>
#define ANOS 14
#define ANO_INICIAL 2010
#define TAM_LISTA 40

char LISTA_NOMES[] = "./../Secundary_archives/nomes.txt";
char DISCIPLINAS[MAX_SIZE][3] = {"matemática", "português", "geografia"};
char INPUT[] = "./../IO-archives/entrada.csv";

void GerarEntrada(aluno* lista, int tam){
    int n_alunos = 0;
    srand(time(NULL));

    FILE* input = fopen(INPUT, "w");

    while(n_alunos < tam){
        int ano = rand() % ANOS + ANO_INICIAL;

        int n_nome = rand() % TAM_LISTA + 1, line = 0;

        char ID[6] = "", name[MAX_SIZE] = "";
        for(int i = 0; i < 6; i++) strcat(ID, (char)(rand()%10+'0'));

        FILE* arq_nomes = fopen(LISTA_NOMES, "r");

        if(arq_nomes == NULL){
		    printf("Erro ao tentar abrir o arquivo.\n");
		    return -1;
        }

        while(!feof(arq_nomes) && line <= n_nome){
            fgets(name, MAX_SIZE, arq_nomes);
            line++;
        }

        strcat(name, ID);

        char disciplina[MAX_SIZE];
        strcpy(disciplina, DISCIPLINAS[rand()%3]);

        double media = (rand()%101)/10.0;

        fprintf(input, "%d,", ano);
        fprintf(input, "%s,", name);
        fprintf(input, "%s,", disciplina);
        fprintf(input, "%f\n", media);

        n_alunos++;
    }
}
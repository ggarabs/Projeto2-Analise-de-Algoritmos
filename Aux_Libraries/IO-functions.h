/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

//Biblioca que realiza as funçoes de sistema
#define MAX_SIZE 150

const char INPUT[] = "./IO-archives/entrada.csv", OUTPUT[] = "./IO-archives/saida.csv"; //Passa o arquivo CSV

void entrada(FILE* input, aluno* lista){ //Recebe a entrada com o arquivo CSV e aloca memoria
	input = fopen(INPUT, "r");
	
	//Aloca a memoria atraves de calloc
	char* line = (char*)calloc(MAX_SIZE, sizeof(char));
	char* buffer = (char*)calloc(MAX_SIZE, sizeof(char));

	//Faz um split da linha do csv e desestrutura as características do objeto, colocando na lista
	while(!feof(input)){
		fgets(line, MAX_SIZE, input);

		lista->semestre = (int)(*line-'0');
		lista->turma = *(line+2);
		lista->periodo = *(line+4);
		
		int j = 6;
		while(*(line+j) != ','){
			*buffer = *(line+j);
			buffer++, j++;
		}
		*buffer = '\0';
		buffer -= ++j-7;

		strcpy(lista->nome, buffer);

		int k = j;
		while(*(line+j) != ','){
			*buffer = *(line+j);
			buffer++; j++;
		}
		*buffer = '\0';
		buffer -= j-k;

		strcpy(lista->disciplina, buffer);

		lista->media = (double)((int)(*(line+j+1)-'0') + (int)(*(line+j+3)-'0')/10.0);

		lista++;
	}
}

//Grava a saída em um CSV já ordenado qundo a função é chamada
void saida(aluno* vetor, int tamanho, FILE *output){
    fprintf(output, "SEMESTRE,TURMA,PERIODO,NOME,DISCIPLINA,MEDIA\n");
	int i = 0;
	while(i < tamanho){
        fprintf(output, "%d,", vetor->semestre);
		fprintf(output, "%c,", vetor->turma);
		fprintf(output, "%c,", vetor->periodo);
		fprintf(output, "%s,", vetor->nome);
		fprintf(output, "%s,", vetor->disciplina);
		fprintf(output, "%.1f\n", vetor->media);
		i++; vetor++;
	}
	printf("\n             Lista de alunos ordenada com sucesso!\n\n"); //Mostra que a lista foi ordenada com sucesso
}

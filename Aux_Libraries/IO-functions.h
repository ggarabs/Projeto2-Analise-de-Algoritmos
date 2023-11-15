/* PROJETO II DE ANÁLISE DE ALGORIMOS I

	INTEGRANTES: 

	- Felipe do Nascimento Fonseca	| 4221536-6
	- Giovanni Alves Lavia			| 4221836-5
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

bool WriteInput(const char* INPUT, student* list, int tam){ //Recebe a entrada com o arquivo CSV e aloca memoria
	FILE* input = fopen(INPUT, "w");

	if(NULL == input){
		printf("Erro ao tentar abrir o arquivo entrada.csv.\n");
		fclose(input);
		return false;
	}

	int line = 0;

    fprintf(input, "ANO,NOME,DISCIPLINA,MEDIA\n"); //Grava os labels das colunas do csv no arquivo de saída 
	while(line < tam){ // guarda cada aluno da estrutura no arquivo de saída
		fprintf(input, "%d,", list->year);
		fprintf(input, "%s,", list->name);
		fprintf(input, "%s,", list->subject);
		fprintf(input, "%.1f\n", list->mean);
		line++;list++;
	}

	fclose(input);
	return true;
}

//Grava a saída em um CSV já ordenado qundo a função é chamada
bool WriteOutput(const char* OUTPUT, student* list, int tam){
	FILE* output = fopen(OUTPUT, "w");

	if(NULL == output){
		printf("Erro ao abrir o arquivo saida.csv");
		fclose(output);
		return false;
	}

	int line = 0;

    fprintf(output, "ANO,NOME,DISCIPLINA,MEDIA\n"); // Grava os labels das colunas do csv no arquivo de saída
	while(line < tam){ // guarda cada aluno da estrutura no arquivo de saída
		fprintf(output, "%d,", list->year);
		fprintf(output, "%s,", list->name);
		fprintf(output, "%s,", list->subject);
		fprintf(output, "%.1f\n", list->mean);
		line++; list++;
	}
	fclose(output);

	return true;
}

//Grava a saída em um CSV já ordenado qundo a função é chamada
void ShowAlgorithmPerformance(int size, double time, long long int swaps, char* algorithmName){
	printf("\n             Lista de alunos ordenada com sucesso!\n\n"); //Mostra que a lista foi ordenada com sucesso
	printf("\nAlgoritmo: %s\n", algorithmName);
	printf("\nTamanho Entrada: %d.\n", size);
	printf("\nTempo execução: %.1f segundos. \n", time);
	printf("\nComparações(passos): %lld.\n\n", swaps);
}
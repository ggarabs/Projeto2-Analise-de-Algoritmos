/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

const char OUTPUT[] = "./IO_archives/saida.csv"; //Passa o arquivo CSV

void WriteInput(const char* INPUT, student* list, int tam){ //Recebe a entrada com o arquivo CSV e aloca memoria
	FILE* input = fopen(INPUT, "w");

	if(NULL == input){
		printf("Erro ao tentar abrir o arquivo entrada.csv.\n");
		fclose(input);
		return;
	}

	int line = 0;

    fprintf(input, "ANO,NOME,DISCIPLINA,MEDIA\n");
	while(line < tam){
		fprintf(input, "%d,", list->year);
		fprintf(input, "%s,", list->name);
		fprintf(input, "%s,", list->subject);
		fprintf(input, "%.1f\n", list->mean);
		line++;list++;
	}

	fclose(input);
}

//Grava a saída em um CSV já ordenado qundo a função é chamada
void WriteOutput(const char* OUTPUT, student* list, int tamanho){
	FILE* output = fopen(OUTPUT, "w");

	if(NULL == output){
		printf("Erro ao abrir o arquivo saida.csv");
		fclose(output);
		return;
	}

	int line = 0;

    fprintf(output, "ANO,NOME,DISCIPLINA,MEDIA\n");
	while(line < tamanho){
		fprintf(output, "%d,", list->year);
		fprintf(output, "%s,", list->name);
		fprintf(output, "%s,", list->subject);
		fprintf(output, "%.1f\n", list->mean);
		line++; list++;
	}
	fclose(output);
}
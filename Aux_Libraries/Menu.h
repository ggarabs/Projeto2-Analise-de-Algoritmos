/* PROJETO II DE ANÁLISE DE ALGORIMOS I

	INTEGRANTES: 

	- Felipe do Nascimento Fonseca	| 4221536-6
	- Giovanni Alves Lavia			| 4221836-5
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

bool ShowMenu(const char link[]){ //Realiza a leitura do arquivo de menu e imprime na tela do usuario
	FILE* arc;

	arc = fopen(link, "r");

	if(NULL == arc){
		printf("Erro ao exibir o menu!");
		return false;
	}

	while(!feof(arc)){ // Imprime o Menu linha a linha
		char line[MAX_SIZE];
		if(NULL != fgets(line, MAX_SIZE, arc)) printf("%s", line);
	}

	fclose(arc);
	return true;
}

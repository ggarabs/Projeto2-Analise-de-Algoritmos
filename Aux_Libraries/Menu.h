/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6
	- Giovanni Alves Lavia          | 4221836-5

*/

void ShowMenu(const char link[]){ //Realiza a leitura do arquivo de menu e imprime na tela do usuario
	FILE* arc;

	arc = fopen(link, "r");

	if(NULL == arc){
		printf("Erro ao exibir o menu!");
		return;
	}

	while(!feof(arc)){ // Imprime o Menu linha a linha
		char line[MAX_SIZE];
		if(NULL != fgets(line, MAX_SIZE, arc)) printf("%s", line);
	}

	fclose(arc);
}

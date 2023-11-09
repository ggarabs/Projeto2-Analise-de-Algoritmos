/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6
	- Giovanni Alves Lavia          | 4221836-5

*/

//Biblioteca do menu
const char MENU[] = "./Secundary_archives/menu.txt"; //O menu foi configurado através de um txt

void Menu(char link[]){ //Realiza a leitura do arquivo de menu e imprime na tela do usuario
	FILE* arq;

	arq = fopen(link, "r");

	if(NULL == arq) return;

	while(!feof(arq)){ // Imprime o Menu linha a linha
		char line[MAX_SIZE];
		if(NULL != fgets(line, MAX_SIZE, arq)) printf("%s", line);
	}

	fclose(arq);
}

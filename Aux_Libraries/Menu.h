/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6
	- Giovanni Alves Lavia          | 4221836-5

*/

//Biblioteca do menu
const char MENU[] = "./Secundary_archives/menu.txt"; //O menu foi configurado através de um txt

void Menu(aluno* lista, int tam){ //Realiza a leitura do arquivo de menu e imprime na tela do usuario
	int resp = 0;

	while(resp < 1 || resp > 5){
		FILE *arq;

		arq = fopen(MENU, "r");

		if(NULL == arq) return;

		while(!feof(arq)){ // Imprime o Menu linha a linha
			char line[MAX_SIZE];
			if(NULL != fgets(line, MAX_SIZE, arq)) printf("%s", line);
		}

		fclose(arq);
	
		scanf("%d", &resp); //Guarda a resposta dada pelo usuario
		switch(resp){ //Passa os parametros de acordo com a ordenação desejada
			case 1:
				GerarEntrada(lista, tam);
				break;
			case 2:
				BubbleSort(lista, tam);
				break;			
			case 3:
				MergeSort(lista, tam);
				break;
			
			default: //Se digitou invalido, apresenta para o usuario digitar novamente
				printf("Valor inválido, por favor digite novamente: ");
		}
	}
}

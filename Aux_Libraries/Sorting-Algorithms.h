/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

//Biblioteca MergeSort realiza a ordenação, este foi o metódo escolhido para ordenação

// Generaliza a função de comparação como um ponteiro com argumentos fortemente tipados.
/*
void MergeSort(aluno* vetor, int tam){ //Função MergeSort, comparador é uma função.
    if (tam <= 1) return; // Se o vetor for unitário, então já está ordenado

    int meio = tam / 2;

    // Aloca dinamicamente dois vetores pra guardar cada metade da sublista que se busca ordenar
	aluno* vetor1 = (aluno*)calloc(meio+1, sizeof(aluno));
	aluno* vetor2 = (aluno*)calloc(meio+1, sizeof(aluno));

    // Copia cada elemento do vetor original para os dois subvetores
    for (int i = 0; i < meio; i++) *(vetor1+i) = *(vetor+i);
    for (int i = meio; i < tam; i++) *(vetor2+i-meio) = *(vetor+i);

    MergeSort(vetor1, meio);
  	MergeSort(vetor2, tam-meio);

    int p1 = 0, p2 = meio; // ponteiros para cada um dos subvetores

    while (p1 < meio && p2 < tam){ // enquanto nenhum dos subvetores estão "vazios"
        if (isEqual(mtd(*vetor1, *vetor2), *vetor1)){ // se vetor1 < vetor2, coloca vetor1 no vetor resultante
            *vetor = *vetor1; 
			vetor1++;
			p1++;
        } 
        else{ // caso contrário, copie vetor2
            *vetor = *vetor2;
			vetor2++;
			p2++;
        }
		vetor++;
    }

    while (p1 < meio){ // se sobrar elementos em vetor1, copie todos para o vetor original
        *vetor = *vetor1;
		vetor++;
		vetor1++;
        p1++;
    }

    while (p2 < tam){ // se sobrar em vetor2, copie todos dele para vetor original
        *vetor = *vetor2;
		vetor2++;
		vetor++;
        p2++;
    }
}

void BubbleSort(aluno* vetor, int tam){ //Função MergeSort, comparador é uma função.
    if (tam <= 1) return; // Se o vetor for unitário, então já está ordenado

    int meio = tam / 2;

    // Aloca dinamicamente dois vetores pra guardar cada metade da sublista que se busca ordenar
	aluno* vetor1 = (aluno*)calloc(meio+1, sizeof(aluno));
	aluno* vetor2 = (aluno*)calloc(meio+1, sizeof(aluno));

    // Copia cada elemento do vetor original para os dois subvetores
    for (int i = 0; i < meio; i++) *(vetor1+i) = *(vetor+i);
    for (int i = meio; i < tam; i++) *(vetor2+i-meio) = *(vetor+i);

    MergeSort(vetor1, meio);
  	MergeSort(vetor2, tam-meio);
    int p1 = 0, p2 = meio; // ponteiros para cada um dos subvetores

    while (p1 < meio && p2 < tam){ // enquanto nenhum dos subvetores estão "vazios"
        if (p1 < meio){ // se vetor1 < vetor2, coloca vetor1 no vetor resultante
            *vetor = *vetor1; 
			vetor1++;
			p1++;
        } 
        else{ // caso contrário, copie vetor2
            *vetor = *vetor2;
			vetor2++;
			p2++;
        }
		vetor++;
    }

    while (p1 < meio){ // se sobrar elementos em vetor1, copie todos para o vetor original
        *vetor = *vetor1;
		vetor++;
		vetor1++;
        p1++;
    }

    while (p2 < tam){ // se sobrar em vetor2, copie todos dele para vetor original
        *vetor = *vetor2;
		vetor2++;
		vetor++;
        p2++;
    }
}
*/
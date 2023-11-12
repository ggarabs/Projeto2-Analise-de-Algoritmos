/* PROJETO 1 DE PROJETO E ANÁLISE DE ALGORIMOS

INTEGRANTES: 

	- Anderson Correa Nicodemo		| 3228567-1
	- Felipe do Nascimento Fonseca	| 4221536-6
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

void MergeSort(student* array, int size, long long int* steps){ //Função MergeSort, comparador é uma função.
    if (size <= 1) return; // Se o vetor for unitário, então já está ordenado

    int mid = size / 2;

    // Aloca dinamicamente dois vetores pra guardar cada metade da sublista que se busca ordenar
	student* array1 = (student*)calloc(mid+1, sizeof(student));
	student* array2 = (student*)calloc(mid+1, sizeof(student));

    // Copia cada elemento do vetor original para os dois subvetores
    for (int i = 0; i < mid; i++) *(array1+i) = *(array+i);
    for (int i = mid; i < size; i++) *(array2+i-mid) = *(array+i);

    MergeSort(array1, mid, steps);
  	MergeSort(array2, size-mid, steps);

    int p1 = 0, p2 = mid; // ponteiros para cada um dos subvetores

    while (p1 < mid && p2 < size){ // enquanto nenhum dos subvetores estão "vazios"
        *steps = *steps+1;
        if (array1->mean < array2->mean){ // se a média do array1 for menor que a média do array2, coloca array1 no vetor resultante
            *array = *array1; 
			array1++;
			p1++;
        } 
        else{ // caso contrário, copie array2
            *array = *array2;
			array2++;
			p2++;
        }
		array++;
    }

    while (p1 < mid){ // se sobrar elementos em array1, copie todos para o vetor original
        *steps = *steps+1;
        *array = *array1;
		array++;
		array1++;
        p1++;
    }

    while (p2 < size){ // se sobrar em array2, copie todos dele para vetor original
        *steps = *steps+1;
        *array = *array2;
		array2++;
		array++;
        p2++;
    }
}

void BubbleSort(student* array, int size, long long int *steps){
    *steps = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1-i; j++){
            *steps = *steps + 1;
            if((array+j)->mean > (array+j+1)->mean){
                student aux = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = aux;
            }
        }
    }
}
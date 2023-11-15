/* PROJETO II DE ANÁLISE DE ALGORIMOS I

	INTEGRANTES: 

	- Felipe do Nascimento Fonseca	| 4221536-6
	- Giovanni Alves Lavia			| 4221836-5
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

#define YEARS 14
#define INITIAL_YEAR 2010
#define LIST_SIZE 40

bool GenerateInput(const char* NAME_LIST, const char** SUBJECT, student* list, int size){
    int n_students = 0;

    FILE* name_file;

    while(n_students < size){ // enquanto não tivermos tantos alunos quanto desejado
        list->year = rand() % YEARS + INITIAL_YEAR; // gero randomicamente um ano aleatorio entre 2010 e 2023

        int name_number = rand() % LIST_SIZE + 1, line = 0; // gero randomicamente uma linha na lista "nomes.txt"

        char ID[7] = "", aux[2]; // aux armazena um numero entre 0 e 9 gerado randomicamente para armazenar em ID
        
        for(int i = 0; i < 6; i++){
            aux[0] = (char)(rand()%10+'0');
            aux[1] = '\0'; // definir o final da string
            strcat(ID, aux); // guarda o numero sorteado no buffer ID
        }
        ID[6] = '\0';

        name_file = fopen(NAME_LIST, "r");

        if(NULL == name_file){
		    printf("Erro ao tentar abrir o arquivo nomes.txt.\n");
            fclose(name_file);
		    return false;
        }

        char name[MAX_SIZE];

        while(!feof(name_file) && line <= name_number){ // enquanto não se chega na linha gerada
            fgets(name, MAX_SIZE, name_file); // recebe uma nova linha e soma um no contador de linhas
            line++;
        }

        name[strlen(name)-1] = '\0'; // finalizador da string name

        strcpy(list->name, strcat(name,ID)); // guarda o buffer name na struct

        strcpy(list->subject, SUBJECT[rand()%3]); // guarda na struct a disciplina gerada randomicamente

        list->mean = (rand()%101)/10.0; // guarda a media também gerada randomicamente

        n_students++;
        list++;
    }

    fclose(name_file);

    return true; // se conseguiu gerar a lista de alunos, o retorno é verdadeiro
}
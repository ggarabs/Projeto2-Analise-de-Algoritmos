#define ANOS 14
#define ANO_INICIAL 2010
#define TAM_LISTA 40

const char *DISCIPLINAS[] = {"matematica", "portugues", "geografia"};
const char LISTA_NOMES[] = "./Secundary_archives/nomes.txt";
const char INPUT[] = "./IO_archives/entrada.csv";

int GerarEntrada(aluno* list, int tam){
    int n_alunos = 0;
    srand(time(NULL));

    FILE* input = fopen(INPUT, "w"), *arq_nomes;

    if(NULL == input){
        printf("Erro ao tentar abrir o arquivo entrada.csv.\n");
        fclose(input);
        return -1;
    }

    while(n_alunos < tam){
        list->year = rand() % ANOS + ANO_INICIAL;

        int n_nome = rand() % TAM_LISTA + 1, line = 0;

        char ID[7] = "", aux[2];
        
        for(int i = 0; i < 6; i++){
            aux[0] = (char)(rand()%10+'0');
            aux[1] = '\0';
            strcat(ID, aux);
        }
        ID[6] = '\0';

        arq_nomes = fopen(LISTA_NOMES, "r");

        if(NULL == arq_nomes){
		    printf("Erro ao tentar abrir o arquivo nomes.txt.\n");
            fclose(arq_nomes);
            fclose(input);
		    return -1;
        }

        char name[MAX_SIZE];

        while(!feof(arq_nomes) && line <= n_nome){
            fgets(name, MAX_SIZE, arq_nomes);
            line++;
        }

        name[strlen(name)-1] = '\0';

        strcpy(list->nome, strcat(name,ID));

        strcpy(list->disciplina, DISCIPLINAS[rand()%3]);

        list->media = (rand()%101)/10.0;

        fprintf(input, "%d,", list->year);
        fprintf(input, "%s,", list->nome);
        fprintf(input, "%s,", list->disciplina);
        fprintf(input, "%.1f\n", list->media);

        n_alunos++;
        list++;
    }

    printf("Lista de %d alunos gerada com sucesso no arquivo entrada.csv!\n", tam);
    fclose(arq_nomes);
    fclose(input);

    return 1;
}
#define YEARS 14
#define INITIAL_YEAR 2010
#define LIST_SIZE 40

bool GenerateInput(const char* NAME_LIST, const char** SUBJECT, student* list, int size){
    int n_students = 0;

    FILE* name_file;

    while(n_students < size){
        list->year = rand() % YEARS + INITIAL_YEAR;

        int name_number = rand() % LIST_SIZE + 1, line = 0;

        char ID[7] = "", aux[2];
        
        for(int i = 0; i < 6; i++){
            aux[0] = (char)(rand()%10+'0');
            aux[1] = '\0';
            strcat(ID, aux);
        }
        ID[6] = '\0';

        name_file = fopen(NAME_LIST, "r");

        if(NULL == name_file){
		    printf("Erro ao tentar abrir o arquivo nomes.txt.\n");
            fclose(name_file);
		    return false;
        }

        char name[MAX_SIZE];

        while(!feof(name_file) && line <= name_number){
            fgets(name, MAX_SIZE, name_file);
            line++;
        }

        name[strlen(name)-1] = '\0';

        strcpy(list->name, strcat(name,ID));

        strcpy(list->subject, SUBJECT[rand()%3]);

        list->mean = (rand()%101)/10.0;

        n_students++;
        list++;
    }

    fclose(name_file);

    return true;
}
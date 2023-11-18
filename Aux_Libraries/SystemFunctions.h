#include <stdlib.h>

int IdentifyOS(){ // Identifica o SO que o usuário está utilizando
    int value;
    #if __linux__
        value = 0;
    #elif __unix__
        value = 0;
    #elif __APPLE__
        value = 0;
	#elif _WIN32
        value = 1;
    #elif _WIN64
        value = 1;
	#endif
	return value;
}

void clearScreen(){ // Limpa o terminal onde o programa está sendo executado
    int value = IdentifyOS();

    if(value == 0) system("clear");
    else system("cls");
}

bool continuar(char interrupt){
    getchar(); // coleta o \n usado na ultima inserção de texto 
    printf("Deseja seguir utilizando o programa? [s/N]: ");
	interrupt = getchar(); // coleta o caractere da escolha

    clearScreen(); // limpa a tela

    return (interrupt == 'n' || interrupt == 'N');
}
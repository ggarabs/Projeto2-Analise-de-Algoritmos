/* PROJETO II DE ANÁLISE DE ALGORIMOS I

	INTEGRANTES: 

	- Felipe do Nascimento Fonseca	| 4221536-6
	- Giovanni Alves Lavia			| 4221836-5
	- Gustavo Garabetti Munhoz		| 4221195-6

*/

#define MAX_SIZE 150 //Define o tamanho maximo do nome como 150

struct Student{
	int year;
	char name[MAX_SIZE], subject[MAX_SIZE];
	double mean;
};

typedef struct Student student; //Renomeia a struct Aluno para simplificar a escrita de código
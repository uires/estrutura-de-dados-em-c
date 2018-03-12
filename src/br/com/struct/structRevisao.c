#include <stdio.h>
#include <string.h>

typedef struct{
	
	int dia;
	int mes;
	int ano;
	
}DATA;
typedef struct{
	
	char nome[50];
	int idade;

	DATA dataNascimento;
	
}ALUNO_CADASTRO;

void cadastraAlunos(ALUNO_CADASTRO * aluno);
void printarCadastro (ALUNO_CADASTRO aluno);
int main(){
	
	ALUNO_CADASTRO aluno;
	cadastraAlunos(&aluno);
	printarCadastro(aluno);
	
	
	
	
	
	
	
	return 0;
}
void cadastraAlunos (ALUNO_CADASTRO * aluno){
	
	
	printf("Digite seu nome...: ");
	gets(aluno->nome);
	
	printf("Digite seu idade...: ");
	scanf("%d", &aluno->idade);
	
	printf("Digite a data de nascimento do aluno...: ");
	scanf("%d %d %d", &aluno->dataNascimento.dia, &aluno->dataNascimento.mes, &aluno->dataNascimento.ano);
	
}

void printarCadastro (ALUNO_CADASTRO aluno){
	printf("Nome ...: %s\n", aluno.nome);
	printf("Idade ...: %d\n", aluno.idade);
	printf("Data Nascimento ...: %d/%d/%d\n", aluno.dataNascimento.dia, aluno.dataNascimento.mes, aluno.dataNascimento.ano );
	
	
}


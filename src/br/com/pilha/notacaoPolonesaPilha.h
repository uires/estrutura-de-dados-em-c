#define MAX 10

/*


	@uthor uíres
	2018-03-21  15:09


*/



typedef char char_tipo;

typedef struct{
	int item[MAX];
	int topo;
}TP_PILHA_CHAR;

void inicializa_pilha(TP_PILHA_CHAR * p){
	p->topo = -1;
}
int pop(TP_PILHA_CHAR * p, int * e){
	if(isEmpty(p)){
		printf("A pilha estÃ¡ vÃ¡zia!\n");
	}else{
		*e = p->item[p->topo];
		p->topo--;
		return 1;
	}
}

int push(TP_PILHA_CHAR * pointerPilha, int value){
	if(isFull(pointerPilha) == 1){
		printf("Pilha cheia!\n");
	}else{
		pointerPilha->topo++;
		pointerPilha->item[pointerPilha->topo] = value;
	}	
}
int isEmpty(TP_PILHA_CHAR * pointerPilha){
	if(pointerPilha->topo == -1){
		return 1;
	}else{
		return 0;
	}
}
int isFull(TP_PILHA_CHAR  * pointerPilha){
	if(pointerPilha->topo == MAX - 1){
		return 1;
	}else{
		return 0;
	}
		
}
/*
*	@uthor uíres
*	date 2018-03-18
*	
*	Essa função recebe uma struct como parâmetro e uma string onde deve conter um expressão polonesa Reversa
*	Com isso a utilização de pilha para empurrar os dados e realizar a lógica de operação polonesa
*
*/



void notacaoPolonesa(TP_PILHA_CHAR * pointerPilha, char string[10]){
	int cont = 0;
	char e;
	int x,y;
	int contador = strlen(string);
	int convertUm, result;
	while(cont < contador){
		printf("cont = %d, value array char = %c\n", cont, string[cont]);
		if((string[cont] == '*') || (string[cont] == '/') || (string[cont] == '+') || (string[cont] == '-')){
			pop(pointerPilha, &y);
			pop(pointerPilha, &x);
			printf("pop = %d -- %d\n", x, y);
			switch(string[cont]){
				case '*':
					printf(" valor x e y = %d    %d\n\n",x, y );
					result = x * y;
					printf("result = %d\n", result);
					push(pointerPilha, result);
					
					break;
				case '/':
					printf(" valor x e y = %d    %d\n\n",x, y );
					result = x / y;
					printf("result = %d\n", result);
					push(pointerPilha, result);
					
					break;
				case '+':
					printf(" valor x e y = %d    %d\n\n",x, y );
					result = x  + y;
					printf("result = %d\n", result);
					push(pointerPilha, result);
					
					break;
				case '-':
					printf(" valor x e y = %d    %d\n\n",x, y );
					result = x - y;
					printf("result = %d\n", result);
					push(pointerPilha, result);
					break;					
			}
		}else{
			e = string[cont];
			
			convertUm = (int) e - 48;
			printf(" Valor convertido...: %d\n", convertUm);
			push(pointerPilha, convertUm);			
		}
		cont++;
	}
	pop(pointerPilha, &result);
	printf("resultado final...: %d\n", result);	
}

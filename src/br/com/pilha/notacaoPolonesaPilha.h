#define MAX 10

typedef char char_tipo;

typedef struct{
	int item[MAX];
	int topo;
}TP_PILHA_CHAR;

void inicializa_pilha(TP_PILHA_CHAR * p){
	p->topo = -1;
}
int pop(TP_PILHA_CHAR * p, int * e){
	*e = p->item[p->topo];
	p->topo--;
	return 1;
}

int push(TP_PILHA_CHAR * p, int value){
	
	p->topo++;
	p->item[p->topo] = value;
	
}




void notacaoPolonesa(TP_PILHA_CHAR * pointerPilha, char string[10]){
	int cont = 0;
	char e;
	int x,y;
	int contador = strlen(string);
	int convertUm, convertDois, result;
	while(cont < contador){
		if((string[cont] == '*') || (string[cont] == '/') || (string[cont] == '+') || (string[cont] == '-')){
			pop(pointerPilha, &y);
			pop(pointerPilha, &x);
			switch(string[cont]){
				case '*':
					convertUm = x - 48;
					convertDois = y - 48;
					result = convertUm * convertDois;
					push(pointerPilha, result);
					
					break;
				case '/':
					convertUm = x - 48;
					convertDois = y - 48;
					result = convertUm / convertDois;
					push(pointerPilha, result);
					
					break;
				case '+':
					convertUm = x - 48;
					convertDois = y - 48;
					result = convertUm + convertDois;
					push(pointerPilha, result);
					
					break;
				case '-':
					convertUm = x - 48;
					convertDois = y - 48;
					result = convertUm - convertDois;
					push(pointerPilha, result);
					break;					
			}
		}else{
			e = string[cont];
			push(pointerPilha, e);			
		}
		cont++;
	}
	pop(pointerPilha, &result);
	printf("result...: %d\n", result);	
}

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
	if(isEmpty(p)){
		printf("A pilha está vázia!\n");
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
		p->topo++;
		p->item[p->topo] = value;
	}	
}
int isEmpty(TP_PILHAR_CHAR * pointerPilha){
	if(pointerPilha->topo == -1){
		return 1;
	}else{
		return 0;
	}
}
int isFull(TP_PILHAR_CHAR  * pointerPilha){
	if(pointerPilha->topo == MAX - 1){
		return 1;
	}else{
		return 0;
	}
		
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

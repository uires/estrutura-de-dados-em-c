

typedef struct TP_NO{
	int informacao;
	struct TP_NO * proximoElementoLista;
	
}TP_LIST;

TP_LIST * inicializaPonteiroLista(){
	return NULL;	
}

int isEmptyLista(TP_LIST * pointeiroLista){
	if(pointeiroLista == NULL){
		return 1;
	}else{
		return 0;
	}
}
TP_LIST * alocaMemoriaList(){
	TP_LIST * listaAlocada;
	listaAlocada = ((TP_LIST *) malloc(sizeof(TP_LIST)));
	return listaAlocada;
}

int adicionarNovoNoLista(TP_LIST **ponteiroLista, int valorInserido){
	TP_LIST *ponteiroListaAuxiliar, *novaInstanciaLista;
	novaInstanciaLista = alocaMemoriaList();
	if(novaInstanciaLista == NULL){
		return 0;
	}else{
		novaInstanciaLista->proximoElementoLista = inicializaPonteiroLista();		
		novaInstanciaLista->informacao = valorInserido;
		if(isEmptyLista(*ponteiroLista) == 1){
			*ponteiroLista = novaInstanciaLista;
		}else{
			ponteiroListaAuxiliar = *ponteiroLista;
			while(ponteiroListaAuxiliar->proximoElementoLista != NULL){
				ponteiroListaAuxiliar = ponteiroListaAuxiliar->proximoElementoLista;
			}
			*ponteiroLista = novaInstanciaLista;
		}
		return 1;
	}
}
int imprimirListaEncadeada(TP_LIST * ponteiroLista){
	if(isEmptyLista(ponteiroLista) == 1){
		return 0;
	}else{
		TP_LIST * ponteiroAuxiliar;
		ponteiroAuxiliar = ponteiroLista;
		while(ponteiroAuxiliar->proximoElementoLista != NULL){
			printf("[%d]-> %d\n", ponteiroAuxiliar->proximoElementoLista, ponteiroAuxiliar->informacao);
			ponteiroAuxiliar = ponteiroAuxiliar->proximoElementoLista;
		}
		return 1;
	}
}/*
int retiraImparesFilaEncadeada(TP_LIST * poteiroLista){
	if(poteiroLista == NULL){
		
	}
}*/

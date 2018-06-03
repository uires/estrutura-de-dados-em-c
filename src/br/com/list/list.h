/*
*	@author: u'ires deivide
*	@desc: struct para representação de um nó contendo
*			o ponteiro para o próximo nó da lista;
*	@param ( )
*	@date: 05/30/2018
*/
typedef struct TP_NO{
	int informacaoDaLista;
	struct TP_NO * proximoElementoDaLista;
}TP_LISTA;
/*
*	@desc: retorna um ponteiro null do tipo TP_LISTA
*	@param ( )
*	@return null
*/
TP_LISTA * retornaPonteiroNulo(){
	return NULL;
}
/*
*	@desc: retorna um novo nó através de uma aloção dinâmica
*	@param ( )
*	@return ponteiro do tipo TP_LISTA
*/
TP_LISTA * alocacaoDeNovoNo(){
	TP_LISTA * novoNoLista;
	novoNoLista = ((TP_LISTA *) malloc(sizeof(TP_LISTA)));
	return novoNoLista;
}
/*
*	@desc: verifca se o ponteiro é nulo
*	@param ( ponteiro de TP_LISTA )
*	@return 1 (verdadeiro) ou 0 (falso)
*/
int isEmptyLista(TP_LISTA * ponteiroLista){
	if(ponteiroLista == NULL){
		return 1;
	}else{
		return 0;
	}
}
/*
*	@desc: adiciona um novo nó na lista
*	@param ponteiroListaOrigem, int
*	return 1 (inserido) ou 0 (näo inserido)
*/
int addListaElemento(TP_LISTA  **listaMainPonteiro, int valorASerInseridoNaLista){
	TP_LISTA * ponteiroAuxiliar, * novoNoLista;
	novoNoLista = alocacaoDeNovoNo();
	if(novoNoLista == NULL){
		printf("Não foi possível alocar memória!\n");
		return 0;
	}else{
		novoNoLista->informacaoDaLista = valorASerInseridoNaLista;
		novoNoLista->proximoElementoDaLista = NULL;
		if(isEmptyLista(*listaMainPonteiro) == 1){
			*listaMainPonteiro = novoNoLista;
			return 1;
		}else{
			ponteiroAuxiliar = *listaMainPonteiro;
			while(ponteiroAuxiliar->proximoElementoDaLista != NULL){
				ponteiroAuxiliar = ponteiroAuxiliar->proximoElementoDaLista;
			}
			ponteiroAuxiliar->proximoElementoDaLista = novoNoLista;
		}
		return 1;
	}
}
/*
*	@desc: imprimi na tela os valores dos nós da lista
*	@param ponteiro do tipo TP_LISTA
*	return 1 ou 0
*/

int imprimirListaEnceadea(TP_LISTA *ponteiroLista){
	if( isEmptyLista(ponteiroLista)  == 1){
		return 0;
	}else{
		TP_LISTA * ponteiroAuxiliarLista;
		ponteiroAuxiliarLista = ponteiroLista;
		while(ponteiroAuxiliarLista != NULL){
			printf("=>: %d\n", ponteiroAuxiliarLista->informacaoDaLista);
			ponteiroAuxiliarLista= ponteiroAuxiliarLista->proximoElementoDaLista;
		}
	}
	return 1;
}
/*
*	@desc: Remove um nó da lista
*	@param ponteiroListaOrigem, elemento a ser pesquisado
*	return 0(não removido) ou não zero == removido
*/

/*	De longe a mais complicada função */
int removeListaElemento(TP_LISTA **listaMainPonteiro, int informacaoAserRemovida){
	if(isEmptyLista(*listaMainPonteiro) == 1){
		printf("Lista vázia!\n");
		return 0;
	}else{
		TP_LISTA * ponteiroAuxiliar, *ponteiroAnteriorLista;
		ponteiroAnteriorLista = NULL;
		ponteiroAuxiliar = *listaMainPonteiro;
		while((ponteiroAuxiliar != NULL) && (ponteiroAuxiliar->informacaoDaLista != informacaoAserRemovida)){
			ponteiroAnteriorLista = ponteiroAuxiliar;
			ponteiroAuxiliar = ponteiroAuxiliar->proximoElementoDaLista;
		}
		/*	o valor informado não foi encontrado na lista */
		if(ponteiroAuxiliar == NULL){
			printf("Elemento não encontrado na lista!\n");
			return 0;
		}else{
			/*
			*	Nesse momento à possiblidade de dois possíveis cenários,
			*	o primeiro séria que na busca o primeiro elemento
			*	fosse encontrado, com isso o não não entraria no while sendo assim
			*	ponteiroAnterior vai estar nulo, então só preciso tratar a atribuição
			*	o listaMainPonteiro para o próximo nó do ponteiroAuxliar->proximoElementoLista
				
			*	E o segundo caso é somente tratar o nó anterior  para que aponte
			*	para o ponteiroAuxiliar->proximoElemento e por fim limpar da memória
			*	do ponteiroAuxiliar;
			*/
			if(ponteiroAnteriorLista == NULL){
				*listaMainPonteiro = ponteiroAuxiliar->proximoElementoDaLista;
			}else{
				ponteiroAnteriorLista->proximoElementoDaLista = ponteiroAuxiliar->proximoElementoDaLista;
			}
			/*
				Limpa o ponteiro e faz atribui nullo ao mesmo
			*/
			free(ponteiroAuxiliar);
			ponteiroAuxiliar = NULL;
		}
		printf("Elemento retirado com sucesso!\n");
		return 1;
	}
}
/*
*	@desc: Limpa uma lista, destruindo todos os nós, disponiblizando assim a memória para o SO
*	@param ( )
*	@return
*
*/
int destroyLista(TP_LISTA **ponteiroListaMain){
	if(isEmptyLista(*ponteiroListaMain) == 1){
		printf("Lista vázia!\n");
		return 0;
	}else{
		TP_LISTA * pointeiroAuxiliar, *ponteiroPostumo;
		pointeiroAuxiliar = *ponteiroListaMain;
		while(pointeiroAuxiliar != NULL){
			ponteiroPostumo = pointeiroAuxiliar->proximoElementoDaLista;
			free(pointeiroAuxiliar);
			pointeiroAuxiliar = ponteiroPostumo;
		}
		*ponteiroListaMain = NULL;
		return 1;
	}
}


















#include "TAD_AF.h"
#include <stdlib.h>

Automata* create_automata(){
    Automata* A = (Automata*) malloc(sizeof(Automata));
    A->states = NULL;
    A->q0 = NULL;
    A->deterministic = true; // Por defecto, asumimos que el autómata es determinista
    return A;
}

void add_transition(Automata* A, char* from, char* symbol, char* to) {
    StateNode* fromState = find_state(A, from);
    StateNode* toState = find_state(A, to);

    if (fromState == NULL || toState == NULL) {
        printf("Error: Estado no encontrado. from: %s, to: %s\n", from, to);
        return;
    }

    Transition* newTransition = (Transition*) malloc(sizeof(Transition));
    newTransition->symbol = symbol;
    newTransition->to = toState;
    newTransition->next = fromState->transitions;
    fromState->transitions = newTransition;

    // Verificar si el autómata sigue siendo determinista
    Transition* current = fromState->transitions;
    while (current != NULL) {
        if (current->symbol == symbol && current->to != toState) {
            A->deterministic = false; // Si hay una transición con el mismo símbolo a un estado diferente, no es determinista
            break;
        }
        current = current->next;
    }
}

void printTransition(Transition *transition){
	Transition *aux = transition;
	while(aux != NULL){
		printSTR(transition->symbol);
		printf("->");
		print_Tdata(transition->to);
		aux = aux->next;
	}
}
void print_automata(Automata* A){
	//Estado inicial
	printf("Estado inicial: ");
	printSTR(A->q0);
	
	//Estados
	printf("Estados\n");
	StateNode *aux = A->states;
	while(aux != NULL){
		printf("Estado: ");
		printSTR(A->states->name);
		if(A->states->isFinal)printf("\nEstado de aceptacion\n");
		//Transiciones del estado
		printf("Transiciones:\n");
		printTransition(aux->transitions);
		
		aux = aux->next;
	}
	//Es determinista?
	if(A->deterministic){printf("Automata determinista");}
	else printf("Automata no determinista");
	//
}
//ejemplo add_state(A,"q0",false); add_state(A,"q1",true);
void add_state(Automata* A, char* name, bool isFinal){
	StateNode *newState = (StateNode*)malloc(sizeof(StateNode));
	
	newState->name = (String)name;
	newState->transitions = NULL;
	newState->isFinal = isFinal;
	newState->next = NULL;
	
	newState->next = A->states;
	A->states = newState;
}

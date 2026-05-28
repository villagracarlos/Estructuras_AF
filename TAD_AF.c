#include "TAD_AF.h"
#include <stdlib.h>

Automata* create_automata(){
    Automata* A = (Automata*) malloc(sizeof(Automata));
    A->states = NULL;
    A->q0 = NULL;
    A->deterministic = true; // Por defecto, asumimos que el autómata es determinista
    return A;
}
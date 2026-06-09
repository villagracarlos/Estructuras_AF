#include "TAD_AST.h"

typedef String State;
typedef String Symbol;

typedef struct transition Transition;
typedef struct stateNode StateNode;

struct transition{
    Symbol symbol;

    Tdata to; // SET de estados destino

    Transition* next;
};

struct stateNode{
    State name;

    Transition* transitions;

    bool isFinal;

    struct stateNode* next;
};
//La estructura de stateNode representa q0: a -> {q1,q2}    Osea se representa como grafos
//                                          b -> {q3}

typedef struct{
    StateNode* states;

    State q0;

    bool deterministic;
} Automata;

Automata* create_automata();

void add_state(Automata* A, char* name, bool isFinal);
//ejemplo add_state(A,"q0",false); add_state(A,"q1",true);

StateNode* find_state(Automata* A, char* name);

void add_transition(Automata* A, char* from, char* symbol, char* to); 
//ejemplo add_transition(A,"q0","a","q1"); add_transition(A,"q0","a","q2");

void print_automata(Automata* A);

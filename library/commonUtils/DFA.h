#ifndef SPBU_C_HOMEWORKS_DFA_H
#define SPBU_C_HOMEWORKS_DFA_H

#include <stdbool.h>

#define WRONG_DFA (-1)
#define SYMBOL_OUT_FROM_LANGUAGE (-2)

typedef struct Transition Transition;
typedef struct DFA DFA;
typedef struct State State;

DFA* createDFA(int n, Transition** nTransitions, int m, int* mFinalPositions, int startPosition);
Transition* createTransition(int source, int destination, bool (*Validator)(char));
bool belongsToLanguage(DFA* automaton, char* string, int* error);
void deleteDFA(DFA* automaton);

#endif // SPBU_C_HOMEWORKS_DFA_H

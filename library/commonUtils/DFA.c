#include "DFA.h"
#include <stdlib.h>
#include <string.h>

struct DFA {
    int startPosition;
    int nFinalPositions;
    int* finalPositions;
    int nStates;
    State** states;
};

struct State {
    int position;
    int nTransitions;
    Transition** transitions;
};

struct Transition {
    int source;
    int destination;
    bool (*Validator)(char);
};

Transition* createTransition(int source, int destination, bool (*Validator)(char))
{
    Transition* transition = malloc(sizeof(Transition));
    transition->source = source;
    transition->destination = destination;
    transition->Validator = Validator;
    return transition;
}

State* createState(int position)
{
    State* state = malloc(sizeof(State));
    state->position = position;
    state->nTransitions = 0;
    state->transitions = NULL;
    return state;
}

void addTransition(State* state, Transition* transition)
{
    state->nTransitions++;
    if (state->nTransitions == 1)
        state->transitions = malloc(sizeof(Transition*));
    state->transitions = realloc(state->transitions, state->nTransitions * sizeof(Transition*));
    state->transitions[state->nTransitions - 1] = transition;
}

void addState(DFA* automaton, State* state)
{
    automaton->nStates++;
    if (automaton->nStates == 1)
        automaton->states = malloc(sizeof(State*));
    automaton->states = realloc(automaton->states, automaton->nStates * sizeof(State*));
    automaton->states[automaton->nStates - 1] = state;
}

State* getStateByPosition(State** states, int nStates, int position)
{
    for (int i = 0; i < nStates; i++)
        if (states[i]->position == position)
            return states[i];
    return NULL;
}

DFA* createDFA(int n, Transition** transitions, int m, int* finalPositions, int startPosition)
{
    DFA* automaton = malloc(sizeof(DFA));
    automaton->startPosition = startPosition;
    automaton->nFinalPositions = m;
    automaton->finalPositions = malloc(m * sizeof(int));
    automaton->nStates = 0;
    automaton->states = NULL;
    memcpy(automaton->finalPositions, finalPositions, m * sizeof(int));
    for (int i = 0; i < n; i++) {
        State* current = getStateByPosition(automaton->states, automaton->nStates, transitions[i]->source);
        if (!current)
            current = createState(transitions[i]->source);
        addTransition(current, transitions[i]);
        if (!getStateByPosition(automaton->states, automaton->nStates, transitions[i]->source))
            addState(automaton, current);
    }
    return automaton;
}

bool belongsToLanguage(DFA* automaton, char* string, int* error)
{
    int currentPosition = automaton->startPosition;
    for (int i = 0; i < strlen(string); i++) {
        char symbol = string[i];
        State* currentState = getStateByPosition(automaton->states, automaton->nStates, currentPosition);
        if (!currentState) {
            *error = WRONG_DFA;
            return false;
        }
        bool hasTransition = false;
        for (int j = 0; j < currentState->nTransitions; j++) {
            if (currentState->transitions[j]->Validator(symbol)) {
                currentPosition = currentState->transitions[j]->destination;
                hasTransition = true;
            }
        }
        if (!hasTransition) {
            *error = SYMBOL_OUT_FROM_LANGUAGE;
            return false;
        }
    }
    bool isFinalState = false;
    for (int i = 0; i < automaton->nFinalPositions; ++i) {
        if (automaton->finalPositions[i] == currentPosition)
            isFinalState = true;
    }
    return isFinalState;
}

void deleteDFA(DFA* automaton)
{
    free(automaton->finalPositions);
    for (int i = 0; i < automaton->nStates; i++) {
        State* current = automaton->states[i];
        for (int j = 0; j < current->nTransitions; j++)
            free(current->transitions[j]);
        free(current->transitions);
        free(current);
    }
    free(automaton->states);
    free(automaton);
}
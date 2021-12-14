#include "../library/commonUtils/DFA.h"
#include <stdbool.h>
#include <stdio.h>

bool isE(char ch)
{
    return ch == 'E';
}

bool isPlusOrMinus(char ch)
{
    return ch == '+' || ch == '-';
}

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isDot(char ch)
{
    return ch == '.';
}

int main()
{
    Transition* transitions[] = {
        createTransition(0, 1, isPlusOrMinus),
        createTransition(0, 2, isDot),
        createTransition(0, 3, isDigit),
        createTransition(1, 2, isDot),
        createTransition(1, 3, isDigit),
        createTransition(2, 4, isDigit),
        createTransition(3, 3, isDigit),
        createTransition(3, 2, isDot),
        createTransition(3, 5, isE),
        createTransition(4, 4, isDigit),
        createTransition(4, 5, isE),
        createTransition(5, 6, isPlusOrMinus),
        createTransition(5, 7, isDigit),
        createTransition(6, 7, isDigit),
        createTransition(7, 7, isDigit)
    };
    int finalPositions[3] = { 3, 4, 7 };
    DFA* dfa = createDFA(15, transitions, 3, finalPositions, 0);

    int error = 0;

    char string[256] = "";
    printf("Please enter a string: ");
    scanf("%s", string);
    bool result = belongsToLanguage(dfa, string, &error);
    if (!result) {
        if (error == WRONG_DFA) {
            printf("Error handled. You have create a wrong DFA");
            return 0;
        } else if (error == SYMBOL_OUT_FROM_LANGUAGE)
            printf("This string has symbols, which are out from DFA's language\n");
        else
            printf("DFA ended work at non-final position\n");
    }
    printf("%s", result ? "This is a number!" : "This is not a number ;(");
    deleteDFA(dfa);
    return 0;
}
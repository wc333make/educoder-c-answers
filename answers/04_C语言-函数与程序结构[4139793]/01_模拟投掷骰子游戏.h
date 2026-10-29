#include <stdio.h>
#include <stdlib.h>
void diceGame(int randSeed) {
    srand((unsigned)randSeed);
    int point = 0;
    for (int round = 1;; round++) {
        int a = rand() % 6 + 1, b = rand() % 6 + 1, score = a + b;
        int success = round == 1 ? (score == 7 || score == 11) : score == point;
        int failed = round == 1 ? (score == 2 || score == 3 || score == 12) : score == 7;
        printf("Round %d:  Score:%d  %s!\n", round, score,
               success  ? "Success"
               : failed ? "Failed"
                        : "Continue");
        if (success || failed)
            break;
        if (round == 1) {
            point = score;
            printf("Next rounds: Score %d:Success, Score 7:Failed, others:Continue\n", point);
        }
    }
}

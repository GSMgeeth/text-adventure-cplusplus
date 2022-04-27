/**
 * @file text-adventure.cpp
 * @author Geeth Sandaru (geeth.gsm@gmail.com)
 * @brief A game of storytelling where user can select where the story goes.
 * @version 0.1
 * @date 2022-04-24
 *
 * @copyright Copyright (c) 2022
 *
 * @todo
 * - Design a story where user can achieve the dream if work hard. (https://lucid.app/lucidchart/ff7836d2-3b5d-4a37-ac48-ea45fd826246/edit?beaconFlowId=ACE9CDEAD7FB2AF4&page=0_0&invitationId=inv_7e5bc962-de02-4ca6-b2d4-036f2b27a0cf#)
 * - Add at least 3 different endings.
 * - Design paths where they go in separate directions but at some point joins a one major path.
 * - Having fun not always take him down but there's a limit.
 * - Have some ASCII arts to make the game not boring. https://en.wikipedia.org/wiki/ASCII_art
 *
 */

#include <iostream>

using namespace std;

void getAnswer(const string question, int &answer, const int noOfAnswers);

int main() {
    int score = 7;
    int answer = 0;
    int previousAnswer = 0;

    cout << "Text Adventure" << endl
         << endl;

    cout << "Hello there! Let's take you through a journey that will either make you a success man or just a man who has achieved, well, not much." << endl
         << "From now on, you are Bob and you need to work hard to achieve your goals." << endl
         << "Let's begin!" << endl;

    getAnswer("(1) Work / study or (2) play ? ", answer, 2);

    // First answer evaluation
    switch (answer) {
        case 1:
            score++;
            getAnswer("You worked / learnt. Next, (1) worked / learnt or (2) play ? ", answer, 2);
            break;
        case 2:
            getAnswer("You played. Next, (1) worked / learnt or (2) play ? ", answer, 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            answer = 0;
            break;
    }

    // Second answer evaluation
    switch (answer) {
        case 1:
            score++;
            getAnswer("You worked / learnt. Next, (1) worked / learnt or (2) sleep ? ", answer, 2);
            break;
        case 2:
            score = previousAnswer == 1 ? score : score - 1;
            getAnswer("You played. Next, (1) worked / learnt or (2) sleep ? ", answer, 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            answer = 0;
            break;
    }

    // Third answer evaluation
    switch (answer) {
        case 1:
            score--;
            getAnswer("You worked / learnt. Next, (1) worked / learnt or (2) sleep ? ", answer, 2);
            break;
        case 2:
            score++;
            getAnswer("You played. Next, (1) worked / learnt or (2) sleep ? ", answer, 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            answer = 0;
            break;
    }
}

void getAnswer(const string question, int &answer, const int noOfAnswers = 3) {
    do {
        cout << question << endl;
        cin >> answer;

    } while (answer <= 0 || answer > noOfAnswers);
}

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
#include <string>

using namespace std;

void getAnswer(const string question, int &answer, const int noOfOptions);

int main() {
    int score = 7;
    int answers[9] = {0, 0, 0, 0, 0, 0, 0, 0};

    cout << "Text Adventure" << endl
         << endl;

    cout << "Hello there! Let's take you through a journey that will either make you a success man or just a man who has achieved, well, not much." << endl
         << "From now on, you are Bob and you need to work hard to achieve your goals." << endl
         << "Let's begin!" << endl;

    getAnswer("(1) Work or (2) play ? ", answers[0], 2);

    // First answer evaluation
    switch (answers[0]) {
        case 1:
            score++;
            getAnswer("You worked. Next, (1) work or (2) play ? ", answers[1], 2);
            break;
        case 2:
            getAnswer("You played. Next, (1) work or (2) play ? ", answers[1], 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            break;
    }

    // Second answer evaluation
    switch (answers[1]) {
        case 1:
            score++;
            getAnswer("You worked. Next, (1) work or (2) sleep ? ", answers[2], 2);
            break;
        case 2:
            score = answers[0] == 1 ? score : score - 1;
            getAnswer("You played. Next, (1) work or (2) sleep ? ", answers[2], 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            break;
    }

    // Third answer evaluation
    switch (answers[2]) {
        case 1:
            score = (answers[0] == 1 && answers[1] == 1) ? score : score + 1;
            getAnswer("You worked and then slept. Next, (1) work or (2) cry ? ", answers[3], 2);
            break;
        case 2:
            score = (answers[0] == 1 && answers[1] == 1) ? score + 1 : score;
            getAnswer("You slept. Next, (1) work or (2) cry ? ", answers[3], 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            break;
    }

    // Forth answer evaluation
    switch (answers[3]) {
        case 1:
            score++;
            getAnswer("You worked. Next, (1) work or (2) cry ? ", answers[4], 2);
            break;
        case 2:
            getAnswer("You cried. Next, (1) work or (2) cry ? ", answers[4], 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            break;
    }

    // Fifth answer evaluation
    switch (answers[4]) {
        case 1:
            score++;
            getAnswer("You worked. You meet a VC, (1) talk to VC or (2) work ? ", answers[5], 2);
            break;
        case 2:
            score = answers[3] == 2 ? score - 1 : score;
            getAnswer("You cried. You meet a VC, (1) talk to VC or (2) work ? ", answers[5], 2);
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            break;
    }

    // Sixth answer evaluation
    switch (answers[5]) {
        case 1:
            score++;
            cout << "You talked to VC." << endl;
            break;
        case 2:
            score--;
            cout << "You worked and missed VC." << endl;
            break;
        default:
            cout << "The answer is incorrect! Please try again." << endl;
            break;
    }

    if (score > 11 && answers[5] == 1) {
        getAnswer("VC fund you. (1) Work or (2) play ? ", answers[6], 2);

        for (int i = 0; i < 2; i++)
        {
            // Ending 1
            if (answers[6 + i] == 1) {
                cout << "Hard work finally paysoff. You are very successful and achieved your goals. Congratulations!" << endl;
                return 0;
            }
            else if (i != 1) {
                score = 11;
                getAnswer("Remember how hard you worked for this. Keep it safe! (1) Work or (2) play ? ", answers[7], 2);
            }
            else {
                getAnswer("You are overwhelmed by success. Control yourself! (1) Work or (2) play ? ", answers[8], 2);
                score = answers[8] == 1 ? score : 6;
            }
        }
    }
    
    // Ending 2
    if (score > 6 && score <= 11 && answers[5] == 1) {
        cout << "Your work finally paysoff. You are successful and achieved many of your goals. Congratulations!" << endl;
        return 0;
    }
    // Ending 3
    else {
        cout << "Oh! you couldn't make it. But, don't worry. There is still hope! (1) work (2)..." << endl;
        return 0;
    }
}

/**
 * @brief Get the answer from user an set to answer reference.
 * getAnswer keeps asking for the answer until the user gives a valid answer.
 * 
 * @param question the question text
 * @param answer the answer reference
 * @param noOfOptions no of options to choose from
 */
void getAnswer(const string question, int &answer, const int noOfOptions = 2) {
    do {
        cout << question << endl;
        cin >> answer;

    } while (answer <= 0 || answer > noOfOptions);
}

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Score {
private:
    int score;

public:
    Score(int initialScore) : score(initialScore) {}

    Score& operator++() {
        ++score;
        return *this;
    }

    Score& operator--() {
        --score;
        return *this;
    }

    Score operator--(int) {
        Score temp = *this;
        score--;
        return temp;
    }

    int getScore() const {
        return score;
    }
};

class GuessingGame {
private:
    int targetNumber;
    int attempts;
    Score score;

    int generateRandomNumber() {
        return (rand() % 10) + 1;
    }

public:
    GuessingGame() : score(5) {
        srand(time(0));
        targetNumber = generateRandomNumber();
        attempts = 0;
    }

    void play() {
        cout << "Virtual Guessing Game Starts!\n";
        cout << "The virtual player will guess a number between 1 and 10. \n";
        cout << "Score decreases for incorrect guesses";
        cout << " and increases for correct ones. \n\n";

        while (true) {
            int guess = generateRandomNumber();
            ++attempts;

            cout << "Attempt " << attempts << " : Virtual player guesses ";
            cout << guess << ".  ";

            if (guess > targetNumber) {
                --score;
                cout << "Too high! Score decreases. ";
            } else if (guess < targetNumber) {
                --score;
                cout << "Too low! Score decreases. ";
            } else {
                ++score;
                cout << "Correct! Score increases! \n";
                break;
            }

            cout << "Current score: " << score.getScore() << "\n";

            if (score.getScore() <= 0) {
                cout << "\nGame Over! The Virtual Player Ran Out of Score. \n";
                cout << "The Correct Number was: " << targetNumber << "\n";
                return;
            }
        }

        cout << "The virtual player guessed the correct number: ";
        cout << targetNumber << "\n";
        cout << "Final score: " << score.getScore() << "\n";
    }
};

int main() {
    GuessingGame game;
    game.play();
    getch();
    return 0;
}


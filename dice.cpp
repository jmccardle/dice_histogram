#include <iostream> //cout, cin
#include <vector>
#include "histogram.h"
#include "dice.h"

using namespace std;

int main(int argc, char* argv[])
{
    random_seed();
    vector<int> rolls(7); //size 7 means elements 0 through 6. We just ignore the zero index.

    //user input for number of rolls
    int number_rolls;
    cout << "How many rolls? ";
    cin >> number_rolls;

    //roll the dice into the rolls vector
    for(int i = 0; i < number_rolls; i++) rolls.at(dice())++;

    //output #1: List values and percentages
    cout << endl << "Dice rolled: " << number_rolls << endl;
    display_counts(rolls, 1, 6, number_rolls);

    //output #2: histogram.
    cout << endl << "Histogram: " << endl;
    display_histogram(rolls, 1, 6);

    //phase 2: same output, but with results of 2d6 (two six-sided die).
    cout << "Rolling a pair of dice." << endl;
    rolls.clear(); //sets vector to size 0
    rolls.resize(13); //size 13 means 0 through 12: 0 and 1 will be ignored.

    for(int i = 0; i < number_rolls; i++) rolls.at(dice() + dice())++;

    //output #1: list values and percentages
    cout << endl << "Dice rolled: " << number_rolls << " x2" << endl;
    display_counts(rolls, 2, 12, number_rolls);

    //output #2: histogram.
    cout << endl << "Histogram: " << endl;
    display_histogram(rolls, 2, 12);

    //done.
    return 0;

}

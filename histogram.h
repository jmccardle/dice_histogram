#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream> //cout
#include <iomanip> // setprecision, fixed
#include <math.h> //floor
#include <vector>

using namespace std;

int proportion(int value, int max, int max_length)
//returns a value between 0 and max_length representing value's proportional size.
{
    return int(floor(value / float(max) * max_length));
}

int find_max(vector<int> v)
{
    int max = v.at(0);
    for (int i = 0; i < v.size(); i++)
        if (v.at(i) > max) max = v.at(i);
    return max;
}

void display_counts(vector<int> v, int start, int end, int sum)
//Displays the counts of each value between start and end (inclusive) and a percentage (v.at(i) / sum * 100).
{
	int total = 0;
    for (int i = start; i <= end; i++)
    {
		total += v.at(i);
        cout << i << "\t-----\t" << v.at(i) << "\t(";
        cout << setprecision(2) << float(v.at(i)) / sum * 100; //Output up to 2 decimal places for percentage
        cout << "%)" << endl;
    }
	cout << "total\t-----\t" << total << "\t(";
	cout << fixed << setprecision(0) << float(total) / sum * 100; //This should always say 100%.
	cout << "%)" << endl;
}

void display_histogram(vector<int> v, int start, int end, int max_width = 60)
//displays a number of x's proportional to the maximum element in the vector.
{
    int max = find_max(v);
    for (int i = start; i <= end; i++)
    {
        cout << i << " ";
        int width = proportion(v.at(i), max, max_width);
        for (int j = 0; j < width; j++) cout << "x"; //Caution! Single statement for loop.
        cout << endl;
    }

}

#endif

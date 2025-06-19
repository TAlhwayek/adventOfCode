#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    // Used to count number of valid lines
    int valid = 0;

    ifstream myFile("text.txt");
    if (!myFile.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    string line;
    while (getline(myFile, line)) {
        istringstream iss(line);
        // Temp vector per loop
        vector<int> numbers;
        int value;
        bool isIncreasing = true;
        bool isDecreasing = true;
        bool isSafe = true;

        // Insert all words into vector
        while (iss >> value) {
            numbers.push_back(value);
        }

        // Check for pattern
        for (int i = 1; i < numbers.size(); i++) {
            // Check if increasing pattern
            if (numbers[i] <= numbers[i - 1])
                isIncreasing = false;

            // Check if decreasing pattern
            if (numbers[i] >= numbers[i - 1])
                isDecreasing = false;

            // Check if difference is within required limits
            int diff = abs(numbers[i] - numbers[i - 1]);
            if (diff < 1 || diff > 3)
                isSafe = false;

            // Is it worth looping?
            // Checks if anything passed the test
            if (!isIncreasing && !isDecreasing && !isSafe)
                break;
        }

        if ((isIncreasing || isDecreasing) && isSafe) {
            valid++;
        }
    }

    cout << "Valid: " << valid << endl;

    return 0;
}

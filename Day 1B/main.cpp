#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream myFile("text.txt");
    if (!myFile.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }
    vector<int> leftList;
    vector<int> simList;
    unordered_map<int, int> map;

    int left, right;

    // Read everything from file
    // Count occurrences using map
    while (myFile >> left >> right) {
        leftList.push_back(left);
        map[right]++;
    }

    for (auto i: leftList) {
        simList.push_back(i * map[i]);
    }

    int sum = 0;
    for (auto value: simList) {
        sum += value;
    }

    cout << sum << endl;

    return 0;
}

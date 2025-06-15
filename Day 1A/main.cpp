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
    vector<int> rightList;
    vector<int> sumList;
    int left, right;

    // Read everything from file
    while(myFile >> left >> right) {
        leftList.push_back(left);
        rightList.push_back(right);
    }

    // Find lowest elements, add them to new vector, delete them
    while (!leftList.empty()) {
        auto lowestLeft = min_element(leftList.begin(), leftList.end());
        auto lowestRight = min_element(rightList.begin(), rightList.end());
        sumList.push_back(abs(*lowestLeft - *lowestRight));
        leftList.erase(lowestLeft);
        rightList.erase(lowestRight);

    }

    int sum = 0;
    for (auto value : sumList) {
        sum += value;
    }
    cout << sum << endl;
    return 0;
}

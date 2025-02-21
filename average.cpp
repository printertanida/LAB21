#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Please input numbers to find average." << endl;
        return 0;
    }

    vector<double> numbers;
    for (int i = 1; i < argc; i++) {
        try {
            double num = stod(argv[i]);
            numbers.push_back(num);
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << argv[i] << endl;
            return 1;
        } catch (const out_of_range& e) {
            cerr << "Number out of range: " << argv[i] << endl;
            return 1;
        }
    }

    if (numbers.empty()) {
        cerr << "No valid numbers provided." << endl;
        return 1;
    }

    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }

    double average = sum / numbers.size();

    cout << "---------------------------------" << endl;
    cout << "Average of " << numbers.size() << " numbers = " << round(average) << endl;
    cout << "---------------------------------" << endl;

    return 0;
}

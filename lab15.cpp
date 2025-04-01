#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

void getInfo(int &n, int &k) {
    cout << "How many balls (1-12) are in the pool to pick from? ";
    while (!(cin >> n) || n < 1 || n > 12) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input Error! There must be between 1 and 12 balls.\n";
        cout << "How many balls (1-12) are in the pool to pick from? ";
    }

    cout << "How many balls (1-" << n << ") will be drawn? ";
    while (!(cin >> k) || k < 1 || k > n) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Input Error! \n";
        cout << "How many balls (1-" << n << ") will be drawn? ";
    }
}

double computeWays(int n, int k) {
    return 1.0 / (factorial(n) / (factorial(k) * factorial(n - k)));
}

double factorial(int num) {
    if (num <= 1) return 1;
    return num * factorial(num - 1);
}

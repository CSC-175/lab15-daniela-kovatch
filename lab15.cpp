#include <iostream>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

void getInfo(int &n, int &k) {
    do {
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> n;
        if (cin.fail() || n < 1 || n > 12) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input Error! There must be between 1 and 12 balls.\n";
        }
    } while (n < 1 || n > 12);

    do {
        cout << "How many balls (1-" << n << ") will be drawn? ";
        cin >> k;
        if (cin.fail() || k < 1 || k > n) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input Error!\n";
        }
    } while (k < 1 || k > n);
}

double computeWays(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

double factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    return num * factorial(num - 1);
}

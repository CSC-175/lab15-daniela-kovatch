#include<iostream>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

/*******************************************************************
* getLotteryInfo                                                   *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
********************************************************************/
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
            cout << "Input Error! \n";
        }
    } while (k < 1 || k > n);
}


/*******************************************************************
* computeWays                                                      *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is     k!(n- k)!                            *
*                             --------                             *
*                                 n!                               *
* Note that the computation is done in a way that does not require *
* multiplying two factorials together. This is done to prevent any *
* intermediate result becoming so large that it causes overflow.   *
********************************************************************/
double computeWays(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/*******************************************************************
* factorial                                                        *
* This function computes factorials recursively.                   *
*******************************************************************/
double factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    return num * factorial(num - 1);
}


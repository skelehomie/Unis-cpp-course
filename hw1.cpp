#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
int num;
int reverse = 0;
int i = 0;
cin>>num;
     while (i < 4) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
        i++;
    }
    cout<<setw(4)<<setfill('0')<<reverse;

    return 0;
}
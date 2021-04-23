#include <iostream>
#include <vector>
#include <string>
/*
const long long int QUINTUS    = 83621143489848416212;
const long long int SERENUS    = 298611126818977066911787;  //just took root squares of these
const long long int SAMMONICUS = 354224848179261908310;   //numbers
*/
void findSumWays(int n, int arr[][2]) // even numbers only
{
    int j = n;
    int k = 0;
    for (int i = 0; i < n/2; i++) {
        j -= 1;
        k += 1;
        arr[i][0] = j;
        arr[i][1] = k;
    }
}

int binarySearch(int first_number, int last_number) {
    int between = (last_number - first_number)/2;
    char less_or_more;

    while (less_or_more != '=') {
        std::cout << "Is your number greater or less than " << between << "?" "Just type '>' or '<' or '='." << '\n';
        std::cin >> less_or_more;
        if (less_or_more == '<') {
            last_number = between;
        }
        else if (less_or_more == '>') {
            first_number = between;
        }
        between = (last_number - first_number)/2 + first_number;
    }
    return between;
}

//"int128" realization
string add (string &s1, string &s2){
    int carry=0,sum,i;

    string  min=s1,
    max=s2,
    result = "";

    if (s1.length()>s2.length()){
        max = s1;
        min = s2;
    } else {
        max = s2;
        min = s1;
    }

    for (i = min.length()-1; i>=0; i--){
        sum = min[i] + max[i + max.length() - min.length()] + carry - 2*'0';

        carry = sum/10;
        sum %=10;

        result = (char)(sum + '0') + result;
    }

    i = max.length() - min.length()-1;

    while (i>=0){
        sum = max[i] + carry - '0';
        carry = sum/10;
        sum%=10;

        result = (char)(sum + '0') + result;
        i--;
    }

    if (carry!=0){
        result = (char)(carry + '0') + result;
    }

    return result;
}



void getting_sequence_number() {}    //wHat iF the sequence is greatest_secrete_code * Fi - 6765 ??1!/!/

int main() {
    std::cout << "Hello! I'm ready for the your challenge." << '\n';
    std::cout << '\n' << "Ok. Let's start. Think of a number from 1 to 9999, I'll try guess it." << '\n';
    int n = binarySearch(1, 9999); //guessed number
    int all_sums[n/2][2];
    findSumWays(n, all_sums);
    int greatest_secret_code = all_sums[1][0]; // just for example


    return 0;
}

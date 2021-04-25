#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findSumWays(int n, int arr[][2]) 
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
    int carry=0,sum,i; //carry over numbers

    string  min=s1, max=s2, result = "";

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

    i = max.length() - min.length()-1; //digit difference

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

string multiply(string &s1, string &s2) { //s2 as coef
    int coefficient = stoi(s2);
    string temp;
    for (int i = 1; i < coefficient; i++) {
        if (i == 1) { temp = add(s1, s1); }
        else {
            temp = add(temp, s1);
        }
    }
    return temp;
}


int fibonacci_numbers(string getting_sequence_number) {
    int n = 150;  //n - number of fibonacci members in the array
    string fn[n];
    string f1 = "1";
    string f2 = f1;
    fn[0] = f1;
    fn[1] = f2;
    string sum;
    for (int i = 2; i < n; i++) {
        sum = add(f1, f2);
        //cout << sum << endl;
        fn[i] = sum;
        f1 = f2;
        f2 = sum;
    }
    // O(n)
    for (int i = 0; i < n; i++) {
        if (getting_sequence_number == fn[i]) {
            return i;
        }
    }
    return 0;
}


int main() {
    std::cout << "Hello! I'm ready for the your challenge." << '\n';
    std::cout << '\n' << "Ok. Let's start. Think of a number from 1 to 9999, I'll try guess it." << '\n';
    int n = binarySearch(1, 9999); //guessed number
    int all_sums[n/2][2];
    findSumWays(n, all_sums);
    // greater secret code = ...

    string quintus = "83621143489848416212";
    string sammonicus = "354224848179261908310";
    string serenus = "298611126818977066911787";

    string dif = "6765";
    quintus = add(quintus, dif);
    sammonicus = add(sammonicus, dif);
    serenus = add(serenus, dif);

    int seq_quintus = fibonacci_numbers(quintus) + 1;
    int seq_sammonicus = fibonacci_numbers(sammonicus) + 1;
    int seq_serenus = fibonacci_numbers(serenus) + 1; // * greatest code

    cout << "It's your code phrase, get the pizza with it: " << endl <<  (char)seq_quintus << (char)(seq_quintus+1) << (char)seq_serenus
        << (char)seq_quintus << (char)(seq_sammonicus-1) << (char)seq_quintus
        << (char)seq_sammonicus << (char)seq_quintus << (char)(seq_quintus+1)
        << (char)seq_serenus << (char)seq_quintus << endl;

    return 0;
}

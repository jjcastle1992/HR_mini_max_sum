#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    long long minSum = 0;
    long long maxSum = 0;
    //Function takes in 5 positive ints, and then sum 4 of the 5 ints, finding max and min values.
    //Then print the two values.


    //Need to sort the vector first
    std::sort(arr.begin(), arr.end());
    //if want min, then just sum from beginning of the vector to n-1
    for (int i = 0; i < (arr.size() - 1); i++) {
        minSum += arr[i];
    }
    //if want max, then sum from beginning + 1 of the vector to n
    for (int i = 1; i < arr.size(); i++) {
        maxSum += arr[i];
    }
    //Must print the min value and then the max value
    cout << minSum << " " << maxSum;

}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        //Data validate that arr_item is at least 1 and not greater than 1e9.
        if (arr_item >= 1 && arr_item <= 1e9) {
            arr[i] = arr_item;
        }
        else {
            arr[i] = 0;
        }
    }

    miniMaxSum(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
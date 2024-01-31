#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string> &v)
{                     // by reference
    int n = v.size(); // current size of vector
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<string> v_string;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v_string.push_back(s);
    }
    printVector(v_string);
}
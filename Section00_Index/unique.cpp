#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // remove consecutive duplicates
    vector<int> data = { 9,1,1,2,3,3,2,5,12,12 };

    cout << "Before: ";
    for (auto it = data.begin(); it != data.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "Before Size: " << data.size() << endl;
    
    auto new_end = unique(data.begin(), data.end());

    data.resize(distance(data.begin(), new_end));

    cout << "After: ";
    for (auto it = data.begin(); it != new_end; it++)
        cout << *it << " ";
    cout << endl;

    cout << "After Size: " << data.size() << endl;

    cout << "After All: ";
    for (auto it = data.begin(); it != data.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}

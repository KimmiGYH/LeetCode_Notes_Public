# STL Binary Search

[Youtube: STL Algorithms 2: std::binary_search, std::lower_bound & std::upper_bound](https://youtu.be/rXuqUtifDU8)

## `binary_search`

```cpp
vector<int> v = {7, 5, 3, 1};

cout << (binary_search(v.begin(), v.end(), 3, greater<int> ()) ? "Found" : "Not Found") << endl; // outputs Found
cout << (binary_search(v.begin(), v.end(), 4, greater<int> ()) ? "Found" : "Not Found") << endl; // outputs Not Found
```

## `lower_bound` (first equal to or greater than)

```cpp
vector<int> v = {1, 3, 3, 5, 7};

auto it  = lower_bound(v.begin(), v.end(), 3);
auto it2 = lower_bound(v.begin(), v.end(), 4);
auto it3 = lower_bound(v.begin(), v.end(), 8);

cout << (it  != v.end() ? to_string(*it) : "Not Found") << endl; // outputs 3
cout << (it2 != v.end() ? to_string(*it2) : "Not Found") << endl; // outputs 5
cout << (it3 != v.end() ? to_string(*it3) : "Not Found") << endl; // outputs Not Found

cout << distance(v.begin(), it) << endl; // outputs 1 (index位置)
```

## `upper_bound` (first greater than)

```cpp
vector<int> v = {1, 3, 3, 5, 7};

auto it  = upper_bound(v.begin(), v.end(), 3);
auto it2 = upper_bound(v.begin(), v.end(), 4);
auto it3 = upper_bound(v.begin(), v.end(), 8);

cout << (it  != v.end() ? to_string(*it)  : "Not Found") << endl; // outputs 5
cout << (it2 != v.end() ? to_string(*it2) : "Not Found") << endl; // outputs 5
cout << (it3 != v.end() ? to_string(*it3) : "Not Found") << endl; // outputs Not Found
```

## `first_less_than`

```cpp
template<typename ForwardIterator, typename T>
ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value) {
    auto it = std::lower_bound(first, last, value);
    return (it == first ? last : --it);
}
```

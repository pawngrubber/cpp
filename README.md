# cpp practice

Run all tests:
```bash
for d in */; do g++ -std=c++17 -Wall "$d"solution.cpp "$d"tests.cpp -o "$d"run && "$d"run; done
```

Run one problem's tests:
```bash
g++ -std=c++17 -Wall 01_longest_unique_substring/solution.cpp 01_longest_unique_substring/tests.cpp -o 01_longest_unique_substring/run && 01_longest_unique_substring/run
```

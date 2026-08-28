# cpp practice

Run all tests:
```bash
for d in */; do (cd "$d" && g++ -std=c++17 -Wall solution.cpp tests.cpp -o run && ./run); done
```

Run one problem's tests:
```bash
cd 01_longest_unique_substring
g++ -std=c++17 -Wall solution.cpp tests.cpp -o run && ./run
```

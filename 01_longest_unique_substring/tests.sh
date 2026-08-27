#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"

g++ -std=c++17 -O2 -o solution solution.cpp

pass=0
fail=0

check() {
    local input="$1"
    local expected="$2"
    local actual
    actual=$(printf '%s' "$input" | ./solution)
    if [ "$actual" = "$expected" ]; then
        pass=$((pass+1))
    else
        fail=$((fail+1))
        echo "FAIL: input=\"$input\" expected=\"$expected\" got=\"$actual\""
    fi
}

check "abcabcbb" "3"
check "bbbbb" "1"
check "pwwkew" "3"
check "" "0"
check "dvdf" "3"
check "abba" "2"

echo "$pass/$((pass+fail)) tests passed"
[ "$fail" -eq 0 ]

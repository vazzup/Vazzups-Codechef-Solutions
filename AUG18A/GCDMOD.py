#!/usr/bin/env python3

from math import gcd

def main():
    t = int(input().strip())
    for i in range(t):
        a, b, n = map(int, input().strip().split())
        MOD = 10**9 + 7
        if a == b:
            print((2 * pow(a, n, MOD)) % MOD)
        else:
            print(gcd((a - b), (2 * pow(b, n, a - b)) % (a - b)) % MOD)

if __name__ == '__main__':
    main()

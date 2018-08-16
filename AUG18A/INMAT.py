#!/usr/bin/env python

def main():
    n, k, v = map(int, input().strip().split())
    if k < n*n:
        x = 5 / 0
    for i in range(n):
        for j in range(n):
            print('1', i, j, flush=True)
            x = int(input().strip())
            if x == v:
                print('2', i, j, flush=True)
                return
    print('2 -1 -1', flush=True)

main()

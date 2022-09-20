import sys

count = sys.stdin.readline().strip()

ch = -1
for i in range(int(count)):
    el = sys.stdin.readline().strip()
    if el != ch:
        print(el)
    ch = el

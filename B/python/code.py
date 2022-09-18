import sys

count = sys.stdin.readline().strip()

result = 0
max = 0
for i in range(int(count)):
    el = sys.stdin.readline().strip()
    if el == '1':
        result += 1
    else:
        if max < result:
            max = result
        result = 0

print(max if max > result else result)
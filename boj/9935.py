import sys
stack = []
target = sys.stdin.readline().rstrip()
bomb = sys.stdin.readline().rstrip()
bomb_len = len(bomb)
for i in range(len(target)):
    stack.append(target[i])
    if ''.join(stack[-bomb_len:]) == bomb:
        for _ in range(bomb_len):
            stack.pop()
if stack:
    print(''.join(stack))
else:
    print('FRULA')
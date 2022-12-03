import os


res = 0
q = []
with open(os.getcwd()+"/day1/input.txt") as f:
    ls = f.read().split('\n')
    s = 0
    for line in ls:
        if line=='':
            q.append(s)
            s = 0
        else: s+=int(line)
    q.append(s)
q = sorted(q)
q = list(reversed(q))
print(q[0]+q[1]+q[2])
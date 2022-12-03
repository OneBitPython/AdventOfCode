import os


res = 0

with open(os.getcwd()+"/day1/input.txt") as f:
    ls = f.read().split('\n')
    s = 0
    for line in ls:
        if line=='':
            res = max(res, s)
            s = 0
        else: s+=int(line)
    res = max(res, s);
print(res)
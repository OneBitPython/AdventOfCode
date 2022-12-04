import os
path = os.getcwd()+"/input.txt"
res = 0
def check(a, b, c, d):
    if d >= a and d <= b:return 1
    elif c <= a and d >= b:return 1
    if c>=a and c <= b:return 1;
    return 0;
for line in open(path).readlines():
    line = line.strip()
    line = line.split(',')
    e = line[0].split("-")
    a = int(e[0])

    b = int(e[1])
    e = line[1].split("-")
    c = int(e[0])
    d = int(e[1])
    if check(a,b,c,d) or check(c,d,a,b):res+=1
print(res)
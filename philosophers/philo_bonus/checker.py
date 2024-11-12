with open("out") as f:
    ls = list(map(str.split, f.readlines()))
mp = {}
forks = max([int(x[1]) for x in ls]) + 1

for x in ls:
    if x[2] == 'is' and x[3] == 'eating':
        num, t = int(x[1]), int(x[0])
        if num in mp:
            mp[num].append(t)
        else:
            mp[num] = [t]
    if x[2] == 'has' and x[3] == 'taken':
        forks -= 1
    if x[2] == 'is' and x[3] == 'sleeping':
        forks += 2
        assert forks >= 0
for num in mp:
    for i in reversed(range(len(mp[num]) - 1)):
        mp[num][i+1] -= mp[num][i]
print(mp)
for x in mp.values():
    assert max(x) <= 599


list1 = []
list2 = []
frequence = [0] * 100000

with open("input.txt", 'r') as f:
    for line in f:
        line = line.strip()
        w = [int(x) for x in line.split()]
        list1.append(w[0])
        list2.append(w[1])
        frequence[w[1]] += 1
        
list1.sort()
list2.sort()

ans1 = ans2 = 0

for index in range(0, len(list1)):
    ans1 += abs(list1[index] - list2[index])
    ans2 += list1[index] * frequence[list1[index]]

print(ans1)
print(ans2)

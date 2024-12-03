
ans1 = ans2 = 0

#part 1

with open("input.txt", 'r') as f:
    for line in f:
        line = line.strip()
        line = [int(x) for x in line.split()]

        increase = False
        decrease = False
        difference = False

        for i in range(1, len(line)):
            if line[i] > line[i-1]:
                increase = True
            elif line[i] < line[i-1]:
                decrease = True
            else:
                increase = decrease = True
            if abs(line[i] - line[i-1]) > 3:
                difference = True

        if increase != decrease and difference == False:
            ans1 += 1

print(ans1)

#part 2

with open("input.txt", 'r') as f:
    for line in f:
        line = line.strip()
        line = [int(x) for x in line.split()]

        ok = False

        for i in range(0, len(line)):
            new_line = line.copy()
            new_line.pop(i)

            increase = False
            decrease = False
            difference = False

            for j in range(1, len(new_line)):
                if new_line[j] > new_line[j-1]:
                    increase = True
                elif new_line[j] < new_line[j-1]:
                    decrease = True
                else:
                    increase = decrease = True
                if abs(new_line[j] - new_line[j-1]) > 3:
                    difference = True

            if increase != decrease and difference == False:
                ok = True
        if ok:
            ans2 += 1

print(ans2)
        



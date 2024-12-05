ans1 = ans2 = 0

manual = True
manualList = []
for i in range (0,100):
    manualList.append([])

def topologicalSort(list, deg, graph):
    visited = [False] * 100
    sorted = []

    for i in range(len(list)):
        for j in list:
            j = int(j)
            if not visited[j] and deg[j] == 0:
                visited[j] = True
                sorted.append(j)
                for k in graph[j]:
                    deg[k] -= 1
                break
    return sorted


with open("input.txt", 'r') as f:
    for line in f:
        if line == "\n":
            manual = False
        else:
            line = line.strip()
            if manual:
                line = line.split('|')
                manualList[int(line[1])].append(int(line[0]))
            else:
                graph = []
                for i in range (0,100):
                    graph.append([])
                deg = [0] * 100
                cantPrint = [False] * 100
                valid = True
                line = line.split(",")
                for number in line:
                    number = int(number)
                    if cantPrint[number] == True:
                        valid = False
                    for i in manualList[number]:
                        cantPrint[i] = True
                        if str(i) in line:
                            deg[number] += 1
                            graph[i].append(number)
                if valid:
                    ans1 += int(line[len(line)//2])
                else:
                    line = topologicalSort(line, deg, graph)
                    ans2 += int(line[len(line)//2])



print(ans1)
print(ans2)



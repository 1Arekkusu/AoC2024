import re

ans1 = ans2 = 0

with open("input.txt", "r") as f:
    file = f.read()
    instructions = re.findall("mul\(\d+,\d+\)", file)

    for i in range(len(instructions)):
        digits = re.findall("\d+", instructions[i])
        ans1 += (int(digits[0]) * int(digits[1]))

    instructions = file.strip().replace("\n", "")
    instructions = re.sub("(don\'t\(\)).+?(do\(\))", "", instructions)
    instructions = re.sub("(don\'t\(\)).+", "", instructions)
    instructions = re.findall("mul\(\d+,\d+\)", instructions)

    for i in range(len(instructions)):
        digits = re.findall("\d+", instructions[i])
        ans2 += (int(digits[0]) * int(digits[1]))

    print(ans1)
    print(ans2)
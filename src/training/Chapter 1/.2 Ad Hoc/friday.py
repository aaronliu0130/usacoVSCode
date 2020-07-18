"""
ID: aaronli2
LANG: PYTHON3
TASK: friday
"""
import sys
import pdb; pdb.set_trace()
sys.stdin=open("friday.in",'r')
sys.stdout=open("friday.out",'w')
def dim(month, year):
    if month == 1:
        return 28 if (year % 4) == 1 or ((year % 100) == 0 and ((year+300) % 400) == 1) else 29
    return {
        8: 30,
        3: 30,
        5: 30,
        10: 30
    }.get(month, 31)


n = eval(input())
if n < 0:
    n = 0
if n > 400:
    n = 400
res = [0, 0, 0, 0, 0, 0, 0]
dow = 0
for i in range(0, n):
    for m in range(0, 12):
        res[(dow+6) % 7] += 1
        dow = (dow+dim(m, i)) % 7
end2 = " "
for i in range(0, 7):
    if i == 6:
        end2 = "\n"
    print(res[(i+6) % 7], end=end2)
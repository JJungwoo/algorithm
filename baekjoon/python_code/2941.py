import re 

instr = input();

sum = len(instr)
m = re.findall('c=', instr)
sum -= len(m)
m = re.findall('c-', instr)
sum -= len(m)
m = re.findall('dz=', instr)
sum -= len(m)
m = re.findall('d-', instr)
sum -= len(m)
m = re.findall('lj', instr)
sum -= len(m)
m = re.findall('nj', instr)
sum -= len(m)
m = re.findall('s=', instr)
sum -= len(m)
m = re.findall('z=', instr)
sum -= len(m)


print(sum)

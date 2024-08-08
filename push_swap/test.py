from random import shuffle
from os import system
from subprocess import run
import subprocess

a = (list(range(500)))
a = [1, 1, 2, 3]
err = 0
for i in range(100):
	shuffle(a)
	inp = ' '.join(map(str, a))
	print("./push_swap "+inp+" | ./checker "+inp)
	system("./push_swap "+inp+" | ./checker "+inp)
	# print(' '.join(cmd))
	# proc = run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	# l = proc.stdout.decode().count('\n')
	# print(l)
	# if l > 700:
	# 	err += 1
	

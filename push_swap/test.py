from random import shuffle
from os import system
from subprocess import run
import subprocess

a = (list(range(100)))

err = 0
for i in range(100):
	shuffle(a)
	cmd = ["./push_swap",' '.join(map(str, a))]#,"|", "wc",  "-l"]
	# print(' '.join(cmd))
	proc = run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	l = proc.stdout.decode().count('\n')
	print(l)
	if l > 700:
		err += 1
	
print(err/100)

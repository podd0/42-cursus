import numpy as np
from math import cos, sin
import math

def rotx(theta):
	theta = math.radians(theta)
	return np.array([[1, 0, 0],
		[0, cos(theta), -sin(theta)],
		[0, sin(theta), cos(theta)]])


def roty(theta):
	theta = math.radians(theta)
	return np.array([[cos(theta), 0, sin(theta)],
				[0, 1, 0],
				[-sin(theta), 0, cos(theta)]])
def rotz(theta):
	theta = math.radians(theta)
	return np.array([[cos(theta), -sin(theta), 0],
					[sin(theta), cos(theta), 0],
					[0, 0, 1]])


def to_loc(vec, frame):
	return np.dot(vec, frame.T)

def to_world(vec, frame):
	frt = frame
	return vec[0]*frt[0]+ vec[1]*frt[1] + vec[2]*frt[2]

frame1 = rotz(45).T

print(frame1)
# exit()
frame2 = frame1.copy()
# print(to_loc(frame1[0], frame1))
# print(np.dot(rotx(45), to_loc(frame1[0], frame1)))
# print(to_world(np.array([1, 0, 0]), frame1))
# exit()
for i in range(3):
	frame2[i] = to_world(np.dot(rotx(45), to_loc(frame1[i], frame1)), frame1)

for x in frame2:
	print(list(x))
# print(repr(frame2.T))

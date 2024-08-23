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
	print("to _world :",vec, '\n', frame)
	return np.dot(frt, vec)
	return vec[0]*frt[0]+ vec[1]*frt[1] + vec[2]*frt[2]



frame1 = rotz(45)
frame2 = to_world(rotx(-45), frame1)
print(frame2)

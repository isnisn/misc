# Description: Plots Asin(kx+b)+c and Acos(kx+b)+c using matplotlib

import matplotlib.pyplot as plt
import math

amplitude = 2
k = 1 #Period ω
c = 0 #Displacement y-axis
b = 0 #Displacement x-axis

#Resolution. 10 will yield a list of [0.1, 0.2, 0.3 ... 0.9] and 100 [0.01, 0.02, 0.03 ... 0.99]
resolution = 50

x_vals = [x / resolution for x in range(-200,resolution + 200)]
y_vals_sin = []
y_vals_cos = []

for x in x_vals:
  #Sin
  y_sin = amplitude * math.sin(k*x + b) + c
  y_vals_sin.append(y_sin)
  
  #Cos
  y_cos = amplitude * math.cos(k*x + b) + c
  y_vals_cos.append(y_cos)

plt.plot(x_vals, y_vals_sin)
plt.plot(x_vals, y_vals_cos)

x_line = [*range(-4,4)]
y_line = [0] * len(x_line)
plt.plot(x_line,y_line)

plt.xlabel('x - axis')
plt.ylabel('y - axis')
plt.title('')
plt.show()

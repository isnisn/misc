def largest_K(n):
    k = 1  # Starting with the first odd integer
    total = 0  # Initialize the total sum
    
    # While the total sum plus the current odd integer is less than N
    # e.g 1 + 3 = 4 < 5
    while total + k < n:
        total += k  # Add the current odd integer to the total sum
        k += 2  # Move to the next odd integer
    return k - 2  # Subtract 2 to get the largest K

# Example usage:
N = 40
result = largest_K(N)
print("For N =", N, ", K =", result)

"""
• A function positive_int(float_lst) that returns a new list with
all the positive numbers in the float list float_lst correctly rounded off
to integers. For example, the input [1.3, 2.67, -2.25, 4.88] the
function should return [1, 3, 5].
"""

def positivt_int(float_lst):
    
    new_lst = []
    
    for el in float_lst:
      if(el > 0): # Only positive numbers
        new_lst.append(round(el))
        
    return new_lst
  
float_lst = [1.3, 2.67, -2.25, 4.88]
print(positivt_int(float_lst))

"""
Create a Python program triangle.py reading a positive integer N from the
keyboard, and then prints a right-angled triangle. See example below to see what
we mean by right-angled in this case. The program should end with an error message if the input N is a non-positive integer. An execution might look like this:
Provide a positive integer: 7
*
**
***
****
*****
******
*******
"""
n = int(input("Give me a natural number {1,2,3 ... }:")) +1
y = n

sym = '*'
pad = ' '

for i in range(1,n+1):
  print(pad*y, end="")
  for j in range(1,i):
    print("*", end="")
  print("")
  y -= 1

print (largest_K(n))

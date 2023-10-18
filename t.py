def largest_K(n):
    k = 1  # Starting with the first odd integer
    total = 0  # Initialize the total sum
    while total + k < n:
        total += k  # Add the current odd integer to the total sum
        k += 2  # Move to the next odd integer
    return k - 2  # Subtract 2 to get the largest K

# Example usage:
N = 24
result = largest_K(N)
print("For N =", N, ", K =", result)

# Python3 program for the above approach

# Function to calculate the maximum
# Manhattan distance


def MaxDist(A, N):

	# List to store maximum and
	# minimum of all the four forms
	V = [0 for i in range(N)]
	V1 = [0 for i in range(N)]

	for i in range(N):
		V[i] = A[i][0] + A[i][1]
		V1[i] = A[i][0] - A[i][1]

	# Sorting both the vectors
	V.sort()
	V1.sort()

	maximum = max(V[-1] - V[0],
				V1[-1] - V1[0])

	print(maximum)


# Driver code
if __name__ == "__main__":

	N = 3

	# Given Co-ordinates
	A = [[3, 10], [5, 15], [4, 4]]

	# Function call
	MaxDist(A, N)

# This code is contributed by rutvik_56

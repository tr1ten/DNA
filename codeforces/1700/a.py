# Python3 program for the above approach
mod = 1000000007

# Function to count number of ways
# to convert string S to string T by
# performing K cyclic shifts
def countWays(s, t, k):
	
	# Calculate length of string
	n = len(s)
	
	# a is no. of good cyclic shifts
	# b is no. of bad cyclic shifts
	a = 0
	b = 0
	
	# Iterate in string
	for i in range(n):
		p = s[i : ] + s[: i]
		
		# Precompute the number of good
		# and bad cyclic shifts
		if(p == t):
			a += 1
		else:
			b += 1
			
	# Initialize two dp arrays
	# dp1[i] to store the no of ways to
	# get to a goof shift in i moves
	
	# dp2[i] to store the no of ways to
	# get to a bad shift in i moves
	dp1 = [0] * (k + 1)
	dp2 = [0] * (k + 1)
	
	if(s == t):
		dp1[0] = 1
		dp2[0] = 0
	else:
		dp1[0] = 0
		dp2[0] = 1
		
	# Calculate good and bad shifts	
	for i in range(1, k + 1):
		dp1[i] = ((dp1[i - 1] * (a - 1)) % mod +
				(dp2[i - 1] * a) % mod) % mod

		dp2[i] = ((dp1[i - 1] * (b)) % mod +
				(dp2[i - 1] * (b - 1)) % mod) % mod
					
	# Return the required number of ways
	return(dp1[k])
	
# Driver Code

# Given Strings
S = 'abcd'
T = 'cdab'

# Given K shifts required
K = 2

# Function call
print(countWays(S, T, K))

# This code is contributed by Arjun Saini

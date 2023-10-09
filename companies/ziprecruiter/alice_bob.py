def solve(nums) : 
	st = []; 
	counter = 0
	for i in range(len(nums)) :
		if len(st) == 0 or st[-1] != nums[i] :  st.append(nums[i]); 
		else: 
			counter += 1; 
			st.pop(); 
	return "Bob" if counter%2==0 else "Alice"
		
print(solve([1,4,5,5,6]))
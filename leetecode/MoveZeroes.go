package main

import (
	"fmt"
)

// think inversly move non zero to starting
func moveZeroes(nums []int)  {
	nZeros := 0;
	n := len(nums);
	for i := 0; i < n; i++ {
		if(nums[i]==0) {
			nZeros++;
		}
	}
	temp :=0;
	for i := 0; i < n && temp < (n-nZeros); i++ {
		if(nums[i]!=0) {
			nums[temp] = nums[i];
			temp++
		}
	}
	for j := 0; j < nZeros; j++ {
		nums[n-j-1] = 0;
	}

	
}

func printArr(nums []int) {
	for _, v := range nums {
		fmt.Println(v);
	}
}

func main()  {
	arr := []int{5,1,2,0,0,2,1,0,0,1};
	// printArr(arr[:]);
	moveZeroes(arr[:]);
	printArr(arr[:]);
}
x = int(input("Enter the number"))
print("Not Prime" if any([x%i==0 for i in range(2,x)]) else "prime")

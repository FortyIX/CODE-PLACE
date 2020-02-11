
# (c) 2019 FU ZHANG

# Question 1
# Create a python program that prints all prime numbers in a range of numbers. take the input from the user as the
# endpoint and print all prime number from 1 to that endpoint.
#
# EXAMPLE INPUT
# 5
#
# EXPECTED OUTPUT:
# 2
# 3


value = input("Enter a number as the end point \n")

for i in range(0, int(value)+1):
    if i > 1:   #primer nums are greater than 1
        for j in range(2, i):  #process to check if this number is divisable by 2
            if (i % j) == 0:
                break
        else:
            print(i)

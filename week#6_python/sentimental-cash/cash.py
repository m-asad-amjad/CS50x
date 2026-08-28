#imporing get_int from cs50
from cs50 import get_float

#taking valid value for change from the user
while True:
    change = get_float("Change: ")

    if change >= 0:
        break


#converting dollars to cents
change = round(change * 100)

#taking coins zero at start
coins = 0


#making function to getrid of doing same task again and again
def reducer(value_to_reduce):
    #making coins and chang global to use in the function
    global change
    global coins


    while change >= value_to_reduce:

        change = change - value_to_reduce
        coins = coins + 1


# Use the largest coins first
reducer(25)
reducer(10)
reducer(5)
reducer(1)


print(coins)


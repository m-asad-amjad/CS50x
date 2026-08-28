while True:
    try:
        height = int(input("Height: "))
        #python takes input in form of dtring as default therefore it is specified to int
        if 1 <= height <=8:
        #this will take height between 1 and 8
             break
        #this will stop the loop when we got our correct input
    except ValueError:
        pass
        #pass means let the program run doing nothing
        #without except invalid input will crash the program
        #in this case python will ignore invalid input like strings

for i in range(height):

    print(f" " * (height - 1 -i), end="")
    #this will print spaces until all the "#" make a vertical line to for a pyramidal shape
    print("#" *(i + 1))
    # i + 1 will make height equal to actual heigth instead of one less than actual height
    # actual height is that what entered by user

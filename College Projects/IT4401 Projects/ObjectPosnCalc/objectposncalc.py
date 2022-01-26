print("Welcome to my Object Position Calculator!")

do_calculation = True
while (do_calculation):
    while(True):
        try:
            x0 = float(input("Please enter the initial position: "))
        except ValueError:
            print("Invalid Entry. Please enter only numerical values.")
        else:
            break

    while(True):
        try:
            v0 = float(input("Please enter the initial velocity: "))
        except ValueError:
            print("Invalid Entry. Please enter only numerical values.")
        else:
            break

    while(True):
        try:
            a = float(input("Please enter the acceleration: "))
        except ValueError:
            print("Invalid Entry. Please enter only numerical values.")
        else:
            break
    
    while(True):
        try:
            t = float(input("Please enter the time elapsed: "))
            if (t < 0):
                print("Negative time values are not allowed. :(")
                continue
        except ValueError:
            print("Invalid Entry. Please enter only numerical values.")
        else:
            break


    xf = x0 + v0 * t + (1/2 * a * t * t)
    print("Final Position: " + str(xf))

    another_calculation = input("Do you want to calculate another value? (y/n): ")
    if (another_calculation != "y"):
        do_calculation = False
        


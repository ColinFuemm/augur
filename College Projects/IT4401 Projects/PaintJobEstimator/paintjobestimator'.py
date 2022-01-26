import math
print("Welcome to my Paint Job Estimator!")

do_calculation = True
while (do_calculation):
    laborCost = 62.25
    
    while(True):
        try:
            squareFootage = float(input("What is the square footage of the area? "))
            if (squareFootage < 0):
                print("Negative values are not allowed. :(")
                continue
        except ValueError:
            print("Invalid Entry. Please enter only numerical values.")
        else:
            break
        
    while(True):
        try:
            price = float(input("What is the price per gallon? "))
            if (price < 0):
                print("Negative values are not allowed. :(")
                continue
        except ValueError:
            print("Invalid Entry. Please enter only numerical values.")
        else:
            break


    gallonsPaint = math.ceil(squareFootage/350)
    costPaint = gallonsPaint * price
    laborHours = 6*(squareFootage/350)
    laborPrice = laborCost * laborHours
    total = laborPrice + costPaint

    print("You should buy " + str(gallonsPaint) + " gallons of paint for this job.")

    formatString = "{:.1f}".format(laborHours)
    print("This job will require " + formatString + " hours of labor.")

    formatString = "{:.2f}".format(costPaint)
    print("The paint will cost $" + formatString)

    formatString = "{:.2f}".format(laborPrice)
    print("Labor will cost $" + formatString)

    formatString = "{:.2f}".format(total)
    print("The total estimate for this job is $" + formatString)

    another_calculation = input("Would you like to make another estimate? (y/n): ")
    if (another_calculation != "y"):
        do_calculation = False
        


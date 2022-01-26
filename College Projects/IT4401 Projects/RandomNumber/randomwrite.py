import random

def getNumCount():
    numQuantity = 0
    while(True):
        try:
            numQuantity = int(input('How many random numbers do you want? '))
            if (numQuantity <= 0):
                print('Number must be higher than 0.')
                continue
        except:
            print('Only integer values are valid.')
            continue
        else:
            break
    return numQuantity

def getMinRange():
    minimum = 0
    while(True):
        try:
            minimum = int(input('What is the lowest the random number should be? '))
        except:
            print('Only integer values are valid.')
            continue
        else:
            break
    return minimum

def getMaxRange(minimum):
    maximum = 0
    while(True):
        try:
            maximum = int(input('What is the highest the random number should be? '))
            if (maximum < minimum):
                print('Number must be greater than the minimum.')
                continue
        except:
            print('Only integer values are valid.')
            continue
        else:
            break
    return maximum

def generateNum(numQuantity, minimum, maximum):
    f = open("randomnum.txt", "w")
    count = 0
    while (count < numQuantity):
        n = random.randrange(minimum, maximum)
        f.write(str(n))
        f.write("\n")
        count = count + 1
    print("The random numbers were written to randomnum.txt")
    f.close()

def main():
    count = getNumCount()
    min = getMinRange()
    max = getMaxRange(min)
    generateNum(count, min, max)

main()
    
    

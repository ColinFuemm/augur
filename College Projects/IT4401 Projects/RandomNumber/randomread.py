try:
    f = open("randomnum.txt")
except:
    print("Error: No File Found")
else:
    print("List of random numbers in randomnum.txt")
    Lines = f.readlines()
    count = 0
    for line in Lines:
        print(line.strip())
        count += 1
    print("Number of Values: ",  count )
    f.close()

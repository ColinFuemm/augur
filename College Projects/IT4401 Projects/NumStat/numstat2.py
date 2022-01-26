from collections import Counter

def get_numbers(file):
    numbers = []
    fp = None
    try:
        fp = open(file, 'r')
        for number_string in fp:
            numbers.append(int(number_string)) # convert string in file to an int value
    except Exception as error:
        print(error)
    finally:
        if (fp != None):
            fp.close()
    return numbers
            
def calculate_median_and_mode(numbers):
    numSize = len(numbers)
    numbers.sort()

    if numSize % 2 == 0:
        med = numbers[numSize//2]
        ian = numbers[numSize//2 - 1]
        median = (med + ian)/2
    else:
        median = numbers[numSize//2]
    print("Median: " + str(median))
    
    c = Counter(numbers)
    mode = [k for k, v in c.items() if v == c.most_common(1)[0][1]]
    print("Mode: " + str(mode))

def generate_report(numbers, file):
    print("File Name: ", file)
    sum = 0
    count = 0
    max = -999999999
    min = 999999999
    for num in numbers:
        count += 1
        sum += num
        if num > max:
            max = num
        if num < min:
            min = num
    if count == 0:
            print("Error: No numbers found")
            return
    print("Sum:",  sum)
    print("Count:",  count)
    print("Average:",  sum/count)
    print("Maximum:",  max)
    print("Minimum:",  min)
    print("Range:",  max-min)
    calculate_median_and_mode(numbers)
        
    
def main():
    while (True):
        file = input("Please enter the name of your file: ")
        numbers = get_numbers(file)
        generate_report(numbers, file)
        calculate_again = input("Would you like to check another file? y/n:" )
        if (calculate_again != "y"):
            break  
        else:
            print('') # separator between inputs
    
main()
                    
                    
   
    
    

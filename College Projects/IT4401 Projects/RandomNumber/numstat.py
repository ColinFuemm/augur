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
    print("Sum:",  sum)
    print("Count:",  count)
    print("Average:",  sum/count)
    print("Maximum:",  max)
    print("Minimum:",  min)
    print("Range:",  max-min)
        
    
def main():
    file = input("Please enter the name of your file: ")
    numbers = get_numbers(file)
    generate_report(numbers, file)
    
main()
                    
                    
   
    
    

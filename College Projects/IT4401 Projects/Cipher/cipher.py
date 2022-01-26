def prompt_user():
    print("Welcome to my message cipher!")
    print("1 Encode a Message")
    print("2 Decode a Message")
    print("3 Exit Program")
    string = input("What would you like to do? ")
    return string

def encode(string):
    string = string.replace("a", "0")
    string = string.replace('b','1')
    string = string.replace('c','2')
    string = string.replace('d','3')
    string = string.replace('e','4')
    string = string.replace('f','5')
    string = string.replace('g','6')
    string = string.replace('h','7')
    string = string.replace('i','8')
    string = string.replace('j','9')
    string = string.replace('k','!')
    string = string.replace('l','@')
    string = string.replace('m','#')
    string = string.replace('n','$')
    string = string.replace('o','%')
    string = string.replace('p','^')
    string = string.replace('q','&')
    string = string.replace('r','*')
    string = string.replace('s','(')
    string = string.replace('t',')')
    string = string.replace('u','-')
    string = string.replace('v','+')
    string = string.replace('w','<')
    string = string.replace('x','>')
    string = string.replace('y','?')
    string = string.replace('z','=')
    print("Encoded String: " + string)
        
def decode(string):
    string = string.replace("0", "a")
    string = string.replace('1','b')
    string = string.replace('2','c')
    string = string.replace('3','d')
    string = string.replace('4','e')
    string = string.replace('5','f')
    string = string.replace('6','g')
    string = string.replace('7','h')
    string = string.replace('8','i')
    string = string.replace('9','j')
    string = string.replace('!','k')
    string = string.replace('@','l')
    string = string.replace('#','m')
    string = string.replace('$','n')
    string = string.replace('%','o')
    string = string.replace('^','p')
    string = string.replace('&','q')
    string = string.replace('*','r')
    string = string.replace('(','s')
    string = string.replace(')','t')
    string = string.replace('-','u')
    string = string.replace('+','v')
    string = string.replace('<','w')
    string = string.replace('>','x')
    string = string.replace('?','y')
    string = string.replace('=','z')
    print("Decoded String: " + string)
    
def main():
    calculate_again = 'y'
    while (True):
        string = prompt_user()
        if string == "1":
            encode(input("Please Enter a String: "))
            print('')
        elif string == "2":
            decode(input("Please Enter a String: "))
            print('')
        elif string == "3":
            break
        else:
            print("Oops! Please enter a number between 1 and 3.")
    
main()

import cs50
import sys

if len(sys.argv) == 2:
    num = sys.argv[1]
    
    #convert argv to integer
    k = int(num)
   
    #get plaintext
    p = input("plaintext: ")
    
    #encipher plain text
    #iterate over each char in plain text
    print("ciphertext: ",end="")
    
    for char in p:
        if char.isalpha():
            
            if char.isupper():
                a = ord(char) - 65
                c = ((a+k)%26) + 65
                print(chr(c),end="")
            
            elif char.islower():
                a = ord(char) - 97
                c = ((a+k)%26) + 97
                print(chr(c),end="")
                
        else:
            print(char,end="")
    
    print()
    
else:
    print("Usage: "+ sys.argv[0])
    

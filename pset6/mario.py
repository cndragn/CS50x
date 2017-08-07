import cs50

height = int(input("Height: "))

if height > 0 and height < 23:
    
    x = " "
    spaces = height
    hashes = 2
    
    print(hashes)

    for i in range(0,height):
        for s in range(1,spaces):
            print(x,end="")
            
        for h in range(0,hashes):
            print("#",end="")
            
        spaces -= 1 
        hashes += 1
        print()
        
            
        
        

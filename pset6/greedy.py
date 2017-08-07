import cs50

while True:
    change = float(input("O hai! How much chnage is owed? "))
    if change > 0:
        break

change = round(change * 100)
coins = 0

#print(change);

while change > 0:
    while change >= 25:
        change = change - 25
        coins = coins + 1
        
    while change >= 10:
        change = change - 10
        coins = coins + 1
        
    while change >= 5:
        change = change - 5
        coins = coins + 1
        
    while change >= 1:
        change = change - 1
        coins = coins + 1
        
print(coins)
    

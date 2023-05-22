from cs50 import get_float
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

change *= 100
coins = 0
while change > 0:
    if change >= 25:
        change = change - 25
        coins = coins + 1
    elif change >= 10:
        change -= 10
        coins = coins + 1
    elif change >= 5:
        change = change - 5
        coins = coins + 1
    else:
        change = change - 1
        coins = coins + 1
print(coins)


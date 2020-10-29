from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")

    if dollars >= 0:
        break

cents = round(dollars, 100) * 100
coins = (25, 10, 5, 1)

num_of_coins, i = 0, 0

while cents != 0:
    if cents - coins[i] >= 0:
        cents -= coins[i]
        num_of_coins += 1
    else:
        i += 1

print(num_of_coins)

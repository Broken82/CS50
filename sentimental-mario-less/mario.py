from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break


for i in range(n):
    print("")
    for j in range(n - i - 1):
        print(" ", end="")
    for k in range(i + 1):
        print("#", end="")


print("")




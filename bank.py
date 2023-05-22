import cs50

greeting = cs50.get_string("Greeting: ").casefold()


if "hello" in greeting:
    print("$0")

elif "h" in greeting[0]:
    print("$20")

else:
    print("$100")

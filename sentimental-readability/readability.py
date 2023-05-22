from cs50 import get_string


text = get_string("Text: ")
stops = ["!", "?", "."]


sentences = 0
words = 1
letters = 0

for c in text:
    if c in stops:
        sentences += 1
    if " " in c:
        words += 1
    if c.isalpha():
        letters += 1


index = 0.0588 * letters/words * 100 - 0.296 * sentences/words * 100 - 15.8

if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")
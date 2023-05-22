import sys
from pyfiglet import Figlet
import random


figlet = Figlet()
fonts = figlet.getFonts()
f = random.choice(figlet.getFonts())




if len(sys.argv) == 1:
    s = input("Input: ")
    figlet.setFont(font=f)
    print(figlet.renderText(s))

elif (len(sys.argv) == 3) and (sys.argv[1] == "-f" or sys.argv[1] == "--font") and (sys.argv[2] in fonts):
    s = input("Input: ")
    figlet.setFont(font=sys.argv[2])
    print(figlet.renderText(s))


else:
    sys.exit("Invalid usage")








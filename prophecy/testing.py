from cs50 import SQL
import csv

db = SQL("sqlite:///newroster.db")

hogwarts = []
with open("students.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        hogwarts.append(row)

print(list(hogwarts[0]))

houses = {
    'Slytherin': 1,
    'Ravenclaw': 2,
    'Hufflepuff': 3,
    'Gryffindor': 4
}


for i in range(len(hogwarts)):
    keys = list(hogwarts[0])
    values = list(hogwarts[i].values())

    id = db.execute("INSERT INTO assingment (student_id, house_id) VALUES (?, ?)", values[0], houses[values[2]])

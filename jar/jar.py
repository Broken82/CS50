class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0
        if self.capacity < 0:
            raise ValueError

    def __str__(self):
        return ("🍪" * self.size)

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError
        else:
            self.size += n

    def withdraw(self, n):
        if self.size - n < 0:
            raise ValueError
        else:
            self.size -= n

    @property
    def capacity(self):
        return self.capacity


    @property
    def size(self):
        return self.size


def main():
    jar = Jar()

    print(str(jar.size))
    jar.deposit(3)
    print(str(jar.size))


main()
class student(object):
    def __init__(self, name, score, gender):
        self.name = name
        self.score = score
        self.__gender = gender

    def print_score(self):
        print("%s %s" % (self.name, self.score))

    def get_gender(self):
        return self.__gender


a = student('a', 100, 'm')
b = student('b', 99, 'f')
a.print_score()
b.print_score()
# print(a.__gender)private
print(a._student__gender)
print(a.get_gender())


class fstu(student):
    def __init__(self, name, score, gender='f'):
        self.name = name
        self.score = score


c = fstu('c', 98)
c.print_score()

print(type(c))
print(isinstance(c, student))
print(dir(c))

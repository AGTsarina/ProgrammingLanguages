class Student:
    def __init__(self):
        self.name = "Name"
        self.age = 20
        self.grades = [100,100,100]
        self.group = "M-25"

student = Student()
students = [student, student, student]
student.group = "VT-25"
print()
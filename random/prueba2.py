import random



abc = ["a", "b", "c", "d", "e", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
alumnos = []
for i in range(48):
    alumno = ""
    for i in range(random.randint(3, 8)):
        alumno += abc[random.randint(0, len(abc)-1)]
    alumnos.append(alumno)

print(alumnos)
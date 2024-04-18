#users = ["algo", "algo mas", "algo mas todavia"]
#passwords = ["algo123", "algomas123", "algomastodavia123"]

#with open("txt/base.txt", "a") as text:
#    i = 0
#    for idx in users:
#        text.write(users[i] + "\n")
#        i += 1

with open("txt/base.txt", "r") as text:
    users = []
    i = 0
    for item in text:
        users.append(item)
    print(users)
    
    


#name = input("Ingrese usuario: ")
# logged = False
# user = -1
# for i in users:
#     if name in users[i]:
#         logged = True
#         user = i
#         break

#if logged:
#    pword = input("Ingrese contraseña: ")
#    if pword == passwords[i]:
#        print("Logged in succesfully")
def coef(vel, mas):
    coeficientes = []
    for i in range(len(vel)):
        if int(vel[i]) <= 1200:
            coeficientes.append(int(vel[i]) / int(mas[i]))
            
    return sorted(coeficientes)



velocidades = ['150000', '500', '300', '1200', '690', '500']
masas = ['100', '900', '300', '69', '1700', '600']

coeficientes = coef(velocidades, masas)
print(coeficientes)
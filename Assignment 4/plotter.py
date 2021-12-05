import matplotlib.pyplot as plt
import csv

file= open("data.csv", "r")
reader = csv.reader(file)

x = []
y_sus = []
y_inf = []
y_rec = []

for row in reader:
    x.append(int(row[0]))
    y_sus.append(int(row[1]))
    y_inf.append(int(row[2]))
    y_rec.append(int(row[3]))

plt.plot(x, y_sus, label="Susceptible")
plt.plot(x, y_inf, label="Infected")
plt.plot(x, y_rec, label="Recovered")
plt.xlabel("Number of days")
plt.ylabel("Number of people")
plt.title("SIR model")
plt.legend()
plt.show()
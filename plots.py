import csv
import matplotlib.pyplot as plt

def read_csv(filename):
    Ns = []
    random_t = []
    reverse_t = []
    almost_t = []

    with open(filename, "r") as f:
        reader = csv.reader(f)
        next(reader)
        for row in reader:
            Ns.append(int(row[0]))
            random_t.append(float(row[1]))
            reverse_t.append(float(row[2]))
            almost_t.append(float(row[3]))

    return Ns, random_t, reverse_t, almost_t


Ns_pure, pure_r, pure_rev, pure_alm = read_csv("results_quick_pure.csv")
Ns_intro, intro_r, intro_rev, intro_alm = read_csv("results_intro.csv")

plt.figure(figsize=(12, 6))
plt.plot(Ns_pure, pure_r, label="QuickSort")
plt.plot(Ns_intro, intro_r, label="Introsort")
plt.xlabel("Размер массива N")
plt.ylabel("Время (мкс)")
plt.title("Random — QuickSort vs Introsort")
plt.grid()
plt.legend()
plt.savefig("plot_random.png", dpi=200)
plt.close()

plt.figure(figsize=(12, 6))
plt.plot(Ns_pure, pure_rev, label="QuickSort")
plt.plot(Ns_intro, intro_rev, label="Introsort")
plt.xlabel("Размер массива N")
plt.ylabel("Время (мкс)")
plt.title("Reverse — QuickSort vs Introsort")
plt.grid()
plt.legend()
plt.savefig("plot_reverse.png", dpi=200)
plt.close()


plt.figure(figsize=(12, 6))
plt.plot(Ns_pure, pure_alm, label="QuickSort")
plt.plot(Ns_intro, intro_alm, label="Introsort")
plt.xlabel("Размер массива N")
plt.ylabel("Время (мкс)")
plt.title("Almost sorted — QuickSort vs Introsort")
plt.grid()
plt.legend()
plt.savefig("plot_almost.png", dpi=200)
plt.close()

print("Графики построены: plot_random.png, plot_reverse.png, plot_almost.png")

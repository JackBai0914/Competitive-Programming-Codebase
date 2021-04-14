import matplotlib.pyplot as plt
import numpy as np

f = open("race_data14.csv", "r")
s = f.read()
t = s.split("\n")
u = [t[i].split(",") for i in range(1, len(t)-1)]
v = [[int(uu[0]), int(uu[1]), float(uu[2])] for uu in u]

def average_list (lst, r):
	ans = []
	c = 0
	for i in range (len(lst)):
		c = c * r + lst[i] * (1-r)
		ans.append(c / (1 - np.power(r, i + 1)));
		# print(np.power(r, i + 1))
	return ans

rnd = [vv[0] for vv in v]
wpm = [vv[1] for vv in v]
acc = [vv[2] for vv in v]
date = [uu[6][5:10] for uu in u]

def show_typing_speed(decay_rate):
	fig, ax1 = plt.subplots(figsize=(8, 6), dpi=100)
	plt.title('Typing Speed', fontsize=25)
	plt.xlabel('Date', fontsize=20)
	plt.xlim(0, len(u) * 1.05)
	plt.grid(axis='y', linestyle='--')
	plt.plot(rnd, average_list(wpm, decay_rate), color = 'lightcoral', linewidth = 1, label = 'WPM-' + str(decay_rate))
	plt.legend(loc='lower left', fontsize=10, ncol=2)
	plt.ylabel('Words per Minute', fontsize=20)
	xtk = [date[int(x)] for x in list(np.linspace(0, len(u) - 1, 15))];
	plt.xticks(np.linspace(0, len(u) - 1, 15), xtk, fontsize = 10)
	plt.savefig('typing_speed_'+str(len(u))+'.jpg', quality=95)
	# plt.show()

def show_typing_accuracy(decay_rate):
	fig, ax1 = plt.subplots(figsize=(8, 6), dpi=100)
	plt.title('Typing Accuracy', fontsize=25)
	plt.xlabel('Date', fontsize=20)
	plt.xlim(0, len(u) * 1.05)
	plt.grid(axis='y', linestyle='--')
	plt.plot(rnd, average_list(acc, decay_rate), color = 'blue', linewidth = 1, label = 'Accuracy-' + str(decay_rate))
	plt.legend(loc='lower left', fontsize=10, ncol=2)
	xtk = [date[int(x)] for x in list(np.linspace(0, len(u) - 1, 15))];
	plt.xticks(np.linspace(0, len(u) - 1, 15), xtk, fontsize = 10)
	# plt.show()
	plt.savefig('typing_accuracy_'+str(len(u))+'.jpg', quality=95)

show_typing_accuracy(0.990)
show_typing_speed(0.98)


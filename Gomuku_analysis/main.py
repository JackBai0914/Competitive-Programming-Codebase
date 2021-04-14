import matplotlib.pyplot as plt
import numpy as np
import random as rd
from scipy import interpolate

days_in_months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
def trans_time_to_hour (month, date, hour):
	all_hour = (date - 1) * 24 + hour
	for i in range(1, month): 
		all_hour += days_in_months[i] * 24
	return all_hour;
def trans_hour_to_time (hour):
	month = 0;
	while hour >= days_in_months[month + 1] * 24:
		month += 1
		hour -= days_in_months[month] * 24
	month += 1
	day = hour // 24 + 1
	hour %= 24;
	return str(month)+'.'+str(day)
def trans_hours_to_times (hours):
	times = []
	for hour in hours:
		times.append(trans_hour_to_time(hour))
	return times

def trans_time_to_sec (minute, second):
	return minute * 60 + second
def trans_sec_to_time (sec):
	return str(sec//60)
def trans_secs_to_times (secs):
	times = []
	for sec in secs:
		times.append(trans_sec_to_time(sec))
	return times


db = open('db.txt').readlines();

games_tuples = [[], [], [], []];

for game in db:
	if game == '\n':
		break;
	game_info = game.split(" ");
	month = int(game_info[2].split(".")[0]);
	date = int(game_info[2].split(".")[1]);
	hour = int(game_info[2].split(".")[2][0]) + 12 * (game_info[2].split(".")[2][1] == 'p') + rd.uniform(-8, 8);
	minute = int(game_info[1].split(":")[0]);
	second = int(game_info[1].split(":")[1]);

	diff = game_info[0];
	time = trans_time_to_sec (minute, second)
	loc = trans_time_to_hour (month, date, hour)
	if diff == 'e':
		games_tuples[0].append(tuple([loc, time]));
	if diff == 'm':
		games_tuples[1].append(tuple([loc, time]));
	if diff == 'h':
		games_tuples[2].append(tuple([loc, time]));
	if diff == 'ex':
		games_tuples[3].append(tuple([loc, time]));

for i in range(0, 4):
	games_tuples[i] = sorted(games_tuples[i])

fig, ax = plt.subplots(figsize = (14, 7))
ax.set_title('Gomuku Analysis Chart',fontsize=18)
X_MN = trans_time_to_hour(6, 20, 0)
X_MX = trans_time_to_hour(6, 28, 0)
Y_MN = trans_time_to_sec(0, 0)
Y_MX = trans_time_to_sec(10, 0)
ax.set_xlim(X_MN - 5, X_MX + 5)
ax.set_xticks(range(X_MN, X_MX + 1, 24))
ax.set_xticklabels(trans_hours_to_times(range(X_MN, X_MX + 1, 24)))
ax.set_ylim(Y_MN, Y_MX)
ax.set_yticks(range(Y_MN, Y_MX + 1, 60))
ax.set_yticklabels(trans_secs_to_times(range(Y_MN, Y_MX + 1, 60)))

def sum_seconds(list):
	sum = 0
	for e in list:
		sum += e[1]
	return sum

def paint (games):
	# paint each game as a point
	# calculate the average time of previous 5 games, and ChaZhi them
	# calculate the average time of previous 10 games, and ChaZhi them
	# calculate the average time of all played games, and ChaZhi the
	games_x = []
	prev_5 = []
	prev_10 = []
	prev_all = []
	for i in range(0, len(games)):
		game = games[i]
		games_x.append(game[0])
		prev_5.append(sum_seconds(games[max(0, i - 4) : i + 1]) / (i + 1 - max(0, i - 4)))
		prev_10.append(sum_seconds(games[max(0, i - 9) : i + 1]) / (i + 1 - max(0, i - 9)))
		prev_all.append(sum_seconds(games[0 : i + 1]) / (i + 1))
		if game[0] < X_MN or game[0] > X_MX:
			continue	
		ax.scatter(game[0], game[1], color = 'blue')
	prev_all_f = interpolate.UnivariateSpline(games_x, prev_all, s = 6000)
	ax.plot(games_x, prev_all_f(games_x), color = 'green')

	prev_10_f = interpolate.UnivariateSpline(games_x, prev_10, s = 6000)
	ax.plot(games_x, prev_10_f(games_x), color = 'orange')

	prev_5_f = interpolate.UnivariateSpline(games_x, prev_5, s = 6000)
	ax.plot(games_x, prev_5_f(games_x), color = 'red')


	# ax.plot(games_x, prev_10, color = 'yellow')
	# ax.plot(games_x, prev_5, color = 'red')

paint (games_tuples[1])

plt.show();









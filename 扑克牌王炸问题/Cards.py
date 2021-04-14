#dp[points][fir_num][sec_num][bomb_num] represents the possibility that:
#	after spreading all cards with points no larger than points, the first player has fir_num cards, the second player has sec_num cards, and there're bomb_num bombs.
dp = [[[[0.0 for bn in range (14)] for sn in range (19)] for fn in range (19)] for pts in range (14)]
dp[0][0][0][0] = 1


def dfs (stage, bn, step, fn, sn, tn, fh, sh, th, weight):
	if weight == 0:
		return
	if (step == 5):
		if fh == 4 or sh == 4 or th == 4:
			dp[stage + 1][fn + fh][sn + sh][bn + 1] += dp[stage][fn][sn][bn] * weight
		else:
			dp[stage + 1][fn + fh][sn + sh][bn] += dp[stage][fn][sn][bn] * weight
		return
	fw, sw, tw = 18 - fn - fh, 18 - sn - sh, 18 - tn - th
	dfs (stage, bn, step + 1, fn, sn, tn, fh + 1, sh, th, weight * fw)
	dfs (stage, bn, step + 1, fn, sn, tn, fh, sh + 1, th, weight * sw)
	dfs (stage, bn, step + 1, fn, sn, tn, fh, sh, th + 1, weight * tw)

# dynamic programming process
for pts in range (13):
	for fn in range (19):
		for sn in range (19):
			for bn in range (pts + 1):
				if dp[pts][fn][sn][bn] == 0:
					continue
				tn = 4 * pts - fn - sn
				dfs (pts, bn, 1, fn, sn, tn, 0, 0, 0, 1)						

ans = [0.0 for bn in range (15)]

#now consider jokers
for fn in range (19):
	for sn in range (19):
		for bn in range (14):
			tn = 4 * 13 - fn - sn
			if fn == 16 or sn == 16 or tn == 16:
				# there's an additional bomb
				ans[bn + 1] += dp[13][fn][sn][bn] * 2
			else:
				ans[bn] += dp[13][fn][sn][bn] * 2

#output
fac_54 = 230843697339241380472092742683027581083278564571807941132288000000000000
for bn in range (15):
	print ("the possibility of having", bn, "bombs is: ", '{:.0f}'.format(ans[bn]), "/ 54!", "= {0:.15f}".format(ans[bn] / fac_54)) 
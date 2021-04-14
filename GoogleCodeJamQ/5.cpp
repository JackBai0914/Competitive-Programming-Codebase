/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* @author: Xingjian Bai 
* @date: 2021-03-26 14:18:09
* @description: 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long double ld;
typedef long long ll;
const int oo = 1e9;

const int n = 100, m = 10000;
int T, P, sum = 0;
int mp[100][10000], ss[100], sq[10000];
ld lists[601], listq[601], cht[601];
ld preds[100], predq[10000];

namespace Input {
	ld s[100], q[10000];
	ld Random () {return (ld)rand()/RAND_MAX;}
	ld f (ld s, ld q) {return 1.0 / (1 + exp(q - s));}
	int cheater;
	void main() {
		cheater = rand() % 100;
		for (int i = 0; i < n; i ++)	s[i] = Random() * 6 - 3;
		for (int i = 0; i < m; i ++)	q[i] = Random() * 6 - 3;
		sort(s, s + n);sort(q, q + m);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++) {
				if (i == cheater && Random() > 0.5)	mp[i][j] = 1;
				else	mp[i][j] = (Random() <= f(s[i], q[j]));
			}
	}
	bool correct (int x) {return x == cheater;}
}

inline ld f (ld s, ld q) {return 1.0 / (1 + exp(q - s));}
void init () {
	memset(lists, 0, sizeof(lists));
	for (int i = 0; i <= 600; i ++)
		for (int j = 0; j <= 600; j ++)
			lists[i] += f(i * 0.01 - 3, j * 0.01 - 3) / 600 * 10000;
}
void init2() {
	memset(listq, 0, sizeof(listq));
	for (int i = 0; i <= 600; i ++)
		for (int j = 0; j < n; j ++)
			listq[i] += f(preds[j], i * 0.01 - 3);
}
void init_cht() {
    for (int i = 0; i <= 600; i ++) {
        cht[i] = 5000;
        for (int j = 0; j <= 600; j ++)
            cht[i] += f(i * 0.01 - 3, j * 0.01 - 3) / 600 * 5000 ;
    }
}
ld rev(ld x) {
    ld mn = 1e9, id = -1;
    for (int i = 0; i <= 600; i ++)
        if (fabs(cht[i] - x) < mn)
            mn = fabs(cht[i] - x), id = i;
    return id * 0.01 - 3;
}

// void report() {
// 	ld avn = 0, avm = 0;
// 	for (int i = 0; i < n; i ++)avn += fabs(Input::s[i] - preds[i]);
//     for (int i = 0; i < m; i ++)avm += fabs(Input::q[i] - predq[i]);
//     cerr << "acc: " << avn / n << " " << avm / m << endl;
// }
// void refine() {
// 	for (int i = 0; i <= 600; i ++) {
// 		lists[i] = 0;
// 		for (int j = 0; j < m; j ++)
// 			lists[i] += f(i * 0.01 - 3, predq[j]);
// 	}
// 	for (int i = 0; i < n; i ++) {
//     	int mn = 1e9, id = 0;
//     	for (int j = 0; j < 600; j ++)
//     		if (fabs(ss[i] - lists[j]) < mn)
//     			mn = fabs(ss[i] - lists[j]), id = j;
//     	preds[i] = id * 0.01 - 3;
//     }
//     for (int i = 0; i <= 600; i ++) {
// 		listq[i] = 0;
// 		for (int j = 0; j < n; j ++)
// 			listq[i] += f(preds[j], i * 0.01 - 3);
// 	}
//     for (int i = 0; i < m; i ++) {
//     	int mn = 1e9, id = 0;
//     	for (int j = 0; j <= 600; j ++)
//     		if (fabs(listq[j] - sq[i]) < mn)
//     			mn = fabs(listq[j] - sq[i]), id = j;
//     	predq[i] = id * 0.01 - 3;
//     }
// }

int main() {
	srand(time(0));
    ios::sync_with_stdio(false);

    cin >> T >> P; //OR: 
    // T = 100;
    
    init();
    init_cht();
    for (int t = 1; t <= T; t ++) {
    	memset(sq, 0, sizeof sq);
    	memset(ss, 0, sizeof ss);

    	for (int i = 0; i < n; i ++) {
         string ins;
    		cin >> ins;
    		for (int j = 0; j < m; j ++)
    			mp[i][j] = ins[j] - '0';
    	}
    	// Input::main();

    	for (int i = 0; i < n; i ++)
    		for (int j = 0; j < m; j ++)
        		ss[i] += mp[i][j], sq[j] += mp[i][j];
    	for (int i = 0; i < n; i ++) {
            ld mn = oo; int id = 0;
    		for (int j = 0; j < 600; j ++)
    			if (fabs(ss[i] - lists[j]) < mn)
    				mn = fabs(ss[i] - lists[j]), id = j;
    		preds[i] = id * 0.01 - 3;
    	}
    	init2();
    	for (int i = 0; i < m; i ++) {
            ld mn = oo; int id = 0;
    		for (int j = 0; j <= 600; j ++)
    			if (fabs(listq[j] - sq[i]) < mn)
    				mn = fabs(listq[j] - sq[i]), id = j;
    		predq[i] = id * 0.01 - 3;
    	}
        // report();

    	int likelihood = oo, id = -1;
    	for (int i = 0; i < n; i ++) {
    		ld notfake = 0, fake = 0, r = rev(ss[i]);
    		for (int j = 0; j < m; j ++) {
    			int v = mp[i][j] ^ 1;
    			notfake += log(fabs(v - f(preds[i], predq[j])));
    			fake += log(fabs(v - (f(r, predq[j]) * 0.5 + 0.5)));
    		}
    		if (notfake - fake < likelihood && ss[i] >= m * 0.5)
    			likelihood = notfake - fake, id = i;
    	}

    	// sum +=  Input::correct(id);
        cout << "Case #" << t << ": " << id + 1 << endl;
    }
    // cout << "accuracy: " << (ld)sum/T << endl;
    return 0;
}
/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* g++ -fsanitize=address -ftrapv -O2 input.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

namespace InputOutput {
	//BASE-0
	int D, I, S, V, F; //duration, #intersections, #streets, #cars, #bonus points
	map <string, int> streetName; //streetName->streetIndex

	struct Street {
		string name;
		int st, ed, L;
		int weight; // cars passing through
		Street () {}
		Street (string _n, int _s, int _e, int _L) {
			name = _n, st = _s, ed = _e, L = _L; weight = 0;
		}
	}; vector <Street> streets; //store all streets
	struct Intersect {
		vector <int> inStreet;
		vector <int> outStreet;
		void addIn (int streetId) {
			inStreet.push_back(streetId);
		}
		void addOut (int streetId) {
			outStreet.push_back(streetId);
		}
		vector <pii> strategy; // (inStreetID, time)
		void simplestStretegy() {
			//assign each input edge one second of green
			for (int i = 0; i < inStreet.size(); i ++)
				if (streets[inStreet[i]].weight)
					strategy.push_back(MP(inStreet[i], streets[inStreet[i]].weight));
		}
		void output() {
			cout << strategy.size() << endl;
			for (int i = 0; i < strategy.size(); i ++)
				cout << streets[strategy[i].first].name << " " << strategy[i].second << endl;
		}
	}; vector <Intersect> intersect;
	struct Cars {
		int length; // length of paths
		int initTime; //shortest time needed
		vector <int> path;
		vector <int> nodes; //the nodes the car go through. Not including the first node.
		void input () {
			initTime = 0;
			cin >> length;
			string s;
			for (int i = 0; i < length; i ++) {
				cin >> s;
				path.push_back(streetName[s]);
				nodes.push_back(streets[streetName[s]].ed);
				if (i != 0) {
					initTime += streets[streetName[s]].L;
					initTime += intersect[streets[streetName[s]].ed].inStreet.size() / 4;
				}
			}
			// cerr << "examine init time: " << initTime << endl;
			if (initTime <= D) {
				for (int i = 0; i < length; i ++)
					streets[path[i]].weight ++;
			}
		}
		void output() {
			cout << "Car info: initTime = " << initTime << ", length = " << length << endl;
		}
	}; vector <Cars> cars;
	void input () { //the function should be called
		cin >> D >> I >> S >> V >> F;
		intersect.resize(I);
		streets.resize(S);
		cars.resize(V);

		for (int i = 0; i < S; i ++) {
			string name;
			int st, ed, L;
			cin >> st >> ed >> name >> L;
			streetName[name] = i;
			streets[i] = Street(name, st, ed, L);
			intersect[st].addOut(i);
			intersect[ed].addIn(i);
		}
		for (int i = 0; i < V; i ++) {
			cars[i].input();
			// cars[i].output();
		}
	}
	void simplestStretegy() {
		for (int i = 0; i < I; i ++)
			intersect[i].simplestStretegy();
	}
	void output() {
		int outputcnt = 0;
		for (int i = 0; i < I; i ++)
			outputcnt += (intersect[i].strategy.size() != 0);
		cout << outputcnt << endl;
		for (int i = 0; i < I; i ++) {
			if (intersect[i].strategy.size()) {
				cout << i << endl;
				intersect[i].output();
			}
		}

	}
} using namespace InputOutput;

// namespace serban {
//     struct TrafficLight {
//         int street_id, time;
//     };
//     using Schedule = vector<TrafficLight>;
//     using Solution = vector<Schedule>;
// }

int main() {
	srand(time(NULL));
    ios::sync_with_stdio(false);

    InputOutput::input();
    // cerr << "finish reading " << TIME << endl; 
    InputOutput::simplestStretegy();

    InputOutput::output();



    return 0;
}
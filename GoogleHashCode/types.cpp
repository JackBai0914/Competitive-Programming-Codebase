	int D, I, S, V, F; //duration, #intersections, #streets, #cars, #bonus points
	map <string, int> streetName; //streetName->streetIndex
	struct Intersect {
		vector <int> inStreet;
		vector <int> outStreet;
		void addIn (int streetId) {
			inStreet.push_back(streetId);
		}
		void addOut (int streetId) {
			outStreet.push_back(streetId);
		}
	}; vector <Intersect> intersect;
	struct Street {
		string name;
		int st, ed, L;
		Street () {}
		Street (string _n, int _s, int _e, int _L) {
			name = _n, st = _s, ed = _e, L = _L;

		}
	}; vector <Street> street; //store all streets
	struct Cars {
		int length; // length of paths
		int initTime; //shortest time needed
		vector <int> path;
		vector <int> nodes; //the nodes the car go through. Not including the first node.
		void input () {
			cin >> length;
			string s;
			for (int i = 0; i < length; i ++) {
				cin >> s;
				path.push_back(streetName[s]);
				nodes.push_back(street[streetName[s]].ed);
			}
		}
	}; vector <Cars> cars;
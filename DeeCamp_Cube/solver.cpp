#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

//3-D Coordinate
struct Co {
	int x, y, z;
	Co () {}
	Co (int a, int b, int c) {x = a, y = b, z=c;}
};

//The structure of Cube and Piece
struct Cube {
	int a[3][3][3];
	void clear() {memset(a, 0, sizeof a);}
	Cube () 									{clear();}
	Cube (int c, Co a1, Co a2, Co a3) 			{clear();a[a1.x][a1.y][a1.z]=a[a2.x][a2.y][a2.z]=a[a3.x][a3.y][a3.z]=c;}
	Cube (int c, Co a1, Co a2, Co a3, Co a4)	{clear();a[a1.x][a1.y][a1.z]=a[a2.x][a2.y][a2.z]=a[a3.x][a3.y][a3.z]=a[a4.x][a4.y][a4.z]=c;}
	void output() {
		for (int i = 0; i < 19; i ++)
			cout << '-';
		cout << endl;
		for (int y = 0; y < 3; y ++) {
			cout << '|';
			for (int z = 0; z < 3; z ++) {
				for (int x = 0; x < 3; x ++) {
					cout << a[x][y][z];
					if (x != 2)	cout << ' ';
				}
				cout << '|';
			}
			cout << endl;
		}
		for (int i = 0; i < 19; i ++)
			cout << '-';
		cout << endl;
	}
	bool add (Cube new_piece) {
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++)
					if (a[x][y][z] && new_piece.a[x][y][z])
						return false;
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++)
					a[x][y][z] |= new_piece.a[x][y][z];
		return true;
	}
	void sub (Cube added_piece) {
		// only used when the piece has been added
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++)
					a[x][y][z] -= added_piece.a[x][y][z];
	}
	Cube flip (int x_c, int y_c, int z_c) {
		Cube ret;
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++) {
					ret.a[x][y][z] = a[x+x_c*(1-x)][y+y_c*(1-y)][z+z_c*(1-z)];
					//x_c=0:x  x_c=1:2-x 
				}
		return ret;
	}
	Cube switch_axis (int x_id, int y_id, int z_id) {
		Cube ret;
		int i[3];
		for (i[0] = 0; i[0] < 3; i[0] ++)
			for (i[1] = 0; i[1] < 3; i[1] ++)
				for (i[2] = 0; i[2] < 3; i[2] ++)
					ret.a[i[x_id]][i[y_id]][i[z_id]] = a[i[0]][i[1]][i[2]];
		return ret;
	}
	vector <Cube> all_Cubes () {
		//Find all Cubes that can be obtained by rotation.
		vector <Cube> ret;
		int rt[3] = {0, 1, 2};
		do {
			Cube base = switch_axis (rt[0], rt[1], rt[2]);
			int swap_num = (rt[0] > rt[1]) + (rt[0] > rt[2]) + (rt[1] > rt[2]);
			for (int x = 0; x <= 1; x ++)
				for (int y = 0; y <= 1; y ++)
					for (int z = 0; z <= 1; z ++)
						//***very important to keep X 'product' Y = Z, so the rotation is achievable.
						if ((x + y + z + swap_num) % 2 == 0)
							ret.push_back(base.flip(x*2, y*2, z*2));
		} while (next_permutation(rt, rt + 3));
		return ret;
	}
	Cube simplify () {
		// only apply on pieces, moveing them to the conner,
		Cube ret;
		int mn_x = 3, mn_y = 3, mn_z = 3;
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++)
					if (a[x][y][z])
						mn_x = min(mn_x, x), mn_y = min(mn_y, y), mn_z = min(mn_z, z);
		for (int x = 0; x + mn_x < 3; x ++)
			for (int y = 0; y + mn_y < 3; y ++)
				for (int z = 0; z + mn_z < 3; z ++)
					ret.a[x][y][z] = a[x+mn_x][y+mn_y][z+mn_z];
		return ret;
	}
	bool equal (Cube b) {
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++)
					if (a[x][y][z] != b.a[x][y][z])
						return false;
		return true;
	}
	bool by_all_means_equal (Cube base) {
		//a 'by_all_means_equal' b ==> Cube a can become b by rotation
		vector <Cube> all = all_Cubes();
		for (int i = 0; i < all.size(); i ++)
			if (all[i].simplify().equal(base.simplify()))
				return true;
		return false;
	}
};
typedef vector <Cube> Cubes;

//this structure stores all possible positions of certain piece.
struct Pieces {
	int color;
	Cubes shape, cand;
	Pieces () {}
	void dfs (Cube cube, int num) {
		if (!num) {
			cand.push_back(cube);
			return ;
		}
		for (int x = 0; x < 3; x ++)
			for (int y = 0; y < 3; y ++)
				for (int z = 0; z < 3; z ++) {
					if (cube.a[x][y][z])
						return ;
					cube.a[x][y][z] = color;
					dfs (cube, num - 1);
					cube.a[x][y][z] = 0;
				}
	}
	Pieces (int c, int num, Cube init) {
		color = c;
		dfs (Cube(), num);
		for (int i = 0; i < cand.size(); i ++)
			if (cand[i].by_all_means_equal(init))
				shape.push_back(cand[i]);
	}
};

// seven kinds of pieces
Pieces Tri  =	Pieces(1, 3, Cube(1, Co(0,0,0), Co(0,1,0), Co(1,0,0)));
Pieces Hat  =	Pieces(2, 4, Cube(2, Co(0,0,0), Co(1,0,0), Co(1,1,0), Co(2,0,0)));
Pieces L    =	Pieces(3, 4, Cube(3, Co(0,0,0), Co(1,0,0), Co(0,1,0), Co(2,0,0)));
Pieces IZ   =	Pieces(4, 4, Cube(4, Co(0,0,0), Co(1,0,0), Co(1,1,0), Co(2,1,0)));
Pieces Cnr  =	Pieces(5, 4, Cube(5, Co(0,0,0), Co(1,0,0), Co(0,1,0), Co(0,0,1)));
Pieces TriL = 	Pieces(6, 4, Cube(6, Co(0,0,0), Co(1,0,0), Co(0,1,0), Co(0,1,1)));
Pieces TriR = 	Pieces(7, 4, Cube(7, Co(0,0,0), Co(1,0,0), Co(0,1,0), Co(1,0,1)));
Cubes all_shapes[7] = {Cnr.shape, Hat.shape, IZ.shape, TriL.shape, TriR.shape, L.shape, Tri.shape};


Cubes final_ans;

int count_dfs = 0;
void dfs (Cube cube, int l) {
	// if ((++count_dfs) % 1000000 == 0)
		// cerr << "searching..." << count_dfs << endl;
	if (l == 7) {
		for (int i = 0; i < final_ans.size(); i ++)
			if (cube.by_all_means_equal(final_ans[i]))
				return ;
		final_ans.push_back(cube);
		return ;
	}
	for (int i = 0; i < all_shapes[l].size(); i ++) {
		if (!l)
			cerr << "searching first layer: " << i << " ..." << TIME << endl;
		if (cube.add(all_shapes[l][i])) {
			dfs (cube, l + 1);
			cube.sub(all_shapes[l][i]);
		}
	}
}

int main() {
	dfs (Cube(), 0);
	cerr << "search finished" << endl;
	cout << "answer size: " << final_ans.size() << endl;
	for (int i = 0; i < final_ans.size(); i ++) {
		cout << "solution #" << i << endl;
		final_ans[i].output();
	}
	return 0;
}

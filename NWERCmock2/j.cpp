#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define LSOne(S) (S & (-S))
#define dbg(x) if (debug){ x }
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define brep(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define umap unordered_map
#define uset unordered_set
#define umset unordered_multiset
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<t3i> v3i;
typedef vector<bool> vb;
typedef vector<pii> vpi;
#define debug false

int N; string S;
vi board;

int transition[5][5][5];
void populate_transition(){
    rep(a, 0, 5){
    rep(b, 0, 5){
    rep(c, 0, 5){
        int a_add = a>=2;
        int c_add = c>=2;
        int me = a_add+b+c_add; if(b>1){me-=2;}
        transition[a][b][c] = me;
    }
    }
    }
}
bool do_iteration(){
    vi new_board(N); copy(all(board), new_board.begin());
    bool has_2 = false;
    new_board[0] = transition[0][board[0]][board[1]];
    new_board[N-1] = transition[board[N-2]][board[N-1]][0];
    has_2 |= new_board[0]>1;
    has_2 |= new_board[N-1]>1;
    rep(i, 1, N-1){
        int left = board[i-1]; int right = board[i+1];
        int mid = board[i];
        new_board[i] = transition[left][mid][right];
        has_2 |= new_board[i] > 1;
    }
    board = new_board;
    return has_2;
}
void board_out(){
    trav(x, board) cout << x; cout << endl;
}

int main() {
    populate_transition();
    cin >> S; N = S.size();
    bool has_2 = false;
    trav(s, S){
        board.push_back(s-'0');
        if(s-'0'==2){
            has_2 = true;
        }
    }
    if (N == 1){

        switch (board[0]){
            case 0: cout << 0 << endl; return 0;
            case 1: cout << 1 << endl; return 0;
            case 2: cout << 0 << endl; return 0;
        }
    }

    while(has_2) {
        has_2 = do_iteration();
        board_out();
    }

    cout << " ---------- new algo -------------- " << endl;
    deque<int> zero_behind;
    deque<int> zero_forward;
    deque<int> two_inxs;
    vi jugglers;
    rep(i, 0, N){
        char s = S[i];
        int val = s-'0';
        board.push_back(val);
        if (val==0){zero_forward.push_back(i);}
        if (val==2){two_inxs.push_back(i);}
    }
    rep(i, 0, N){zero_forward.push_back(N);}
    rep(i, 0, N){zero_behind.push_back(-1);}

    trav(two_inx, two_inxs){
        cerr << "enter: " << two_inx << " " << zero_behind.front() << " " << zero_forward.front() << endl;
        while(zero_forward.front() < two_inx){
            zero_behind.push_front(zero_forward.front());
            zero_forward.pop_front();
        }
        if (zero_forward.front() == two_inx){
            zero_forward.pop_front();
            continue;
        }
        zero_forward.pop_front();
        zero_behind.pop_front();
        int reflection = zero_behind.front()+zero_forward.front()-two_inx;
        cerr << "ref: " << reflection << " " << zero_behind.front() << " " << zero_forward.front() << " " << two_inx << endl;
        if (reflection <= two_inx){
            zero_behind.push_front(reflection);
        } else {
            zero_forward.push_front(reflection);
        }
    }

    vi result(N); fill(all(result), 1);
    while(zero_behind.front()>=0){
        result[zero_behind.front()] = 0; zero_behind.pop_front();
    }
    while(zero_forward.front()<N){
        result[zero_forward.front()] = 0; zero_forward.pop_front();
    }

    string outjuggler;
    outjuggler.reserve(N);
    rep(i, 0, N){int res = result[i]; outjuggler += '0'+res;}
    cout << outjuggler << endl;
    return 1;
}

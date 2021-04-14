#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long double ld;

string q;
string inf = "fjdgfffehfeeejeeihhfefgdkhhifgehifjhhhfggihiheihjhkjekihkfiighekffhgjchfighefhifjhhiggjhggicgjhffhifgidgheefgffhiijffcighfgiihggijhffhgihghefgchhfgghgdghegjhiidhjfiggfjghghjjgghifefhjgfhihkgeehejffggghdihihhgehgefhhhejkhffgdfcegfgjghdkghfghhffgfhfhgggjhghjgigjghfhhghfhdghegjihgihkgjfcgdgifgiggkeljfdjhgdehihgfghgeihgjhkkggigiggchghfidjhefgijjghhiihijgifgeeijhicihjfeghfigfeihiilhgheeibfehiiljggjifgigmgfhggehhkigffifhfhjhidghijifhhlghggighhiggjjfeeiifghhhhighjghgghjhhjgjhieighghhhehlihgjhhehghhjdhfjhehiigkildhdfeffhjehfhjgggieielhjheiefjjfgjhghfhigkeghhgigdhgheffjfgjhiekiikjgieggihhbffhhfcjhgfghgghfijhefhhihheiefhfjeffhggghhfgdehehikihgdghdejhjhhihggghhkijdiffghhjeghhfgigjfghgfehifgliifjhigggjifgghfehfefffdiifhfhiihkjgelfhhgghfidfhfghchggjjkggdigejfefjfgefifgligghihfhjcfggcdlgghiffigdjfihhjehhheieihhhgijhfehcifjggfhgjfhffhgggfjfhehdihddic";
string inf2 = "/5IN0J,0N,>KF<A,ORGA-2-))=:)0*E3M(K-8W082)(EJ/*FA:G=CD5-6)4<+XBU7)(?65I,RCN8PQ)/TR3(GWL;G5+<LFKX0.O(C6KVIFD>M.G46RAXS)/9,A6L6<VM-;-YAFPLG>@KJL/C8L9ISV?G(TGU?OHO@4SC@1IAX)2/SPT<9>6;E<8=;95G>Q,W.;2*510<.STJ.?DU>@Y>W55HDV@R,:C?K03(JNK31BK*4.PXD==J<Q8:6-YACY8R?9J(CT?N<C:@R:AJ66OR=5IRYF>>C?639161RU/N-JFM307M.S)NJCW<@9G.20.B:@)GL.J+ONM=MJP<A@AJ,F9TCWD42Y.N/D*AGYY,J(MX><77<@@J-;1R<<@L6>@X2JUK1GMQ+=/2JF>VW4K0:W0TJ9HACIA@6/S<7QN<E,P;9BLT3:-?<A*NLEQ5;J(/-/C0(*G+7I>CP</-95JXRH@C?J?R/77JJ)HLHD3?=(T61IWJ>MA*8*FO4IJQTV4J7.<X-9@7W,+U25LJ8HM=5C,-Q1GV,PB>N<MUVFMAP-=ENT>-/VY,/:5IGM)J7HM7<;=(NA>W2,,+-R*O-G)T5)H++:,>5;?.6(?4.BNB8)MJ2-(9YU7U+NT/-(A/.(,P5D*I+W,LLW/7.@SQ<RKRMV,UF@HH/5IF)?:KV8D5SLM@PCD56JCJB9U7X8G92*EH(3W1V0/VDO0.4T*6AU;?5MYV-44/5T-QNO=U00F-D=CU3GK-;B.OF3X??C6.3R1.-=+?-A4QXKUUH?8R>.=LXCO?=)6-4GWVW>N.W+9XHKERGMQRYK-O*WH10E1E/6V32T.D08P@14(HB3J";
int prob[14][14] = 
{
{130,120,110,100,90,80,70,60,50,40,30,20,10,0},
{120,111,103,94,86,77,69,60,52,43,35,26,18,10},
{110,103,96,89,82,75,68,61,54,47,40,33,26,20},
{100,94,89,83,78,73,67,62,56,51,46,40,35,30},
{90,86,82,78,74,70,66,63,59,55,51,47,43,40},
{80,77,75,73,70,68,66,63,61,59,56,54,52,50},
{70,69,68,67,66,66,65,64,63,63,62,61,60,60},
{60,60,61,62,63,63,64,65,66,66,67,68,69,70},
{50,52,54,56,59,61,63,66,68,70,73,75,77,80},
{40,43,47,51,55,59,63,66,70,74,78,82,86,90},
{30,35,40,46,51,56,62,67,73,78,83,89,94,100},
{20,26,33,40,47,54,61,68,75,82,89,96,103,110},
{10,18,26,35,43,52,60,69,77,86,94,103,111,12},
{0,10,20,30,40,50,60,70,80,90,100,110,120,130},
};



int main() {
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	freopen("3.out", "w", stdout);
	cin >> q;
	q=q.substr(0, 11000);
	ld fans = 0;
	int pt = 0;
	for (int sum, rd, i = 0; i < q.size(); i += 13, pt ++) {
		sum = 0;
		rd = 0; 
		for (int j = 0; j < 13 && i + j < q.size(); j ++) {
			sum += (q[i+j] == '1');
			rd = (rd * 233 + (p[i+j] == '1')) % 10007;
		}
		if (rd )
		fans += 130 - prob[inf[pt]][sum];
	}
	cout << fans / 10 << endl;
	return 0;
}
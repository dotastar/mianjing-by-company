#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
 
 

	struct Enemy{
	int strength;
	int count;
	};

	bool myfunction (const Enemy& lhs,const Enemy& rhs) { return (lhs.strength<rhs.strength); }

class SpaceWarDiv2
{

public:
    int minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector <int> enemyCount) 
    {
		int girl_num = magicalGirlStrength.size();
		int enemy_num = enemyStrength.size();
		vector<Enemy> e(enemy_num);
		sort(magicalGirlStrength.begin(), magicalGirlStrength.end());
		for(int i = 0; i < enemy_num; ++i) {
			e[i].strength = enemyStrength[i];
			e[i].count = enemyCount[i];
		}
		sort(e.begin(), e.end(), myfunction);
		
		int max_girl = magicalGirlStrength.back();
		int max_enemy = e.back().strength;
		if(max_girl < max_enemy) return -1;

		/*for(int i = 0; i < enemy_num; ++i){
			cout<<e[i].strength<<"-->"<<e[i].count<<endl;
		}
		*/
		vector<int> fatigue(girl_num, 0);
		int remain_enemy = enemy_num;
		while(1){
			if(remain_enemy <= 0) break;
			for(int i = 0; i < girl_num; ++i){
				int  j= enemy_num-1;
				for(; j >= 0; --j) {
					if(e[j].strength <= magicalGirlStrength[i] && e[j].count > 0) break;
				}
				if(j >= 0) {
					e[j].count--;
					if(e[j].count == 0) remain_enemy--;
					fatigue[i]++;
				}
			}
		}

		//for(int i = 0; i < girl_num; ++i){
		//	cout<<magicalGirlStrength[i]<<"->"<<fatigue[i]<<endl;
		//}
        return *max_element(fatigue.begin(), fatigue.end());
    }
    

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

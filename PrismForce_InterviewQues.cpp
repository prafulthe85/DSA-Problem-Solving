#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Coding Problem for Prism Force

// Time Complexity: O(n), Space Complexity:O(1)
// In the solution we traversed for the 11 circles and then updated the power of abhimanyu after every batter
// but while Battles we have also handles the case for the regenerated power for k3 and k7 circles
// and also in case of the recharge of abhimanyu when the power of abhimanyu is less than the opponent before the battle then he will get recharged
// and we have skipped the battles for first circles while crossing

// Also the test cases are provided at the end of this file to test

bool chakravyuh(vector<int>& enemy_power, int skips, int recharge, int ab_power){
    int cur_power = ab_power;
    bool regen_k3 = false;
    bool regen_k7 = false;

    for (int i = 0; i<enemy_power.size(); i++) {
        cout << " Round: " << i << " Enemy power " << enemy_power[i] <<" Abhimanyu Power: "<<cur_power<< endl;
        if(i ==2 ){
            regen_k3 = true;
        }
        if(i==6){
            regen_k7 = true;
        }
        if(skips>0){
            cout << "Abhimanyu skips circle " << i + 1 << " with Enemy power " << enemy_power[i] << endl;
            skips--;
            continue;
        }

        if(cur_power>=enemy_power[i]){
            cur_power -= enemy_power[i];
            cout << "Abhimanyu wins in circle " << i + 1 << " remaining power : " << cur_power<<endl;
        }else{
            // in case of less power recharge abhimanyu
            if(recharge>0){
                cur_power = ab_power;
                recharge--;
                cout << "Abhimanyu recharges before the circle " << i + 1 << endl;
                if(cur_power>=enemy_power[i]){
                    cur_power -= enemy_power[i];
                    cout << "Abhimanyu wins in circle " << i + 1 << " remaining power : " << cur_power<<endl;
                }else{
                    cout << "Abhimanyu loses in circle " << i + 1 << " with enemy power : " << enemy_power[i] << endl;
                    return false;
                }
            }else{
                cout << "Abhimanyu loses in circle " << i + 1 << " with enemy power : " << enemy_power[i] << endl;
                return false;
            }
        }
        
        
        // Regen for k3 and k7 enemies
        if ((i==2 and regen_k3)  or  (i==6 and regen_k7)){
            int regen_power = enemy_power[i]/2;
            if (cur_power >= regen_power ){
                cur_power -= regen_power;
                regen_k3 = false;
                regen_k7 = false;
                cout << "Abhimanyu wins in circle " << i + 1 << " when regen happens, remaining power : " << cur_power<<endl;
            }else{
                // In case the current power is less but have recharge 
                if(recharge>0){
                    cur_power = ab_power;
                    recharge--;
                    cur_power -= enemy_power[i];
                    cout << "Abhimanyu wins in circle " << i + 1 << " when regen happens, remaining power : " << cur_power<<endl;
                }
                
                cout << "Abhimanyu loses in circle " << i + 1 << " when regen happens, with enemy power : " << enemy_power[i] << endl;
                return false;
            }
        }

    }
    return true;
}

int main(){

    vector<int> enemy_power(11);

    cout << "Enter enemy power: " << endl;
    for(int i = 0; i < enemy_power.size();i++){
        cin>>enemy_power[i];
    }

    int ab_power;
    int skips, recharge;
    cout<<"Enter Abhimanyu Power, Skips, Recharge"<< endl;
    cin>>ab_power>>skips>>recharge;

    skips = min(11, skips);
    recharge = min(11,recharge);

    bool result1 = chakravyuh(enemy_power, skips, recharge, ab_power);

    if (result1) {
        cout << "Abhimanyu successfully crossed all circles!" << endl;
    } else {
        cout << "Abhimanyu failed to cross the Chakravyuh." << endl;
    }

    return 0;
}

// Test Case 1:
// Enter enemy power: 12 13 14 17 13 21 21 32 23 8 9 
// Enter Abhimanyu Power, skips, recharge= 100 1 1

//  Round: 0 Enemy power 12 Abhimanyu Power: 100
// Abhimanyu skips circle 1 with Enemy power 12
//  Round: 1 Enemy power 13 Abhimanyu Power: 100
// Abhimanyu wins in circle 2 remaining power : 87
//  Round: 2 Enemy power 14 Abhimanyu Power: 87
// Abhimanyu wins in circle 3 remaining power : 73
// Abhimanyu wins in circle 3 when regen happens, remaining power : 66
//  Round: 3 Enemy power 17 Abhimanyu Power: 66
// Abhimanyu wins in circle 4 remaining power : 49
//  Round: 4 Enemy power 13 Abhimanyu Power: 49
// Abhimanyu wins in circle 5 remaining power : 36
//  Round: 5 Enemy power 21 Abhimanyu Power: 36
// Abhimanyu wins in circle 6 remaining power : 15
//  Round: 6 Enemy power 21 Abhimanyu Power: 15
// Abhimanyu recharges before the circle 7 
// Abhimanyu wins in circle 7 remaining power : 79
// Abhimanyu wins in circle 7 when regen happens, remaining power : 69
//  Round: 7 Enemy power 32 Abhimanyu Power: 69
// Abhimanyu wins in circle 8 remaining power : 37
//  Round: 8 Enemy power 23 Abhimanyu Power: 37
// Abhimanyu wins in circle 9 remaining power : 14
//  Round: 9 Enemy power 8 Abhimanyu Power: 14
//  Round: 8 Enemy power 23 Abhimanyu Power: 37
// Abhimanyu wins in circle 9 remaining power : 14
//  Round: 9 Enemy power 8 Abhimanyu Power: 14
// Abhimanyu wins in circle 10 remaining power : 6
//  Round: 10 Enemy power 9 Abhimanyu Power: 6
// Abhimanyu loses in circle 11 with enemy power : 9
// Abhimanyu failed to cross the Chakravyuh.

// Test Case 2:
// Enter enemy power: 12 13 11 12 10 9 08 07 4 34 12  
// Enter Abhimanyu Power, skips, recharge = 100 2 2
// Round: 0 Enemy power 12 Abhimanyu Power: 100
// Abhimanyu skips circle 1 with Enemy power 12
//  Round: 1 Enemy power 13 Abhimanyu Power: 100
// Abhimanyu skips circle 2 with Enemy power 13
//  Round: 2 Enemy power 11 Abhimanyu Power: 100
// Abhimanyu wins in circle 3 remaining power : 89
// Abhimanyu wins in circle 3 when regen happens, remaining power : 84
//  Round: 3 Enemy power 12 Abhimanyu Power: 84
// Abhimanyu wins in circle 4 remaining power : 72
//  Round: 4 Enemy power 10 Abhimanyu Power: 72
// Abhimanyu wins in circle 5 remaining power : 62
//  Round: 5 Enemy power 9 Abhimanyu Power: 62
// Abhimanyu wins in circle 6 remaining power : 53
//  Round: 6 Enemy power 8 Abhimanyu Power: 53
// Abhimanyu wins in circle 7 remaining power : 45
// Abhimanyu wins in circle 7 when regen happens, remaining power : 41
//  Round: 7 Enemy power 7 Abhimanyu Power: 41
// Abhimanyu wins in circle 8 remaining power : 34
//  Round: 8 Enemy power 4 Abhimanyu Power: 34
// Abhimanyu wins in circle 9 remaining power : 30
//  Round: 9 Enemy power 34 Abhimanyu Power: 30
// Abhimanyu recharges before the circle 10
// Abhimanyu wins in circle 10 remaining power : 66
//  Round: 10 Enemy power 12 Abhimanyu Power: 66
// Abhimanyu wins in circle 11 remaining power : 54
// Abhimanyu successfully crossed all circles!

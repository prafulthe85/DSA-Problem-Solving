#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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

# PrismForce Coding Test ⚔️

## Coding Problem for Prism Force

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### Explanation

- The solution traverses 11 circles and updates the power of Abhimanyu after each battle.
- It handles the case for regenerated power for the k3 and k7 circles.
- In case Abhimanyu's power is less than the opponent's before the battle, he will recharge his power.
- It allows for skipping battles for the initial circles.

### Test Cases

#### Test Case 1:

- **Input**:

  - Enter enemy power: `12 13 14 17 13 21 21 32 23 8 9`
  - Enter Abhimanyu Power, skips, recharge: `100 1 1`

- **Output**:
  ```
  Round: 0 Enemy power 12 Abhimanyu Power: 100
  Abhimanyu skips circle 1 with Enemy power 12
  Round: 1 Enemy power 13 Abhimanyu Power: 100
  Abhimanyu wins in circle 2 remaining power : 87
  Round: 2 Enemy power 14 Abhimanyu Power: 87
  Abhimanyu wins in circle 3 remaining power : 73
  Abhimanyu wins in circle 3 when regen happens, remaining power : 66
  Round: 3 Enemy power 17 Abhimanyu Power: 66
  Abhimanyu wins in circle 4 remaining power : 49
  Round: 4 Enemy power 13 Abhimanyu Power: 49
  Abhimanyu wins in circle 5 remaining power : 36
  Round: 5 Enemy power 21 Abhimanyu Power: 36
  Abhimanyu wins in circle 6 remaining power : 15
  Round: 6 Enemy power 21 Abhimanyu Power: 15
  Abhimanyu recharges before the circle 7
  Abhimanyu wins in circle 7 remaining power : 79
  Abhimanyu wins in circle 7 when regen happens, remaining power : 69
  Round: 7 Enemy power 32 Abhimanyu Power: 69
  Abhimanyu wins in circle 8 remaining power : 37
  Round: 8 Enemy power 23 Abhimanyu Power: 37
  Abhimanyu wins in circle 9 remaining power : 14
  Round: 9 Enemy power 8 Abhimanyu Power: 14
  Abhimanyu wins in circle 10 remaining power : 6
  Round: 10 Enemy power 9 Abhimanyu Power: 6
  Abhimanyu loses in circle 11 with enemy power : 9
  Abhimanyu failed to cross the Chakravyuh.
  ```

#### Test Case 2:

- **Input**:

  - Enter enemy power: `12 13 11 12 10 9 08 07 4 34 12`
  - Enter Abhimanyu Power, skips, recharge: `100 2 2`

- **Output**:
  ```
  Round: 0 Enemy power 12 Abhimanyu Power: 100
  Abhimanyu skips circle 1 with Enemy power 12
  Round: 1 Enemy power 13 Abhimanyu Power: 100
  Abhimanyu skips circle 2 with Enemy power 13
  Round: 2 Enemy power 11 Abhimanyu Power: 100
  Abhimanyu wins in circle 3 remaining power : 89
  Abhimanyu wins in circle 3 when regen happens, remaining power : 84
  Round: 3 Enemy power 12 Abhimanyu Power: 84
  Abhimanyu wins in circle 4 remaining power : 72
  Round: 4 Enemy power 10 Abhimanyu Power: 72
  Abhimanyu wins in circle 5 remaining power : 62
  Round: 5 Enemy power 9 Abhimanyu Power: 62
  Abhimanyu wins in circle 6 remaining power : 53
  Round: 6 Enemy power 8 Abhimanyu Power: 53
  Abhimanyu wins in circle 7 remaining power : 45
  Abhimanyu wins in circle 7 when regen happens, remaining power : 41
  Round: 7 Enemy power 7 Abhimanyu Power: 41
  Abhimanyu wins in circle 8 remaining power : 34
  Round: 8 Enemy power 4 Abhimanyu Power: 34
  Abhimanyu wins in circle 9 remaining power : 30
  Round: 9 Enemy power 34 Abhimanyu Power: 30
  Abhimanyu recharges before the circle 10
  Abhimanyu wins in circle 10 remaining power : 66
  Round: 10 Enemy power 12 Abhimanyu Power: 66
  Abhimanyu wins in circle 11 remaining power : 54
  Abhimanyu successfully crossed all circles!
  ```

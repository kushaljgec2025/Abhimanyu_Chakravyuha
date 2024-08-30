## ASDE Algorithm Test

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies.
Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back. 
 
Given:
  Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers
Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy
a times 
 Abhmanyu can recharge himself with power b times 
 Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
 If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
  k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial
power and can attack Abhimanyu from behind if he is battling in iteratively next circle 
 
 
Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of test cases.


### Test Case 1 : 
enemyPower=[1 2 5 2 1 3 5 8 8 2 1] </br>
power=10 </br>
a=2 </br>
b=2 </br>

#### Input : 
1 2 5 2 1 3 5 8 8 2 1 </br>
10  2  2

#### Output : Abhimanyu can cross the Chakrvyuha

### Test Case 2 : 
enemyPower=[1 2 5 2 1 3 5 8 8 2 9] </br>
power=10 </br>
a=2 </br>
b=2 </br>

#### Input : 
1 2 5 2 1 3 5 8 8 2 9 </br>
10  2  2

#### Output : Abhimanyu cannot cross the Chakrvyuha


### Time Complexity :
If TOTAL_ENIMIES = 11 Then Time complexity will be O(11) it means <strong> Constant Time <strong/>
#### Time Complexity : O(1)
If TOTAL_ENIMIES = N Then 
#### Time Complexity : O(N^3)



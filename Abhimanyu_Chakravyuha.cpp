#include <bits/stdc++.h>

using namespace std;

const int max_enemies = 11; // Total number of enemies in the Chakravyuha
int power;                  // Initial power of Abhimanyu

// DP table to store the results of subproblems
// dp[enemy][cur_power][skips][recharge]
int dp[max_enemies][101][12][12];

// Function to check if Abhimanyu can cross the Chakravyuha using dynamic programming
bool canCrossChakrvyuha(vector<int> &enemyPower, int enemy, int cur_power, int behind, int skips, int recharge)
{
    // Base case: Abhimanyu successfully crossed the Chakravyuha
    if (enemy == max_enemies)
        return true;

    // Check if this subproblem has been solved already
    if (dp[enemy][cur_power][skips][recharge] != -1)
        return dp[enemy][cur_power][skips][recharge];

    bool flag = false;

    // Option 1: Recharge if available and current power is less than the initial power
    if (recharge > 0 && cur_power < power)
        flag |= canCrossChakrvyuha(enemyPower, enemy, power, behind, skips, recharge - 1);

    // If Abhimanyu can fight with the enemy attacking from behind
    if (cur_power >= behind)
    {
        cur_power -= behind;
        behind = 0;
    }
    else
    {
        return dp[enemy][cur_power][skips][recharge] = false;
    }

    // Option 2: Skip the current enemy if skips are available
    if (skips > 0)
        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power, behind, skips - 1, recharge);

    // Option 3: Fight with the current enemy without recharge or skip
    if (cur_power >= enemyPower[enemy])
    {
        if (enemy == 2 || enemy == 6)
            behind = enemyPower[enemy] / 2;

        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power - enemyPower[enemy], behind, skips, recharge);
    }

    // Store the result of the current subproblem
    return dp[enemy][cur_power][skips][recharge] = flag;
}

int main()
{
    vector<int> enemyPower(max_enemies); // Powers of each enemy from 1-11

    for (int i = 0; i < max_enemies; i++)
        cin >> enemyPower[i];

    int a, b; // a: Total number of skips Abhimanyu has, b: Number of times Abhimanyu can recharge himself
    cin >> power >> a >> b;
    a = min(a, max_enemies); // Restrict the maximum skips to the total number of enemies (11)
    b = min(b, max_enemies); // Restrict the maximum recharges to the total number of enemies (11)

    // Initialize the DP table with -1 (indicating unsolved subproblems)
    memset(dp, -1, sizeof(dp));

    int behind = 0; // Power of regenerated enemy to attack from behind

    if (canCrossChakrvyuha(enemyPower, 0, power, behind, a, b))
        cout << "Abhimanyu can cross the Chakrvyuha" << endl;
    else
        cout << "Abhimanyu cannot cross the Chakrvyuha" << endl;

    return 0;
}
/*
Test Case 1 : 
enemyPower=[1 2 5 2 1 3 5 8 8 2 1]
power=10
a=2
b=2

Input : 
1 2 5 2 1 3 5 8 8 2 1
10 2 2

Output : Abhimanyu can cross the Chakrvyuha

Test Case 2 : 
enemyPower=[1 2 5 2 1 3 5 8 8 2 9]
power=10
a=2
b=2

Input : 
1 2 5 2 1 3 5 8 8 2 9
10 2 2

Output : Abhimanyu cannot cross the Chakrvyuha
*/

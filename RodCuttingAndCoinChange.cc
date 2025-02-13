#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>

using namespace std;

// function prototypes
int rodCutting(vector<pair<int, int>>& prices, int length);
double coinChange(vector<int>& coins, int amount);
vector<vector<double>> coinChangeReconstructions(vector<int>& coins, int amount);

// main function
int main()
{
    //----------------------------------------------------------------------------------
    //                              Rod Cutting Problem
    //----------------------------------------------------------------------------------

    // creates the prices vector and the test lengths array
    vector<pair<int, int>> prices = {{1, 1}, {2, 5}, {4, 9}, {6, 17}, {8, 20}, {10, 30}, {12, 36}, {16, 48}};
    int test_lengths_length = 11;
    int test_lengths [test_lengths_length] = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

    // creates the table header
    cout << "------------------- Rod Cutting Problem -------------------" << endl;
    cout << setw(20) << left << "Length" << setw(20) << left << "Max Revenue ($)" << setw(20) << left << "Time Taken (sec)" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    // loops through the test lengths
    for(int i = 0; i < test_lengths_length; i++)
    {
        // prints the current test length in the table
        cout << setw(20) << left << test_lengths[i] << setw(20) << left;

        // times the rod cutting function
        int max_revenue = 0;
        auto start = chrono::high_resolution_clock::now();
        max_revenue = rodCutting(prices, test_lengths[i]);
        auto end = chrono::high_resolution_clock::now();

        // prints out the max revenue for the current test length
        cout << setw(20) << left << max_revenue << setw(20) << left;

        // prints out the time taken for the current call
        chrono::duration<double> elapsed = end - start;
        cout << fixed << setprecision(6) << elapsed.count();
        cout << setprecision(0) << endl;
    }
    cout << endl;
    
    //----------------------------------------------------------------------------------
    //                                Coin problem A
    //----------------------------------------------------------------------------------

    // creates the US coins vector and the test amounts array
    vector<int> coins_US = {1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000};
    int test_amounts_part1_length = 9;
    int test_amounts_part1 [9] = {10, 50, 100, 500, 1000, 1500, 2000, 3000, 5000};

    // creates the table header
    cout << "------------------- Coin Problem A -------------------" << endl;
    cout << setw(20) << left << "Amount" << setw(20) << left << "Number of Ways" << setw(20) << left << "Time Taken (sec)" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    // loops through the test amounts
    for(int i = 0; i < test_amounts_part1_length; i++)
    {
        // prints the current test amount to the table
        cout << setw(20) << left << test_amounts_part1[i] << setw(20) << left;

        // times the coin change function and find the ways to make the current test amount
        double ways = 0;
        auto start = chrono::high_resolution_clock::now();
        ways = coinChange(coins_US, test_amounts_part1[i]);
        auto end = chrono::high_resolution_clock::now();
        
        // prints the number of ways to make the current test amount
        cout << ways << setw(20) << left;
        
        // prints out the time taken for the current call
        chrono::duration<double> elapsed = end - start;
        cout << fixed << setprecision(6) << elapsed.count();
        cout << setprecision(0) << endl;
    }
    cout << endl;

    //----------------------------------------------------------------------------------
    //                                Coin problem B
    //----------------------------------------------------------------------------------

    // creates the WW coins vector
    vector<int> coins_WW = {1, 29, 493};
    
    // creates the table header
    cout << "------------------- Coin Problem B -------------------" << endl;
    cout << setw(20) << left << "Amount" << setw(20) << left << "Number of Ways" << setw(20) << left << "Time Taken (sec)" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    // loops through the test amounts
    for(int i = 0; i < test_amounts_part1_length; i++)
    {
        // prints the current test amount to the table
        cout << setw(20) << left << test_amounts_part1[i] << setw(20) << left;
        
        // times the coin change function and find the ways to make the current test amount
        double ways = 0;
        auto start = chrono::high_resolution_clock::now();
        ways = coinChange(coins_WW, test_amounts_part1[i]);
        auto end = chrono::high_resolution_clock::now();
        
        // prints the number of ways to make the current test amount
        cout << ways << setw(20) << left;
        
        // prints out the time taken for the current call
        chrono::duration<double> elapsed = end - start;
        cout << fixed << setprecision(6) << elapsed.count();
        cout << setprecision(0) << endl;
    }
    cout << endl;

    //----------------------------------------------------------------------------------
    //                          Coin problem A reconstruction
    //----------------------------------------------------------------------------------

    // creates the test amounts array
    int test_amounts_part2_length = 4;
    int test_amounts_part2 [test_amounts_part2_length] = {10, 25, 50, 100};

    // creates the divider for the output
    cout << "----------- Coin Problem A Reconstruction -----------" << endl;

    // loops through the test amounts
    for(int i = 0; i < test_amounts_part2_length; i++)
    {        
        // times the coin change reconstruction function and find the ways to make the current test amount
        vector<vector<double>> combinations;
        auto start = chrono::high_resolution_clock::now();
        combinations = coinChangeReconstructions(coins_US, test_amounts_part2[i]);
        auto end = chrono::high_resolution_clock::now();

        // prints the all the ways to make the current test amount
        cout << "Ways to make " << test_amounts_part2[i] << ": " << endl;
        for(size_t i = 0; i < combinations.size(); i++)
        {
            for(size_t j = 0; j < combinations[i].size(); j++)
            {
                cout << combinations.at(i).at(j) << " ";
            }
            cout << endl;
        }

        // prints out the time taken for the current call
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken for this call: " << fixed << setprecision(6) << elapsed.count() << " seconds";
        cout << endl;
        cout << endl;
        cout << setprecision(0);
    }
    
    //----------------------------------------------------------------------------------
    //                          Coin problem B reconstruction
    //----------------------------------------------------------------------------------

    // creates the divider for the output
    cout << "----------- Coin Problem B Reconstruction -----------" << endl;
    
    // loops through the test amounts
    for(int i = 0; i < test_amounts_part2_length; i++)
    {
        // times the coin change reconstruction function and find the ways to make the current test amount
        vector<vector<double>> combinations;
        auto start = chrono::high_resolution_clock::now();
        combinations = coinChangeReconstructions(coins_WW, test_amounts_part2[i]);
        auto end = chrono::high_resolution_clock::now();

        // prints the all the ways to make the current test amount
        cout << "Ways to make " << test_amounts_part2[i] << ": " << endl;
        for(size_t i = 0; i < combinations.size(); i++)
        {
            for(size_t j = 0; j < combinations[i].size(); j++)
            {
                cout << combinations.at(i).at(j) << " ";
            }
            cout << endl;
        }
        
        // prints out the time taken for the current call
        chrono::duration<double> elapsed = end - start;
        cout << "Time taken for this call: " << fixed << setprecision(6) << elapsed.count() << " seconds";
        cout << endl;
        cout << endl;
        cout << setprecision(0);
    }

    return 0;
}

// function to find the max revenue for a rod of a given length
int rodCutting(vector<pair<int, int>>& prices, int length) 
{
    // creates the revenue vector
    vector<int> revenue(length + 1, 0);

    // loops through the lengths inputted
    for (int i = 1; i <= length; i++) 
    {
        // loops through the prices vector
        for (int j = 0; j < prices.size(); j++) 
        {
            // checks if the current price is less than or equal to the current length
            if (prices.at(j).first <= i)
            {
                // sets the current revenue to the max of the current revenue and the current price plus the revenue at
                // the current length minus the current price
                revenue.at(i) = max(revenue.at(i), prices.at(j).second + revenue.at(i - prices.at(j).first));
            }
        }
    }

    // returns the max revenue for the given length
    return revenue.at(length);
}

// function to find the number of ways to make a given amount with a given set of coins
double coinChange(vector<int>& coins, int amount) 
{
    // creates the ways vector
    int number_of_coins = coins.size();
    vector<vector<double>> ways(number_of_coins+1, vector<double>(amount+1, 0));
    
    // sets the ways vector to 1
    for (int i = 0; i <= number_of_coins; i++) 
    {
        ways.at(i).at(0) = 1;
    }

    // sets the first row to 0
    for (int j = 1; j <= amount; j++) 
    {
        ways.at(0).at(j) = 0;
    }

    // loops through the coins and the amounts
    for (int i = 1; i <= number_of_coins; i++) 
    {
        for (int j = 1; j <= amount; j++) 
        {
            // checks if the current coin is greater than the current amount
            if (coins.at(i-1) > j) 
            {
                // sets the current way to the way above it
                ways.at(i).at(j) = ways.at(i-1).at(j);
            } 
            else 
            {
                // sets the current way to the way that was saved above it plus the way at the current
                // amount minus the current coin
                ways.at(i).at(j) = ways.at(i-1).at(j) + ways.at(i).at(j-coins.at(i-1));
            }
        }
    }
    
    // returns the number of ways to make the given amount
    return ways.at(number_of_coins).at(amount);
}

// function to find all the ways to make a given amount with a given set of coins
vector<vector<double>> coinChangeReconstructions(vector<int>& coins, int amount) 
{
    // creates the combinations vector
    int number_of_coins = coins.size();
    vector<vector<vector<double>>> combinations(amount + 1);

    // loops through the available coins
    for (int i = 0; i < number_of_coins; i++)
    {
        // loops through the amounts starting at the current coin
        for(int j = coins.at(i); j <= amount; j++)
        {
            // loops through the combinations at the current amount minus the current coin
            for(size_t k = 0; k < combinations.at(j - coins.at(i)).size(); k++)
            {
                // adds the current coin to the combinations at the current amount
                vector<double> temp = combinations.at(j - coins.at(i)).at(k);
                temp.push_back(coins.at(i));
                combinations.at(j).push_back(temp);
            }
            // checks if the current amount is equal to the current coin
            if(j == coins.at(i))
            {
                // adds the current coin to the combinations at the current amount
                vector<double> temp;
                temp.push_back(coins.at(i));
                combinations.at(j).push_back(temp);
            }
        }
    }
    
    // returns the combinations at the given amount
    return combinations.at(amount);
}
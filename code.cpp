// Online GBD format
// Calcuate splitting bills amongst frinds
// how much each owes, recieves

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void calculateExpenses(int friends, string names[], double expenses[]) 
{
    // calculate total expenses
    
    double total = 0.0;
    for (int i = 0; i < friends; ++i) 
    {
        total += expenses[i];
    }

    // calculate average expense and output
    
    double average = total / friends;
    cout << "Average: " << fixed << setprecision(2) << average << endl;

    // calculate balance for each friend and find how much they owe/need
    
    double balance[friends];
    for (int i = 0; i < friends; ++i) 
    {
        balance[i] = expenses[i] - average;
    }

    // settle debts using two pointers
    
    int i = 0, j = 0;
    while (i < friends && j < friends) 
    {
        // find next person who needs to pay debitor=neg
        
        while (i < friends && balance[i] >= 0) 
        {
            i++;
        }
        
        // find next person who should receive money creditor=pos
        
        while (j < friends && balance[j] <= 0)
        {
            j++;
        }
        
        // calculate based on given interval
        
        if (i < friends && j < friends) 
        {
            double transfer = min(-balance[i], balance[j]);

            // Ignore if needed
            
            if (transfer > 0.01) 
            {
                cout << names[i] << " " << names[j] << " " << transfer << endl;
            }

            // adjust
            
            balance[i] += transfer; // debtors balance increase
            balance[j] -= transfer; //credor balance decrease
        }
    }
}

int main() 
{
    int friends;
    
    //find number of friends
    
    cin >> friends;
    
    string names[friends];
    double expenses[friends];
    
    //store respective parts in array
    
    for (int i = 0; i < friends; ++i) 
    {
        cin >> names[i] >> expenses[i];
    }
    
    //plug in respective numbers/string in func
    
    calculateExpenses(friends, names, expenses);
    return 0;
}

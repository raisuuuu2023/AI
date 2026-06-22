#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int N = 8;
int POP_SIZE = 80;
int MAX_GEN = 5000;

// fitness = number of conflicts (0 = solution)
int calcFitness(const vector<int> &b)
{
    int conflicts = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(b[i] == b[j])
                conflicts++;

            if(abs(i - j) == abs(b[i] - b[j]))
                conflicts++;
        }
    }

    return conflicts;
}

// random board
vector<int> randomBoard()
{
    vector<int> b(N);

    for(int i = 0; i < N; i++)
        b[i] = rand() % N;

    return b;
}

// crossover (fixed midpoint for stability)
vector<int> crossover(const vector<int> &a, const vector<int> &b)
{
    vector<int> child(N);

    int mid = N / 2;

    for(int i = 0; i < N; i++)
    {
        if(i < mid)
            child[i] = a[i];
        else
            child[i] = b[i];
    }

    return child;
}

// mutation (stronger for diversity)
void mutate(vector<int> &b)
{
    int idx = rand() % N;
    b[idx] = rand() % N;
}

int main()
{
    srand(time(0));

    vector<vector<int>> population;

    // initial population
    for(int i = 0; i < POP_SIZE; i++)
        population.push_back(randomBoard());

    for(int gen = 0; gen < MAX_GEN; gen++)
    {
        // sort by fitness (best first)
        sort(population.begin(), population.end(),
        [](const vector<int> &a, const vector<int> &b)
        {
            return calcFitness(a) < calcFitness(b);
        });

        // solution found
        if(calcFitness(population[0]) == 0)
        {
            cout << "Solution found in generation " << gen << ":\n\n";

            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if(population[0][i] == j)
                        cout << "Q ";
                    else
                        cout << ". ";
                }
                cout << "\n";
            }

            return 0;
        }

        vector<vector<int>> newPop;

        // elitism (keep best)
        newPop.push_back(population[0]);

        // generate new population
        while(newPop.size() < POP_SIZE)
        {
            vector<int> p1 = population[rand() % (POP_SIZE / 2)];
            vector<int> p2 = population[rand() % (POP_SIZE / 2)];

            vector<int> child = crossover(p1, p2);

            // stronger mutation
            if(rand() % 100 < 40)
                mutate(child);

            newPop.push_back(child);
        }

        population = newPop;
    }

    cout << "No solution found within generations.\n";

    return 0;
}
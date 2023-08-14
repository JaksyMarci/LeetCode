#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>

// this is similar to a DFS implementation, just without needing access to the whole graph
struct State
{
    size_t p1;
    size_t p2;
    std::vector<size_t> coins;
    bool visited;
};

bool make_move(std::stack<State> &s)
{
    // true is push, false is pop / nothing
    State state = s.top();
    size_t p1 = state.p1;
    size_t p2 = state.p2;
    std::vector<size_t> coins = state.coins;
    bool visited = state.visited;
    while (true)
    {

        if (visited)
        { // check if the current state has been exhausted
            s.pop();
            if (s.top().p2 < coins.size() - 1)
            { // move pointers of next state if necessary
                s.top().p2++;
            }
            else if (s.top().p1 < coins.size() - 2)
            {
                s.top().p1++;
                s.top().p2 = p1 + 1;
            }
            else if (s.top().p1 == coins.size() - 2 && s.top().p2 == coins.size() - 1)
            {
                s.top().visited = true;
            }

            return false;
        }

        if (coins[p1] != 0 && coins[p2] != 0)
        { // push to stack

            s.top().p1 = p1;
            s.top().p2 = p2;

            State new_state = state;

            new_state.coins[p1]--;
            new_state.coins[p2]--;
            new_state.p1 = 0;
            new_state.p2 = 1;
            new_state.visited = false;
            s.push(new_state);
            return true;
        }
        else if (p2 < coins.size() - 1)
        { // move pointer/index
            p2++;
        }
        else if (p1 < coins.size() - 2)
        { // move pointer/index
            p1++;
            p2 = p1 + 1;
        }
        else if (p1 == coins.size() - 2 && p2 == coins.size() - 1)
        { // mark that every possible case has been tried in this state
            s.top().visited = true;

            return false;
        }
    }
}

int main()
{

    size_t amount_of_stacks;
    std::cin >> amount_of_stacks;
    std::vector<size_t> coins;

    for (size_t i = 0; i < amount_of_stacks; i++)
    {
        size_t stack_size;
        std::cin >> stack_size;
        coins.push_back(stack_size);
    }
    // perform preliminary checks
    if (std::accumulate(coins.begin(), coins.end(), 0) % 2 != 0)
    {
        std::cout << "no";
        return 0;
    }
    if (*std::max_element(coins.begin(), coins.end()) >
        std::accumulate(coins.begin(), coins.end(), 0) - *std::max_element(coins.begin(), coins.end()))
    {
        std::cout << "no";
        return 0;
    }
    if (coins.size() == 2 && coins[0] != coins[1])
    {
        std::cout << "no\n";
        return 0;
    }

    std::stack<State> s;

    State init = {0, 1, coins, false};
    s.push(init);

    while (true)
    {

        // check exit conditions
        if (s.size() == 1 && s.top().visited == true)
        {

            std::cout << "no\n";
            break;
        }
        if (std::accumulate(s.top().coins.begin(), s.top().coins.end(), 0) == 0)
        {
            std::cout << "yes\n";
            s.pop();
            while (!s.empty())
            {
                std::cout << s.top().p1 + 1 << " " << s.top().p2 + 1 << "\n";
                s.pop();
            }
            break;
        }

        make_move(s); // advance the algorithm
    }

    return 0;
}

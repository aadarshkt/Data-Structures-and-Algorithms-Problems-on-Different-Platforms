#include <bits/stdc++.h>
using namespace std;

// Size of the puzzle
const int N = 4;

// Structure to represent each state of the puzzle
struct PuzzleState {
    int board[N][N];
    int empty_row, empty_col;
    int g, h;

    PuzzleState() {
        g = h = 0;
        empty_row = empty_col = 0;
        memset(board, 0, sizeof(board));
    }
};

struct Compare {
    bool operator()(const pair<int, PuzzleState>& a, const pair<int, PuzzleState>& b) const {
        // Compare based on the sum of g and h values
        return (a.first + a.second.h) > (b.first + b.second.h);
    }
};

// Function to calculate the Manhattan distance heuristic
int manhattanDistance(PuzzleState& state) {
    int distance = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state.board[i][j] != 0) {
                int target_row = (state.board[i][j] - 1) / N;
                int target_col = (state.board[i][j] - 1) % N;
                distance += abs(i - target_row) + abs(j - target_col);
            }
        }
    }
    return distance;
}

// Function to check if a state is the goal state
bool isGoalState(PuzzleState& state) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state.board[i][j] != i * N + j + 1 && !(i == N - 1 && j == N - 1))
                return false;
        }
    }
    return true;
}

// Function to generate successor states
vector<PuzzleState> generateSuccessors(PuzzleState& state) {
    vector<PuzzleState> successors;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    for (int d = 0; d < 4; ++d) {
        int new_row = state.empty_row + dr[d];
        int new_col = state.empty_col + dc[d];
        if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N) {
            PuzzleState successor = state;
            swap(successor.board[state.empty_row][state.empty_col], successor.board[new_row][new_col]);
            successor.empty_row = new_row;
            successor.empty_col = new_col;
            successor.g = state.g + 1;
            successor.h = manhattanDistance(successor);
            successors.push_back(successor);
        }
    }
    return successors;
}

// Function to solve the puzzle using A* algorithm
void solvePuzzle(PuzzleState& initial) {
    priority_queue<pair<int, PuzzleState>, vector<pair<int, PuzzleState>>, Compare> pq;
    unordered_set<string> visited;

    pq.push({-initial.h, initial});
    visited.insert(string((char*)&initial, sizeof(initial)));

    while (!pq.empty()) {
        PuzzleState current = pq.top().second;
        pq.pop();

        if (isGoalState(current)) { 
            cout << "Solution Found!\n";
            cout << "Total moves: " << current.g << endl;
            return;
        }

        vector<PuzzleState> successors = generateSuccessors(current);
        for (const auto& successor : successors) {
            string successor_hash((char*)&successor, sizeof(successor));
            if (visited.find(successor_hash) == visited.end()) {
                pq.push({-(successor.g + successor.h), successor});
                visited.insert(successor_hash);
            }
        }
    }

    cout << "No solution found!\n";
}

int main() {
    PuzzleState initial;

    // Input the initial state of the puzzle
    cout << "Enter the initial state of the puzzle (0 for empty space):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> initial.board[i][j];
            if (initial.board[i][j] == 0) {
                initial.empty_row = i;
                initial.empty_col = j;
            }
        }
    }

    // Solve the puzzle
    solvePuzzle(initial);

    return 0;
}
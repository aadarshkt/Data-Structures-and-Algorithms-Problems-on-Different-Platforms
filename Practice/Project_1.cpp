// for N*N -1 puzzle algorithm A* algorithm
#include <bits/stdc++.h>
using namespace std;
#define N 4

class PuzzleState {
	public:
		vector<vector<int>> board;
		int empty_row, empty_col;

		PuzzleState() {
			empty_row = empty_col = 0;
			board.resize(N, vector<int>(N,0));
		}
};

// Function to read puzzles from the input file
vector<PuzzleState> readPuzzlesFromFile(const string& filename) {
    ifstream inputFile(filename);

    vector<PuzzleState> puzzles;
	while(inputFile){
		PuzzleState puzzle;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				inputFile >> puzzle.board[i][j];
				if(puzzle.board[i][j] == -1){
					puzzle.empty_row = i;
					puzzle.empty_col = j;
				}
			}
		}
		if(!inputFile)break;
		puzzles.push_back(puzzle);
	}

    inputFile.close();
    return puzzles;
}

// state space tree nodes
struct Node
{
	// stores the parent node of the current node
	// helps in tracing path when the answer is found
	Node* parent;

	// stores matrix
	vector<vector<int>> mat;

	// stores blank tile coordinates
	int x, y;

	// stores the number of misplaced tiles
	int cost;

	// stores the number of moves so far
	int level;
};

// Function to allocate a new node
Node* newNode(vector<vector<int>> &mat, int x, int y, int newX,
			int newY, int level, Node* parent)
{
	Node* node = new Node;

	// set pointer for path to root
	node->parent = parent;

	// copy data from parent node to current node
	node->mat = mat;

	// move tile by 1 position
	swap(node->mat[x][y], node->mat[newX][newY]);

	// set number of misplaced tiles
	node->cost = INT_MAX;

	// set number of moves so far
	node->level = level;

	// update new blank tile coordinates
	node->x = newX;
	node->y = newY;

	return node;
}

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the number of misplaced tiles
// ie. number of non-blank tiles not in their goal position
int calculateCost(vector<vector<int>> &initial, vector<vector<int>> &final)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (initial[i][j] && initial[i][j] != final[i][j])
		count++;
	return count;
}

// Function to check if (x, y) is a valid matrix coordinate
int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

// print path from root node to destination node
int backtrack(Node* root)
{
	if (root == NULL)
		return 0;
	int num = 0;
	num = 1 + backtrack(root->parent);
	return num;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};

//check if solution is possible.
bool check(vector<vector<int>> &mat){
    vector<int> a;
    for(int i=0; i<4;i++){
        for(int j=0;j<4;j++){
            a.push_back(mat[i][j]);
        }
    }

    int inv = 0;
    for (int i=0; i<16; ++i)
        if (a[i] != -1)
            for (int j=0; j<i; ++j)
                if (a[j] > a[i])
                    ++inv;
    for (int i=0; i<16; ++i)
        if (a[i] == -1)
            inv += 1 + i / 4;

    if(inv & 1)return false;
    return true;
}

struct comp1
{
	bool operator()(const pair<int,Node*> lhs, const pair<int,Node*> rhs) const
	{
		return (lhs.second->cost + lhs.second->level) > (rhs.second->cost + rhs.second->level);
	}
};

// Function to solve N*N - 1 puzzle algorithm using
// Branch and Bound. x and y are blank tile coordinates
// in initial state
void solve(vector<vector<int>> &initial, int x, int y,
		vector<vector<int>> &final, int &numberOfMoves, bool &answer_found, vector<string> &moves, set<vector<vector<int>>> &st)
{
	// Create a priority queue to store live nodes of
	// search tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// create a root node and calculate its cost
	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);

	// Add root to list of live nodes;
	pq.push(root);

	// Finds a live node with least cost,
	// add its childrens to list of live nodes and
	// finally deletes it from the list.
	while (!pq.empty())
	{
		// Find a live node with least estimated cost
		Node* min = pq.top();

		// The found node is deleted from the list of
		// live nodes
		pq.pop();

		// if min is an answer node
		if (min->cost == 0)
		{
			// print the path from root to destination;
			answer_found = 1;
			numberOfMoves = backtrack(min);
			return;
		}

		//choose the lowest cost puzzle and move in four directions.


		priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, comp1> pq1;

		// do for each child of min
		// max 4 children for a node
		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{
				// create a child node and calculate
				// its cost
				Node* child = newNode(min->mat, min->x,
							min->y, min->x + row[i],
							min->y + col[i],
							min->level + 1, min);
				child->cost = calculateCost(child->mat, final);

                if(st.count(child->mat))continue;
                else st.insert(child->mat);
				if(child->level + child->cost > 1000)continue;

				// Add child to list of live nodes
				pq1.push({i, child});
			}
		}

		if(!pq1.empty()){
			pq.push(pq1.top().second);
			int next = pq1.top().first;
			string move = "";
			move = to_string(min->x + row[next]) + " " + to_string(min->y + col[next]);
			if(next == 0){
				move += " U";
			}else if(next == 1){
				move += " R";
			}else if(next == 2){
				move += " D";
			}else {
				move += " L";
			}
			moves.push_back(move);
		}
	}
}

// Driver code
int main()
{

	vector<PuzzleState> puzzles = readPuzzlesFromFile("15_puzzles.txt");

	ofstream outFile("output.txt");

	for(int i = 0; i<puzzles.size();i++){
		vector<vector<int>> initial = puzzles[i].board;
		set<vector<vector<int>>> st;

		bool answer_found = 0;
		int x = puzzles[i].empty_row;
		int y = puzzles[i].empty_col;

		vector<vector<int>> final =
			{
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 15, -1}
			};
		int numberOfMoves = 0;
		vector<string> moves;
		solve(initial, x, y, final, numberOfMoves, answer_found, moves, st);

		outFile << i + 1 << ", ";
		if (!check(initial)) {
			outFile << "not solvable"<<"\n\n";
			
			continue;
		}
		if (answer_found) {
			outFile << "solvable, solved, " << numberOfMoves - 1 << ":\n";
			for (auto str : moves) {
				outFile << str << '\n';
			}
		} else {
			outFile << "solvable, not solved, 1000\n";
		}
		outFile << '\n';

		st.clear();
	}
	outFile.close();

	return 0;
}

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
	int location = 0;

	vector<int> space; // pick up된 인형들 담길 공간
	int space_index = 0; // pick up된 인형들 관리 인덱스
	
    // pick up 구간
	for (int i = 0; i < moves.size(); ++i)
	{
		location = moves[i] - 1;
		for (int j = 0; j < board.size(); ++j)
		{
			if (board[j][location] != 0)
			{
				space.push_back(board[j][location]);
				board[j][location] = 0;
				break;
			}
		}
	}
	
    // pick up된 인형들 터트리는 구간
	int space_length = space.size();

	for (int k = 0; k < space_length; ++k)
	{
		space_index += 1;
		if (space_length > space_index)
		{
			if (space[k] == space[space_index])
			{
				answer += 2;

				space.erase(space.begin() + space_index);
				space.erase(space.begin() + k);

				space_index = 0;
				k = -1;
				space_length = space.size();
			}
		}
	}

	return answer;
}

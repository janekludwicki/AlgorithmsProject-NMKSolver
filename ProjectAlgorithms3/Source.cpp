#include <iostream>
using namespace std;

char checkRow(int N, int M, int K, char** array, char player) {
    bool hasZero = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (array[i][j] == '0')
                hasZero = true;
            if (array[i][j] == player)
            {
                int counter = 1;
                int temp = j + 1;
                while (temp < M && array[i][temp] == array[i][j])
                {
                    counter++;
                    temp++;
                    if (counter == K)
                        return array[i][j];
                }
            }
        }
    }
    if (!hasZero)
        return 'T';
    return '0';
}

char checkColumn(int N, int M, int K, char** array, char player) {
    bool hasZero = false;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array[j][i] == '0')
                hasZero = true;
            if (array[j][i] == player)
            {
                int counter = 1;
                int temp = j + 1;
                while (temp < N && array[temp][i] == array[j][i])
                {
                    counter++;
                    temp++;
                    if (counter == K)
                        return array[j][i];
                }
            }
        }
    }
    if (!hasZero)
        return 'T';
    return '0';
}

char checkDiagonalRight(int N, int M, int K, char** array, char player) {
    bool hasZero = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (array[i][j] == '0')
                hasZero = true;
            if (array[i][j] == player)
            {
                int counter = 1;
                int temp = i + 1;
                int temp2 = j + 1;

                while (temp < N && temp2 < M && array[temp][temp2] == array[i][j])
                {
                    counter++;
                    temp++;
                    temp2++;
                    if (counter == K)
                        return array[i][j];
                }
            }
        }
    }
    if (!hasZero)
        return 'T';
    return '0';
}

char checkDiagonalLeft(int N, int M, int K, char** array, char player) {
    bool hasZero = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (array[i][j] == '0')
                hasZero = true;
            if (array[i][j] == player)
            {
                int counter = 1;
                int temp = i + 1;
                int temp2 = j - 1;
                while (temp < N && temp2 >= 0 && array[temp][temp2] == array[i][j])
                {
                    counter++;
                    temp++;
                    temp2--;
                    if (counter == K)
                        return array[i][j];
                }
            }
        }
    }
    if (!hasZero)
        return 'T';
    return '0';
}

char CheckIfGameIsWon(int N, int M, int K, char** array, char player) {

    char checkRowResult = checkRow(N, M, K, array, player);

    if (checkRowResult != '0' && checkRowResult != 'T')
        return checkRowResult;

    char checkColumnResult = checkColumn(N, M, K, array, player);
    if (checkColumnResult != '0' && checkColumnResult != 'T')
        return checkColumnResult;

    char checkDiagonalLeftResult = checkDiagonalLeft(N, M, K, array, player);
    if (checkDiagonalLeftResult != '0' && checkDiagonalLeftResult != 'T')
        return checkDiagonalLeftResult;

    return checkDiagonalRight(N, M, K, array, player);
}

char** GenerateAllPositions(int N, int M, char activePlayer, char** array, int zeroToFill) {
    int counter = 0;
    char** result = new char* [N];

    for (int i = 0; i < N; i++) {
        result[i] = new char[M];
        for (int j = 0; j < M; j++) {
            result[i][j] = array[i][j];
            if (result[i][j] == '0')
            {
                if (counter == zeroToFill)
                    result[i][j] = activePlayer;
                counter++;
            }
        }
    }

    return result;
}

void PrintArray(char** array, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int SolveGame(char** array, int N, int M, int K, char player, char opponent, int min, int max) {
    char result = CheckIfGameIsWon(N, M, K, array, opponent);
    if (result == '1')
        return 1;
    if (result == '2')
        return -1;
    if (result == 'T')
        return 0;

    int bestScore = -1;
    if (player == '2')
        bestScore = 1;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (array[y][x] != '0')
                continue;

            array[y][x] = player;
            int score = SolveGame(array, N, M, K, opponent, player, min, max);
            array[y][x] = '0';

            if (player == '1' && score > bestScore)
                bestScore = score;

            if (player == '2' && score < bestScore)
                bestScore = score;

            if (player == '1' && min < bestScore)
                min = bestScore;
            if (player == '2' && max > bestScore)
                max = bestScore;

            if (min >= max)
                return bestScore;
        }
    }
    return bestScore;
}

int main() {
    int N, M, K;
    char activePlayer, command[100];
    while (cin >> command >> N >> M >> K >> activePlayer)
    {
        int zeros = 0;
        char** array = new char* [N];
        for (int i = 0; i < N; i++) {
            array[i] = new char[M];
            for (int j = 0; j < M; j++) {
                cin >> array[i][j];
                if (array[i][j] == '0')
                    zeros++;
            }
        }
        char opponent = '1';
        if (activePlayer == '1')
            opponent = '2';

        if (strcmp(command, "GEN_ALL_POS_MOV") == 0)
        {
            if (CheckIfGameIsWon(N, M, K, array, opponent) != '0')
                cout << 0 << endl;
            else
            {
                cout << zeros << endl;
                for (int h = 0; h < zeros; h++)
                {
                    char** newArray = GenerateAllPositions(N, M, activePlayer, array, h);
                    PrintArray(newArray, N, M);
                    for (int l = 0; l < N; l++) {
                        delete[] newArray[l];
                    }
                    delete[] newArray;
                }
            }
        }
        else if (strcmp(command, "GEN_ALL_POS_MOV_CUT_IF_GAME_OVER") == 0)
        {
            if (CheckIfGameIsWon(N, M, K, array, opponent) != '0')
                cout << 0 << endl;
            else
            {
                char*** arrays = new char** [zeros];
                for (int i = 0; i < zeros; i++)
                    arrays[i] = nullptr;
                bool cut = false;
                for (int i = 0; i < zeros; i++)
                {
                    arrays[i] = GenerateAllPositions(N, M, activePlayer, array, i);

                    if (CheckIfGameIsWon(N, M, K, arrays[i], activePlayer) != '0')
                    {
                        cout << 1 << endl;
                        PrintArray(arrays[i], N, M);
                        cut = true;
                        break;
                    }

                }
                if (cut == false)
                {
                    cout << zeros << endl;
                    for (int i = 0; i < zeros; i++)
                    {
                        PrintArray(arrays[i], N, M);
                    }
                }

                for (int i = 0; i < zeros; i++)
                {
                    if (arrays[i] == nullptr)
                        continue;
                    for (int j = 0; j < N; j++) {
                        delete[] arrays[i][j];
                    }

                    delete[] arrays[i];
                }
                delete[] arrays;
            }

        }
        else if (strcmp(command, "SOLVE_GAME_STATE") == 0)
        {
            int result = SolveGame(array, N, M, K, activePlayer, opponent, -1, 1);
            if (result == 1)
                cout << "FIRST_PLAYER_WINS" << endl;
            if (result == -1)
                cout << "SECOND_PLAYER_WINS" << endl;
            if (result == 0)
                cout << "BOTH_PLAYERS_TIE" << endl;

        }
        for (int i = 0; i < N; i++) {
            delete[] array[i];
        }
        delete[] array;
    }

    return 0;
}

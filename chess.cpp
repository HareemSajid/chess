//#include <iostream>
//#include <SFML/Graphics.hpp>
//
//using namespace std;
//using namespace sf;
//
//class Chess
//{
//public:
//    int size;
//    int board[8][8];
//    int selectedRow;
//    int selectedCol;
//    Texture blackTextures[6]; // Textures for black pieces
//    Texture whiteTextures[6];
//    int move;
//    int player = 1; //-1 for black and 1 for white
//
//    Chess()
//    {
//        size = 80;
//        selectedRow = -1, selectedCol = -1, move = 0, player = -1;
//        //The arrangement of these numbers in the initialBoard is according to  initial setup of pieces on a standard chessboard
//        int initialBoard[8][8] =
//        {
//            2, 3, 4, 5, 6, 4, 3, 2,
//            1, 1, 1, 1, 1, 1, 1, 1,
//            0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0,
//            0, 0, 0, 0, 0, 0, 0, 0,
//            -1, -1, -1, -1, -1, -1, -1, -1,
//            -2, -3, -4, -5, -6, -4, -3, -2,
//        };
//
//        // Load textures for black pieces
//        if (!blackTextures[0].loadFromFile("images/PawnB.png") ||
//            !blackTextures[1].loadFromFile("images/RookB.png") ||
//            !blackTextures[2].loadFromFile("images/KnightB.png") ||
//            !blackTextures[3].loadFromFile("images/BishopB.png") ||
//            !blackTextures[4].loadFromFile("images/QueenB.png") ||
//            !blackTextures[5].loadFromFile("images/KingB.png"))
//        {//In case if there is error loaing textures
//            cerr << "Failed to load texture for black pieces." << endl;
//        }
//
//        // Load textures for white pieces
//        if (!whiteTextures[0].loadFromFile("images/PawnW.png") ||
//            !whiteTextures[1].loadFromFile("images/RookW.png") ||
//            !whiteTextures[2].loadFromFile("images/KnightW.png") ||
//            !whiteTextures[3].loadFromFile("images/BishopW.png") ||
//            !whiteTextures[4].loadFromFile("images/QueenW.png") ||
//            !whiteTextures[5].loadFromFile("images/KingW.png"))
//        {//In case if there is error loaing textures
//            cerr << "Failed to load texture for white pieces." << endl;
//        }
//
//
//        // Copy the initial board to the game board
//        for (int i = 0; i < 8; ++i)
//        {
//            for (int j = 0; j < 8; ++j)
//            {
//                board[i][j] = initialBoard[i][j];
//            }
//        }
//    }
//
//    void draw(RenderWindow& window)
//    { // Draw the board and pieces
//        for (int row = 0; row < 8; ++row)
//        {
//            for (int col = 0; col < 8; ++col)
//            {
//                RectangleShape square(Vector2f(size, size));
//                square.setPosition(col * size, row * size);
//                if ((row + col) % 2 == 0)
//                    square.setFillColor(Color(209, 139, 71)); // Light color
//                else
//                    square.setFillColor(Color(255, 206, 158)); // Dark color
//                window.draw(square);
//
//                int piece = board[row][col];
//
//                if (piece < 0)
//                {
//                    Sprite sprite(whiteTextures[-piece - 1]);
//                    sprite.setPosition(col * size, row * size);
//                    window.draw(sprite);
//                }
//                else if (piece > 0)
//                {
//                    Sprite sprite(blackTextures[piece - 1]);
//                    sprite.setPosition(col * size, row * size);
//                    window.draw(sprite);
//                }
//            }
//        }
//    }
//
//
//    //Polymorphism is demonstrated through the use of pure virtual function The handleMouseClick function in the Chess class is declared as a pure virtual function using 
//    //virtual void handleMouseClick(const Event& e, RenderWindow& window) = 0;.This allows subclass eg Pieces to override this function enabling polymorphic behavior.
//    virtual void handleMouseClick(const Event& e, RenderWindow& window) = 0;
//};
//
////inheritance is used!
////The Pieces class inherits from the Chess class. It inherits attributes like size, board, and methods like draw and handleMouseClick. This allows Pieces to reuse  
////the functionalities defined in Chess while adding its own specific functionalities.
//
//
//class Pieces : public Chess
//{
//public:
//    int wking_x;
//    int wking_y; // Declare wking y-coordinate
//    int bking_x; // Declare bking x-coordinate
//    int bking_y; // Declare bking y-coordinate
//
//    Pieces()
//    {
//        //Default constructor
//    }
//
//    bool isValidMovePawnWhite(int oldRow, int oldCol, int newRow, int newCol) {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//        if (newCol == oldCol) {
//            if (newRow == oldRow + 1 && board[newRow][newCol] == 0)
//                return true;
//            else if (oldRow == 1 && newRow == oldRow + 2 && board[oldRow + 1][newCol] == 0 && board[newRow][newCol] == 0)
//                return true;
//        }
//        else if ((newCol == oldCol + 1 || newCol == oldCol - 1) && newRow == oldRow + 1 && board[newRow][newCol] < 0)
//            return true;
//        return false;
//    }
//
//    bool isValidMovePawnBlack(int oldRow, int oldCol, int newRow, int newCol) {
//
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//        if (newCol == oldCol && newRow == oldRow - 1 && board[newRow][newCol] == 0) {
//            return true;
//        }
//        if (oldRow == 6 && newCol == oldCol && newRow == oldRow - 2 && board[oldRow - 1][oldCol] == 0 && board[oldRow - 2][oldCol] == 0) {
//            return true;
//        }
//        if ((newCol == oldCol - 1 || newCol == oldCol + 1) && newRow == oldRow - 1 && board[newRow][newCol] > 0) {
//            return true;
//        }
//        return false;
//    }
//
//    bool isvalidmovewhiterook(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//        if (newRow == oldRow && newCol == oldCol)
//            return false;
//        if (newRow == oldRow || newCol == oldCol)
//        {
//            if (newRow == oldRow)
//            { // Moving horizontally
//                int startCol = min(oldCol, newCol);
//                int endCol = max(oldCol, newCol);
//                for (int col = startCol + 1; col < endCol; ++col)
//                {
//                    if (board[oldRow][col] != 0)
//                        return false;
//                }
//            }
//            else
//            { // Moving vertically
//                int startRow = min(oldRow, newRow);
//                int endRow = max(oldRow, newRow);
//                for (int row = startRow + 1; row < endRow; ++row)
//                {
//                    if (board[row][oldCol] != 0)
//                        return false;
//                }
//            }
//            return (board[newRow][newCol] <= 0);
//        }
//        return false;
//    }
//
//    bool isvalidmoveblackrook(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//        if (newRow == oldRow && newCol == oldCol)
//            return false;
//        if (newRow == oldRow || newCol == oldCol) {
//
//            if (newRow == oldRow) {
//                int startCol = min(oldCol, newCol);
//                int endCol = max(oldCol, newCol);
//                for (int col = startCol + 1; col < endCol; ++col) {
//                    if (board[oldRow][col] != 0)
//                        return false;
//                }
//            }
//            else {
//                int startRow = min(oldRow, newRow);
//                int endRow = max(oldRow, newRow);
//                for (int row = startRow + 1; row < endRow; ++row) {
//                    if (board[row][oldCol] != 0)
//                        return false;
//                }
//            }
//            return (board[newRow][newCol] >= 0);
//        }
//
//        return false;
//    }
//
//    bool isvaliwhitebishop(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//
//        int rowDiff = newRow - oldRow;
//        int colDiff = newCol - oldCol;
//        if ((rowDiff == colDiff) || (rowDiff == -colDiff)) {
//
//            int rowDir, colDir;
//            if (rowDiff > 0) {
//                rowDir = 1;
//            }
//            else {
//                rowDir = -1;
//            }
//
//            if (colDiff > 0) {
//                colDir = 1;
//            }
//            else {
//                colDir = -1;
//            }
//            for (int i = 1; i < (rowDiff >= 0 ? rowDiff : -rowDiff); ++i) {
//                if (board[oldRow + i * rowDir][oldCol + i * colDir] != 0)
//                    return false;
//            }
//            return (board[newRow][newCol] <= 0);
//        }
//
//        return false;
//    }
//
//    bool isvaliblackbishop(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//        int rowDiff = newRow - oldRow;
//        int colDiff = newCol - oldCol;
//        if ((rowDiff == colDiff) || (rowDiff == -colDiff)) {
//
//            int rowDir, colDir;
//            if (rowDiff > 0) {
//                rowDir = 1;
//            }
//            else {
//                rowDir = -1;
//            }
//
//            if (colDiff > 0) {
//                colDir = 1;
//            }
//            else {
//                colDir = -1;
//            }
//
//            for (int i = 1; i < (rowDiff >= 0 ? rowDiff : -rowDiff); ++i) {
//                if (board[oldRow + i * rowDir][oldCol + i * colDir] != 0)
//                    return false;
//            }
//            return (board[newRow][newCol] >= 0);
//        }
//
//        return false;
//    }
//
//    bool isValidMoveQueenWhite(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//
//        int rowDiff = newRow - oldRow;
//        int colDiff = newCol - oldCol;
//        if ((rowDiff == colDiff) || (rowDiff == -colDiff) || (newRow == oldRow) || (newCol == oldCol)) {
//
//            if (isvaliwhitebishop(oldRow, oldCol, newRow, newCol) || isvalidmovewhiterook(oldRow, oldCol, newRow, newCol))
//                return true;
//        }
//        return false;
//    }
//    bool isValidMoveQueenBlack(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//
//        int rowDiff = newRow - oldRow;
//        int colDiff = newCol - oldCol;
//
//        if ((rowDiff == colDiff) || (rowDiff == -colDiff) || (newRow == oldRow) || (newCol == oldCol)) {
//
//            if (isvaliblackbishop(oldRow, oldCol, newRow, newCol) || isvalidmoveblackrook(oldRow, oldCol, newRow, newCol))
//                return true;
//        }
//
//        return false;
//    }
//
//    bool isValidMoveKnightWhite(int oldRow, int oldCol, int newRow, int newCol) {
//
//        int horizontalDistance = newRow - oldRow;
//        int verticalDistance = newCol - oldCol;
//
//        if (horizontalDistance < 0) horizontalDistance = -horizontalDistance;
//        if (verticalDistance < 0) verticalDistance = -verticalDistance;
//        if ((horizontalDistance == 2 && verticalDistance == 1) || (horizontalDistance == 1 && verticalDistance == 2)) {
//
//            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
//                if (board[newRow][newCol] <= 0) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    bool isValidMoveKnightBlack(int oldRow, int oldCol, int newRow, int newCol) {
//
//        int horizontalDistance = oldRow - newRow;
//        int verticalDistance = oldCol - newCol;
//        if (horizontalDistance < 0) horizontalDistance = -horizontalDistance;
//        if (verticalDistance < 0) verticalDistance = -verticalDistance;
//        if ((horizontalDistance == 2 && verticalDistance == 1) || (horizontalDistance == 1 && verticalDistance == 2)) {
//            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
//                if (board[newRow][newCol] >= 0) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    //checks
//    bool PawnWhiteCheck(int RowPosition, int ColPosition, int KingRow, int KingCol)
//    {
//        if (KingRow >= 0 && KingRow < 8 && KingCol >= 0 && KingCol < 8) {
//
//            if (ColPosition - 1 >= 0 && RowPosition + 1 < 8) {
//                if ((ColPosition - 1 == KingCol && RowPosition + 1 == KingRow)) {
//                    return true;
//                }
//            }
//            if (ColPosition + 1 < 8 && RowPosition + 1 < 8) {
//                if ((ColPosition + 1 == KingCol && RowPosition + 1 == KingRow)) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    bool PawnBlackCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        if (KingRow >= 0 && KingRow < 8 && KingCol >= 0 && KingCol < 8) {
//
//            if (oldCol - 1 >= 0 && board[oldCol - 1][oldRow + 1] <= 0) {
//                if (KingCol == oldCol - 1 && KingRow == oldRow + 1) {
//                    return true;
//                }
//            }
//
//            if (oldCol + 1 < 8 && board[oldCol + 1][oldRow + 1] <= 0) {
//                if (KingCol == oldCol + 1 && KingRow == oldRow + 1) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//
//    bool RookWhiteCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        for (int i = oldRow - 1; i >= 0; i--) // to left
//        {
//            if (board[oldCol][i] >= 0 && (KingRow == i && KingCol == oldCol))
//            {
//                return true;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol - 1; i >= 0; i--) // up
//        {
//            if (board[i][oldRow] >= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return true;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldRow + 1; i < 8; i++) // to right
//        {
//            if (board[oldCol][i] >= 0 && (KingCol == oldCol && KingRow == i))
//            {
//                return true;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol + 1; i < 8; i++) // down
//        {
//            if (board[i][oldRow] >= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return true;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        return false;
//    }
//
//    bool RookBlackCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        for (int i = oldRow - 1; i >= 0; i--) //to left
//        {
//            if (board[oldCol][i] <= 0 && (KingRow == i && KingCol == oldCol))
//            {
//                return 1;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol - 1; i >= 0; i--) // up
//        {
//            if (board[i][oldRow] <= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return 1;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldRow + 1; i < 8; i++) // right
//        {
//            if (board[oldCol][i] <= 0 && (KingCol == oldCol && KingRow == i))
//            {
//                return 1;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol + 1; i < 8; i++) // down
//        {
//            if (board[i][oldRow] <= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return 1;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        return 0;
//    }
//
//    bool BishopWhiteCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        int j = oldRow - 1;
//        for (int i = oldCol - 1; i >= 0; i--) // diagonally left up
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol - 1; i >= 0; i--) // diagonally right up
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        j = oldRow - 1;
//        for (int i = oldCol + 1; i <= 7; i++) //diagonally left down
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol + 1; i <= 7; i++)  // diagonally right down
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        return 0;
//    }
//
//    bool BishopBlackCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        int j = oldRow - 1;
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        j = oldRow - 1;
//        for (int i = oldCol + 1; i <= 7; i++)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol + 1; i <= 7; i++)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        return 0;
//    }
//
//    bool QueenWhiteCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        for (int i = oldRow - 1; i >= 0; i--)
//        {
//            if (board[oldCol][i] >= 0 && (KingRow == i && KingCol == oldCol))
//            {
//                return 1;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][oldRow] >= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return 1;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldRow + 1; i < 8; i++)
//        {
//            if (board[oldCol][i] >= 0 && (KingCol == oldCol && KingRow == i))
//            {
//                return 1;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol + 1; i < 8; i++)
//        {
//            if (board[i][oldRow] >= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return 1;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        int j = oldRow - 1;
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        j = oldRow - 1;
//        for (int i = oldCol + 1; i <= 7; i++)
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol + 1; i < 8; i++)
//        {
//            if (board[i][j] >= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        return 0;
//    }
//
//    bool QueenBlackCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        for (int i = oldRow - 1; i >= 0; i--)
//        {
//            if (board[oldCol][i] <= 0 && (KingRow == i && KingCol == oldCol))
//            {
//                return 1;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][oldRow] <= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return 1;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldRow + 1; i < 8; i++)
//        {
//            if (board[oldCol][i] <= 0 && (KingCol == oldCol && KingRow == i))
//            {
//                return 1;
//            }
//            else if (board[oldCol][i] != 0)
//            {
//                break;
//            }
//        }
//        for (int i = oldCol + 1; i < 8; i++)
//        {
//            if (board[i][oldRow] <= 0 && (KingCol == i && KingRow == oldRow))
//            {
//                return 1;
//            }
//            else if (board[i][oldRow] != 0)
//            {
//                break;
//            }
//        }
//        int j = oldRow - 1;
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol - 1; i >= 0; i--)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        j = oldRow - 1;
//        for (int i = oldCol + 1; i <= 7; i++)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j--;
//        }
//        j = oldRow + 1;
//        for (int i = oldCol + 1; i < 8; i++)
//        {
//            if (board[i][j] <= 0 && (KingCol == i && KingRow == j))
//            {
//                return 1;
//            }
//            else if (board[i][j] != 0)
//            {
//                break;
//            }
//            j++;
//        }
//        return 0;
//    }
//
//    bool KnightWhiteCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        if (oldCol - 2 >= 0 && oldRow - 1 >= 0 && KingCol == oldCol - 2 && KingRow == oldRow - 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 2 >= 0 && oldRow + 1 < 8 && KingCol == oldCol - 2 && KingRow == oldRow + 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && oldRow + 2 < 8 && KingCol == oldCol - 1 && KingRow == oldRow + 2 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 1 >= 0 && oldRow + 2 < 8 && KingCol == oldCol + 1 && KingRow == oldRow + 2 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 2 < 8 && oldRow + 1 < 8 && KingCol == oldCol + 2 && KingRow == oldRow + 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 2 < 8 && oldRow - 1 >= 0 && KingCol == oldCol + 2 && KingRow == oldRow - 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 1 < 8 && oldRow - 2 >= 0 && KingCol == oldCol + 1 && KingRow == oldRow - 2 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && oldRow - 2 >= 0 && KingCol == oldCol - 1 && KingRow == oldRow - 2 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        return 0;
//    }
//
//    bool KnightBlackCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        if (oldCol - 2 >= 0 && oldRow - 1 >= 0 && KingCol == oldCol - 2 && KingRow == oldRow - 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 2 >= 0 && oldRow + 1 < 8 && KingCol == oldCol - 2 && KingRow == oldRow + 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && oldRow + 2 < 8 && KingCol == oldCol - 1 && KingRow == oldRow + 2 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 1 >= 0 && oldRow + 2 < 8 && KingCol == oldCol + 1 && KingRow == oldRow + 2 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 2 < 8 && oldRow + 1 < 8 && KingCol == oldCol + 2 && KingRow == oldRow + 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 2 < 8 && oldRow - 1 >= 0 && KingCol == oldCol + 2 && KingRow == oldRow - 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 1 < 8 && oldRow - 2 >= 0 && KingCol == oldCol + 1 && KingRow == oldRow - 2 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && oldRow - 2 >= 0 && KingCol == oldCol - 1 && KingRow == oldRow - 2 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        return 0;
//    }
//
//    bool KingWhiteCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        if (oldRow - 1 >= 0 && oldCol - 1 >= 0 && KingCol == oldCol - 1 && KingRow == oldRow - 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && KingRow == oldRow && KingCol == oldCol - 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && oldRow + 1 < 8 && KingRow == oldRow + 1 && KingCol == oldCol - 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldRow + 1 < 8 && KingCol == oldCol && KingRow == oldRow + 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldRow + 1 < 8 && oldCol + 1 < 8 && KingCol == oldCol + 1 && KingRow == oldRow + 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 1 < 8 && KingCol == oldCol + 1 && KingRow == oldRow && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldRow - 1 >= 0 && oldCol + 1 < 8 && KingRow == oldRow - 1 && KingCol == oldCol + 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        if (oldRow - 1 >= 0 && KingCol == oldCol && KingRow == oldRow - 1 && board[KingCol][KingRow] <= 0)
//        {
//            return 1;
//        }
//        return 0;
//    }
//
//    bool KingBlackCheck(int oldRow, int oldCol, int KingRow, int KingCol)
//    {
//        if (oldRow - 1 >= 0 && oldCol - 1 >= 0 && KingCol == oldCol - 1 && KingRow == oldRow - 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && KingRow == oldRow && KingCol == oldCol - 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol - 1 >= 0 && oldRow + 1 < 8 && KingRow == oldRow + 1 && KingCol == oldCol - 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldRow + 1 < 8 && KingCol == oldCol && KingRow == oldRow + 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldRow + 1 < 8 && oldCol + 1 < 8 && KingCol == oldCol + 1 && KingRow == oldRow + 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldCol + 1 < 8 && KingCol == oldCol + 1 && KingRow == oldRow && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldRow - 1 >= 0 && oldCol + 1 < 8 && KingRow == oldRow - 1 && KingCol == oldCol + 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        if (oldRow - 1 >= 0 && KingCol == oldCol && KingRow == oldRow - 1 && board[KingCol][KingRow] >= 0)
//        {
//            return 1;
//        }
//        return 0;
//    }
//
//    //checkmates
//    bool KingBlackChechMate(int positionKingRow, int positionKingCol)
//    {
//        int check = 0;
//        for (int i = 0; i < 8; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                if (board[i][j] < 0)
//                {
//                    if (board[i][j] == 1)
//                    {
//                        check = PawnWhiteCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == 2)
//                    {
//                        check = RookWhiteCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == 3)
//                    {
//                        check = KnightWhiteCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == 4)
//                    {
//                        check = BishopWhiteCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == 5)
//                    {
//                        check = QueenWhiteCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == 6)
//                    {
//                        check = KingWhiteCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (check == 1)
//                    {
//                        return 0;
//                    }
//                }
//            }
//        }
//        return 1;
//    }
//
//    bool KingWhiteCheckMate(int positionKingRow, int positionKingCol)
//    {
//        int check = 0;
//        for (int i = 0; i < 8; i++)
//        {
//            for (int j = 0; j < 8; j++)
//            {
//                if (board[i][j] > 0)
//                {
//                    if (board[i][j] == -1)
//                    {
//                        check = PawnBlackCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == -2)
//                    {
//                        check = RookBlackCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == -3)
//                    {
//                        check = KnightBlackCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == -4)
//                    {
//                        check = BishopBlackCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == -5)
//                    {
//                        check = QueenBlackCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (board[i][j] == -6)
//                    {
//                        check = KingBlackCheck(j, i, positionKingRow, positionKingCol);
//                    }
//                    if (check == 1)
//                    {
//                        return 0;
//                    }
//                }
//            }
//        }
//        return 1;
//    }
//
//    bool isvalidmoveKingWhite(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (oldRow - 1 >= 0 && oldCol - 1 >= 0 && newCol == oldCol - 1 && newRow == oldRow - 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow - 1, oldCol - 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldCol - 1 >= 0 && newRow == oldRow && newCol == oldCol - 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow, oldCol - 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldCol - 1 >= 0 && oldRow + 1 < 8 && newRow == oldRow + 1 && newCol == oldCol - 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow + 1, oldCol - 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow + 1 < 8 && newCol == oldCol && newRow == oldRow + 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow + 1, oldCol);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow + 1 < 8 && oldCol + 1 < 8 && newCol == oldCol + 1 && newRow == oldRow + 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow + 1, oldCol + 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldCol + 1 < 8 && newCol == oldCol + 1 && newRow == oldRow && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow, oldCol + 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow - 1 >= 0 && oldCol + 1 < 8 && newRow == oldRow - 1 && newCol == oldCol + 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow - 1, oldCol + 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow - 1 >= 0 && newCol == oldCol && newRow == oldRow - 1 && board[newCol][newRow] <= 0)
//        {
//            int check = KingWhiteCheckMate(oldRow - 1, oldCol);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool  isvalidmoveKingBlack(int oldRow, int oldCol, int newRow, int newCol)
//    {
//        if (oldRow - 1 >= 0 && oldCol - 1 >= 0 && newCol == oldCol - 1 && newRow == oldRow - 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow - 1, oldCol - 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldCol - 1 >= 0 && newRow == oldRow && newCol == oldCol - 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow, oldCol - 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldCol - 1 >= 0 && oldRow + 1 < 8 && newRow == oldRow + 1 && newCol == oldCol - 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow + 1, oldCol - 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow + 1 < 8 && newCol == oldCol && newRow == oldRow + 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow + 1, oldCol);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow + 1 < 8 && oldCol + 1 < 8 && newCol == oldCol + 1 && newRow == oldRow + 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow + 1, oldCol + 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldCol + 1 < 8 && newCol == oldCol + 1 && newRow == oldRow && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow, oldCol + 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow - 1 >= 0 && oldCol + 1 < 8 && newRow == oldRow - 1 && newCol == oldCol + 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow - 1, oldCol + 1);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        if (oldRow - 1 >= 0 && newCol == oldCol && newRow == oldRow - 1 && board[newCol][newRow] >= 0)
//        {
//            int check = KingBlackChechMate(oldRow - 1, oldCol);
//            if (check == 1)
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void positionKingWhite() {
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                if (board[i][j] == 6) {
//                    wking_x = j; // Assign x-coordinate of white king
//                    wking_y = i; // Assign y-coordinate of white king
//                    return;
//                }
//            }
//        }
//    }
//
//    void positionKingBlack() {
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                if (board[i][j] == -6) {
//                    bking_x = j; // Assign x-coordinate of black king
//                    bking_y = i; // Assign y-coordinate of black king
//                    return;
//                }
//            }
//        }
//    }
//
//    bool isWhiteKingCaptured() {
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                if (board[i][j] == -6) {
//                    return false;
//                }
//            }
//        }
//        return true; // White king is captured
//    }
//
//    bool isBlackKingCaptured() {
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                if (board[i][j] == 6) {
//                    return false;
//                }
//            }
//        }
//        return true; // Black king is captured
//    }
//
//
//    void handleMouseClick(const Event& e, RenderWindow& window) override {
//        static bool isDragging = false;
//        static Vector2f offset;
//        static int pieceRow = -1;
//        static int pieceCol = -1;
//
//        if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
//        {
//            Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
//            // Check if the mouse is clicked on a piece
//            for (int row = 0; row < 8; ++row) {
//                for (int col = 0; col < 8; ++col) {
//                    // Check if the piece belongs to the current player
//                    if ((player == 1 && board[row][col] > 0) || (player == -1 && board[row][col] < 0)) {
//                        FloatRect pieceBounds(col * size, row * size, size, size);
//                        if (pieceBounds.contains(mousePosition) && board[row][col] != 0) {
//                            isDragging = true;
//                            offset = mousePosition - pieceBounds.getPosition();
//                            pieceRow = row;
//                            pieceCol = col;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        if (isDragging) {
//
//            Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window)) - offset;
//
//            int newRow = static_cast<int>((mousePosition.y + size / 2) / size);
//            int newCol = static_cast<int>((mousePosition.x + size / 2) / size);
//
//            newRow = std::max(0, std::min(7, newRow));
//            newCol = std::max(0, std::min(7, newCol));
//
//            // Update the board with the new position if it's valid
//            if (e.type == Event::MouseButtonReleased && e.mouseButton.button == Mouse::Left) {
//                // Check if the move is valid for the selected piece and for the current player
//                if (isValidMove(pieceRow, pieceCol, newRow, newCol) &&
//                    ((player == 1 && board[pieceRow][pieceCol] > 0) || (player == -1 && board[pieceRow][pieceCol] < 0))) {
//                    board[newRow][newCol] = board[pieceRow][pieceCol];
//                    board[pieceRow][pieceCol] = 0; // Clear the original position
//                    // Toggle the turn after a valid move
//                    player = -player;
//                }
//
//                isDragging = false;
//                pieceRow = -1;
//                pieceCol = -1;
//            }
//        }
//    }
//
//    bool isValidMove(int oldRow, int oldCol, int newRow, int newCol) {
//        if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8)
//            return false;
//
//        if (board[newRow][newCol] == 0 || board[oldRow][oldCol] * board[newRow][newCol] < 0) {
//            // Check if the selected piece is a white rook
//            if (board[oldRow][oldCol] == 2 || board[oldRow][oldCol] == -2) {
//                if (board[oldRow][oldCol] == 2) {
//                    return isvalidmovewhiterook(oldRow, oldCol, newRow, newCol);
//                }
//                // Check if the selected piece is a black rook
//                else {
//                    return isvalidmoveblackrook(oldRow, oldCol, newRow, newCol);
//                }
//            }
//
//            // Check if the selected piece is a pawn
//            if (board[oldRow][oldCol] == 1 || board[oldRow][oldCol] == -1) {
//
//                if (board[oldRow][oldCol] == 1) {
//                    // Valid move for white pawn
//                    return isValidMovePawnWhite(oldRow, oldCol, newRow, newCol);
//                }
//                else {
//                    // Valid move for black pawn
//                    return isValidMovePawnBlack(oldRow, oldCol, newRow, newCol);
//                }
//            }
//
//            if (board[oldRow][oldCol] == 4 || board[oldRow][oldCol] == -4) {
//
//                if (board[oldRow][oldCol] == 4) {
//                    // Valid move for white bishop
//                    return isvaliwhitebishop(oldRow, oldCol, newRow, newCol);
//                }
//                else {
//                    // Valid move for black bishop
//                    return isvaliblackbishop(oldRow, oldCol, newRow, newCol);
//                }
//            }
//
//            if (board[oldRow][oldCol] == 5 || board[oldRow][oldCol] == -5) {
//
//                if (board[oldRow][oldCol] == 5) {
//                    // Valid move for white queen
//                    return isValidMoveQueenWhite(oldRow, oldCol, newRow, newCol);
//                }
//                else {
//                    // Valid move for black queen
//                    return isValidMoveQueenBlack(oldRow, oldCol, newRow, newCol);
//                }
//            }
//
//            if (board[oldRow][oldCol] == 3 || board[oldRow][oldCol] == -3)
//            {
//                if (board[oldRow][oldCol] == 3)
//                {
//                    // Valid move for white knight
//                    return isValidMoveKnightWhite(oldRow, oldCol, newRow, newCol);
//                }
//                else
//                {
//                    // Valid move for black knight
//                    return isValidMoveKnightBlack(oldRow, oldCol, newRow, newCol);
//                }
//            }
//
//            if (board[oldRow][oldCol] == 6 || board[oldRow][oldCol] == -6)
//            {
//                if (board[oldRow][oldCol] == 6)
//                {
//                    // Valid move for white king
//                    return isvalidmoveKingWhite(oldRow, oldCol, newRow, newCol);
//                }
//                else
//                {
//                    // Valid move for black king
//                    return isvalidmoveKingBlack(oldRow, oldCol, newRow, newCol);
//                }
//            }
//
//        }
//
//        return false;
//    }
//
//
//};
//
//int main() {
//    // Create the main window
//    sf::RenderWindow window(sf::VideoMode(640, 640), "Chess Game");
//
//    // Load cover page image
//    sf::Texture coverTexture;
//    if (!coverTexture.loadFromFile("Images/cp.png")) {
//        return -1;
//    }
//
//    Sprite coverSprite(coverTexture);
//
//    float scaleFactor = 3.1f;
//    coverSprite.setScale(scaleFactor, scaleFactor);
//
//    bool gameStarted = false;
//    Chess* chess = new Pieces();
//    while (window.isOpen())
//    {
//
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//            else if (event.type == Event::KeyPressed)
//            {
//                // If Enter key is pressed, start the game
//                if (event.key.code == sf::Keyboard::Enter)
//                    gameStarted = true;
//            }
//
//            chess->handleMouseClick(event, window);
//        }
//
//        window.clear();
//
//        // Display cover page if game not started
//        if (!gameStarted) {
//            window.draw(coverSprite);
//        }
//        else {
//            // Draw the chess board and pieces
//            chess->draw(window);
//
//
//            Pieces* pieces = dynamic_cast<Pieces*>(chess);
//            if (pieces) {
//                pieces->positionKingWhite();
//                pieces->positionKingBlack();
//                if (pieces->isWhiteKingCaptured()) {
//                    cout << "Winner is team black!" << std::endl;
//                    window.close();
//                }
//                else if (pieces->isBlackKingCaptured()) {
//                    cout << "Winner is team white!" << std::endl;
//                    window.close();
//                }
//            }
//        }
//
//
//        window.display();
//    }
//
//    delete chess;
//    return 0;
//}
//
//
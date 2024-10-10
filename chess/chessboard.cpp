#include "chessboard.h"
#include <iostream>
#include "figure.h"

bool chessboard::isInBoard = true;

chessboard::chessboard()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board[i][j] = nullptr;
        }
    }
}

chessboard::~chessboard()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            delete board[i][j];
        }
    }
}
bool chessboard::canPlaceKingAt(int row, int col)
{
    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            figure *piece = board[newRow][newCol];
            if (piece && piece->getSymbol() == 'K')
            {
                return false;
            }
        }
    }

    return true;
}
void chessboard::placePiece(figure *piece)
{
    int row = piece->getRow();
    int col = piece->getCol();
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
    {
        std::cout << "Invalid position" << std::endl;
        chessboard::isInBoard = false;
        return;
    }
    if (piece->getSymbol() == 'K')
    {
        if (!canPlaceKingAt(row, col))
        {
            chessboard::isInBoard = false;
            std::cout << "Cannot place king at row: " << piece->getRow() << " and column: " << piece->getRow() << " because another king is too close." << std::endl;
            return;
        }
    }
    board[row][col] = piece;
}

bool chessboard::isCheck(const std::string &kingPosition)
{
    int kingRow = kingPosition[1] - '1';
    int kingCol = kingPosition[0] - 'A';

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            figure *piece = board[row][col];
            if (piece && piece->getColor() != "Black")
            { 
                if (piece->isAttacking(kingPosition, board))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool chessboard::isCheckmate(const std::string &kingPosition)
{
    int kingRow = kingPosition[1] - '1';
    int kingCol = kingPosition[0] - 'A';

    if (!isCheck(kingPosition))
    {
        return false;
    }

    const int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
        int newRow = kingRow + rowOffsets[i];
        int newCol = kingCol + colOffsets[i];

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            std::string newKingPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);

            figure *originalKing = board[kingRow][kingCol];
            board[kingRow][kingCol] = nullptr;
            board[newRow][newCol] = originalKing;
            originalKing->move(newKingPosition);

            bool stillInCheck = isCheck(newKingPosition);

            originalKing->move(kingPosition);
            board[newRow][newCol] = nullptr;
            board[kingRow][kingCol] = originalKing;

            if (!stillInCheck)
            {
                return false;
            }
        }
    }

    return true;
}

bool chessboard::checkmateInOne(const std::string &kingPosition)
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            figure *piece = board[row][col];
            if (piece && piece->getSymbol() != 'K' && piece->getColor() == "White")
            {
                for (int newRow = 0; newRow < 8; ++newRow)
                {
                    for (int newCol = 0; newCol < 8; ++newCol)
                    {
                        std::string targetPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
                        if (piece->isAttacking(targetPosition, board) && (board[newRow][newCol] == nullptr))
                        {
                            int originalRow = piece->getRow();
                            int originalCol = piece->getCol();
                            figure *targetPiece = board[newRow][newCol];

                            piece->move(targetPosition);
                            board[originalRow][originalCol] = nullptr;
                            board[newRow][newCol] = piece;

                            if (isCheckmate(kingPosition) && !canCapture(kingPosition))
                            {
                                piece->move(std::string(1, originalCol + 'A') + std::to_string(originalRow + 1));
                                board[originalRow][originalCol] = piece;
                                board[newRow][newCol] = targetPiece;
                                return true;
                            }

                            piece->move(std::string(1, originalCol + 'A') + std::to_string(originalRow + 1));
                            board[originalRow][originalCol] = piece;
                            board[newRow][newCol] = targetPiece;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void chessboard::print()
{
    for (int row = 7; row >= 0; --row)
    {
        std::cout << row + 1 << " ";
        for (int col = 0; col < 8; ++col)
        {
            if (board[row][col] == nullptr)
            {
                std::cout << "- ";
            }
            else
            {
                std::cout << board[row][col]->getSymbol() << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  A B C D E F G H" << std::endl;
}

bool chessboard::getPlacement()
{
    return isInBoard;
}

bool chessboard::canCapture(const std::string &kingPosition)
{
    int kingRow = kingPosition[1] - '1';
    int kingCol = kingPosition[0] - 'A';

    const int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i)
    {
        int newRow = kingRow + rowOffsets[i];
        int newCol = kingCol + colOffsets[i];

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            std::string newKingPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
            figure *targetPiece = board[newRow][newCol];

            if (targetPiece != nullptr && targetPiece->getColor() != "Black")
            {
                figure *originalPiece = board[kingRow][kingCol];

                board[kingRow][kingCol] = nullptr;
                board[newRow][newCol] = originalPiece;
                originalPiece->move(newKingPosition);

                bool inCheck = isCheck(newKingPosition);

                board[newRow][newCol] = targetPiece;
                board[kingRow][kingCol] = originalPiece;
                originalPiece->move(kingPosition);

                if (!inCheck)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool chessboard::checkmateInTwo()
{
    std::string blackKingPosition;
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            figure *piece = board[row][col];
            if (piece && piece->getSymbol() == 'K' && piece->getColor() == "Black")
            {
                blackKingPosition = std::string(1, col + 'A') + std::to_string(row + 1);
                break;
            }
        }
    }

    if (blackKingPosition.empty())
    {
        std::cerr << "Black king not found on the board!" << std::endl;
        return false;
    }

    if (isCheckmate(blackKingPosition) && !canCapture(blackKingPosition))
    {
        std::cout << "Already in checkmate" << std::endl;
        return true;
    }

    const int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            figure *piece = board[row][col];
            if (piece && piece->getColor() == "White")
            {
                for (int newRow = 0; newRow < 8; ++newRow)
                {
                    for (int newCol = 0; newCol < 8; ++newCol)
                    {
                        std::string targetPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
                        if (piece->isAttacking(targetPosition, board) && !board[newRow][newCol])
                        {
                            int originalRow = piece->getRow();
                            int originalCol = piece->getCol();
                            figure *capturedPiece = board[newRow][newCol];

                            piece->move(targetPosition);
                            board[originalRow][originalCol] = nullptr;
                            board[newRow][newCol] = piece;

                            bool checkmateInOnePossible = true;

                            for (int i = 0; i < 8; ++i)
                            {
                                int newKingRow = blackKingPosition[1] - '1' + rowOffsets[i];
                                int newKingCol = blackKingPosition[0] - 'A' + colOffsets[i];
                                if (newKingRow >= 0 && newKingRow < 8 && newKingCol >= 0 && newKingCol < 8)
                                {
                                    std::string newKingPosition = std::string(1, newKingCol + 'A') + std::to_string(newKingRow + 1);

                                    if (isCheck(newKingPosition))
                                    {
                                        continue;
                                    }

                                    figure *blackKing = board[blackKingPosition[1] - '1'][blackKingPosition[0] - 'A'];
                                    blackKing->move(newKingPosition);
                                    board[blackKingPosition[1] - '1'][blackKingPosition[0] - 'A'] = nullptr;
                                    board[newKingRow][newKingCol] = blackKing;

                                    if (!checkmateInOne(newKingPosition))
                                    {
                                        checkmateInOnePossible = false;
                                    }

                                    blackKing->move(blackKingPosition);
                                    board[blackKingPosition[1] - '1'][blackKingPosition[0] - 'A'] = blackKing;
                                    board[newKingRow][newKingCol] = nullptr;
                                }
                            }

                            if (checkmateInOnePossible)
                            {
                                print();
                                return true;
                            }

                            piece->move(std::string(1, originalCol + 'A') + std::to_string(originalRow + 1));
                            board[originalRow][originalCol] = piece;
                            board[newRow][newCol] = capturedPiece;
                        }
                    }
                }
            }
        }
    }

    return false;
}

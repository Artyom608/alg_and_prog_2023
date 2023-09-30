#include <iostream>
#include <vector>
#include <string>

bool dfs(std::vector<std::string>& maze, int row, int col) {
    int rows = maze.size();
    int cols = maze[0].size();
    
    // Проверка на выход за границы лабиринта
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return false;
    }
    
    char current = maze[row][col];
    
    // Проверка, достигли ли мы выхода
    if (current == 'E') {
        return true;
    }
    
    // Если текущая ячейка не проходима (стена или уже посещена), возвращаем false
    if (current == '#' || current == 'X') {
        return false;
    }
    
    // Помечаем текущую ячейку как посещенную
    maze[row][col] = 'X';
    
    // Рекурсивный поиск выхода во всех соседних ячейках
    if (dfs(maze, row - 1, col) || dfs(maze, row + 1, col) || dfs(maze, row, col - 1) || dfs(maze, row, col + 1)) {
        return true;
    }
    
    return false;
}

bool is_can_exit_from_maze(std::vector<std::string>& maze, int row, int col) {
    if (maze[row][col] == '#') {
        return false; // Стартовая позиция - стена
    }
    
    return dfs(maze, row, col);
}

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}

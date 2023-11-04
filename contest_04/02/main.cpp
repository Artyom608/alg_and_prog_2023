#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

int main() {
    ifstream file("data.json");

    // Чтение JSON файла
    json jsonData;
    file >> jsonData;
    file.close();

    int user_id_inp, completed_tasks = 0;
    cin >> user_id_inp;

    // Перебираем элементы JSON
    for (const auto &item : jsonData) {
        const json &tasks = item["tasks"];
        for (const auto &task : tasks) {
            int userID = task["user_id"];
            bool completed = task["completed"];

            if (userID == user_id_inp && completed == true) {
                completed_tasks++;
            }
        }
    }

    std::cout << completed_tasks << std::endl;

    return 0;
}

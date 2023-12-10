#include <iostream>
#include <map>
#include <set>
#include <vector>

// Структура для хранения информации о компьютерах
struct Computer {
    int id;
    std::string department;
    std::string room;
};

// Функция для прямого обхода дерева
void traverse(std::map<std::string, std::vector<Computer>>& tree, std::map<std::string, std::set<std::string>>& roomDepartments) {
    for (auto& node : tree) {
        for (auto& comp : node.second) {
            roomDepartments[comp.room].insert(comp.department);
        }
    }
}

int main()
{
    system("chcp 1251");

    // Создаем два дерева
    std::map<std::string, std::vector<Computer>> departmentTree;
    std::map<std::string, std::vector<Computer>> buildingTree;

    // Заполняем деревья данными
    departmentTree["Факультет 1"].push_back({ 1, "Кафедра 1", "Аудитория 1" });
    departmentTree["Факультет 1"].push_back({ 2, "Кафедра 1", "Аудитория 2" });
    departmentTree["Факультет 2"].push_back({ 3, "Кафедра 2", "Аудитория 2" });
    departmentTree["Факультет 2"].push_back({ 4, "Кафедра 2", "Аудитория 3" });
    departmentTree["Факультет 3"].push_back({ 5, "Кафедра 3", "Аудитория 3" });
    departmentTree["Факультет 3"].push_back({ 6, "Кафедра 3", "Аудитория 4" });
    departmentTree["Факультет 4"].push_back({ 7, "Кафедра 4", "Аудитория 4" });
    departmentTree["Факультет 4"].push_back({ 8, "Кафедра 4", "Аудитория 1" });

    buildingTree["Корпус 1"].push_back({ 1, "Кафедра 1", "Аудитория 1" });
    buildingTree["Корпус 1"].push_back({ 2, "Кафедра 1", "Аудитория 2" });
    buildingTree["Корпус 2"].push_back({ 3, "Кафедра 2", "Аудитория 2" });
    buildingTree["Корпус 2"].push_back({ 4, "Кафедра 2", "Аудитория 3" });
    buildingTree["Корпус 3"].push_back({ 5, "Кафедра 3", "Аудитория 3" });
    buildingTree["Корпус 3"].push_back({ 6, "Кафедра 3", "Аудитория 4" });
    buildingTree["Корпус 4"].push_back({ 7, "Кафедра 4", "Аудитория 4" });
    buildingTree["Корпус 4"].push_back({ 8, "Кафедра 4", "Аудитория 1" });

    // Создаем дерево для хранения информации о том, какие кафедры используют каждую аудиторию
    std::map<std::string, std::set<std::string>> roomDepartments;

    // Находим аудитории, которые принадлежат более чем одной кафедре
    traverse(departmentTree, roomDepartments);
    traverse(buildingTree, roomDepartments);

    // Выводим результат
    for (const auto& room : roomDepartments) {
        if (room.second.size() > 1) {
            std::cout << room.first << std::endl;
        }
    }

    return 0;
}

#include <iostream>
#include <map>
#include <set>
#include <vector>

// ��������� ��� �������� ���������� � �����������
struct Computer {
    int id;
    std::string department;
    std::string room;
};

// ������� ��� ������� ������ ������
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

    // ������� ��� ������
    std::map<std::string, std::vector<Computer>> departmentTree;
    std::map<std::string, std::vector<Computer>> buildingTree;

    // ��������� ������� �������
    departmentTree["��������� 1"].push_back({ 1, "������� 1", "��������� 1" });
    departmentTree["��������� 1"].push_back({ 2, "������� 1", "��������� 2" });
    departmentTree["��������� 2"].push_back({ 3, "������� 2", "��������� 2" });
    departmentTree["��������� 2"].push_back({ 4, "������� 2", "��������� 3" });
    departmentTree["��������� 3"].push_back({ 5, "������� 3", "��������� 3" });
    departmentTree["��������� 3"].push_back({ 6, "������� 3", "��������� 4" });
    departmentTree["��������� 4"].push_back({ 7, "������� 4", "��������� 4" });
    departmentTree["��������� 4"].push_back({ 8, "������� 4", "��������� 1" });

    buildingTree["������ 1"].push_back({ 1, "������� 1", "��������� 1" });
    buildingTree["������ 1"].push_back({ 2, "������� 1", "��������� 2" });
    buildingTree["������ 2"].push_back({ 3, "������� 2", "��������� 2" });
    buildingTree["������ 2"].push_back({ 4, "������� 2", "��������� 3" });
    buildingTree["������ 3"].push_back({ 5, "������� 3", "��������� 3" });
    buildingTree["������ 3"].push_back({ 6, "������� 3", "��������� 4" });
    buildingTree["������ 4"].push_back({ 7, "������� 4", "��������� 4" });
    buildingTree["������ 4"].push_back({ 8, "������� 4", "��������� 1" });

    // ������� ������ ��� �������� ���������� � ���, ����� ������� ���������� ������ ���������
    std::map<std::string, std::set<std::string>> roomDepartments;

    // ������� ���������, ������� ����������� ����� ��� ����� �������
    traverse(departmentTree, roomDepartments);
    traverse(buildingTree, roomDepartments);

    // ������� ���������
    for (const auto& room : roomDepartments) {
        if (room.second.size() > 1) {
            std::cout << room.first << std::endl;
        }
    }

    return 0;
}

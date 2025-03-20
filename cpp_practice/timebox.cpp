#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

struct Task {
    std::string name;
    int estimated_duration; // 見積もり時間（秒）
    int actual_duration;    // 実際にかかった時間（秒）
    bool is_done;           // タスク完了フラグ
};

const std::string FILENAME = "tasks.txt";
const int TASK_NAME_WIDTH = 20; // タスク名の最大表示幅

std::string formatTaskName(const std::string& name) {
    if (name.length() > TASK_NAME_WIDTH) {
        return name.substr(0, TASK_NAME_WIDTH +5) + "...";
    }
    return name;
}

void saveTasks(const std::vector<Task>& tasks) {
    std::ofstream file(FILENAME);
    for (const auto& task : tasks) {
        file << task.name << "," << task.estimated_duration << ","
             << task.actual_duration << "," << task.is_done << "\n";
    }
}

void loadTasks(std::vector<Task>& tasks) {
    std::ifstream file(FILENAME);
    if (!file) return; // ファイルが存在しない場合は何もしない
    
    tasks.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Task task;
        std::string is_done_str;
        
        std::getline(ss, task.name, ',');
        ss >> task.estimated_duration;
        ss.ignore();
        ss >> task.actual_duration;
        ss.ignore();
        ss >> task.is_done;
        
        tasks.push_back(task);
    }
}

void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
    } else {
        std::cout << "\n+----+----------------------+--------------+--------------+--------+" << std::endl;
        std::cout << "| #  | Task Name            | Estimated (s)| Actual (s)  | Status |" << std::endl;
        std::cout << "+----+----------------------+--------------+--------------+--------+" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "| " << std::setw(2) << i + 1 << " | "
                      << std::setw(TASK_NAME_WIDTH) << std::left << formatTaskName(tasks[i].name) << " | "
                      << std::setw(12) << std::right << tasks[i].estimated_duration << " | "
                      << std::setw(12) << (tasks[i].is_done ? std::to_string(tasks[i].actual_duration) : "--") << " | "
                      << (tasks[i].is_done ? " Done  |" : " InProgress |") << std::endl;
        }
        std::cout << "+----+----------------------+--------------+--------------+--------+\n";
    }
}

int main() {
    std::vector<Task> tasks;
    loadTasks(tasks);
    std::string command;
    
    while (true) {
        std::cout << "\nCommands: add | list | complete | exit" << std::endl;
        std::cout << "Enter command: ";
        std::cin >> command;
        
        if (command == "add") {
            Task task;
            std::cout << "Enter task name: ";
            std::cin >> std::ws;
            std::getline(std::cin, task.name);
            std::cout << "Enter estimated duration (seconds): ";
            std::cin >> task.estimated_duration;
            task.actual_duration = 0;
            task.is_done = false;
            tasks.push_back(task);
            saveTasks(tasks);
        } else if (command == "list") {
            listTasks(tasks);
        } else if (command == "complete") {
            int taskIndex;
            std::cout << "Enter task number to mark as complete: ";
            std::cin >> taskIndex;
            if (taskIndex > 0 && taskIndex <= tasks.size()) {
                std::cout << "Enter actual duration (seconds): ";
                std::cin >> tasks[taskIndex - 1].actual_duration;
                tasks[taskIndex - 1].is_done = true;
                std::cout << "Task marked as completed!" << std::endl;
                saveTasks(tasks);
            } else {
                std::cout << "Invalid task number." << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Use 'add', 'list', 'complete', or 'exit'." << std::endl;
        }
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <stdlib.h>

enum task
{
    none = 0,
    A = 2,
    B = 3,
    C = 4,
};
class Worker
{
    std::string nameWorker = "Worker name";
    char task = 0;
    friend class Manager;
    friend class CEO;
    Worker(std::string inNameWorker) : nameWorker(inNameWorker)
    {
        assert(inNameWorker != "");
        nameWorker = inNameWorker;
        true;
    }
};
class Manager
{
    std::string nameManager = "Manager name";
    std::vector<Worker> workers;
    friend class CEO;
    Manager(int inQuantityWorkers, std::string inNameManager) : nameManager(inNameManager)
    {
        for (int i = 0; i < inQuantityWorkers; i++)
        {
            std::string name = "Worker#" + std::to_string(i);
            workers.push_back(Worker(name));
        }
    }
};
class CEO
{
    std::string nameCEO = "CEO name";
    std::vector<Manager> managers;
    friend class Manager;

public:
    CEO()
    {
        std::cout << "Enter name CEO: ";
        std::cin >> nameCEO;
        std::cout << "Enter quantity comand: ";
        int inQuantityComand;
        std::cin >> inQuantityComand;
        for (int i = 0; i < inQuantityComand; i++)
        {
            std::cout << "Enter quantity workers in comand " << i + 1 << ":";
            int value;
            std::cin >> value;
            std::string name = "Manager#" + std::to_string(i);
            managers.push_back(Manager(value, name));
        }
    }
};

// Worker::Worker(std::string inNameWorker) : nameWorker(inNameWorker)
// {
//     assert(inNameWorker != "");
//     nameWorker = inNameWorker;
//     true;
// }
// Manager::Manager(int inQuantityWorkers, std::string inNameManager) : nameManager(inNameManager)
// {
//     for (int i = 0; i < inQuantityWorkers; i++)
//     {
//         std::string name = "Worker#" + std::to_string(i);
//         workers.push_back(Worker(name));
//     }
// }
// CEO::CEO()
// {
//     std::cout << "Enter name CEO: ";
//     std::string inNameCEO;
//     std::cin >> inNameCEO;
//     std::cout << "Enter quantity comand: ";
//     int inQuantityComand;
//     std::cin >> inQuantityComand;
//     for (int i = 0; i < inQuantityComand; i++)
//     {
//         std::cout << "Enter quantity workers in comand" << i + 1 << ":";
//         int value;
//         std::cin >> value;
//         std::string name = "Manager#" + std::to_string(i);
//         managers.push_back(Manager(value, name));
//     }
// }

int main()
{
    //     std::cout << "Enter name CEO: ";
    //     std::string sss;
    //     std::cin >> sss;
    CEO ceo = CEO();
}
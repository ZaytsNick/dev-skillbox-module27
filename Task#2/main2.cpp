#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <stdlib.h>

enum task
{
    none = 0,
    A = 1,
    B = 2,
    C = 3,
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
    int getCountComand()
    {
        return managers.size();
    }
    int getCountWorkers(int inI)
    {
        return managers[inI].workers.size();
    }
    void receivingTasks(int inTask, int inI)
    {
        for (int i = 0; i < managers[inI].workers.size(); i++)
        {
            if (managers[inI].workers[i].task == 0)
            {
                managers[inI].workers[i].task = rand() % 4 + 1;
                std::cout << "Worker: " << managers[inI].workers[i].nameWorker << " received task " << managers[inI].workers[i].task << std::endl;
                // i++;
            }
        }
    }
};

int main()
{
    CEO ceo = CEO();
    while (true)
    {
        for (int i = 0; i < ceo.getCountComand(); i++)
        {
            std::cout << "Enter value: ";
            int hash;
            std::cin >> hash;
            std::srand(hash + i);
            int tasksCount = rand() % (ceo.getCountWorkers(i) + 1);
            ceo.receivingTasks(tasksCount, i);
        }
    }
}
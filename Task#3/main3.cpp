#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <vector>
#include <map>

class Branch
{
    std::string nameElf = "None";
    Branch *parent = nullptr;
    std::vector<Branch> branch;

public:
    void setTree()
    {
        for (int i = 0; i < rand() % 5 + 3; i++)
        {
            std::cout << "Parent Branch #" << i + 1 << std::endl;
            Branch temp;
            // std::cout << "Enter name elf: ";
            temp.nameElf = std::to_string(i + 1);
            // std::cin >> temp.nameElf;
            temp.parent = this;
            branch.push_back(temp);
            for (int j = 0; j < rand() % 3 + 2; j++)
            {
                std::cout << "Child Branch #" << j + 1 << std::endl;
                Branch tmp;
                // std::cout << "Enter name elf: ";
                tmp.nameElf = std::to_string(i + 1) + std::to_string(j + 1);
                // std::cin >> tmp.nameElf;
                tmp.parent = &branch[i];
                branch[i].branch.push_back(tmp);
            }
        }
    }
    Branch getParentBranch(std::string searchName)
    {
        // Если это дерево
        if (parent == nullptr)
        {
            for (int i = 0; i < branch.size(); i++)
            {
                if (branch[i].nameElf == searchName)
                    return branch[i];
                else
                {
                    Branch temp = branch[i].getParentBranch(searchName);
                    if (temp.parent == branch[i].parent)
                        return branch[i];
                }
            }
        }
        // Если это средняя ветка
        else if (parent->parent == nullptr)
        {
            for (int i = 0; i < branch.size(); i++)
            {
                if (branch[i].nameElf == searchName)
                    return *this;
            }
            return branch[0];
        }
        return *this;
        // Если это маленькая ветка
        // return parent->getParentBranch();
    }
    int countNeighbours(Branch parentBranch)
    {
        assert(parentBranch.parent != nullptr);

        int count = -1;
        parentBranch.nameElf != "None" ? count++ : 0;
        for (int i = 0; i < parentBranch.branch.size(); i++)
        {
            parentBranch.branch[i].nameElf != "None" ? count++ : 0;
        }
        return count;
    }
};

int main()
{
    Branch tree;
    tree.setTree();

    std::string searchName;
    std::cout << "Enter search name: ";
    std::cin >> searchName;
    std::cout << "Count neighbours: " << tree.countNeighbours(tree.getParentBranch(searchName));
}

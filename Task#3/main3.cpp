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
    // Branch getParentBranch(Branch *parentBranch)
    // {
    //     if (parent == parentBranch)
    //         return *this;
    //     for (int i = 0; i < branch.size(); i++)
    //     {
    //         if (&branch[i] == parentBranch)
    //             return branch[i];
    //     }
    // }
    Branch searchElf(std::string searchingName)
    {
        if (parent == nullptr) // Если это дерево
        {
            for (int i = 0; i < branch.size(); i++)
            {
                if (branch[i].searchElf(searchingName) != nullptr)
                    return branch[i];
            }
        }
        else if (parent->parent == nullptr) // Если это средняя ветка
        {
            if (searchingName == nameElf)
                return *this;
            else
            {
                for (int i = 0; i < branch.size(); i++)
                {
                    if (branch[i].searchElf(searchingName) != nullptr)
                    {
                        return *this;
                    }
                    else
                        return nullptr;
                }
            }
        }
        else // Если это маленькая ветка
        {
            if (searchingName == nameElf)
                return;
            else
                return nullptr;
        }
    }
    int countNeighbours()
    {
        std::string search;
        std::cin >> search;
        Branch parentBranch;
        parentBranch = searchElf(search);
        int count = -1;
        parentBranch.nameElf != "None" ? count++ : 0;
        // std::cout << "parentBranch->branch.size()"; // parentBranch.nameElf;
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
    int count = tree.countNeighbours();
    std::cout << "Count neighbours: " << count;
    // tree.getTree();
}
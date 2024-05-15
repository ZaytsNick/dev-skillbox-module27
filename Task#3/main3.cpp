// #include <iostream>
// #include <vector>
// #include <map>

// class Tree
// {
//     std::vector<MainBranch> mainBranch(rand() % 6 + 3);
//     Tree()
//     {
//         for (int i = 0; i < mainBranch.size(); i++)
//         {
//             std::cout << "Enter name elf life in the house: ";
//             std::cin >> mainBranch.name;
//             for (int j = 0; j < mainBranch.childBranch.size(); j++)
//             {
//                 std::cout << "Enter name elf life in the house: ";
//                 std::cin >> mainBranch.childBranch.name;
//             }
//         }
//     }
// };
// class MainBranch
// {
// public:
//     std::string house = "None";
//     std::vector<ChildBranch> childBranch(rand() % 4 + 2);
//     friend class Tree
// };
// class ChildBranch
// {
// public:
//     std::string house = "None";
//     friend class MainBranch
// };
// int[2] threadSearch(std::string searchName, Tree tree[5])
// {
//     for (int i = 0; i < tree.size(); i++)
//     {
//         for (int j = 0; j < tree[i].size(); j++)
//         {
//             if (searchName == tree[i].mainBranch[j].house)
//             {
//             }
//         }
//     }
// }

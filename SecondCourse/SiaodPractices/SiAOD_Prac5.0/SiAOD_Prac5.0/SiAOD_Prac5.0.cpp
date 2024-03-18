#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

//----Struct of wordRecord----//
struct wordRecord
{
    char word[4];
    int amountOfEntry;

    wordRecord() {};
    wordRecord(std::string word, int outAmountOfEntry)
    {
        for(int i = 0; i < 4; i++)
        {
            this->word[i] = word[i];
        }
        this->amountOfEntry = outAmountOfEntry;
    }
};
//----Struct of binTree----//
struct binNode
{
    unsigned int key;
    std::streampos offset;
    binNode* leftNode;
    binNode* rightNode;

    binNode(unsigned int outKey, int currOffset)
    {
        offset = currOffset;
        key = outKey;
        leftNode = nullptr;
        rightNode = nullptr;
    }
    ~binNode() {};
};
//---Struct of binTree-----//
struct binTree
{
    binNode* root;

    binTree() { root = nullptr; }
    void insertNode(std::streampos currOffset, unsigned int outKey, binNode*& start)
    {
        if (start == nullptr) { start = new binNode(outKey, currOffset); }
        else if (start->key > outKey) { insertNode(currOffset, outKey, start->leftNode); }
        else { insertNode(currOffset, outKey, start->rightNode); }
        return;
    }
    binNode*& searchNode(unsigned int searchKey, binNode*& start)
    {
        if (start->key == searchKey) { return(start); }
        else if (start->key > searchKey) { searchNode(searchKey, start->leftNode); }
        else { searchNode(searchKey, start->rightNode); }
    }
    binNode* preDeleteNode(unsigned int deleteKey, binNode*& start)
    {
        if (start->leftNode == nullptr || start->rightNode == nullptr) return(nullptr);
        if (start->leftNode->key == deleteKey) return(start);
        if (start->rightNode->key == deleteKey) return(start);
        else if (start->key > deleteKey) { preDeleteNode(deleteKey, start->leftNode); }
        else { preDeleteNode(deleteKey, start->rightNode); }
    }
    void removeNode(unsigned int deleteKey)
    {
        binNode* preDelete = preDeleteNode(deleteKey, root);
        binNode* targetDelete = nullptr;
        if (preDelete == nullptr)
        {
            return;
        }
        //if target element is rightChild
        if (preDelete->rightNode->key == deleteKey)
        {
            targetDelete = preDelete->rightNode;
            //target element has only right child
            if (targetDelete->leftNode == nullptr)
            {
                preDelete->rightNode = targetDelete->rightNode;
                delete targetDelete;
                return;
            }
            //target element has only left child
            else if (targetDelete->rightNode == nullptr)
            {
                preDelete->rightNode = targetDelete->leftNode;
                delete targetDelete;
                return;
            }
            //target has both right and left childs
            else
            {
                preDelete->rightNode = targetDelete->rightNode;
                binNode* iterRightLeft = targetDelete->rightNode;
                while (iterRightLeft->leftNode != nullptr)
                {
                    iterRightLeft = iterRightLeft->leftNode;
                }
                iterRightLeft->leftNode = targetDelete->leftNode;
                delete targetDelete;
                return;
            }
        }
        else
        {
            targetDelete = preDelete->leftNode;
            //target element has only right child
            if (targetDelete->leftNode == nullptr)
            {
                preDelete->leftNode = targetDelete->rightNode;
                delete targetDelete;
                return;
            }
            //target element has only left child
            else if (targetDelete->rightNode == nullptr)
            {
                preDelete->leftNode = targetDelete->leftNode;
                delete targetDelete;
                return;
            }
            //target has both right and left childs
            else
            {
                preDelete->leftNode = targetDelete->rightNode;
                binNode* iterRightLeft = targetDelete->rightNode;
                while (iterRightLeft->leftNode != nullptr)
                {
                    iterRightLeft = iterRightLeft->leftNode;
                }
                iterRightLeft->leftNode = targetDelete->leftNode;
                delete targetDelete;
                return;
            }
        }
    }
    void showTree(binNode*& start, unsigned int level)
    {
        if (start != nullptr)
        {
            showTree(start->rightNode, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "   ";
            std::cout << "-->" << start->key << '_' << start->offset << '\n';
            showTree(start->leftNode, level + 1);
        }
    }
    ~binTree() {};
};

int main()
{
    unsigned short userChoise;
    binTree tree;
    do
    {
        std::cin >> userChoise;
        switch (userChoise)
        {
            case 0:
            {
                unsigned int amount;
                unsigned int pos;
                std::ofstream fileWriteBin("test.bin", std::ios::binary);
                std::cout << "ENter a,ount: \n";
                std::cin >> amount;
                for (int i = 0; i < amount; i++)
                {
                    wordRecord newWord("word", rand() % 300 + 1);
                    tree.insertNode(fileWriteBin.tellp(), newWord.amountOfEntry, tree.root);
                    fileWriteBin.write((char*)(&newWord), sizeof(wordRecord));
                }
                fileWriteBin.close();
                break;
            }
            case 1:
            {
                tree.showTree(tree.root, 0);
                break;
            }
            case 2:
            {
                unsigned int deleteKey;
                std::cin >> deleteKey;
                tree.removeNode(deleteKey);
                break;
            }
            case 3:
            {
                wordRecord check;
                std::ifstream fileReadBin("test.bin", std::ios::binary);
                unsigned int searchKey;
                std::cin >> searchKey;
                auto start = std::chrono::high_resolution_clock::now();
                int pos = tree.searchNode(searchKey, tree.root)->offset;
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                fileReadBin.seekg(pos);
                fileReadBin.read((char*)(&check), sizeof(wordRecord));
                std::cout << check.amountOfEntry;
            }
        }

    } while (userChoise == 0 || userChoise == 1 || userChoise == 2);
}
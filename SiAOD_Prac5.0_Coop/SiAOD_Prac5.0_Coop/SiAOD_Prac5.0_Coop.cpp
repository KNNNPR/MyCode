#include <iostream>

//----Struct of binTree----//
struct binNode
{
    unsigned int key;
    std::streampos offset;
    binNode* leftNode;
    binNode* rightNode;

    binNode(unsigned int outKey)
    {
        key = outKey;
        offset = -1;
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
    void insertNode(unsigned int outKey, binNode*& start)
    {
        if (start == nullptr) { start = new binNode(outKey); }
        else if (start->key > outKey) { insertNode(outKey, start->rightNode); }
        else{ insertNode(outKey, start->leftNode); }
        return;
    }
    binNode*& preDeleteNode(unsigned int deleteKey, binNode*& start)
    {
        if (start->leftNode != nullptr && start->leftNode->key == deleteKey) return(start);
        if (start->rightNode != nullptr && start->rightNode->key == deleteKey) return(start);
        else if (start->key > deleteKey) { preDeleteNode(deleteKey, start->rightNode); }
        else { preDeleteNode(deleteKey, start->leftNode); }
    }
    void removeNode(unsigned int deleteKey)
    {
        binNode*& start = preDeleteNode(deleteKey, root);
        binNode* toDelete = start;
        if (start->leftNode != nullptr) 
        {
            if(start->leftNode->key == deleteKey) toDelete = start->leftNode;
        }
        else {toDelete = start->rightNode; }
        if (toDelete->leftNode == nullptr )
        {
            if (toDelete == start->leftNode)
            {
                start->leftNode = toDelete->leftNode;
                delete toDelete;
                return;
            }
            start->rightNode = toDelete->rightNode;
            delete toDelete;
            return;
        }
        else if (toDelete->rightNode == nullptr)
        {
            if (toDelete = start->leftNode)
            {
                start->leftNode = toDelete->leftNode;
                delete toDelete;
                return;
            }
            start->rightNode = toDelete->rightNode;
            delete toDelete;
            return;
        }
        else
        {
            if (toDelete == start->rightNode)
            {
                start->rightNode = toDelete->leftNode;

                binNode* iterLeft = toDelete->leftNode;
                while (iterLeft->rightNode != nullptr) { iterLeft = iterLeft->rightNode; }
                iterLeft->rightNode = toDelete->rightNode;
                delete toDelete;
                return;
            }
            else
            {
                start->leftNode = toDelete->leftNode;

                binNode* iterLeft = toDelete->leftNode;
                while (iterLeft->rightNode != nullptr) { iterLeft = iterLeft->rightNode; }
                iterLeft->rightNode = toDelete->rightNode;
                delete toDelete;
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
            std::cout << "-->" << start->key << '\n';
            showTree(start->leftNode, level + 1);
        }
    }
    binNode*& searchNode(unsigned int searchKey, binNode*& start)
    {
        if (start->key == searchKey) { return(start); }
        else if (start->key > searchKey) { searchNode(searchKey, start->rightNode); }
        else { searchNode(searchKey, start->leftNode); }
    }

    ~binTree() {};
};

int main()
{
  
}
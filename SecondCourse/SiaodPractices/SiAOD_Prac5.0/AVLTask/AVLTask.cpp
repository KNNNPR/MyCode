#include <iostream>
#include <fstream>
#include <chrono>

static double inserts = 0;
static double rotates = 0;

struct wordRecord
{
    char word[4];
    int amountOfEntry;

    wordRecord() {};
    wordRecord(std::string word, int outAmountOfEntry)
    {
        for (int i = 0; i < 4; i++)
        {
            this->word[i] = word[i];
        }
        this->amountOfEntry = outAmountOfEntry;
    }
};
struct AVLNode
{
    unsigned int key;
    unsigned char height;
    std::streampos offset;
    AVLNode* leftNode;
    AVLNode* rightNode;

    AVLNode(unsigned int userKey, int currOffset)
    {
        offset = currOffset;
        key = userKey;
        leftNode = nullptr;
        rightNode = nullptr;
        height = 1;
    }
};
unsigned char getHeight(AVLNode* treeNode)
{
    if (treeNode == nullptr) return(0);
    return(treeNode->height);
}
int bfactor(AVLNode* treeNode)
{
    return(getHeight(treeNode->rightNode) - getHeight(treeNode->leftNode));
}
void fixHeight(AVLNode* treeNode)
{
    unsigned char leftHeight = getHeight(treeNode->leftNode);
    unsigned char rightHeight = getHeight(treeNode->rightNode);
    if (leftHeight > rightHeight) treeNode->height = leftHeight + 1;
    else treeNode->height = rightHeight + 1;
}
void showTree(AVLNode* start, unsigned int level)
{
    if (start != nullptr)
    {
        showTree(start->rightNode, level + 1);
        for (int i = 0; i < level; i++)
            std::cout << "   ";
        std::cout << "-->" << start->key << ' ' << start->offset << '\n';
        showTree(start->leftNode, level + 1);
    }
}
AVLNode* searchNode(int searchKey, AVLNode* start)
{
    if(start->key == searchKey) { return(start); }
    else if (start->key > searchKey) { searchNode(searchKey, start->leftNode); }
    else { searchNode(searchKey, start->rightNode); }
}
AVLNode* rotateRight(AVLNode* treeNode)
{
    rotates++;
    AVLNode* leftChild = treeNode->leftNode;
    treeNode->leftNode = leftChild->rightNode;
    leftChild->rightNode = treeNode;
    fixHeight(treeNode);
    fixHeight(leftChild);
    return (leftChild);
}
AVLNode* rotateLeft(AVLNode* treeNode)
{
    rotates++;
    AVLNode* rightChild = treeNode->rightNode;
    treeNode->rightNode = rightChild->leftNode;
    rightChild->leftNode = treeNode;
    fixHeight(treeNode);
    fixHeight(rightChild);
    return (rightChild);
}
AVLNode* balanceFunc(AVLNode* treeNode)
{
    fixHeight(treeNode);
    if (bfactor(treeNode) == 2)
    {
        if (bfactor(treeNode->rightNode) < 0)
            treeNode->rightNode = rotateRight(treeNode->rightNode);
        return rotateLeft(treeNode);
    }
    if (bfactor(treeNode) == -2)
    {
        if (bfactor(treeNode->leftNode) > 0)
            treeNode->leftNode = rotateLeft(treeNode->leftNode);
        return rotateRight(treeNode);
    }
    return (treeNode);
}
AVLNode* insertNode(AVLNode* treeNode, int key, int currOffset)
{
    if (!treeNode) return (new AVLNode(key, currOffset));
    if (key < treeNode->key) treeNode->leftNode = insertNode(treeNode->leftNode, key, currOffset);
    else treeNode->rightNode = insertNode(treeNode->rightNode, key, currOffset);
    return balanceFunc(treeNode);
}
AVLNode* findMin(AVLNode* treeNode)
{
    if (treeNode->leftNode == nullptr) return(treeNode);
    else return(findMin(treeNode->leftNode));
}
AVLNode* removeMin(AVLNode* treeNode)
{
    if (treeNode->leftNode == 0) return (treeNode->rightNode);
    treeNode->leftNode = removeMin(treeNode->leftNode);
    return (balanceFunc(treeNode));
}
AVLNode* removeNode(AVLNode* treeNode, int deleteKey)
{
    if (!treeNode) return (0);
    if (deleteKey < treeNode->key) treeNode->leftNode = removeNode(treeNode->leftNode, deleteKey);
    else if (deleteKey > treeNode->key) treeNode->rightNode = removeNode(treeNode->rightNode, deleteKey);
    else
    {
        AVLNode* l = treeNode->leftNode;
        AVLNode* r = treeNode->rightNode;
        delete treeNode;
        if (!r) return (l);
        AVLNode* min = findMin(r);
        min->rightNode = removeMin(r);
        min->leftNode = l;
        return (balanceFunc(min));
    }
    return (balanceFunc(treeNode));
}

int main()
{
    AVLNode* root = new AVLNode(0, 0);
    unsigned int amount;
    unsigned int pos;
    unsigned int userChoice;
    std::ofstream fileWriteBin("testTwo.bin", std::ios::binary);
    std::cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        wordRecord newWord("word", rand() % 300 + 1);
        if (i == 0) 
        {
            root = new AVLNode(newWord.amountOfEntry, fileWriteBin.tellp());
            inserts++;
        }
        else 
        {
            root = insertNode(root, newWord.amountOfEntry, fileWriteBin.tellp());
            inserts++;
        }
        fileWriteBin.write((char*)(&newWord), sizeof(wordRecord));
    }
    fileWriteBin.close();
    showTree(root, 0);
    do
    {
        std::cin >> userChoice;
        switch (userChoice)
        {
            case 1:
            {
                int deleteKey;
                std::cin >> deleteKey;
                root = removeNode(root, deleteKey);
                showTree(root, 0);
                break;
            }
            case 2:
            {
                wordRecord check;
                int pos;
                int key;
                std::cin >> key;
                pos = searchNode(key, root)->offset;
                std::ifstream fileReadBin("testTwo.bin", std::ios::binary);
                fileReadBin.seekg(pos);
                fileReadBin.read((char*)(&check), sizeof(wordRecord));
                std::cout << check.amountOfEntry << '\n';
                break;
            }
            case 3:
            {
                double coeff = rotates / inserts;
                std::cout << coeff << '\n';
                break;
            }
        }
    } while (userChoice == 1 || userChoice == 2 || userChoice == 3);
}
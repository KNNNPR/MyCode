#include <iostream>
#include <stack>

//----Func to classified digit----//
bool isFormula(char c)
{
    return((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
}
//----Func to classified operator----//
bool isOperator(char c)
{
    return(c == '+' || c == '-' || c == '*' || c == '/');
}
//----Func to get operation priority----//
int getPriority(char oper)
{
    switch (oper)
    {
    case '/':
    case '*':
    {
        return(3);
        break;
    }
    case '+':
    case '-':
    {
        return(2);
        break;
    }
    default:
    {
        return(0);
        break;
    }
    }
}
//----Stack component realisation----//
struct stackComponent
{
    char stackCompData;
    stackComponent* nextStackComponent;

    stackComponent(char userData)
    {
        this->stackCompData = userData;
        this->nextStackComponent = nullptr;
    }
};
//----Stack realisation by myself----//
struct stack
{
    stackComponent* top;

    stack()
    {
        top = nullptr;
    }
    char topElement()
    {
        return(top->stackCompData);
    }
    void push(char userData)
    {
        stackComponent* newComp = new stackComponent(userData);
        if (top == nullptr) { top = newComp; }
        else
        {
            newComp->nextStackComponent = top;
            top = newComp;
        }
    }
    void showStack()
    {
        if (top == nullptr) return;
        else
        {
            stackComponent* iter = top;
            while (iter != nullptr)
            {
                std::cout << iter->stackCompData << ' ';
                iter = iter->nextStackComponent;
            }
            std::cout << '\n';
        }
    }
    void pop()
    {
        stackComponent* deleteMark = top;
        top = top->nextStackComponent;
        delete deleteMark;
    }
    void clear()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
    bool isEmpty()
    {
        if (top == nullptr) return(true);
        return(false);
    }
};
//----Node of tree structure----//
struct node
{
    char data;
    node* leftNodePtr;
    node* rightNodePtr;

    node(char userData)
    {
        this->data = userData;
        this->leftNodePtr = nullptr;
        this->rightNodePtr = nullptr;
    }
};
//----Func to print tree in postfix form----//
void postfixPrint(node* root)
{
    if (root == nullptr) 
    {
        return;
    }
    postfixPrint(root->leftNodePtr);
    postfixPrint(root->rightNodePtr);
    std::cout << root->data;
}
//----Func to print postfix expressionTree----//
node* buildExpressionTree(char userInput[])
{
    std::string postfixString = userInput;
    std::stack<node*> s;
    for (char c : postfixString)
    {
        if (isOperator(c))
        {
            node* x = s.top();
            s.pop();
            node* y = s.top();
            s.pop();
            node* a = new node(c);
            a->leftNodePtr = y;
            a->rightNodePtr = x;
            s.push(a);
        }
        else {
            s.push(new node(c));
        }
    }
    return s.top();
}
//----Func to convert infix to postfix----//
void convertToPostfix(std::string infixString, char postfixString [])
{
    unsigned int formulaCounter = 0;
    unsigned int postCounter = 0;
    char formulaElement;
    stack postfixHelp;
    while (formulaCounter < infixString.length())
    {
        formulaElement = infixString[formulaCounter];
        if (formulaElement == '(')
        {
            postfixHelp.push(formulaElement);
            formulaCounter++;
            continue;
        }
        if (formulaElement == ')')
        {
            while (!postfixHelp.isEmpty() && postfixHelp.topElement() != '(')
            {
                postfixString[postCounter++] = postfixHelp.topElement();
                postfixHelp.pop();
            }
            if (!postfixHelp.isEmpty())
            {
                postfixHelp.pop();
            }
            formulaCounter++;
            continue;
        }
        if (getPriority(formulaElement) == 0)
        {
            postfixString[postCounter++] = formulaElement;
        }
        else
        {
            if (postfixHelp.isEmpty())
            {
                postfixHelp.push(formulaElement);
            }
            else
            {
                while (!postfixHelp.isEmpty() && postfixHelp.topElement() != '(' && getPriority(formulaElement) <= getPriority(postfixHelp.topElement()))
                {
                    postfixString[postCounter++] = postfixHelp.topElement();
                    postfixHelp.pop();
                }
                postfixHelp.push(formulaElement);
            }
        }
        formulaCounter++;
    }
    while (!postfixHelp.isEmpty())
    {
        postfixString[postCounter++] = postfixHelp.topElement();
        postfixHelp.pop();
    }
    postfixString[postCounter] = '\0';
}
//----Function to calculate lefttree expression----//
int calculateLeftSubtree(node* root) 
{
    if (isOperator(root->data))
    {
        int leftValue = calculateLeftSubtree(root->leftNodePtr);
        int rightValue = calculateLeftSubtree(root->rightNodePtr);
        switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        default:
            return 0;
        }
    }
    else 
    {
        return root->data - '0';
    }
}
//----Func to count amount of modes in level----//
int countOnLayer(node* root, int targetLayer, int curLayer)
{
    if (curLayer == targetLayer) 
    {
        if (root == nullptr) 
        {
            return 0;
        }
        return 1;
    }

    return countOnLayer(root->leftNodePtr, targetLayer, curLayer + 1) + countOnLayer(root->rightNodePtr, targetLayer, curLayer + 1);
}
//----Func to show prefix form of left subtree----//
std::string prefixPrintLeftSubtree(node* root, std::string ans)
{
    if (root->leftNodePtr == nullptr)return(root->data + ans);
    return root-> data + prefixPrintLeftSubtree(root->leftNodePtr, ans) + prefixPrintLeftSubtree(root->rightNodePtr, ans);
}

int main()
{
    std::cout << "//---------EXPRESSION TREE TASKVAR NUMBER 17---------\\ \n";
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "Enter the formula. Enter symbols: (), +-*/, a,bc..., 123..., but no ' ' \n";
    std::cout << "--->Your formula: ";
    std::string formula;
    node* expTree = nullptr;
    std::cin >> formula;
    char* postfixFormula = (char*)malloc(sizeof(char) * formula.length());
    convertToPostfix(formula, postfixFormula);
    expTree = buildExpressionTree(postfixFormula);
    std::cout << "Expression tree in postfixForm  ";
    postfixPrint(expTree);
    std::cout << '\n';
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "Value of left subtree expression " << calculateLeftSubtree(expTree->leftNodePtr) << '\n';
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "Amount of nodes on 2 level " << countOnLayer(expTree, 2, 0) << '\n';
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "Left tree in prefix form " << prefixPrintLeftSubtree(expTree->leftNodePtr, "") << '\n';
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "//---------EXIT OF THE PROGRAMM---------\\ \n";
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "//----------------------------------------------\\ \n";
    std::cout << "//----------------------------------------------\\ \n";
}
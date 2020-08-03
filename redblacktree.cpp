#include "redblacktree.h"
#include <iostream>
#include <queue>
#include <string>

RedBlackTree::RedBlackTree()
{

}

RedBlackTree::~RedBlackTree()
{
    cleanTree();
}

void RedBlackTree::cleanTree()
{
    if (root != nullptr)
    {
        root->dealockSubTree();
        delete root;
        root = nullptr;
    }
}

bool RedBlackTree::isTheRoot(NodeOfRedBlackTree* node)
{
    return node->father == nullptr;
}

NodeOfRedBlackTree* RedBlackTree::fatherOfNodeHasSibling(NodeOfRedBlackTree* node)
{
    if (node == nullptr || node->father == nullptr)
        return nullptr;

    NodeOfRedBlackTree* father = node->father;

    if (father->father->right == father) //o nó é o da direita
        return father->father->left; //retona esquerda
    else  //o nó é o da esquerda
        return father->father->right; //retorna direita
}

void RedBlackTree::check(NodeOfRedBlackTree* node)
{
    if (node->father->color == RedBlackTreeColor::RedBlackTreeColorBLACK)
        return;

    //Obter a cor do irmão do pai
    NodeOfRedBlackTree* siblingOfFather = fatherOfNodeHasSibling(node);

    //Analisar esta cor
    if (siblingOfFather == nullptr || siblingOfFather->color == RedBlackTreeColor::RedBlackTreeColorBLACK)
    {
        //Atualizar alturas da arvore
        updateHeightOfFullTree();
        //Faz rotação
        RotationType rotationType =
                RedBlackTree::checkTheNeedAndMakeRotation(node->father->father);

        //Atribui novas cores (de acordo com o tipo de rotação)
        if (rotationType != RotationType::None)
        {
            if (rotationType == RotationType::SimpleRotationToLeft)
            {
                node->color = RedBlackTreeColor::RedBlackTreeColorRED;
                node->father->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
                node->father->left->color = RedBlackTreeColor::RedBlackTreeColorRED;
            }
            else if (rotationType == RotationType::SimpleRotationToRight)
            {
                node->color = RedBlackTreeColor::RedBlackTreeColorRED;
                node->father->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
                node->father->right->color = RedBlackTreeColor::RedBlackTreeColorRED;
            }
            else if (rotationType == RotationType::DoubleRotationToLeft ||
                     rotationType == RotationType::DoubleRotationToRight)
            {
                node->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
                node->left->color = RedBlackTreeColor::RedBlackTreeColorRED;
                node->right->color = RedBlackTreeColor::RedBlackTreeColorRED;
            }
        }
    }
    else if (siblingOfFather != nullptr &&
             siblingOfFather->color == RedBlackTreeColor::RedBlackTreeColorRED)
    {
        //Atribuir novas cores ao pai e sibling of pai
        changeColor(node->father);
        changeColor(siblingOfFather);

        if (node->father->father != root) //Checa se o pai do pai de node é o root
        {
            //Se não for, atribui nova cor a ele e o checa
            changeColor(node->father->father);

            check(node->father->father);
        }
    }
}

void RedBlackTree::changeColor(NodeOfRedBlackTree* node)
{
    if (node->color == RedBlackTreeColor::RedBlackTreeColorRED)
        node->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
    else
        node->color = RedBlackTreeColor::RedBlackTreeColorRED;
}

bool RedBlackTree::insertInterface(int data)
{
    NodeOfRedBlackTree* inserted = insert(data);

    if (inserted != nullptr)
    {
        if (root == inserted)
        {
            inserted->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
        }
        else
        {
            inserted->color = RedBlackTreeColor::RedBlackTreeColorRED;

            check(inserted);
        }

        return true;
    }
    else
    {
        return false;
    }
}

NodeOfRedBlackTree* RedBlackTree::insert(int data)
{
    struct NodeOfRedBlackTree* t = new NodeOfRedBlackTree(data, nullptr);
    if (root == nullptr)
    {
        root = t;
    }
    else
    {
        struct NodeOfRedBlackTree* tmp = root;
        while(true)
        {
            if (data < tmp->data) //go to left
            {
                if (tmp->left == nullptr)
                {
                    tmp->left = t;
                    t->father = tmp;
                    break;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
            else if (data > tmp->data)  //go to right
            {
                if (tmp->right == nullptr)
                {
                    tmp->right = t;
                    t->father = tmp;
                    break;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            else
            {
                delete t;
                t = nullptr;
                return nullptr;
            }
        }
    }

    return t;
}

//done in a second case
NodeOfRedBlackTree* RedBlackTree::getInOrderPredecessor(NodeOfRedBlackTree* n)
{
	if (n == nullptr || n->left == nullptr)
		return nullptr;

	NodeOfRedBlackTree* tmp = n->left;
	if (tmp->right != nullptr)
		tmp = tmp->right;

	return tmp;
}

NodeOfRedBlackTree* RedBlackTree::getInOrderSucessor(NodeOfRedBlackTree* n)
{
    if (n == nullptr || n->right == nullptr)
        return nullptr;

    NodeOfRedBlackTree* tmp = n->right;
    if (tmp->left != nullptr)
        tmp = tmp->left;

    return tmp;
}

NodeOfRedBlackTree* RedBlackTree::getFatherOfPredecessor(NodeOfRedBlackTree* n)
{
    if (n->left->right == nullptr)
        return n;

    NodeOfRedBlackTree* temp = n->left;

    while (temp->right->right != nullptr)
        temp = temp->right;
    return temp;
}

NodeOfRedBlackTree* RedBlackTree::remove(NodeOfRedBlackTree* toRemove)
{
	if (toRemove == nullptr)
		return nullptr;

	//Obter sucessor em ordem
	NodeOfRedBlackTree* sucessorNode = getInOrderSucessor(toRemove);
	if (sucessorNode != nullptr)
	{
		int dataBackup = toRemove->data;
		toRemove->data = sucessorNode->data;
		sucessorNode->data = dataBackup;

		if (sucessorNode->right == nullptr)
		{
			//Aqui chama método que analisa em qual caso o remove entra
			removeSwitchRedBlack(sucessorNode);
			return sucessorNode;
		}
		else
		{
			return remove(sucessorNode);
		}
	}
	else
	{
		//Obter predecessor em ordem
		NodeOfRedBlackTree* predecessorNode = getInOrderPredecessor(toRemove);
		if (predecessorNode != nullptr)
		{
			int dataBackup = toRemove->data;
			toRemove->data = predecessorNode->data;
			predecessorNode->data = dataBackup;

			if (predecessorNode->left == nullptr)
			{
				//Aqui chama método que analisa em qual caso o remove entra
				removeSwitchRedBlack(predecessorNode);
				return predecessorNode;
			}
			else
			{
				return remove(predecessorNode);
			}
		}
		else
		{
			//Aqui chama método que analisa em qual caso o remove entra
			removeSwitchRedBlack(toRemove);

			return toRemove;
		}
	}
}

NodeOfRedBlackTree* RedBlackTree::removeInterface(int data)
{
    NodeOfRedBlackTree* nodeOfData = search(data);

	return remove(nodeOfData);
}

void RedBlackTree::replacePointerInFather
(
    NodeOfRedBlackTree* father,
    NodeOfRedBlackTree* oldSon,
    NodeOfRedBlackTree* newPointerSon
)
{
    if (father->left == oldSon)
        father->left = newPointerSon;
    else if (father->right == oldSon)
        father->right = newPointerSon;
}

void RedBlackTree::removeSwitchRedBlack(NodeOfRedBlackTree* nodeToRemove)
{
    //Como o nó a ser removido é o menor da subarvore, ele não tem left

    //case 1
    if (nodeToRemove->color == RedBlackTreeColor::RedBlackTreeColorRED)
    {
        //parece que nó vermelho a ser removido não tem filho leaf right
        //Altera apenas no pai o ponteiro para nulo (estou colocando right)
        replacePointerInFather
        (
            nodeToRemove->father, nodeToRemove, nodeToRemove->right
        );
    }
    else if (nodeToRemove->color == RedBlackTreeColor::RedBlackTreeColorBLACK)
    {
        if (nodeToRemove->left == nullptr && nodeToRemove->right == nullptr)
        {
            //surge double black
            NodeOfRedBlackTree* doubleBlackNode = new NodeOfRedBlackTree(-999, nodeToRemove->father);
            doubleBlackNode->color = RedBlackTreeColor::RedBlackTreeColorDOUBLEBLACK;
            replacePointerInFather
            (
                nodeToRemove->father, nodeToRemove, doubleBlackNode
            );

            //se foi produzido doubleblack, chama removeDoubleBlackSituation
            removeDoubleBlackSituation(doubleBlackNode);
        }
    }
}

void RedBlackTree::removeDoubleBlackSituation(NodeOfRedBlackTree* doubleBlackNode)
{
    //If case 2
    if (doubleBlackNode->father == nullptr) //root
    {
        doubleBlackNode->color = RedBlackTreeColorBLACK;
        //That is all
        return;
    }

    //Get brother reference
    NodeOfRedBlackTree* sibling = getBrotherOfNode(doubleBlackNode->father, doubleBlackNode);

    //Get left child color of brother
    RedBlackTreeColor colorOfLeftChildOfSibling = RedBlackTreeColor::RedBlackTreeColorBLACK;
    if (sibling->left != nullptr)
        colorOfLeftChildOfSibling = sibling->left->color;
    //Get right child of brother
    RedBlackTreeColor colorOfRightChildOfSibling = RedBlackTreeColor::RedBlackTreeColorBLACK;
    if (sibling->right != nullptr)
        colorOfRightChildOfSibling = sibling->right->color;

    //If case 3
    if (sibling->color == RedBlackTreeColor::RedBlackTreeColorBLACK &&
        colorOfLeftChildOfSibling == RedBlackTreeColor::RedBlackTreeColorBLACK &&
        colorOfRightChildOfSibling == RedBlackTreeColor::RedBlackTreeColorBLACK)
    {
        //remover pode ser só tirar o double e colocar um black
        if (doubleBlackNode->data == -999)
        {
            replacePointerInFather
            (
                doubleBlackNode->father, doubleBlackNode, nullptr
            );
        }
        else
            doubleBlackNode->color = RedBlackTreeColorBLACK;

        if (doubleBlackNode->father->color == RedBlackTreeColorRED)
            doubleBlackNode->father->color = RedBlackTreeColorBLACK;
        else if (doubleBlackNode->father->color == RedBlackTreeColorBLACK)
            doubleBlackNode->father->color = RedBlackTreeColorDOUBLEBLACK;

        sibling->color = RedBlackTreeColorRED;

        if (doubleBlackNode->father->color == RedBlackTreeColorDOUBLEBLACK)
        {
            //se foi produzido doubleblack, chama removeDoubleBlackSituation
            removeDoubleBlackSituation(doubleBlackNode->father);
        }

        if (doubleBlackNode->data == -999)
            delete  doubleBlackNode;

        //That is all
        return;
    }

    //If case 4
    if (sibling->color == RedBlackTreeColor::RedBlackTreeColorRED)
    {
        swapColors(doubleBlackNode->father, sibling);

        //Faz simple rotação de pai na direção de db
        NodeOfRedBlackTree* father = doubleBlackNode->father;
        NodeOfRedBlackTree* grandParentBackup = father->father;
        if (doubleBlackNode == father->left)
        {
            //rotaciona para a esquerda
            NodeOfRedBlackTree* leftBackup = sibling->left;
            sibling->left = father;
            father->father = sibling; //pai
            father->right = leftBackup;
            leftBackup->father = father; //pai
            sibling->father = grandParentBackup;

            //todo: check if root need to be changed
            if (grandParentBackup != nullptr)
            {
                replacePointerInFather
                (
                    grandParentBackup, father, sibling
                );
            }

            removeDoubleBlackSituation(doubleBlackNode);
        }
        else
        {
            //rotaciona para a direita
            NodeOfRedBlackTree* rightBackup = sibling->right;
            sibling->right = father;
            father->father = sibling; //pai
            father->left = rightBackup;
            rightBackup->father = father; //pai
            sibling->father = grandParentBackup;

            //todo: check if root need to be changed
            if (grandParentBackup != nullptr)
            {
                replacePointerInFather
                (
                    grandParentBackup, father, sibling
                );
            }

            removeDoubleBlackSituation(doubleBlackNode);
        }

        //That is all
        return;
    }

    NodeOfRedBlackTree* closerNode = getCloserChildOfDoubleBlackNode(sibling);
    NodeOfRedBlackTree* furtherNode = getFurtherChildOfDoubleBlackNode(sibling);
    RedBlackTreeColor colorOfCloserNode = RedBlackTreeColor::RedBlackTreeColorBLACK; //o default é não existe
    RedBlackTreeColor colorOfFurtherNode = RedBlackTreeColor::RedBlackTreeColorBLACK; //o default é não existe

    if (closerNode != nullptr)
        colorOfCloserNode = closerNode->color;
    if (furtherNode != nullptr)
        colorOfFurtherNode = furtherNode->color;

    //If case 5
    if (sibling->color == RedBlackTreeColor::RedBlackTreeColorBLACK &&
        colorOfFurtherNode == RedBlackTreeColor::RedBlackTreeColorBLACK &&
        colorOfCloserNode == RedBlackTreeColor::RedBlackTreeColorRED)
    {
        swapColors(sibling, closerNode);

        //rotacionar em direção oposta a db
        if (furtherNode == sibling->right)
        {
            //rotacionar para a direita o sibling
            NodeOfRedBlackTree* fatherOfSibling = sibling->father;
            NodeOfRedBlackTree* leftChildOfSibling = sibling->left;
            NodeOfRedBlackTree* rightOfLeftNode = leftChildOfSibling->right;
            leftChildOfSibling->right = sibling;
            sibling->father = leftChildOfSibling; //pai
            sibling->left = rightOfLeftNode;
            rightOfLeftNode->father = sibling; //pai
            closerNode->father = fatherOfSibling; //pai
            replacePointerInFather
            (
                fatherOfSibling, sibling, closerNode
            );

            //irá chamar o caso 6
            removeDoubleBlackSituation(doubleBlackNode);
        }
        else
        {
            //rotacionar para a esquerda o sibling
            NodeOfRedBlackTree* fatherOfSibling = sibling->father;
            NodeOfRedBlackTree* rightChildOfSibling = sibling->right;
            NodeOfRedBlackTree* leftOfRightNode = rightChildOfSibling->left;
            rightChildOfSibling->left = sibling;
            sibling->father = rightChildOfSibling; //pai
            sibling->right = leftOfRightNode;
            leftOfRightNode->father = sibling; //pai
            closerNode->father = fatherOfSibling; //pai
            replacePointerInFather
            (
                fatherOfSibling, sibling, closerNode
            );

            //irá chamar o caso 6
            removeDoubleBlackSituation(doubleBlackNode);
        }

        //That is all
        return;
    }

    //If case 6
    if (sibling->color == RedBlackTreeColor::RedBlackTreeColorBLACK &&
            colorOfFurtherNode == RedBlackTreeColor::RedBlackTreeColorRED)
    {
        //passo 6 só dará certo se os pais estiverem corretos
        swapColors(doubleBlackNode->father, sibling);

        //rotação do pai
        NodeOfRedBlackTree* father = doubleBlackNode->father;
        if (doubleBlackNode == father->left)
        {
            //rotaciona pai para a esquerda
            if (father->father == nullptr) //é o root
            {
                root = sibling;
                NodeOfRedBlackTree* backupSiblingLeft = sibling->left;
                sibling->left = father;
                father->father = sibling; //pai
                father->right = backupSiblingLeft;
                backupSiblingLeft->father = father; //pai
            }
            else
            {
                NodeOfRedBlackTree* grandParent = father->father;
                sibling->father = grandParent;
                //alterar em grandparent, father para sibling
                replacePointerInFather
                (
                    grandParent, father, sibling
                );

                NodeOfRedBlackTree* backupSiblingLeft = sibling->left;
                sibling->left = father;
                father->father = sibling; //pai
                father->right = backupSiblingLeft;
                backupSiblingLeft->father = father; //pai
            }
        }
        else
        {
            //rotaciona pai para a direita
            if (father->father == nullptr) //é o root
            {
                root = sibling;
                NodeOfRedBlackTree* backupSiblingRight = sibling->right;
                sibling->right = father;
                father->father = sibling; //pai
                father->left = backupSiblingRight;
                backupSiblingRight->father = father; //pai
            }
            else
            {
                NodeOfRedBlackTree* grandParent = father->father;
                sibling->father = grandParent;
                //alterar em grandparent, father para sibling
                replacePointerInFather
                (
                    grandParent, father, sibling
                );

                NodeOfRedBlackTree* backupSiblingRight = sibling->right;
                sibling->right = father;
                father->father = sibling; //pai
                father->left = backupSiblingRight;
                backupSiblingRight->father = father; //pai
            }
        }

        //remove doubleblack
        //remover pode ser só tirar o double e colocar um black
        if (doubleBlackNode->data == -999)
        {
            replacePointerInFather
            (
                doubleBlackNode->father, doubleBlackNode, nullptr
            );
        }
        else
            doubleBlackNode->color = RedBlackTreeColorBLACK;

        //altera cor de red child para black
        furtherNode->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
    }
}

void RedBlackTree::swapColors(NodeOfRedBlackTree* one, NodeOfRedBlackTree* two)
{
    RedBlackTreeColor tmp = one->color;
    one->color = two->color;
    two->color = tmp;
}

NodeOfRedBlackTree* RedBlackTree::getRoot()
{
    return root;
}

void RedBlackTree::setAsRoot(NodeOfRedBlackTree *node)
{
    this->root = node;
}

NodeOfRedBlackTree* RedBlackTree::getFurtherChildOfDoubleBlackNode
(
    NodeOfRedBlackTree* sibling
)
{
    NodeOfRedBlackTree* father = sibling->father;
    if (father->right == sibling)
        return sibling->right;
    else
        return sibling->left;
}

NodeOfRedBlackTree* RedBlackTree::getCloserChildOfDoubleBlackNode
(
    NodeOfRedBlackTree* sibling
)
{
    NodeOfRedBlackTree* father = sibling->father;
    if (father->right == sibling)
        return sibling->left;
    else
        return sibling->right;
}

NodeOfRedBlackTree* RedBlackTree::getBrotherOfNode
(
    NodeOfRedBlackTree* father,
    NodeOfRedBlackTree* firstNode
)
{
    if (father->left == firstNode)
        return father->right;
    else
        return father->left;
}

//Using in order sucessor
RemoveReturnRB RedBlackTree::remove(int data)
{
    RemoveReturnRB ret;

    if (root == nullptr)
    {
        ret.toRemoveNode = nullptr;
        ret.newNodeInthePosition = nullptr;
        return ret;
    }

    if (root->data == data)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            ret.toRemoveNode = root;
            ret.newNodeInthePosition = nullptr;
            return ret;
        }
        if (root->left == nullptr)
        {
            ret.toRemoveNode = root;

            root = root->right;
            if (root != nullptr)
                root->father = nullptr;

            ret.newNodeInthePosition = root;
            return ret;
        }
        else if (root->right == nullptr)
        {
            ret.toRemoveNode = root;

            root = root->left;
            if (root != nullptr)
                root->father = nullptr;

            ret.newNodeInthePosition = root;
            return ret;
        }
        else
        {
            struct NodeOfRedBlackTree* backup = root;
            if (root->left->right == nullptr)
            {
                root = root->left;
                root->right = backup->right;

                ret.toRemoveNode = backup;
                ret.newNodeInthePosition = root;
                return ret;
            }
            else
            {
                NodeOfRedBlackTree* fatherOfPred = getFatherOfPredecessor(root);
                root = fatherOfPred->right;
                fatherOfPred->right = root->left;
                root->left = backup->left;
                root->right = backup->right;

                ret.toRemoveNode = backup;
                ret.newNodeInthePosition = root;
                return ret;
            }
        }
    }
    else // o root não é o dado
    {
        struct NodeOfRedBlackTree* tmp = root;
        while (tmp != nullptr)
        {
            if (data < tmp->data) //pesquisar no ramo esquerdo
            {
                if (tmp->left == nullptr)
                {
                    ret.toRemoveNode = nullptr;
                    ret.newNodeInthePosition = nullptr;
                    return ret;
                }
                if (tmp->left->data == data)
                {
                    struct NodeOfRedBlackTree* father = tmp;
                    struct NodeOfRedBlackTree* toRemove = tmp->left;
                    struct NodeOfRedBlackTree* left = toRemove->left;
                    struct NodeOfRedBlackTree* right = toRemove->right;

                    if (left == nullptr && right == nullptr)
                    {
                        tmp->left = nullptr;
                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = father;
                        return ret;
                    }
                    else if (left == nullptr)
                    {
                        father->left = right;
                        if (right != nullptr)
                            right->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = right;
                        return ret;
                    }
                    else if (right == nullptr)
                    {
                        father->left = left;
                        if (left != nullptr)
                            left->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = left;
                        return ret;
                    }
                    else
                    {
                        NodeOfRedBlackTree* fatherOfPred = getFatherOfPredecessor(toRemove);
                        NodeOfRedBlackTree* newNode = fatherOfPred->right;
                        fatherOfPred->right = newNode->left;
                        father->left = newNode;
                        newNode->left = left;
                        newNode->right = right;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = newNode;
                        return ret;
                    }
                }
                else
                    tmp = tmp->left;
            }
            else //pesquisar no ramo direito
            {
                if (tmp->right == nullptr)
                {
                    ret.toRemoveNode = nullptr;
                    ret.newNodeInthePosition = nullptr;
                    return ret;
                }
                if (tmp->right->data == data)
                {
                    struct NodeOfRedBlackTree* father = tmp;
                    struct NodeOfRedBlackTree* toRemove = tmp->right;
                    struct NodeOfRedBlackTree* left = toRemove->left;
                    struct NodeOfRedBlackTree* right = toRemove->right;

                    if (left == nullptr && right == nullptr)
                    {
                        tmp->right = nullptr;
                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = father;
                        return ret;
                    }
                    if (left == nullptr)
                    {
                        father->right = right;
                        if (right != nullptr)
                            right->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = right;
                        return ret;
                    }
                    else if (right == nullptr)
                    {
                        father->right = left;
                        if (left != nullptr)
                            left->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = left;
                        return ret;
                    }
                    else
                    {
                        NodeOfRedBlackTree* fatherOfPred = getFatherOfPredecessor(toRemove);
                        NodeOfRedBlackTree* newNode = fatherOfPred->right;
                        fatherOfPred->right = newNode->left;
                        father->right = newNode;
                        newNode->left = left;
                        newNode->right = right;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = newNode;
                        return ret;
                    }
                }
                else
                    tmp = tmp->right;
            }

        }
    }

    ret.toRemoveNode = nullptr;
    ret.newNodeInthePosition = nullptr;
    return ret;
}

NodeOfRedBlackTree* RedBlackTree::search(int data)
{
    struct NodeOfRedBlackTree* tmp = root;

    while(tmp != nullptr)
    {
        if (tmp->data == data)
            return tmp;
        else
        {
            if (data < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
    }

    return nullptr;
}

const std::string RedBlackTree::gitDotFileMode2()
{
    std::string textToFile = "digraph g{";
    textToFile += "ordering=out;";

    if (root == nullptr)
    {
        textToFile += "NULL;Root -> NULL;";
    }
    else
    {
        int count = 0;
        exibirSubArvore2(nullptr, true, root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string RedBlackTree::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";
    textToFile += "ordering=out;";
    textToFile += "node [margin=0 fontcolor=white fontsize=32 width=0.5 shape=circle style=filled];";

    std::string links;
    std::string nodeDefs;

    if (root == nullptr)
    {
        textToFile += "NULL [ label=\"NULL\" fontcolor=white shape=rect fillcolor=black];Root -> NULL;";
    }
    else
    {
        int count = 0;
        textToFile += "Root->"+std::to_string(root->data)+";";
        exibirSubArvore1(root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string RedBlackTree::preOrder()
{
    std::string content;
    preOrder(root, content);
    return content;
}

const std::string RedBlackTree::inOrder()
{
    std::string content;
    inOrder(root, content);
    return content;
}

const std::string RedBlackTree::posOrder()
{
    std::string content;
    posOrder(root, content);
    return content;
}

const std::string RedBlackTree::InLevelOrder()
{
    std::string content;

    std::queue<NodeOfRedBlackTree*> queue;

    if (root != nullptr)
        queue.push(root);

    NodeOfRedBlackTree* node = nullptr;
    while(queue.size() > 0)
    {
        NodeOfRedBlackTree* node = queue.front(); //acessa o primeiro
        queue.pop(); //remove o primeiro

        content += std::to_string(node->data)+" ";

        if (node->left != nullptr)
            queue.push(node->left);

        if (node->right != nullptr)
            queue.push(node->right);
    }

    return content;
}

std::vector<NodeOfRedBlackTree*> RedBlackTree::inLevelOrderNodes()
{
    std::vector<NodeOfRedBlackTree*> nodes;
    std::queue<NodeOfRedBlackTree*> queue;

    if (root != nullptr)
        queue.push(root);

    NodeOfRedBlackTree* node = nullptr;
    while(queue.size() > 0)
    {
        NodeOfRedBlackTree* node = queue.front(); //acessa o primeiro
        queue.pop(); //remove o primeiro

        nodes.push_back(node);

        if (node->left != nullptr)
            queue.push(node->left);

        if (node->right != nullptr)
            queue.push(node->right);
    }

    return nodes;
}

void RedBlackTree::preOrder(struct NodeOfRedBlackTree* node, std::string& content)
{
    if (node != nullptr)
    {
        content += std::to_string(node->data) + " ";
        preOrder(node->left, content);
        preOrder(node->right, content);
    }
}
void RedBlackTree::inOrder(struct NodeOfRedBlackTree* node, std::string& content)
{
    if (node != nullptr)
    {
        inOrder(node->left, content);
        content += std::to_string(node->data) + " ";
        inOrder(node->right, content);
    }
}
void RedBlackTree::posOrder(struct NodeOfRedBlackTree* node, std::string& content)
{
    if (node != nullptr)
    {
        posOrder(node->left, content);
        posOrder(node->right, content);
        content += std::to_string(node->data) + " ";
    }
}

void RedBlackTree::exibirSubArvore1
(
    struct NodeOfRedBlackTree* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data);
    if (n->color == RedBlackTreeColor::RedBlackTreeColorRED)
        content += "[fillcolor=red];";
    else if (n->color == RedBlackTreeColor::RedBlackTreeColorBLACK)
        content += "[fillcolor=black];";
    else //double black
        content += "[fillcolor=black shape=doublecircle];";

    if (n->left == nullptr)
    {
        content +="NULL"+std::to_string(count)+" [ label=\"NULL\" fontcolor=white shape=rect fillcolor=black];";
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->left->data)+";";
        exibirSubArvore1
        (
            n->left,
            content,
            count
        );
    }

    if (n->right == nullptr)
    {
        content +="NULL"+std::to_string(count)+" [ fontcolor=white label=\"NULL\" shape=rect fillcolor=black];";
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->right->data)+";";
        exibirSubArvore1
        (
            n->right,
            content,
            count
        );
    }
}

void RedBlackTree::exibirSubArvore2
(
    struct NodeOfRedBlackTree* father,
    bool isLeftSon,
    struct NodeOfRedBlackTree* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data);
    content += "[";
    content += "    shape = none";
    content += "    label = <<table border=\"0\" cellspacing=\"0\">";
    content += "    <tr>";
    content += "    <td port=\"port1\" border=\"1\">Left</td>";
    if (n->color == RedBlackTreeColor::RedBlackTreeColorBLACK)
    {
        content += "    <td port=\"port2\" border=\"1\" bgcolor=\"black\"><FONT COLOR=\"white\">"+std::to_string(n->data)+"</FONT></td>";
    }
    else //red
    {
        content += "    <td port=\"port2\" border=\"1\" bgcolor=\"red\">"+std::to_string(n->data)+"</td>";
    }
    content += "    <td port=\"port3\" border=\"1\">Right</td>";
    content += "    </tr>";
    content += "    </table>>";
    content += "];";

    //desenha a ligação entre o pai e ele
    if (father != nullptr)
    {
        if (isLeftSon)
            content += std::to_string(father->data)+":port1->"+std::to_string(n->data)+";";
        else
            content += std::to_string(father->data)+":port3->"+std::to_string(n->data)+";";
    }
    else
    {
        //é o root
        content += "ROOT[shape=none fontcolor=blue];";
        content += "ROOT->"+std::to_string(n->data)+";";
    }

    if (n->left != nullptr)
    {
        exibirSubArvore2
        (
            n,
            true, //is left
            n->left,
            content,
            count
        );
    }

    if (n->right != nullptr)
    {
        exibirSubArvore2
        (
            n,
            false, //is not left
            n->right,
            content,
            count
        );
    }
}

//avl methods
void RedBlackTree::updateHeightOfFullTree()
{
    updateHeightOfNode(root);
}

void RedBlackTree::updateHeightOfNode(struct NodeOfRedBlackTree* node)
{
    int leftHeight = 0;
    if (node->left != nullptr)
    {
        updateHeightOfNode(node->left);
        leftHeight = node->left->height;
    }
    int rightHeight = 0;
    if (node->right != nullptr)
    {
        updateHeightOfNode(node->right);
        rightHeight = node->right->height;
    }
    node->height = 1 + std::max(leftHeight, rightHeight);
}

int RedBlackTree::getBalanceOfNode(struct NodeOfRedBlackTree* node)
{
    int leftHeight = 0;
    if (node->left != nullptr)
    {
        leftHeight = node->left->height;
    }
    int rightHeight = 0;
    if (node->right != nullptr)
    {
        updateHeightOfNode(node->right);
        rightHeight = node->right->height;
    }
    return leftHeight - rightHeight;
}

RotationType RedBlackTree::checkTheNeedAndMakeRotation(NodeOfRedBlackTree* tmp)
{
    //Must perform the check to rotate operation
    //do something
    //level of left:
    int ret = getBalanceOfNode(tmp);
    if (abs(ret)>=2)
    {
        //Deve fazer uma rotação aqui
        //identificar se está mais pesada para direita ou esquerda
        if (ret > 0) //está mais pesada para a esquerda
        {
            //Identificar se é rotação simples
            int rightP = 0;
            int leftP = 0;
            if (tmp->left->left != nullptr)
                leftP = tmp->left->left->height;
            if (tmp->left->right != nullptr)
                rightP = tmp->left->right->height;

            if (leftP > rightP) //rotação simples
            {
                if (root == tmp)
                {
                    NodeOfRedBlackTree* backup = tmp->left->right;
                    NodeOfRedBlackTree* backup2 = tmp->left;
                    tmp->left->right = tmp;
                    tmp->left = backup;
                    root = backup2;
                    root->father = nullptr;
                    root->right->father = root;
                    if (root->right->left != nullptr)
                        root->right->left->father = root->right;

                    //tmp passa a ser backup2
                    tmp = backup2;
                }
                else
                {
                    NodeOfRedBlackTree* parentBackup = tmp->father;
                    NodeOfRedBlackTree* backup = tmp->left;
                    NodeOfRedBlackTree* backup2 = backup->right;
                    backup->right = tmp;
					tmp->father = backup; //new after search
                    if (backup2 != nullptr)
                        backup2->father = tmp;
                    tmp->left = backup2;

                    //update backup father (pai de tmp)
                    if (backup != nullptr)
                        backup->father = parentBackup;

                    //atualizar filho ou esquerdo ou direito do
                    //pai de tmp
                    if (parentBackup->right == tmp)
                        parentBackup->right = backup;
                    else
                        parentBackup->left = backup;

                    //tmp passa a ser backup
                    tmp = backup;
                }

                //foi feita rotação simples para a direita
                return RotationType::SimpleRotationToRight;
            }
            else //rotação dupla
            {
                if (root == tmp)
                {
                    NodeOfRedBlackTree* a = tmp;
                    NodeOfRedBlackTree* b = a->left;
                    NodeOfRedBlackTree* c = b->right;
                    NodeOfRedBlackTree* cL = c->left;
                    NodeOfRedBlackTree* cR = c->right;

                    root = c;
                    root->father = nullptr;
                    root->right = a;
                    a->father = root;
                    root->left = b;
                    b->father = root;
                    a->left = cR;
                    if (cR != nullptr)
                        cR->father = a;
                    b->right = cL;
                    if (cL != nullptr)
                        cL->father = b;

                    //c passa a ser o novo tmp
                    tmp = c;
                }
                else
                {
                    NodeOfRedBlackTree* aParent = tmp->father;
                    NodeOfRedBlackTree* a = tmp;
                    NodeOfRedBlackTree* b = a->left;
                    NodeOfRedBlackTree* c = b->right;
                    NodeOfRedBlackTree* cL = c->left;
                    NodeOfRedBlackTree* cR = c->right;

                    c->left = b;
                    b->father = c;

                    c->right = a;
                    a->father = c;

                    a->left = cR;
                    if (cR != nullptr)
                        cR->father = a;

                    b->right = cL;
                    if (cL != nullptr)
                        cL->father = b;

                    c->father = aParent;

                    if (aParent->right == a)
                        aParent->right = c;
                    else
                        aParent->left = c;

                    //c passa a ser o novo tmp
                    tmp = c;
                }

                //foi feita rotação dupla para a direita
                return RotationType::DoubleRotationToRight;
            }
        }
        else //está mais pesada para a direita
        {
            //identificar se é rotação simples
            int rightP = 0;
            if (tmp->right->right != nullptr)
                rightP = tmp->right->right->height;
            int leftP = 0;
            if (tmp->right->left != nullptr)
                leftP = tmp->right->left->height;
            if (rightP > leftP)
            {
                if (root == tmp)
                {
                    NodeOfRedBlackTree* backup = tmp->right->left;
                    NodeOfRedBlackTree* backup2 = tmp->right;
                    tmp->right->left = tmp;
                    tmp->right = backup;
                    root = backup2;
                    root->father = nullptr;
                    root->left->father = root;
                    if (root->left->right != nullptr)
                        root->left->right->father = root->left;

                    //tmp passa a ser backup2
                    tmp = backup2;
                }
                else
                {
                    NodeOfRedBlackTree* parentBackup = tmp->father;
                    NodeOfRedBlackTree* backup = tmp->right;
                    NodeOfRedBlackTree* backup2 = backup->left;
                    backup->left = tmp;
					tmp->father = backup; //new after search

                    if (backup2 != nullptr)
                        backup2->father = tmp;
                    tmp->right = backup2;

                    //update backup father (pai de tmp)
                    if (backup != nullptr)
                        backup->father = parentBackup;

                    //atualizar filho ou esquerdo ou direito do
                    //pai de tmp
                    if (parentBackup->right == tmp)
                        parentBackup->right = backup;
                    else
                        parentBackup->left = backup;

                    //tmp passa a ser backup
                    tmp = backup;
                }

                //foi feita rotação simples para a esquerda
                return RotationType::SimpleRotationToLeft;
            }
            //ou rotação dupla
            else
            {
                if (root == tmp)
                {
                    NodeOfRedBlackTree* a = tmp;
                    NodeOfRedBlackTree* b = a->right;
                    NodeOfRedBlackTree* c = a->right->left;
                    NodeOfRedBlackTree* cL = c->left;
                    NodeOfRedBlackTree* cR = c->right;

                    root = c;
                    root->father = nullptr;
                    root->left = a;
                    a->father = root;
                    root->right = b;
                    b->father = root;
                    a->right = cL;
                    if (cL != nullptr)
                        cL->father = a;
                    b->left = cR;
                    if (cR != nullptr)
                        cR->father = b;

                    //c passa a ser tmp
                    tmp = c;
                }
                else
                {
                    NodeOfRedBlackTree* aParent = tmp->father;
                    NodeOfRedBlackTree* a = tmp;
                    NodeOfRedBlackTree* b = a->right;
                    NodeOfRedBlackTree* c = a->right->left;
                    NodeOfRedBlackTree* cL = c->left;
                    NodeOfRedBlackTree* cR = c->right;

                    c->left = a;
                    a->father = c;

                    c->right = b;
                    b->father = c;

                    a->right = cL;
                    if (cL != nullptr)
                        cL->father = a;

                    b->left = cR;
                    if (cR != nullptr)
                        cR->father = b;

                    c->father = aParent;

                    if (aParent->right == a)
                        aParent->right = c;
                    else
                        aParent->left = c;

                    //c passa a ser tmp
                    tmp = c;
                }

                //foi feita rotação dupla para a esquerda
                return RotationType::DoubleRotationToLeft;
            }
        }
    }

    return RotationType::None; //Não foi feita rotação
}

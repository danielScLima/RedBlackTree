#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>
#include <vector>
#include "nodeofredblacktree.h"

/*!
 * \brief The RotationType enum
 */
enum RotationType
{
    SimpleRotationToLeft,
    SimpleRotationToRight,
    DoubleRotationToLeft,
    DoubleRotationToRight,
    None
};

/*!
 * \brief The RemoveReturn struct
 */
struct RemoveReturn
{
    NodeOfRedBlackTree* toRemoveNode = nullptr;
    NodeOfRedBlackTree* newNodeInthePosition = nullptr;
};

/*!
 * \brief The RedBlackTree class
 */
class RedBlackTree
{
public:
    /*!
     * \brief RedBlackTree
     */
    RedBlackTree();

    ~RedBlackTree();

    /*!
     * \brief insertInterface
     * \param data
     */
    bool insertInterface(int data);

    /*!
     * \brief search
     * \param data
     * \return
     */
    NodeOfRedBlackTree* search(int data);

    /*!
     * \brief removeInterface
     * \param data
     * \return
     */
    NodeOfRedBlackTree* removeInterface(int data);

    /*!
     * \brief gitDotFileMode1
     * \return
     */
    const std::string gitDotFileMode1();

    /*!
     * \brief gitDotFileMode2
     * \return
     */
    const std::string gitDotFileMode2();

    /*!
     * \brief preOrder
     * \return
     */
    const std::string preOrder();

    /*!
     * \brief inOrder
     * \return
     */
    const std::string inOrder();

    /*!
     * \brief posOrder
     * \return
     */
    const std::string posOrder();

    /*!
     * \brief InLevelOrder
     * \return
     */
    const std::string InLevelOrder();

    /*!
     * \brief isTheRoot
     * \param node
     * \return
     */
    bool isTheRoot(NodeOfRedBlackTree *node);

    /*!
     * \brief fatherOfNodeHasSibling
     * \param node
     * \return
     */
    NodeOfRedBlackTree *fatherOfNodeHasSibling(NodeOfRedBlackTree *node);

    /*!
     * \brief check
     * \param node
     */
    void check(NodeOfRedBlackTree *node);

    /*!
     * \brief changeColor
     * \param node
     */
    void changeColor(NodeOfRedBlackTree *node);

    /*!
     * \brief updateHeightOfNode
     * \param node
     */
    void updateHeightOfNode(NodeOfRedBlackTree *node);

    /*!
     * \brief updateHeightOfFullTree
     */
    void updateHeightOfFullTree();

    /*!
     * \brief getBalanceOfNode
     * \param node
     * \return
     */
    int getBalanceOfNode(NodeOfRedBlackTree *node);

    /*!
     * \brief checkTheNeedAndMakeRotation
     * \param tmp
     * \return
     */
    RotationType checkTheNeedAndMakeRotation(NodeOfRedBlackTree *tmp);

    /*!
     * \brief getInOrderSucessor
     * \param n
     * \return
     */
    NodeOfRedBlackTree *getInOrderSucessor(NodeOfRedBlackTree *n);//has priority

    /*!
     * \brief getInOrderPredecessor
     * \param n
     * \return
     */
	NodeOfRedBlackTree* getInOrderPredecessor(NodeOfRedBlackTree* n);

    /*!
     * \brief getFatherOfPredecessor
     * \param n
     * \return
     */
    NodeOfRedBlackTree *getFatherOfPredecessor(NodeOfRedBlackTree *n);

    /*!
     * \brief removeSwitchRedBlack
     * \param nodeToRemove
     */
    void removeSwitchRedBlack(NodeOfRedBlackTree *nodeToRemove);

    /*!
     * \brief removeDoubleBlackSituation
     * \param doubleBlackNode
     */
    void removeDoubleBlackSituation(NodeOfRedBlackTree *doubleBlackNode);

    /*!
     * \brief inLevelOrderNodes
     * \return
     */
    std::vector<NodeOfRedBlackTree *> inLevelOrderNodes();

    /*!
     * \brief swapColors
     * \param one
     * \param two
     */
    void swapColors(NodeOfRedBlackTree *one, NodeOfRedBlackTree *two);

    /*!
     * \brief getRoot
     * \return
     */
    NodeOfRedBlackTree* getRoot();

    /*!
     * \brief setAsRoot
     */
    void setAsRoot(NodeOfRedBlackTree* node);

private:
    struct NodeOfRedBlackTree* root = nullptr;

    /*!
     * \brief remove
     * \param toRemove
     * \return
     */
	NodeOfRedBlackTree* remove(NodeOfRedBlackTree* toRemove);

    /*!
     * \brief exibirSubArvore1
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore1
    (
        NodeOfRedBlackTree *n,
        std::string &content,
        int& count
    );

    /*!
     * \brief exibirSubArvore2
     * \param father
     * \param isLeftSon
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore2
    (
        NodeOfRedBlackTree *father,
        bool isLeftSon,
        NodeOfRedBlackTree *n,
        std::string &content,
        int &count
    );

    /*!
     * \brief preOrder
     * \param node
     * \param content
     */
    void preOrder(NodeOfRedBlackTree *node, std::string &content);

    /*!
     * \brief inOrder
     * \param node
     * \param content
     */
    void inOrder(NodeOfRedBlackTree *node, std::string &content);

    /*!
     * \brief posOrder
     * \param node
     * \param content
     */
    void posOrder(NodeOfRedBlackTree *node, std::string &content);

    /*!
     * \brief insert
     * \param data
     * \return
     */
    NodeOfRedBlackTree* insert(int data);

    /*!
     * \brief remove
     * \param data
     * \return
     */
    RemoveReturn remove(int data);

    /*!
     * \brief replacePointerInFather
     * \param father
     * \param oldSon
     * \param newPointerSon
     */
    void replacePointerInFather
    (
        NodeOfRedBlackTree *father,
        NodeOfRedBlackTree *oldSon,
        NodeOfRedBlackTree *newPointerSon
    );

    /*!
     * \brief getBrotherOfNode
     * \param father
     * \param firstNode
     * \return
     */
    NodeOfRedBlackTree *getBrotherOfNode
    (
        NodeOfRedBlackTree *father,
        NodeOfRedBlackTree *firstNode
    );

    /*!
     * \brief getFurtherChildOfDoubleBlackNode
     * \param sibling
     * \return
     */
    NodeOfRedBlackTree *getFurtherChildOfDoubleBlackNode(NodeOfRedBlackTree *sibling);

    /*!
     * \brief getCloserChildOfDoubleBlackNode
     * \param sibling
     * \return
     */
    NodeOfRedBlackTree *getCloserChildOfDoubleBlackNode(NodeOfRedBlackTree *sibling);
};

#endif // REDBLACKTREE_H

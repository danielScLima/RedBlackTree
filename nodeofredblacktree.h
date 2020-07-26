#ifndef NODEOFREDBLACKTREE_H
#define NODEOFREDBLACKTREE_H

/*!
 * \brief The Color enum
 */
enum Color
{
    RED, BLACK, DOUBLEBLACK
};

/*!
 * \brief The NodeOfRedBlackTree struct
 */
struct NodeOfRedBlackTree
{
    /*!
     * \brief NodeOfRedBlackTree
     */
    NodeOfRedBlackTree():
        data(0), left(nullptr), right(nullptr), father(nullptr)
    {}

    /*!
     * \brief NodeOfRedBlackTree
     * \param data
     * \param father
     */
    NodeOfRedBlackTree(int data, NodeOfRedBlackTree* father):
        data(data), left(nullptr), right(nullptr), father(father)
    {}

    void dealockSubTree()
    {
        if (left != nullptr)
        {
            left->dealockSubTree();
            delete left;
        }

        if (right != nullptr)
        {
            right->dealockSubTree();
            delete right;
        }
    }

    int data = 0;
    int height = 0;
    struct NodeOfRedBlackTree* left = nullptr;
    struct NodeOfRedBlackTree* right = nullptr;
    Color color = Color::RED;
    NodeOfRedBlackTree* father = nullptr;
};

#endif // NODEOFREDBLACKTREE_H

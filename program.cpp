// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "redblacktree.h"

TEST_CASE( "Testing the insert call in the tree", "[single-file]" )
{	
	RedBlackTree r;
	NodeOfRedBlackTree* root = r.getRoot();
	REQUIRE(root == nullptr);
	
	//Inserting 10
	r.insertInterface(10);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//Inserting 18
	r.insertInterface(18);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 18);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 7
	r.insertInterface(7);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 18);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 15
	r.insertInterface(15);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 18);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 15);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 16
	r.insertInterface(16);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 16);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 15);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->right->data == 18);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 30
	r.insertInterface(30);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 16);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->left->data == 15);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 18);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->right->data == 30);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 25
	r.insertInterface(25);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 16);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->left->data == 15);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 25);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->left->data == 18);
	REQUIRE(root->right->right->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->right->right->data == 30);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 40
	r.insertInterface(40);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 16);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 10);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->data == 25);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->data == 7);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 15);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 18);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 30);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->right->data == 40);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 60
	r.insertInterface(60);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 16);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 10);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->data == 25);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->data == 7);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 15);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 18);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->right->data == 60);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->right->left->data == 30);
	REQUIRE(root->right->right->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 2
	r.insertInterface(2);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 16);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 10);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->data == 25);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->data == 7);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 15);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 18);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->right->data == 60);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->right->left->data == 30);
	REQUIRE(root->right->right->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->left->data == 2);
	REQUIRE(root->left->left->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 1
	r.insertInterface(1);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 16);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 10);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->data == 25);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->data == 2);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 15);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 18);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//grandchilds
	REQUIRE(root->left->left->left->data == 1);
	REQUIRE(root->left->left->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->right->data == 7);
	REQUIRE(root->left->left->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	
	REQUIRE(root->right->right->left->data == 30);
	REQUIRE(root->right->right->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->right->right->data == 60);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//Inserting 70
	r.insertInterface(70);
	
	root = r.getRoot();
	REQUIRE(root != nullptr);
	
	REQUIRE(root->data == 16);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 10);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 25);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->left->data == 2);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 15);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 18);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//grandchilds
	REQUIRE(root->left->left->left->data == 1);
	REQUIRE(root->left->left->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->left->left->right->data == 7);
	REQUIRE(root->left->left->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	
	REQUIRE(root->right->right->left->data == 30);
	REQUIRE(root->right->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->right->data == 60);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->right->right->data == 70);
	REQUIRE(root->right->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
}

TEST_CASE( "Testing the remove call, case 1, situation 1, in the tree", "[single-file]" )
{	
	RedBlackTree r;
	NodeOfRedBlackTree* root = r.getRoot();
	REQUIRE(root == nullptr);
	
	r.insertInterface(10);
	r.insertInterface(7);
	r.insertInterface(20);
	r.insertInterface(30);
	
	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 20);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 30);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(30);
	delete nodeRem;
	
	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 20);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
}

TEST_CASE( "Testing the remove call, case 1, situation 2, in the tree", "[single-file]" )
{	
	RedBlackTree r;
	NodeOfRedBlackTree* root = r.getRoot();
	REQUIRE(root == nullptr);
	
	r.insertInterface(10);
	r.insertInterface(7);
	r.insertInterface(20);
	r.insertInterface(30);
	
	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 20);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 30);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(20);
	delete nodeRem;
	
	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->data == 7);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->data == 30);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
}

TEST_CASE( "Testing the remove call, case 1, situation 3, in the tree", "[single-file]" )
{	
	NodeOfRedBlackTree* root = new NodeOfRedBlackTree(10, nullptr);
	root->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	//
	
	root->left = new NodeOfRedBlackTree(5, root);
	root->left->color = RedBlackTreeColor::RedBlackTreeColorRED;
	
	root->right = new NodeOfRedBlackTree(30, root);
	root->right->color = RedBlackTreeColor::RedBlackTreeColorRED;
	
	//
	
	root->left->left = new NodeOfRedBlackTree(2, root->left);
	root->left->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	root->left->right = new NodeOfRedBlackTree(9, root->left);
	root->left->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	root->right->left = new NodeOfRedBlackTree(25, root->right);
	root->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	root->right->right = new NodeOfRedBlackTree(40, root->right);
	root->right->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	//
	
	root->right->right->left = new NodeOfRedBlackTree(38, root->right->right);
	root->right->right->left->color = RedBlackTreeColor::RedBlackTreeColorRED;
	
	RedBlackTree r;
	r.setAsRoot(root);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(30);
	delete nodeRem;
	
	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//
	
	REQUIRE(root->left->data == 5);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	REQUIRE(root->right->data == 38);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
	//
	
	REQUIRE(root->left->left->data == 2);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 9);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->left->data == 25);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
}

TEST_CASE("Testing the remove call, case 1, situation 4, in the tree", "[single-file]")
{
	NodeOfRedBlackTree* root = new NodeOfRedBlackTree(10, nullptr);
	root->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->left = new NodeOfRedBlackTree(5, root);
	root->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right = new NodeOfRedBlackTree(30, root);
	root->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->left->left = new NodeOfRedBlackTree(2, root->left);
	root->left->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->left->right = new NodeOfRedBlackTree(9, root->left);
	root->left->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->left = new NodeOfRedBlackTree(25, root->right);
	root->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->right = new NodeOfRedBlackTree(40, root->right);
	root->right->right->color = RedBlackTreeColor::RedBlackTreeColorRED;

	//

	root->right->right->left = new NodeOfRedBlackTree(35, root->right->right);
	root->right->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->right->right = new NodeOfRedBlackTree(50, root->right->right);
	root->right->right->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->right->right->left->right = new NodeOfRedBlackTree(38, root->right->right->left);
	root->right->right->left->right->color = RedBlackTreeColor::RedBlackTreeColorRED;

	RedBlackTree r;
	r.setAsRoot(root);

	NodeOfRedBlackTree* nodeRem = r.removeInterface(30);
	delete nodeRem;

	root = r.getRoot();

	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->data == 5);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->data == 35);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->left->data == 2);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->left->right->data == 9);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->left->data == 25);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);

	//

	REQUIRE(root->right->right->left->data == 38);
	REQUIRE(root->right->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->right->right->data == 50);
	REQUIRE(root->right->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
}

TEST_CASE("Testing the remove call, case 3, situation 1, in the tree", "[single-file]")
{
	NodeOfRedBlackTree* root = new NodeOfRedBlackTree(10, nullptr);
	root->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->left = new NodeOfRedBlackTree(5, root);
	root->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right = new NodeOfRedBlackTree(20, root);
	root->right->color = RedBlackTreeColor::RedBlackTreeColorRED;
	
	//

	root->right->left = new NodeOfRedBlackTree(15, root->right);
	root->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->right = new NodeOfRedBlackTree(30, root->right);
	root->right->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	RedBlackTree r;
	r.setAsRoot(root);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(15);
	delete nodeRem;

	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->data == 5);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->data == 20);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//
	
	REQUIRE(root->right->right->data == 30);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
}

TEST_CASE("Testing the remove call, case 3 that also tests case 2, situation 2, in the tree", "[single-file]")
{
	NodeOfRedBlackTree* root = new NodeOfRedBlackTree(10, nullptr);
	root->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->left = new NodeOfRedBlackTree(5, root);
	root->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right = new NodeOfRedBlackTree(20, root);
	root->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	//

	root->left->left = new NodeOfRedBlackTree(1, root->left);
	root->left->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->left->right = new NodeOfRedBlackTree(7, root->left);
	root->left->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	root->right->left = new NodeOfRedBlackTree(15, root->right);
	root->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->right = new NodeOfRedBlackTree(30, root->right);
	root->right->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	RedBlackTree r;
	r.setAsRoot(root);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(15);
	delete nodeRem;

	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->data == 5);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorRED);

	REQUIRE(root->right->data == 20);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//
	
	REQUIRE(root->left->left->data == 1);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->left->right->data == 7);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	REQUIRE(root->right->right->data == 30);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
}

TEST_CASE("Testing the remove call, case 4 in the tree", "[single-file]")
{
	NodeOfRedBlackTree* root = new NodeOfRedBlackTree(10, nullptr);
	root->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->left = new NodeOfRedBlackTree(5, root);
	root->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right = new NodeOfRedBlackTree(20, root);
	root->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	//
	
	root->left->left = new NodeOfRedBlackTree(1, root->left);
	root->left->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->left->right = new NodeOfRedBlackTree(7, root->left);
	root->left->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->left = new NodeOfRedBlackTree(15, root->right);
	root->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->right = new NodeOfRedBlackTree(30, root->right);
	root->right->right->color = RedBlackTreeColor::RedBlackTreeColorRED;
	
	//
	
	root->right->right->left = new NodeOfRedBlackTree(25, root->right->right);
	root->right->right->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	root->right->right->right = new NodeOfRedBlackTree(40, root->right->right);
	root->right->right->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	RedBlackTree r;
	r.setAsRoot(root);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(15);
	delete nodeRem;

	root = r.getRoot();
	
	REQUIRE(root->data == 10);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->data == 5);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->data == 30);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->left->data == 1);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->left->right->data == 7);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->left->data == 20);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//
	
	REQUIRE(root->right->left->right->data == 25);
	REQUIRE(root->right->left->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
}

TEST_CASE("Testing the remove call, case 5, that also tests the cases 3 and 6, in the tree", "[single-file]")
{
	NodeOfRedBlackTree* root = new NodeOfRedBlackTree(10, nullptr);
	root->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	//

	root->left = new NodeOfRedBlackTree(5, root);
	root->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right = new NodeOfRedBlackTree(30, root);
	root->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	//
	
	root->left->left = new NodeOfRedBlackTree(1, root->left);
	root->left->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->left->right = new NodeOfRedBlackTree(7, root->left);
	root->left->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;

	root->right->left = new NodeOfRedBlackTree(25, root->right);
	root->right->left->color = RedBlackTreeColor::RedBlackTreeColorRED;

	root->right->right = new NodeOfRedBlackTree(40, root->right);
	root->right->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	//
	
	root->right->left->left = new NodeOfRedBlackTree(20, root->right->left);
	root->right->left->left->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	root->right->left->right = new NodeOfRedBlackTree(28, root->right->left);
	root->right->left->right->color = RedBlackTreeColor::RedBlackTreeColorBLACK;
	
	RedBlackTree r;
	r.setAsRoot(root);
	
	NodeOfRedBlackTree* nodeRem = r.removeInterface(1);
	delete nodeRem;

	root = r.getRoot();
	
	REQUIRE(root->data == 25);
	REQUIRE(root->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->data == 10);
	REQUIRE(root->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->data == 30);
	REQUIRE(root->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	//

	REQUIRE(root->left->left->data == 5);
	REQUIRE(root->left->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->left->right->data == 20);
	REQUIRE(root->left->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->left->data == 28);
	REQUIRE(root->right->left->color == RedBlackTreeColor::RedBlackTreeColorBLACK);

	REQUIRE(root->right->right->data == 40);
	REQUIRE(root->right->right->color == RedBlackTreeColor::RedBlackTreeColorBLACK);
	
	//
	
	REQUIRE(root->left->left->right->data == 7);
	REQUIRE(root->left->left->right->color == RedBlackTreeColor::RedBlackTreeColorRED);
	
}

TEST_CASE( "Testing the search call in the tree", "[single-file]" )
{	
	RedBlackTree r;
	NodeOfRedBlackTree* root = r.getRoot();
	REQUIRE(root == nullptr);
	
	std::vector<int> vec = {10,18,7,15,16,30,25,40,60,2,1,70};
	
	for (auto number: vec)
	{
		r.insertInterface(number);
	}
	
	for (auto number: vec)
	{
		REQUIRE(r.search(number) != nullptr);
	}
}

TEST_CASE( "Testing the search call,c ase 2, in the tree", "[single-file]" )
{	
	RedBlackTree r;
	NodeOfRedBlackTree* root = r.getRoot();
	REQUIRE(root == nullptr);
	
	std::vector<int> vec = {10,18,7,15,16,30,25,40,60,2,1,70};
	
	for (auto number: vec)
	{
		r.insertInterface(number);
	}
	
	for (auto number: vec)
	{
		REQUIRE(r.search(number) != nullptr);
	}
	
	std::vector<int> invalidVec = {12,41,62,55};
	
	for (auto number: invalidVec)
	{
		REQUIRE(r.search(number) == nullptr);
	}
}

TEST_CASE( "Testing the search and remove calls in the tree", "[single-file]" )
{	
	RedBlackTree r;
	NodeOfRedBlackTree* root = r.getRoot();
	REQUIRE(root == nullptr);
	
	std::vector<int> vec = {10,18,7,15,16,30,25,40,60,2,1,70};
	
	for (auto number: vec)
	{
		r.insertInterface(number);
	}
	
	for (auto number: vec)
	{
		REQUIRE(r.search(number) != nullptr);
	}
	
	std::vector<int> toRemoveVec = {40,60,2,1,70};
	std::vector<int> toKeepVec = {10,18,7,15,16,30,25};
	
	NodeOfRedBlackTree* node = nullptr;
	for (auto number: toRemoveVec)
	{
		node = r.removeInterface(number);
		delete node;
	}
	
	for (auto number: toKeepVec)
	{
		node = r.search(number);
		REQUIRE(node != nullptr);
	}
	
	for (auto number: toRemoveVec)
	{
		REQUIRE(r.search(number) == nullptr);
	}
}

TEST_CASE( "Testing the insertion of duplicated entries in the tree", "[single-file]" )
{	
	RedBlackTree r;
	
	REQUIRE(r.insertInterface(10));
	REQUIRE(r.insertInterface(7));
	REQUIRE(r.insertInterface(20));
	REQUIRE(r.insertInterface(30));
	
	REQUIRE(!r.insertInterface(10));
	REQUIRE(!r.insertInterface(7));
	REQUIRE(!r.insertInterface(20));
	REQUIRE(!r.insertInterface(30));
}
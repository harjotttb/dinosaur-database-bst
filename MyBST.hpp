#ifndef CPSC131_BST_MYBST_HPP
#define CPSC131_BST_MYBST_HPP

/**
 * Work on this code!
 * Name: Harjot Bhangu
 * CWID: 828073312
 * Email: harjottb@csu.fullerton.edu
 */


/**
 * ***** TEST COVERAGE BOUNTY *****
 * If you can discover a part of this code that is not currently
 * covered by test cases, you may receive a small amount
 * of extra credit for reporting it to me.
 * 
 * Follow these steps:
 * 
 * 1. Identify what parts of your code are not covered by unit tests.
 * 2. Write up a detailed description of the above.
 * 3. Write up the actual unit tests that would cover the code (i.e., code added to CPP_Tests.cpp)
 * 
 * If I decide to add the test cases for future semesters,
 * you'll be granted the extra credit right away.
 * 
 * Valid only for the first reporter of each test.
 */


#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <queue>


namespace CPSC131::BST
{
	///	YOUR WELCOME
	using std::cout, std::endl;
	
	///	YOUR WELCOME
	///	Must bring std::to_string into this scope so we can overload it further below
	using std::to_string;
	
	///	YOUR WELCOME
	//	Custom exceptions
	class ValueNotFoundError : public std::runtime_error
	{
		public:
			using std::runtime_error::runtime_error;
	};
	class ValueExistsError : public std::runtime_error
	{
		public:
			using std::runtime_error::runtime_error;
	};
	///	YOUR WELCOME
	
	/*********************************
	 * Begin declarations
	 * 
	 * DO NOT modify any existing declarations
	 * or your tests will likely not pass.
	 * 
	 * You may ADD additional declarations if you wish to use helper functions,
	 * which is probably a smart idea.
	 ********************************/
	template <class T>
	class MyBST
	{
		public:
			
			//	Node
			class Node
			{
				public:
					
					/// /////////////////////////////////////
					///	Overloading so std::to_string works
					///	YOUR WELCOME
					std::string to_string(const Node& node)
					{
						std::stringstream ss;
						
						//	Note that this won't compile unless
						//	any custom T type used is overloaded for the stream operator
						ss
							<< "MyBST<T>::Node"
							<< "; Data = " << this->data_
							<< "; Depth = " << this->depth_
							<< "; Parent = " << this->parent_.get()
							<< "; Left Child = " << this->left_child_.get()
							<< "; Right Child = " << this->right_child_.get()
							;
						
						return ss.str();
					}
					/// /////////////////////////////////////
					
					//	CTORs
					Node();
					Node(const Node& other);
					
					//	DTOR
					~Node();
					
					T& getData();
					void setData(T data);
					
					size_t getDepth() const;
					void setDepth(size_t depth);
					
					void setParent(std::shared_ptr<Node> p);
					std::shared_ptr<Node> getParent() const;
					
					void setLeftChild(std::shared_ptr<Node> lc);
					std::shared_ptr<Node> getLeftChild() const;
					
					void setRightChild(std::shared_ptr<Node> rc);
					std::shared_ptr<Node> getRightChild() const;
					
					void clear();
					
					T& operator*();
					bool operator==(const Node& other);
					bool operator!=(const Node& other);
					
				private:
					
					T data_;
					size_t depth_ = 0;
					
					std::shared_ptr<Node>
						parent_,
						left_child_,
						right_child_
						;
				
				friend class MyBST;
			};
			
			//	CTORs
			MyBST();
			MyBST(const MyBST& other);
			
			//	DTOR
			~MyBST();
			
			//
			void insert(T value);
			
			///	Seems redundant to return the object you're looking for
			///	until we remember we can place less information in the
			///	argument's object, relying on comparison operators to still work
			T& find(T value);
			
			std::shared_ptr<Node> find_node(T value) const;
			
			void remove(T value);
			void remove(std::shared_ptr<Node> node);
			
			bool exists(T value) const;
			
			std::shared_ptr<Node> getRoot() const;
			
			bool isRoot(const std::shared_ptr<Node>& node) const;
			bool isInternal(const std::shared_ptr<Node>& node) const;
			bool isExternal(const std::shared_ptr<Node>& node) const;
			bool isLeaf(const std::shared_ptr<Node>& node) const;
			
			bool isParent(const std::shared_ptr<Node>& node) const;
			bool hasParent(const std::shared_ptr<Node>& node) const;
			
			size_t getChildCount(const std::shared_ptr<Node>& node) const;
			bool hasOneChild(const std::shared_ptr<Node>& node) const;
			bool hasTwoChildren(const std::shared_ptr<Node>& node) const;
			
			bool isLeftChild(const std::shared_ptr<Node>& node) const;
			bool hasLeftChild(const std::shared_ptr<Node>& node) const;
			bool isRightChild(const std::shared_ptr<Node>& node) const;
			bool hasRightChild(const std::shared_ptr<Node>& node) const;
			
			void traversePreOrder(std::function<void(MyBST&, std::shared_ptr<Node>)> callback);
			void traverseInOrder(std::function<void(const MyBST&, std::shared_ptr<Node>)> callback) const;
			void traverseInOrder(std::function<void(MyBST&, std::shared_ptr<Node>)> callback);
			void traversePostOrder(std::function<void(MyBST&, std::shared_ptr<Node>)> callback);
			void traverseLevelOrder(std::function<bool(const MyBST&, std::shared_ptr<Node>)> callback) const;
			void traverseLevelOrder(std::function<bool(MyBST&, std::shared_ptr<Node>)> callback);
			
			void clear();
			
			bool empty() const;
			size_t size() const;
			
			std::shared_ptr<Node> getDeepestLeaf();
			size_t computeHeight();
			
			std::string renderToDot() const;
			
			bool operator==(const MyBST<T>& other);
			bool operator!=(const MyBST<T>& other);
			MyBST& operator=(const MyBST<T>& other);
		
		private:
			
			///	YOUR WELCOME
			void traverseLevelOrder
			(
				std::shared_ptr<Node> node,
				std::function<bool(const MyBST&, std::shared_ptr<Node>)> callback
			) const;
			
			///	YOUR WELCOME
			void traverseLevelOrder
			(
				std::shared_ptr<Node> node,
				std::function<bool(MyBST&, std::shared_ptr<Node>)> callback
			);
			
			///	Private members; DO NOT MODIFY
			std::shared_ptr<Node> root_;
			size_t size_ = 0;
			
			///	Friend class; DO NOT MODIFY
			friend class Tester;
	};
	
	/*********************************
	 * Begin definitions
	 * 
	 * Below you'll find definitions (implementations) of all declared
	 * methods you saw above. You must complete each method below.
	 * 
	 * Your work it to complete the incomplete methods below, changing
	 * anything in the methods' bodies you feel is needed.
	 * But do not modify method signatures.
	 * 
	 * 
	 ********************************/


	
	/*********************
	 * Begin Node methods!
	 * aka MyBST<T>::Node
	 ********************/
	
	

	///	Node Constructor (CTOR)
	template <class T>
	MyBST<T>::Node::Node()
	{
		data_ = T();
		depth_ = 0;
		parent_ = nullptr;
		left_child_ = nullptr;
		right_child_ = nullptr;
	}
	
	/**
	 * Node's Copy Constructor
	 * 
	 * What does it mean to "copy one Node to another"?
	 * 
	 * For this project, we'll assume pointer-stealing is totally
	 * fine for Nodes, because they don't own the overall data structure
	 * but simply hold values.
	 * 
	 * In other words, copy all pointers and the value directly.
	 */
	template <class T>
	MyBST<T>::Node::Node(const MyBST<T>::Node& other)
	{
		data_ = other.data_;
		parent_ = other.parent_;
		depth_ = other.depth_;
		left_child_ = other.left_child_;
		right_child_ = other.right_child_;
	}
	
	/**
	 * Node Destructor (DTOR)
	 * 
	 * You probably want to clear out all pointers here.
	 */
	template <class T>
	MyBST<T>::Node::~Node()
	{
		clear();
	}
	
	///	Return the Node's data to the caller, as a reference
	template <class T>
	T& MyBST<T>::Node::getData()
	{
		
		return data_;
	}
	
	///	Set the Node's data
	template <class T>
	void MyBST<T>::Node::setData(T data)
	{
		data_ = data;
	}
	
	///	Return the Node's depth to the caller
	template <class T>
	size_t MyBST<T>::Node::getDepth() const
	{
		
		return depth_;
	}
	
	///	Set the Node's depth
	template <class T>
	void MyBST<T>::Node::setDepth(size_t depth)
	{
		depth_ = depth;
	}
	
	///	Set the Node's parent pointer
	template <class T>
	void MyBST<T>::Node::setParent(std::shared_ptr<MyBST<T>::Node> p)
	{
		parent_ = p;
	}
	
	///	Return the Node's parent pointer to the caller
	template <class T>
	std::shared_ptr<class MyBST<T>::Node::Node> MyBST<T>::Node::getParent() const
	{	
		return parent_;
	}
	
	///	Set the Node's left child pointer
	template <class T>
	void MyBST<T>::Node::setLeftChild(std::shared_ptr<MyBST<T>::Node> lc)
	{
		left_child_ = lc;
	}
	
	///	Return the Node's left child pointer to the caller
	template <class T>
	std::shared_ptr<class MyBST<T>::Node> MyBST<T>::Node::getLeftChild() const
	{
		
		return left_child_;
	}
	
	///	Set the Node's right child pointer
	template <class T>
	void MyBST<T>::Node::setRightChild(std::shared_ptr<MyBST<T>::Node> rc)
	{
		right_child_ = rc;
	}
	
	///	Return the Node's right child pointer to the caller
	template <class T>
	std::shared_ptr<class MyBST<T>::Node::Node> MyBST<T>::Node::getRightChild() const
	{
		
		return right_child_;
	}
	
	/**
	 * The clear() method should null all pointers.
	 * 
	 * Remember that snipping a Node from the tree should
	 * involve not only nulling its pointers, but nulling
	 * any other pointers that refer to it.
	 * 
	 * For example, if you nulled this Node but it still had
	 * a parent pointing down to it (e.g., left child), the
	 * Node wouldn't really be disconnected from the tree.
	 * 
	 * As another example, if you nulled this Node but it still had
	 * a child pointing back up to it (e.g., parent pointer), the
	 * Node wouldn't really be disconnected from the tree.
	 * 
	 * In both of the above examples, the tree would end up
	 * malformed, and/or result in memory leaks.
	 */
	template <class T>
	void MyBST<T>::Node::clear()
	{
		if (parent_) {
           if (parent_->left_child_.get() == this) {
               parent_->left_child_ = nullptr;
           } else if (parent_->right_child_.get() == this) {
               parent_->right_child_ = nullptr;
           }
       }
       if (left_child_) {
           left_child_->parent_ = nullptr;
       }
       if (right_child_) {
           right_child_->parent_ = nullptr;
	   }
		parent_ = nullptr;
		left_child_ = nullptr;
		right_child_ = nullptr;
	}
	
	/**
	 * Dereferencing operator
	 * Return this Node's value to the caller, by reference.
	 */
	template <class T>
	T& MyBST<T>::Node::operator*()
	{	
		return data_;
	}
	
	/**
	 * Comparison/equality operator.
	 * 
	 * For this project, we'll say two nodes are equal
	 * when their data is equal (not their pointers)
	 */
	template <class T>
	bool MyBST<T>::Node::operator==(const Node& other)
	{
		
		return (data_ == other.data_);
	}
	
	/**
	 * Inequality operator,
	 * which is the opposite of the equality operator above
	 */
	template <class T>
	bool MyBST<T>::Node::operator!=(const Node& other)
	{
		
		return !(*this == other);
	}
	
	
	/***********************************
	 * Begin Binary Search Tree methods!
	 * aka MyBST<T>
	 **********************************/
	
	
	/**
	 * Binary Search Tree's Constructor
	 * (BST CTOR)
	 */
	template <class T>
	MyBST<T>::MyBST()
	{
		root_ = nullptr;
		size_ = 0;
	}
	
	/**
	 * BST's Copy Constructor (Copy CTOR)
	 * 
	 * Hint: How can you copy a BST to another and ensure 
	 * the same topology? This is why level-order traversal
	 * has been impemented on your behalf.
	 * 
	 * Simply iterate through the source tree using level-order
	 * traversal.
	 * For each Node you find, just insert() its data into the
	 * destination tree.
	 * 
	 * Level-order traversal automatically handles the correct
	 * topology.
	 * 
	 */
	template <class T>
	MyBST<T>::MyBST(const MyBST& other)
	{
		root_ = nullptr;
		size_ = 0;
		if (!other.empty()){
			other.traverseLevelOrder([this](const MyBST<T>&, std::shared_ptr<MyBST<T>::Node> node) -> bool{
				this ->insert(node->getData());
				return true;
			});
		}
	}
	
	/**
	 * Tree's Destructor.
	 * 
	 * Here you should empty the tree to ensure no memory leaks.
	 */
	template <class T>
	MyBST<T>::~MyBST()
	{
		clear();
	}
	
	/**
	 * Insert the given value into the tree, at the proper position.
	 * 
	 * Throw a ValueExistsError if the value already exists in the tree.
	 */
	template <class T>
	void MyBST<T>::insert(T value)
	{
		if(exists(value)){
			throw ValueExistsError("Value already exists");
		}

		auto newNode = std::make_shared<Node>();
		newNode->setData(value);

		if(empty()){
			root_ = newNode;
			newNode->setDepth(0);
			size_ = 1;
			return;
		}

		auto current = root_;

		while(current){
			if (value == current->getData()){
				throw ValueNotFoundError("Value already exists");
			} 
			if (value < current->getData()){
			    if (!current->getLeftChild()){
					current->setLeftChild(newNode);
					newNode->setParent(current);
					newNode->setDepth(current->getDepth() + 1);
					size_++;
					return;
				}
				current = current->getLeftChild();
			} 
			else {
				if (!current->getRightChild()){
					current->setRightChild(newNode);
					newNode->setParent(current);
					newNode->setDepth(current->getDepth() + 1);
					size_++;
					return;
				}
				current = current->getRightChild();
			}
		}
	}
	
	/**
	 * Find a value in the Tree, and return a reference to it.
	 * 
	 * Should throw ValueNotFoundError if the value isn't in the Tree.
	 */
	template <class T>
	T& MyBST<T>::find(T value)
	{
		auto node = find_node(value);
		if (!node){
			throw ValueNotFoundError("Value is not found");
		}		
		return node->getData();
	}
	
	/**
	 * Find a value in the Tree, and return its containing Node pointer
	 * to the caller.
	 * 
	 * This is very similar to the above find() method,
	 * only find_node returns a Node pointer, while find() returns
	 * a reference to the actual value.
	 * 
	 * If the value isn't found, don't throw any exceptions; Simply
	 * return a null pointer to the caller.
	 */
	template <class T>
	std::shared_ptr<class MyBST<T>::Node> MyBST<T>::find_node(T value) const
	{
		auto temp = root_;
		while (temp){
			if (value == temp->getData()){
				return temp;
			} else if (value < temp->getData()){
				temp = temp->getLeftChild();
			} else {
				temp = temp->getRightChild();
			}
		}
		
		return nullptr;
	}
	
	/**
	 * Remove a value from the Tree.
	 * 
	 * Should throw a ValueNotFoundError excption if the value
	 * doesn't exist in the Tree.
	 */
	template <class T>
	void MyBST<T>::remove(T value)
	{
		auto node = find_node(value);
		if(!node){
			throw ValueNotFoundError("Value is not found");
		}
		remove(node);
	}
	
	/**
	 * Remove a specific Node from the Tree.
	 * 
	 * This is very similar to the above remove(T),
	 * only we specify an actual Node pointer to remove rather
	 * than a value.
	 * 
	 * Should throw some type of exception if the Node is null.
	 */
	template <class T>
	void MyBST<T>::remove(std::shared_ptr<MyBST<T>::Node> node)
	{

	   if (!node) {
          throw ValueNotFoundError("Node is empty");
        }

        auto childCount = getChildCount(node);

        if (childCount == 0) {
           if (node == root_) {
              root_ = nullptr;
        } else if (isLeftChild(node)) {
             node->getParent()->setLeftChild(nullptr);
        } else {
             node->getParent()->setRightChild(nullptr);
        }
        node->setParent(nullptr);
        }

        else if (childCount == 1) {
            auto child = node->getLeftChild() ? node->getLeftChild(): node->getRightChild();

        if (node == root_) {
           root_ = child;
           child->setParent(nullptr);
           child->setDepth(0);

           std::vector<std::shared_ptr<Node>> stack;
           if (child->getLeftChild())  stack.push_back(child->getLeftChild());
           if (child->getRightChild()) stack.push_back(child->getRightChild());

           while (!stack.empty()) {
              auto curr = stack.back();
              stack.pop_back();

              curr->setDepth(curr->getParent()->getDepth() + 1);

              if (curr->getLeftChild())  stack.push_back(curr->getLeftChild());
              if (curr->getRightChild()) stack.push_back(curr->getRightChild());
           }
        } else {
        auto parent = node->getParent();
        size_t newDepth = node->getDepth();

        if (isLeftChild(node)) {
            parent->setLeftChild(child);
        } else {
            parent->setRightChild(child);
        }

        child->setParent(parent);
        child->setDepth(newDepth);

        std::vector<std::shared_ptr<Node>> stack;
        if (child->getLeftChild())  stack.push_back(child->getLeftChild());
        if (child->getRightChild()) stack.push_back(child->getRightChild());

        while (!stack.empty()) {
            auto curr = stack.back();
            stack.pop_back();

            curr->setDepth(curr->getParent()->getDepth() + 1);

            if (curr->getLeftChild())  stack.push_back(curr->getLeftChild());
            if (curr->getRightChild()) stack.push_back(curr->getRightChild());
        }
    }

     node->setParent(nullptr);
     node->setLeftChild(nullptr);
     node->setRightChild(nullptr);
    } else {
      auto successor = node->getRightChild();
      while (successor->getLeftChild()) {
          successor = successor->getLeftChild();
      }

      node->setData(successor->getData());
      remove(successor);
      return;
    }

    size_--;
   }
	
	/**
	 * Return true if the value exists in the Tree,
	 * or false otherwise.
	 */
	template <class T>
	bool MyBST<T>::exists(T value) const
	{
		
		return (find_node(value) != nullptr);
	
	}
	
	/// Return the root Node pointer to the caller
	template <class T>
	std::shared_ptr<class MyBST<T>::Node> MyBST<T>::getRoot() const
	{
		
		return root_;
	}
	
	/// Return true if the specified Node is the root Node
	template <class T>
	bool MyBST<T>::isRoot(const std::shared_ptr<MyBST<T>::Node>& node) const
	{

		return (node && node == root_);
	}
	
	///	Return true if the specified Node is internal
	template <class T>
	bool MyBST<T>::isInternal(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && getChildCount(node) > 0);
	}
	
	///	Return true if the specified Node is external
	template <class T>
	bool MyBST<T>::isExternal(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && getChildCount(node) == 0);
	}
	
	///	Return true if the specified Node is a leaf
	template <class T>
	bool MyBST<T>::isLeaf(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return isExternal(node);
	}
	
	///	Return true if the specified Node is a parent of any other Node
	template <class T>
	bool MyBST<T>::isParent(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && getChildCount(node) > 0);
	}
	
	///	Return true if the specified Node has a parent
	template <class T>
	bool MyBST<T>::hasParent(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && node->getParent() != nullptr);
	}
	
	///	Return the number of child nodes that this Node has
	template <class T>
	size_t MyBST<T>::getChildCount(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		if (!node){
			return 0;
		}
		size_t count = 0;
		if(node->getLeftChild()){
			count++;
		}
		if (node->getRightChild()){
			count++;
		}

		return count;
	}
	
	///	Return true if the specified Node has exactly one child
	template <class T>
	bool MyBST<T>::hasOneChild(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (getChildCount(node) == 1);
	}
	
	///	Return true if the specified Node has exactly two children
	template <class T>
	bool MyBST<T>::hasTwoChildren(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (getChildCount(node) == 2);
	}
	
	///	Return true if the specified Node is the left child of its parent
	template <class T>
	bool MyBST<T>::isLeftChild(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && node->getParent() && node->getParent()->getLeftChild() == node);
	}
	
	///	Return true if the specified Node has a left child
	template <class T>
	bool MyBST<T>::hasLeftChild(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && node ->getLeftChild() != nullptr);
	}
	
	///	Return true if the specified Node is the right child of its parent
	template <class T>
	bool MyBST<T>::isRightChild(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && node->getParent() && node->getParent()->getRightChild() == node);
	}
	
	///	Return true if the specified Node has a right child
	template <class T>
	bool MyBST<T>::hasRightChild(const std::shared_ptr<MyBST<T>::Node>& node) const
	{
		
		return (node && node->getRightChild() != nullptr);
	}
	
	/**
	 * Visit every Node in the Tree, in pre-order traversal.
	 * 
	 * Allow the caller to provide a custom
	 * callback function (lambda, usually) which they can
	 * use to "visit" each Node.
	 * 
	 * The callback function will receive a Tree reference
	 * and a Node pointer as arguments.
	 */
	template <class T>
	void MyBST<T>::traversePreOrder
	(
		std::function<void(MyBST<T>&, std::shared_ptr<MyBST<T>::Node>)> callback
	)
	{
		std::function<void(std::shared_ptr<MyBST<T>::Node>)> preOrderHelper = [&](std::shared_ptr<MyBST<T>::Node> node){
			if (!node) return;
			callback(*this, node);
			preOrderHelper(node->getLeftChild());
			preOrderHelper(node->getRightChild());
		};
		preOrderHelper(root_);
	}
	
	/**
	 * Visit every Node in the Tree, in in-order traversal.
	 * 
	 * This is the const overload of traverseInOrder.
	 * 
	 * Note that some of these traversal methods
	 * have constant overloads, allowing the caller to use them
	 * even in constant contexts. Notice this method is marked
	 * as "const", and also uses a callback signature
	 * that has a constant Tree pointer.
	 * 
	 */
	template <class T>
	void MyBST<T>::traverseInOrder
	(
		std::function<void(const MyBST<T>&, std::shared_ptr<MyBST<T>::Node>)> callback
	) const
	{
		std::function<void(std::shared_ptr<MyBST<T>::Node>)> inOrderHelper = [&](std::shared_ptr<MyBST<T>::Node> node){
			if (!node) return;
			inOrderHelper(node->getLeftChild());
			callback(*this, node);
			inOrderHelper(node->getRightChild());
		};
		inOrderHelper(root_);
	}
	
	/**
	 * This is the non-const overload of traverseInOrder.
	 */
	template <class T>
	void MyBST<T>::traverseInOrder
	(
		std::function<void(MyBST<T>&, std::shared_ptr<MyBST<T>::Node>)> callback
	)
	{
		std::function<void(std::shared_ptr<MyBST<T>::Node>)> inOrderHelper = [&](std::shared_ptr<MyBST<T>::Node> node) {
               if (!node) return;
               inOrderHelper(node->getLeftChild());
               callback(*this, node);
               inOrderHelper(node->getRightChild());
           };
       inOrderHelper(root_);

	}
	
	/**
	 * Traverse the Tree using post-order (non-const)
	 */
	template <class T>
	void MyBST<T>::traversePostOrder
	(
		std::function<void(MyBST<T>&, std::shared_ptr<MyBST<T>::Node>)> callback
	)
	{
		std::function<void(std::shared_ptr<MyBST<T>::Node>)> postOrderHelper = [&](std::shared_ptr<MyBST<T>::Node> node) {
               if (!node) return;
               postOrderHelper(node->getLeftChild());
               postOrderHelper(node->getRightChild());
               callback(*this, node);
           };
       postOrderHelper(root_);

	}
	
	/**
	 * YOUR WELCOME
	 * 
	 * Traverse the Tree using level-order (const version).
	 * 
	 * DO NOT MODIFY this method, as it may be considered tampering with
	 * the unit tests and result in a 0 for the entire assignment.
	 */
	template <class T>
	void MyBST<T>::traverseLevelOrder
	(
		std::function<bool(const MyBST<T>&, std::shared_ptr<MyBST<T>::Node>)> callback
	) const
	{
		this->traverseLevelOrder(this->root_, callback);
	}
	
	/**
	 * YOUR WELCOME
	 * 
	 * Traverse the Tree using level-order (non-const version).
	 * 
	 * DO NOT MODIFY this method, as it may be considered tampering with
	 * the unit tests and result in a 0 for the entire assignment.
	 */
	template <class T>
	void MyBST<T>::traverseLevelOrder
	(
		std::function<bool(MyBST<T>&, std::shared_ptr<MyBST<T>::Node>)> callback
	)
	{
		this->traverseLevelOrder(this->root_, callback);
	}
	
	/**
	 * Clear the Tree by removing every Node.
	 * (results in an empty Tree)
	 */
	template <class T>
	void MyBST<T>::clear()
	{
		std::function<void(std::shared_ptr<MyBST<T>::Node>)> clearHelper = [&](std::shared_ptr<MyBST<T>::Node> node) {
               if (!node) return;
               clearHelper(node->getLeftChild());
               clearHelper(node->getRightChild());
               node->clear();
           };
       clearHelper(root_);
       root_ = nullptr;
       size_ = 0;

	}
	
	///	Return true if the Tree is empty
	template <class T>
	bool MyBST<T>::empty() const
	{
		
		return (root_ == nullptr || size_ == 0);
	}
	
	/**
	 * Return the number of values in this Tree
	 * 
	 * This should run in constant time, not linear!
	 */
	template <class T>
	size_t MyBST<T>::size() const
	{
		
		return size_;
	}
	
	/**
	 * Locate the deepest leaf in the tree,
	 * and return it as a Node pointer.
	 * 
	 * Running in Linear time is fine.
	 */
	template <class T>
	std::shared_ptr<class MyBST<T>::Node> MyBST<T>::getDeepestLeaf()
	{
		if (empty()){
		   return nullptr;
		}

	    std::shared_ptr<MyBST<T>::Node> deepest = nullptr;
        size_t maxDepth = 0;
      
        std::function<void(std::shared_ptr<MyBST<T>::Node>)> findDeepest = [&](std::shared_ptr<MyBST<T>::Node> node) {
               if (!node) return;
               if (isLeaf(node) && node->getDepth() >= maxDepth) {
                   maxDepth = node->getDepth();
                   deepest = node;
               }
               findDeepest(node->getLeftChild());
               findDeepest(node->getRightChild());
        };
      
       findDeepest(root_);
       return deepest;

	}
	
	/**
	 * Compute the height of the Tree and return to the caller.
	 * 
	 * Running in linear time is OK.
	 */
	template <class T>
	size_t MyBST<T>::computeHeight()
	{
		if (empty()){
			return 0;
		}
		std::function<size_t(std::shared_ptr<MyBST<T>::Node>)> heightHelper = [&](std::shared_ptr<MyBST<T>::Node> node) -> size_t {
               if (!node) return 0;
               size_t leftHeight = heightHelper(node->getLeftChild());
               size_t rightHeight = heightHelper(node->getRightChild());
               return 1 + std::max(leftHeight, rightHeight);
        };
      
       return heightHelper(root_);

	}
	
	/**
	 * YOUR WELCOME
	 * 
	 * You should not modify this method, but should study it
	 * for your own learning.
	 * 
	 * This basically generates a graph in the "dot" language,
	 * which we can use with the "dot" program (from graphviz)
	 * to render a pretty pretty graph to an image file.
	 * 
	 * When you manipulate your Tree using the main() TUI's,
	 * you should notice a graph continually being updated
	 * in the file system. You can open it with an image viewer
	 * and see a visual representation of your Tree,
	 * to help your debugging! :)
	 * 
	 */
	template <class T>
	std::string MyBST<T>::renderToDot() const
	{
		std::stringstream ss;
		size_t null_count = 0;
		
		ss
			<< "// Digraph from Object " << this << endl
			<< "digraph \"MyBST\"" << endl
			<< "{" << endl
				<< "\tlabelloc=\"t\";" << endl
				<< "\tlabel=\"My BST\";" << endl
			;
		
		this->traverseLevelOrder
		(
			[&ss, &null_count](const MyBST<T>& t, std::shared_ptr<MyBST<T>::Node> node) -> bool
			{
				std::stringstream temp;
				
				temp << node->getData();
				if ( t.isRoot(node) ) {
					temp << "\nroot";
				}
				else if ( t.isLeaf(node) ) {
					temp << "\nleaf";
				}
				temp << "\nD = " << node->getDepth();
				std::string node_label = temp.str();
				
				//	Node's ID / label line
				ss
					<< "\t\"" << node->getData() << "\""
					<< " [label=\"" << node_label << "\"]"
					<< ";"
					<< endl
					;
				
				std::shared_ptr<MyBST<T>::Node> p;
				
				//	Left child
				p = node->getLeftChild();
				ss << "\t\"" << node->getData() << "\" -> ";
				if ( p ) {
					ss << "\"" << p->getData() << "\"";
				}
				else {
					ss << "null" << null_count;
					null_count++;
				}
				ss << " [label=\"left\"]" << endl;
				
				//	Right child
				p = node->getRightChild();
				ss << "\t\"" << node->getData() << "\" -> ";
				if ( p ) {
					ss << "\"" << p->getData() << "\"";
				}
				else {
					ss << "null" << null_count;
					null_count++;
				}
				ss << " [label=\"right\"]" << endl;
				
				return true;
			}
		);
		
		for ( size_t i = 0; i < null_count; i++ ) {
			ss << "\tnull" << i << "[shape=point][color=red][width=0.2][height=0.2]" << endl;
		}
		
		ss
			<< "}" << endl
			;
		
		return ss.str();
	}
	
	/**
	 * Return true if the two Trees are "equal".
	 * 
	 * In this project, we consider two Trees to be equal
	 * when they have the exact same topology, including
	 * all values
	 * 
	 * We do NOT consider whether their pointer addresses are the same,
	 * because we're not supposed to be engaging in pointer-stealing
	 * anyway.
	 */
	template <class T>
	bool MyBST<T>::operator==(const MyBST<T>& other)
	{
		

		if (size_ != other.size_){
			return false;
		}
		if (empty() && other.empty()){
			return true;
		}
	    std::vector<T> thisValues, otherValues;
      
        this->traverseInOrder([&thisValues](const MyBST<T>&, std::shared_ptr<MyBST<T>::Node> node) {
           thisValues.push_back(node->getData());
        });
      
        other.traverseInOrder([&otherValues](const MyBST<T>&, std::shared_ptr<MyBST<T>::Node> node) {
           otherValues.push_back(node->getData());
        });
      
       return thisValues == otherValues;

	}
	
	/// Return true if the Trees are not equal (opposite of ==)
	template <class T>
	bool MyBST<T>::operator!=(const MyBST<T>& other)
	{
		
		return !(*this == other);
	}
	
	/**
	 * Assignment operator.
	 * 
	 * In this project, this should accomplish the same thing
	 * as the Copy CTOR.
	 */
	template <class T>
	class MyBST<T>& MyBST<T>::operator=(const MyBST<T>& other)
	{
		if (this != &other){
			clear();
			if (!other.empty()){
				other.traverseLevelOrder([this](const MyBST<T>&, std::shared_ptr<MyBST<T>::Node> node)->bool{
					this->insert(node->getData());
					return true;
				});
			}
		}
		return *this;
	}
	
	/**
	 * YOUR WELCOME
	 * 
	 * You are not required to know level-order traversal at this stage,
	 * so this method has been completed on your behalf.
	 * 
	 * If you are curious, study this method a bit, as it is essentially
	 * "breadth first search", an iterative algorithm we'll learn
	 * later in the semester.
	 * 
	 * DO NOT MODIFY this method, as it may be considered tampering with
	 * the unit tests and result in a 0 for the entire assignment.
	 */
	template <class T>
	void MyBST<T>::traverseLevelOrder
	(
		std::shared_ptr<MyBST<T>::Node> node,
		std::function<bool(const MyBST&, std::shared_ptr<MyBST<T>::Node>)> callback
	) const
	{
		//	Ignore empty trees
		if ( this->empty() ) {
			return;
		}
		
		//	Start with a queue, seeded with the root node
		std::queue<std::shared_ptr<MyBST<T>::Node>> q;
		q.push(node);
		
		//	Process the queue until it is empty
		while ( !q.empty() )
		{
			//	Pluck a node
			auto node = q.front();
			q.pop();
			
			//	Visit the plucked node.
			//	When a callback returns false,
			//		we immediately stop traversing
			if ( !callback(*this, node) ) {
				return;
			}
			
			//	Enqueue the Node's children, if any
			if ( node->getLeftChild() ) {
				q.push(node->getLeftChild());
			}
			if ( node->getRightChild() ) {
				q.push(node->getRightChild());
			}
		}
	}
	
	/**
	 * YOUR WELCOME
	 * 
	 * You are not required to know level-order traversal at this stage,
	 * so this method has been completed on your behalf.
	 * 
	 * If you are curious, study this method a bit, as it is essentially
	 * "breadth first search", an iterative algorithm we'll learn
	 * later in the semester.
	 * 
	 * DO NOT MODIFY this method, as it may be considered tampering with
	 * the unit tests and result in a 0 for the entire assignment.
	 */
	template <class T>
	void MyBST<T>::traverseLevelOrder
	(
		std::shared_ptr<MyBST<T>::Node> node,
		std::function<bool(MyBST&, std::shared_ptr<MyBST<T>::Node>)> callback
	)
	{
		//	Ignore empty trees
		if ( this->empty() ) {
			return;
		}
		
		//	Start with a queue, seeded with the root node
		std::queue<std::shared_ptr<MyBST<T>::Node>> q;
		q.push(node);
		
		while ( !q.empty() )
		{
			//	Pluck a node
			auto node = q.front();
			q.pop();
			
			//	Visit the plucked node.
			//	When a callback returns false,
			//		we immediately stop traversing
			if ( !callback(*this, node) ) {
				return;
			}
			
			//	Enqueue the Node's children, if any
			if ( node->getLeftChild() ) {
				q.push(node->getLeftChild());
			}
			if ( node->getRightChild() ) {
				q.push(node->getRightChild());
			}
		}
	}
}






#endif




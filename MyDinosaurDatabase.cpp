
#include "MyDinosaurDatabase.hpp"


#include <algorithm>
#include <iostream>



namespace CPSC131::Databases::Dinosaurs
{
	MyDinosaurDatabase::MyDinosaurDatabase()
	{
		this->rng_ = std::mt19937(this->random_device_());
		
		//	Feel free to add more code here, if you feel it is needed
	}
	
	///	Insert a Dinosaur record into the database
	void MyDinosaurDatabase::insert(const Dinosaur& dino)
	{
		tree_.insert(dino);
	}
	
	///	Check if a Dinosaur record exists in the database
	bool MyDinosaurDatabase::exists(const Dinosaur& dino) const
	{
		
		return tree_.exists(dino);
	}
	

	Dinosaur& MyDinosaurDatabase::find(const Dinosaur& dino)
	{
		
		return tree_.find(dino);
	}
	
	///	Remove a Dinosaur entry from the database.
	void MyDinosaurDatabase::remove(const Dinosaur& dino)
	{
		tree_.remove(dino);
	}
	
	///	Iterate all Dinosaur records using pre-order traversal.
	void MyDinosaurDatabase::traversePreOrder
	(
		std::function<
			void(DinoTree&, std::shared_ptr<DinoTree::Node>)
		> callback
	)
	{
		tree_.traversePreOrder(callback);
	}
	
	/**
	 * Iterate Dinosaur records with in-order traversal
	 * (const version)
	 */
	void MyDinosaurDatabase::traverseInOrder
	(
		std::function<
			void(const DinoTree&, std::shared_ptr<DinoTree::Node>)
		> callback
	) const
	{
		tree_.traverseInOrder(callback);
	}
	
	/**
	 * Iterate Dinosaur records with in-order traversal
	 * (non-const version)
	 */
	void MyDinosaurDatabase::traverseInOrder
	(
		std::function<
			void(DinoTree&, std::shared_ptr<DinoTree::Node>)
		> callback
	)
	{
		tree_.traverseInOrder(callback);
	}
	
	/**
	 * Iterate Dinosaur records with post-order traversal
	 * (non-const)
	 */
	void MyDinosaurDatabase::traversePostOrder
	(
		std::function<
			void(DinoTree&, std::shared_ptr<DinoTree::Node>)
		> callback
	)
	{
		tree_.traversePostOrder(callback);
	}
	
	/**
	 * Iterate Dinosaur records with level-order traversal
	 * (non-const)
	 */
	void MyDinosaurDatabase::traverseLevelOrder
	(
		std::function<
			bool(DinoTree&, std::shared_ptr<DinoTree::Node>)
		> callback
	)
	{
		tree_.traverseLevelOrder(callback);
	
	}
	

	void MyDinosaurDatabase::shuffle()
	{
		std::vector<Dinosaur> dinos_list;
		
		//	Pull all Dinos to a list
		this->tree_.traverseInOrder
		(
			[&dinos_list](DinoTree& t, std::shared_ptr<DinoTree::Node> node) -> bool
			{
				dinos_list.push_back(node->getData());
				
				return true;
			}
		);
		
		//	Shuffle the list
		std::shuffle(dinos_list.begin(), dinos_list.end(), this->rng_);
		
		//	Add back in to the tree
		this->clear();
		for ( auto& dino : dinos_list ) {
			this->insert(dino);
		}
	}
	
	///	Return the computed height of the database's internal BST
	size_t MyDinosaurDatabase::computeHeight()
	{
		
		return tree_.computeHeight();
	}
	
	///	Return the number of records in the database
	size_t MyDinosaurDatabase::size()
	{
		
		return tree_.size();
	}
	
	///	Return true if the database if empty; false otherwise
	bool MyDinosaurDatabase::empty()
	{
		
		return tree_.empty();
	}
	
	///	Clear the entire database
	void MyDinosaurDatabase::clear()
	{
		tree_.clear();
	}
	
	///	Return a reference to the internal binary search tree
	DinoTree& MyDinosaurDatabase::tree()
	{
		
		return tree_;
	}
}


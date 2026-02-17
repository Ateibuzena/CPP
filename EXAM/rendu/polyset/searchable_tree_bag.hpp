#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"


class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node* node, const int value) const
		{
			if (!node)
				return (false);
			if (node->value == value)
				return (true);
			else if (node->value > value)
				return (search(node->l, value);
			else
				return (search(node->r, value);
		}

	public:
		searchable_tree_bag() { }
		searchable_tree_bag(const searchable_tree_bag& source) { }
		
		searchable_tree_bag& operator=(const searchable_tree_bag& source)
		{
			if (this != &source)
				tree_bag::operator=(source);
			return (*this);
		}

		bool has(int) const
		{
			return (search(this->tree, value));
		}

		~searchable_tree_bag() { }
};

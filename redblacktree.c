#include <stdio.h>
#include <stdlib.h>
#include "cache.h"
#include "op.h"
#include "redblacktree.h"

/*
 *	Step1: left rotate operation of tree T at node _x
 */
void _left_rotate(_rb_tree_ptr T, _rb_tree_node_ptr _x)
{
	_rb_tree_node_ptr _y = _x->_right;

	_x->_right = _y->_left;

	if (_y->_left != NULL)
		_y->_left->_parent = _x;

	_y->_parent = _x->_parent;

	if (_x->_parent == NULL)
		T->_root = _y;
	else if (_x->_parent->_left == _x)
		_x->_parent->_left = _y;
	else
		_x->_parent->_right = _y;

	_y->_left = _x;
	_x->_parent = _y;
}





/*
 *Step2: right rotate operation of tree T at node _x
 */
void _right_rotate(_rb_tree_ptr T, _rb_tree_node_ptr _x)
{

/*  Complete this part















*/


}




/*
 * STep3: fix red black tree when insert a node into tree
 */
void _rb_tree_insert_fix(_rb_tree_ptr T, _rb_tree_node_ptr _x)
{
	while (_x != T->_root && _x->_parent->_color == _red)
	{
		if (_x->_parent == _x->_parent->_parent->_left)
		{
			_rb_tree_node_ptr _y = _x->_parent->_parent->_right;
			if (_y != NULL && _y->_color == _red)
			{
				_x->_parent->_color = _black;
				_y->_color = _black;
				_x->_parent->_parent->_color = _red;
				_x = _x->_parent->_parent;
			}
			else
			{
				if (_x == _x->_parent->_right)
				{
					_x = _x->_parent;
					_left_rotate(T, _x);
				}
				_x->_parent->_color = _black;
				_x->_parent->_parent->_color = _red;
				_right_rotate(T, _x->_parent->_parent);
			}
		}
		else
		{
			_rb_tree_node_ptr _y = _x->_parent->_parent->_left;
			if (_y != NULL && _y->_color == _red)
			{
				_x->_parent->_color = _black;
				_y->_color = _black;
				_x->_parent->_parent->_color = _red;
				_x = _x->_parent->_parent;
			}
			else
			{
				if (_x == _x->_parent->_left)
				{
					_x = _x->_parent;
					_right_rotate(T, _x);
				}
				_x->_parent->_color = _black;
				_x->_parent->_parent->_color = _red;
				_left_rotate(T, _x->_parent->_parent);
			}
		}
	}
	T->_root->_color = _black;
}





/*
 *	Step4: insert a node into the tree
 */

int _rb_tree_insert(_rb_tree_ptr T, uint64_t key, uint64_t value)
{
	_rb_tree_node_ptr _y = NULL;
	_rb_tree_node_ptr _x = T->_root;

	_rb_tree_node_ptr _k = (_rb_tree_node_ptr)malloc(sizeof(_rb_tree_node));
	_k->_color = _red;
	_k->_left = NULL;
	_k->_right = NULL;
	_k->_parent = NULL;
	_k->key = key;
	_k->value = value;


/*  Complete this part















*/

	_rb_tree_insert_fix(T, _k);
	return 0;
}







/*
 *	Step5: find a value in tree T
 */
_rb_tree_node_ptr _rb_tree_find(_rb_tree_ptr T, uint64_t key)
{
	_rb_tree_node_ptr _y = NULL;
	_rb_tree_node_ptr _x = T->_root;
	
/*  Complete this part















*/

	return _y;
}





/*
 *	Step6: free the space allocated for tree node
 */
void _rb_tree_node_clear(_rb_tree_node_ptr T)
{
	/*  Complete this part















*/
}







/*
 *	STep7: free the space allocated for tree
 */
void _rb_tree_clear(_rb_tree_ptr T)
{
	_rb_tree_node_clear(T->_root);
	free(T);
}
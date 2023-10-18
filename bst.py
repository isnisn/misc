# Python3 function to search a given key in a given BST

class Node:
	# Constructor to create a new node
	def __init__(self, key):
		self.key = key
		self.left = None
		self.right = None

# A utility function to recursively insert
# a new node with the given key in BST
def insert(node, key):
    
	# If the tree is empty, return a new node
	if node is None:
		return Node(key)

	# Otherwise, recur down the tree
	if key < node.key:
		node.left = insert(node.left, key)
	elif key > node.key:
		node.right = insert(node.right, key)

	# Return the (unchanged) node pointer
	return node

# Utility function to search a key in a BST
def search(root, key):
	# Base Cases: root is null or key is present at root
	if root is None or root.key == key:
		return root

	# Key is greater than root's key
	if root.key < key:
		return search(root.right, key)

	# Key is smaller than root's key
	return search(root.left, key)

# Sort the tree with a self-balancing algoritm
def sort(root):
	if root is None:
		return None
	else:
		# Traverse down the tree
		if root.left :
			print("Going to ", root.key)
			sort(root.left)

		# If we reached end of left side, print the key
		print(root.key)
		
		# Traverse down the right side, if it exists,
		if root.right :
	  		sort(root.right)
  

# Driver Code
if __name__ == '__main__':
	root = None
	root = insert(root, 50)
	insert(root, 30)
	insert(root, 20)
	insert(root, 40)
	insert(root, 70)
	insert(root, 60)
	insert(root, 80)
 
	sort(root)
#				50
#			   /  \
#			  30   70
#			 / \   / \
#			20 40 60 80

	# Key to be found
	key = 6

	# Searching in a BST
	if search(root, key) is None:
		print(key, "not found")
	else:
		print(key, "found")

	key = 60

	# Searching in a BST
	if search(root, key) is None:
		print(key, "not found")
	else:
		print(key, "found")

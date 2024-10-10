#include <bits/stdc++.h>
using namespace std;

// TreeNode class to represent each node in the tree
class TreeNode {
    public:
        TreeNode *parent; 
        string value;  // data field renamed
        vector<TreeNode*> childNodes;  // changed name to be more descriptive
        bool locked = false; 
        bool canBeLocked = true;  // changed to canBeLocked
        int lockedBy = -1;  // changed to lockedBy for clarity
};

// Function to lock a node by a user (uid)
bool lock(TreeNode* node, int userID) {
    if (node->locked || !node->canBeLocked) 
        return false;

    // Check if any of its descendants are locked
    queue<TreeNode*> checkDescendants;
    checkDescendants.push(node);
    
    while (!checkDescendants.empty()) {
        TreeNode* currentNode = checkDescendants.front();
        checkDescendants.pop();
        
        for (auto& child : currentNode->childNodes) {
            checkDescendants.push(child);
            if (child->locked) 
                return false;
        }
    }
    
    // If no descendants are locked, lock this node
    node->locked = true;    
    node->lockedBy = userID;
    
    // Mark descendants as not lockable
    queue<TreeNode*> updateDescendants;
    updateDescendants.push(node);
    
    while (!updateDescendants.empty()) {
        TreeNode* temp = updateDescendants.front();
        updateDescendants.pop();
        
        for (auto& child : temp->childNodes) {
            updateDescendants.push(child);
            child->canBeLocked = false;
        }
    }
    
    return true;
}

// Function to unlock a node if it's locked by the given user
bool unlock(TreeNode* node, int userID) {
    if (!node->locked || node->lockedBy != userID) 
        return false;

    node->locked = false;
    node->lockedBy = -1;

    // Re-enable lockability for descendants
    queue<TreeNode*> updateDescendants;
    updateDescendants.push(node);
    
    while (!updateDescendants.empty()) {
        TreeNode* temp = updateDescendants.front();
        updateDescendants.pop();
        
        for (auto& child : temp->childNodes) {
            updateDescendants.push(child);
            child->canBeLocked = true;
        }
    }

    return true;
}

// Function to upgrade a node if it has locked descendants by the same user
bool upgrade(TreeNode* node, int userID) {
    if (node->locked || !node->canBeLocked) 
        return false;

    int lockedChildCount = 0;
    queue<TreeNode*> checkDescendants;
    checkDescendants.push(node);
    
    while (!checkDescendants.empty()) {
        TreeNode* currentNode = checkDescendants.front();
        checkDescendants.pop();
        
        for (auto& child : currentNode->childNodes) {
            if (child->locked) {
                if (child->lockedBy != userID) 
                    return false;
                lockedChildCount++;
            }
            checkDescendants.push(child);
        }
    }

    // If there are locked children, upgrade the node
    if (lockedChildCount > 0) {
        node->locked = true;
        node->lockedBy = userID;

        // Unlock and make descendants un-lockable
        queue<TreeNode*> updateDescendants;
        updateDescendants.push(node);
        
        while (!updateDescendants.empty()) {
            TreeNode* temp = updateDescendants.front();
            updateDescendants.pop();
            
            for (auto& child : temp->childNodes) {
                updateDescendants.push(child);
                child->canBeLocked = false;
                child->locked = false;
                child->lockedBy = -1;
            }
        }
        return true;
    }
    
    return false;
}

// Function to decide which operation to perform
bool processOperation(int operationType, TreeNode* node, int userID) {
    if (operationType == 1) 
        return lock(node, userID);
    else if (operationType == 2) 
        return unlock(node, userID);
    else if (operationType == 3) 
        return upgrade(node, userID);
    
    return false;
}

int main() {
    int totalNodes, maxChildren, numQueries;
    cin >> totalNodes >> maxChildren >> numQueries;

    if (totalNodes == 0 || maxChildren == 0 || numQueries == 0)
        return 0;

    unordered_map<string, TreeNode*> nodeMap;
    vector<string> nodeNames;

    for (int i = 0; i < totalNodes; ++i) {
        string name;
        cin >> name;
        nodeNames.push_back(name);
    }

    // Construct tree
    int currentIndex = 0;
    string rootNodeValue = nodeNames[currentIndex++];
    TreeNode* rootNode = new TreeNode();
    rootNode->parent = nullptr;
    rootNode->value = rootNodeValue;

    queue<TreeNode*> pendingNodes;
    pendingNodes.push(rootNode);
    nodeMap[rootNodeValue] = rootNode;

    while (!pendingNodes.empty()) {
        TreeNode* parentNode = pendingNodes.front();
        pendingNodes.pop();

        int childCount = min(maxChildren, totalNodes - currentIndex);
        for (int i = 0; i < childCount; ++i) {
            string childName = nodeNames[currentIndex++];
            TreeNode* childNode = new TreeNode();
            childNode->parent = parentNode;
            childNode->value = childName;

            parentNode->childNodes.push_back(childNode);
            pendingNodes.push(childNode);
            nodeMap[childName] = childNode;
        }
    }

    // Process queries
    while (numQueries--) {
        int operationType, userID;
        string nodeName;
        cin >> operationType >> nodeName >> userID;

        cout << (processOperation(operationType, nodeMap[nodeName], userID) ? "true" : "false") << endl;
    }

    return 0;
}
    
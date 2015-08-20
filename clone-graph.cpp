/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
    Nodes are labeled uniquely.

    We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.
	First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
	Second node is labeled as 1. Connect node 1 to node 2.
	Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)   return NULL;
        
        queue<UndirectedGraphNode*> q;		//	for BFS
        map<int, UndirectedGraphNode*> m;	//	fast locate cloned nodes
        
        UndirectedGraphNode *origin;	//	node in original Undirected Graph
        UndirectedGraphNode *curr;		//	cloned node of origin
        UndirectedGraphNode *temp;
        
        map<int, UndirectedGraphNode*>::iterator iter;
        
        int n;		//	temp, number of neighbors
        int val;	//	temp, node value
        
        //	start BFS
        q.push(node);
        while (q.empty() == false) {
            origin = q.front();
            q.pop();
            
            iter = m.find(origin->label);
            
            if (iter == m.end()) {
                curr = new UndirectedGraphNode(origin->label);
                m[origin->label] = curr;
            }   //	not yet created
            else {
                curr = iter->second;
            }	//	node already created
            
            n = origin->neighbors.size();

            while (n-- > 0) {
                val = origin->neighbors[i]->label;

                iter = m.find(val);
                
                if (iter == m.end()) {
                    q.push(origin->neighbors[i]);
                    temp = new UndirectedGraphNode(val);
                    m[val] = temp;
                }   //	not yet created
                else {
                    temp = iter->second;
                }	//	node already created
                
                curr->neighbors.push_back(temp);
            }	//	foreach its neighbor
        }

        return m[node->label];
    }	//	O(n) time, O(n) space
};
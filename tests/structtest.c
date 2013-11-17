#include <stdio.h>

struct node
{
    int node_index;
 
};
struct node all_nodes[10];


int main()
{
    int node_index=0, nodeCount = 4;
   struct node * current_node;
   for(;node_index<nodeCount;node_index++)
   {
     //Get the node to be initialized
     current_node =&all_nodes[node_index];
     
     //Initialize the nodeindex
     current_node->node_index = node_index;
     printf("Current node initialized : %d \n",current_node->node_index);
     int neighbour_index=0;
     
     printf("\n");
   }
   
   node_index=0;
   for(;node_index<nodeCount;node_index++)
   {
     //Get the node to be initialized
     current_node =&all_nodes[node_index];
     
     
     printf("node_index :%d current_node.node_index :%d \n",node_index,current_node->node_index);
     
     printf("\n");
   }
   
}